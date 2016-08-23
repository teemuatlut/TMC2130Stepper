#include "TMC2130Stepper.h"

#define REG_PWMCONF 0X70

///////////////////////////////////////////////////////////////////////////////////////
// REG_PWMCONF

void TMC2130Stepper::PWMCONF(uint32_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set PWMCONF: ");
	Serial.println(value);
#endif
	send2130(WRITE|REG_PWMCONF, &cur_PWMCONF, value, 0xFFFFFFFF);
}

uint8_t TMC2130Stepper::stealth_amplitude() {return val_pwm_ampl;}

void TMC2130Stepper::stealth_amplitude(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set pwm_ampl: ");
	Serial.println(value);
#endif
	val_pwm_ampl = value;
	send2130(WRITE|REG_PWMCONF, &cur_PWMCONF, value, 0xFF);
}

uint8_t TMC2130Stepper::stealth_gradient() {return val_pwm_grad;}

void TMC2130Stepper::stealth_gradient(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set pwm_grad: ");
	Serial.println(value);
#endif
	val_pwm_grad = value;
	send2130(WRITE|REG_PWMCONF, &cur_PWMCONF, (uint32_t)value << 8, 0xFF00);
}

uint8_t TMC2130Stepper::stealth_freq() {return val_pwm_freq;}

void TMC2130Stepper::stealth_freq(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set pwm_freq: ");
	Serial.println(value);
#endif
	uint16_t valid[] = {1024, 683, 512, 410};

	if (value < valid[3]) value = valid[3]; // Make sure we find a match for low values
	for (int i = 0; i<4; i++) {
		if (value >= valid[i]) {
			value = valid[i];
			break;
		}
	}

	val_pwm_freq = value;
	send2130(WRITE|REG_PWMCONF, &cur_PWMCONF, (uint32_t)value << 16, 0x30000);
}

bool TMC2130Stepper::stealth_autoscale() {return val_pwm_autoscale;}

void TMC2130Stepper::stealth_autoscale(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set pwm_autoscale: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_pwm_autoscale = value;
	send2130(WRITE|REG_PWMCONF, &cur_PWMCONF, (uint32_t)value << 18, (uint32_t)0b1 << 18);
}

bool TMC2130Stepper::stealth_symmetric() {return val_pwm_symmetric;}

void TMC2130Stepper::stealth_symmetric(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set pwm_symmetric: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_pwm_symmetric = value;
	send2130(WRITE|REG_PWMCONF, &cur_PWMCONF, (uint32_t)value << 19, (uint32_t)0b1 << 19);
}

uint8_t TMC2130Stepper::standstill_mode() {return val_freewheel;}

void TMC2130Stepper::standstill_mode(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set freewheel: ");
	Serial.println(value);
#endif
	if (value < 1) value = 1;
	else if (value > 4) value = 4;
	val_freewheel = value;
	send2130(WRITE|REG_PWMCONF, &cur_PWMCONF, ((uint32_t)value-1) << 20, 0x300000);
}