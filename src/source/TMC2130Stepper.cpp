#include <SPI.h>
#include "TMC2130Stepper.h"

//#define REG_GCONF			0x00
#define REG_GSTAT			0x01
#define REG_IOIN			0x04
//#define REG_IHOLD_IRUN	0x10
#define REG_TPOWERDOWN		0x11
#define REG_TSTEP			0x12
#define REG_TPWMTHRS		0x13
#define REG_TCOOLTHRS		0x14
#define REG_THIGH			0x15
#define REG_XDIRECT			0x2D
#define REG_VDCMIN			0x33
#define REG_MSCNT			0x6A
#define REG_MSCURACT		0x6B
//#define REG_CHOPCONF		0x6C
//#define REG_COOLCONF		0X6D
#define REG_DCCTRL			0x6E
#define REG_DRVSTATUS		0x6F
//#define REG_PWMCONF		0X70
#define REG_PWMSCALE		0X71
#define REG_ENCMCTRL		0x72
#define REG_LOSTSTEPS		0x73

TMC2130Stepper::TMC2130Stepper(uint8_t pinEN, uint8_t pinDIR, uint8_t pinStep, uint8_t pinCS) {
	_started = false;

	this->_pinEN = pinEN;
	this->_pinDIR = pinDIR;
	this->_pinSTEP = pinStep;
	this->_pinCS = pinCS;
}

void TMC2130Stepper::begin() {
#ifdef TMC2130DEBUG
	Serial.println("TMC2130 Stepper driver library");
	Serial.print("Enable pin: ");
	Serial.println(_pinEN);
	Serial.print("Direction pin: ");
	Serial.println(_pinDIR);
	Serial.print("Step pin: ");
	Serial.println(_pinSTEP);
	Serial.print("Chip select pin: ");
	Serial.println(_pinCS);
#endif
	//set pins
	pinMode(_pinEN, OUTPUT);
	pinMode(_pinDIR, OUTPUT);
	pinMode(_pinSTEP, OUTPUT);
	pinMode(_pinCS, OUTPUT);
	digitalWrite(_pinEN, HIGH); //deactivate driver (LOW active)
	digitalWrite(_pinDIR, LOW); //LOW or HIGH
	digitalWrite(_pinSTEP, LOW);
	digitalWrite(_pinCS, HIGH);
/*
	pinMode(MOSI, OUTPUT);
	pinMode(MISO, INPUT);
	pinMode(SCK, OUTPUT);
	digitalWrite(MOSI, LOW);
	digitalWrite(MISO, HIGH);
	digitalWrite(SCK, LOW);

	SPI.begin();

	GCONF(0x0000UL);
	CHOPCONF(0x0000UL);
	COOLCONF(0x0000UL);
	PWMCONF(0x0000UL);
	hold_current(0x0);
	run_current(0x0);
*/
	off_time(8);
	blank_time(24);

	_started = true;
}

uint32_t TMC2130Stepper::send2130(uint8_t addressByte, uint32_t *config, uint32_t value, uint32_t mask) {
	uint8_t s;
	SPI.begin();
	SPI.beginTransaction(SPISettings(16000000/8, MSBFIRST, SPI_MODE3));
	digitalWrite(_pinCS, LOW);

	s = SPI.transfer(addressByte & 0xFF);
#ifdef TMC2130DEBUG
	Serial.println("Received parameters:");
	Serial.print("#Address byte: ");
	Serial.println(addressByte, HEX);
	Serial.print("#Current config: ");
	Serial.println(*config, BIN);
	Serial.print("#Value to write: ");
	Serial.println(value, BIN);
	Serial.print("#Mask: ");
	Serial.println(mask, BIN);
	Serial.print("#s: ");
	Serial.println(s, BIN);
#endif

	if (addressByte >> 7) { // Check if WRITE command
		*config &= ~mask; // Clear bits being set
		*config |= (value & mask); // Set new values
		SPI.transfer((*config >> 24) & 0xFF);
		SPI.transfer((*config >> 16) & 0xFF);
		SPI.transfer((*config >>  8) & 0xFF);
		SPI.transfer(*config & 0xFF);
#ifdef TMC2130DEBUG
		Serial.println("=> WRITE cmd");
		Serial.print("New config: ");
		Serial.println(*config, BIN);
#endif
	} else { // READ command
		SPI.transfer16(0x0000); // Clear SPI
		SPI.transfer16(0x0000);
		digitalWrite(_pinCS, HIGH);
		digitalWrite(_pinCS, LOW);

		SPI.transfer(addressByte & 0xFF); // Send the address byte again
		*config  = SPI.transfer(0x00);
		*config <<= 8;
		*config |= SPI.transfer(0x00);
		*config <<= 8;
		*config |= SPI.transfer(0x00);
		*config <<= 8;
		*config |= SPI.transfer(0x00);
#ifdef TMC2130DEBUG
		Serial.println("=> READ cmd");
		Serial.print("Received config: ");
		Serial.println(*config, BIN);
#endif
	}

	digitalWrite(_pinCS, HIGH);
	SPI.endTransaction();

	return s;
}
#ifdef TMC2130DEBUG
void TMC2130Stepper::checkStatus() {
	uint32_t data = 0x0;
	uint8_t s;

    //show REG_GSTAT
    s = send2130(READ|REG_GSTAT, &data, 0x0, 0x0);
    Serial.print("GSTAT:     0x0");
    Serial.print(data, HEX);
    Serial.print("\t - ");
    Serial.print("Status: 0x");
    Serial.print(s, HEX);
    if(s & 0x01) Serial.print(" reset");
    if(s & 0x02) Serial.print(" error");
    if(s & 0x04) Serial.print(" sg2");
    if(s & 0x08) Serial.print(" standstill");
    Serial.println(" ");

    //show REG_DRVSTATUS
    s = send2130(READ|REG_DRVSTATUS, &data, 0x0, 0x0);
    Serial.print("DRVSTATUS: 0x");
    Serial.print(data, HEX);
    Serial.print("\t - ");
    Serial.print("Status: 0x");
    Serial.print(s, HEX);
    if(s & 0x01) Serial.print(" reset");
    if(s & 0x02) Serial.print(" error");
    if(s & 0x04) Serial.print(" sg2");
    if(s & 0x08) Serial.print(" standstill");
    Serial.println(" ");
}
#endif

void TMC2130Stepper::SilentStepStick2130(uint16_t current) {
	//begin();
	setCurrent(current, 0.11, 0.5);
}

/*	
	Requested current = mA = I_rms/1000
	Equation for current:
	I_rms = (CS+1)/32 * V_fs/(R_sense+0.02ohm) * 1/sqrt(2)
	Solve for CS ->
	CS = 32*sqrt(2)*I_rms*(R_sense+0.02)/V_fs - 1
	
	Example:
	vsense = 0b0 -> V_fs = 0.325V
	mA = 1640mA = I_rms/1000 = 1.64A
	R_sense = 0.10 Ohm
	->
	CS = 32*sqrt(2)*1.64*(0.10+0.02)/0.325 - 1 = 26.4
	CS = 26
*/	
void TMC2130Stepper::setCurrent(uint16_t mA, float Rsense, float multiplier) {
	uint8_t CS = 32.0*1.41421*mA/1000.0*(Rsense+0.02)/0.325 - 1;
	
	// If Current Scale is too low, turn on high sensitivity R_sense and calculate again
	if (CS < 16) {
		high_sense_R(true);
		CS = 32.0*1.41421*mA/1000.0*(Rsense+0.02)/0.180 - 1;
	} else if(high_sense_R()) { // If CS >= 16, turn off high_sense_r if it's currently ON
		high_sense_R(false);
	}
	run_current(CS);
	hold_current(CS*multiplier);
	val_mA = mA;

	#ifdef TMC2130DEBUG
		Serial.print("mA=");
		Serial.print(mA);
		Serial.print("\tRsense=");
		Serial.print(Rsense);
		Serial.print("\tmultiplier=");
		Serial.print(multiplier);
		Serial.print("\tval_vsense=");
		Serial.print(val_vsense);
		Serial.print(" V_fs=");
		Serial.print(V_fs);
		Serial.print("\tCS=");
		Serial.print(CS);
	#endif
}

uint16_t TMC2130Stepper::getCurrent() {	return val_mA; }

bool TMC2130Stepper::checkOT() {
	uint32_t response = DRVSTATUS();
	if (response & 0x4000000) {
		flag_otpw = 1;
		return true; // bit 26 for overtemperature warning flag
	}
	return false;
}

bool TMC2130Stepper::getOTPW() { return flag_otpw; }

void TMC2130Stepper::clear_otpw() {	flag_otpw = 0; }

bool TMC2130Stepper::isEnabled() { return !digitalRead(_pinEN); }

/*
void TMC2130Stepper::takeSteps(int steps) {
	int stepsLeft = steps;
}

void TMC2130Stepper::step(int steps, int speed) {
	if ((lastStep + speed)<=millis() && stepsLeft > 0) {
		digitalWrite(_pinSTEP, !digitalRead(_pinSTEP));
	}
	stepsLeft -= 1;
	lastStep = millis();
}
*/
///////////////////////////////////////////////////////////////////////////////////////
// REG_TPOWERDOWN

uint8_t TMC2130Stepper::power_down_delay() {return val_tpowerdown;}

void TMC2130Stepper::power_down_delay(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set tpowerdown: ");
	Serial.println(value);
#endif
	val_tpowerdown = value;
	send2130(WRITE|REG_TPOWERDOWN, &cur_TPOWERDOWN, value, 0xFF);
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_GSTAT

uint32_t TMC2130Stepper::status_flags() {
	uint32_t data = 0x0;
	send2130(READ|REG_GSTAT, &data, 0x0, 0x0);
	return data;
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_IOIN

uint32_t TMC2130Stepper::input() {
	uint32_t data = 0x0;
	send2130(READ|REG_IOIN, &data, 0x0, 0x0);
	return data;
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_TSTEP

uint32_t TMC2130Stepper::microstep_time() {
	uint32_t data = 0x0;
	send2130(READ|REG_TSTEP, &data, 0x0, 0x0);
	return data;
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_TPWMTHRS

uint32_t TMC2130Stepper::stealth_max_speed() {return val_tpwmthrs;}

void TMC2130Stepper::stealth_max_speed(uint32_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set tpwmthres: ");
	Serial.println(value);
#endif
	if (value > 1048575) value = 1048575;
	val_tpwmthrs = value;
	send2130(WRITE|REG_TPWMTHRS, &cur_TPWMTHRS, value, 0xFFFFF);
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_TCOOLTHRS

uint32_t TMC2130Stepper::coolstep_min_speed() {return val_tcoolthrs;}

void TMC2130Stepper::coolstep_min_speed(uint32_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set tcoolthrs: ");
	Serial.println(value);
#endif
	if (value > 1048575) value = 1048575;
	val_tcoolthrs = value;
	send2130(WRITE|REG_TCOOLTHRS, &cur_TCOOLTHRS, value, 0xFFFFF);
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_THIGH

uint32_t TMC2130Stepper::mode_sw_speed() {return val_thigh;}

void TMC2130Stepper::mode_sw_speed(uint32_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set thigh: ");
	Serial.println(value);
#endif
	if (value > 1048575) value = 1048575;
	val_thigh = value;
	send2130(WRITE|REG_THIGH, &cur_THIGH, value, 0xFFFFF);
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_XDRIRECT

int16_t TMC2130Stepper::coil_A_current() {return val_xdirect_a;}

void TMC2130Stepper::coil_A_current(int16_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set xdirect_a: ");
	Serial.println(value);
#endif
	if (value < -255) value = -255;
	else if (value > 255) value = 255;
	val_xdirect_a = value;
	send2130(WRITE|REG_XDIRECT, &cur_XDIRECT, value, 0x1FF);
}

int16_t TMC2130Stepper::coil_B_current() {return val_xdirect_b;}

void TMC2130Stepper::coil_B_current(int16_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set xdirect_b: ");
	Serial.println(value);
#endif
	if (value < -255) value = -255;
	else if (value > 255) value = 255;
	val_xdirect_b = value;
	send2130(WRITE|REG_XDIRECT, &cur_XDIRECT, (uint32_t)value << 16, 0x1FF0000);
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_VDCMIN

uint32_t TMC2130Stepper::DCstep_min_speed() {return val_vdcmin;}

void TMC2130Stepper::DCstep_min_speed(uint32_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set vdcmin: ");
	Serial.println(value);
#endif
	if (value > 16777215) value = 16777215;
	val_vdcmin = value;
	send2130(WRITE|REG_VDCMIN, &cur_VDCMIN, value, 0xFFFFFF);
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_DRVSTATUS

uint32_t TMC2130Stepper::DRVSTATUS() {
	uint32_t data = 0x0;
	send2130(READ|REG_DRVSTATUS, &data, 0x0, 0x0);
	return data;
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_PWM_SCALE

uint32_t TMC2130Stepper::PWM_SCALE() {
	uint32_t data = 0x0;
	send2130(READ|REG_PWMSCALE, &data, 0x0, 0x0);
	return data;
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_ENCM_CTRL

bool TMC2130Stepper::invert_encoder() {return val_invert_encoder;}

void TMC2130Stepper::invert_encoder(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set invert_encoder: ");
	Serial.println(value);
#endif
	val_invert_encoder = value;
	send2130(WRITE|REG_ENCMCTRL, &cur_PWMCONF, value, 0b1);
}

bool TMC2130Stepper::maxspeed() {return val_maxspeed;}

void TMC2130Stepper::maxspeed(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set maxspeed: ");
	Serial.println(value);
#endif
	val_maxspeed = value;
	send2130(WRITE|REG_ENCMCTRL, &cur_PWMCONF, value, 0b1 << 1);
}

///////////////////////////////////////////////////////////////////////////////////////
// REG_LOST_STEPS

uint32_t TMC2130Stepper::LOST_STEPS() {
	uint32_t data = 0x0;
	send2130(READ|REG_LOSTSTEPS, &data, 0x0, 0x0);
	return data;
}