#include "TMC2130Stepper.h"

#define REG_GCONF 0x00

///////////////////////////////////////////////////////////////////////////////////////
// REG_GCONF

uint32_t TMC2130Stepper::GCONF() {
#ifdef TMC2130DEBUG
	Serial.println("Get GCONF: ");
#endif
	uint32_t data = 0x0;
	send2130(READ|REG_GCONF, &data, 0x0, 0x0);
	return data;
}

void TMC2130Stepper::GCONF(uint32_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set GCONF: ");
	Serial.println(value);
#endif
	send2130(WRITE|REG_GCONF, &cur_GCONF, value, 0xFFFFFFFF);
}

bool TMC2130Stepper::external_ref() {return val_i_scale_analog;}

void TMC2130Stepper::external_ref(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set I_scale_analog: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_i_scale_analog = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, value, 0b1);
}

bool TMC2130Stepper::internal_sense_R() {return val_internal_r_sense;}

void TMC2130Stepper::internal_sense_R(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set internal_Rsense: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_internal_r_sense = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 1, (uint32_t)0b1 << 1);
}

bool TMC2130Stepper::stealthChop() {return val_en_pwm_mode;}

void TMC2130Stepper::stealthChop(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set en_pwm_mode: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_en_pwm_mode = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 2, (uint32_t)0b1 << 2);
}

bool TMC2130Stepper::commutation() {return val_enc_commutation;}

void TMC2130Stepper::commutation(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set enc_commutation: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_enc_commutation = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 3, (uint32_t)0b1 << 3);
}

bool TMC2130Stepper::shaft_dir() {return val_shaft;}

void TMC2130Stepper::shaft_dir(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set shaft: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_shaft = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 4, (uint32_t)0b1 << 4);
}

bool TMC2130Stepper::diag0_errors() {return val_diag0_error;}

void TMC2130Stepper::diag0_errors(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag0_error: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag0_error = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 5, (uint32_t)0b1 << 5);
}

bool TMC2130Stepper::diag0_temp_prewarn() {return val_diag0_otpw;}

void TMC2130Stepper::diag0_temp_prewarn(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag0_otpw: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag0_otpw = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 6, (uint32_t)0b1 << 6);
}

bool TMC2130Stepper::diag0_stall() {return val_diag0_stall;}

void TMC2130Stepper::diag0_stall(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag0_stall: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag0_stall = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 7, (uint32_t)0b1 << 7);
}

bool TMC2130Stepper::diag1_stall() {return val_diag1_stall;}

void TMC2130Stepper::diag1_stall(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag1_stall: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag1_stall = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 8, (uint32_t)0b1 << 8);
}

bool TMC2130Stepper::diag1_index() {return val_diag1_index;}

void TMC2130Stepper::diag1_index(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag1_index: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag1_index = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 9, (uint32_t)0b1 << 9);
}

bool TMC2130Stepper::diag1_chopper_on() {return val_diag1_onstate;}

void TMC2130Stepper::diag1_chopper_on(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag1_onstate: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag1_onstate = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 10, (uint32_t)0b1 << 10);
}

bool TMC2130Stepper::diag1_steps_skipped() {return val_diag1_steps_skipped;}

void TMC2130Stepper::diag1_steps_skipped(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag1_steps_skipped: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag1_steps_skipped = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 11, (uint32_t)0b1 << 11);
}

bool TMC2130Stepper::diag0_active_high() {return val_diag0_int_pushpull;}

void TMC2130Stepper::diag0_active_high(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag0_int_pushpull: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag0_int_pushpull = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 12, (uint32_t)0b1 << 12);
}

bool TMC2130Stepper::diag1_active_high() {return val_diag1_pushpull;}

void TMC2130Stepper::diag1_active_high(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set diag1_pushpull: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_diag1_pushpull = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 13, (uint32_t)0b1 << 13);
}

bool TMC2130Stepper::small_hysterisis() {return val_small_hysterisis;}

void TMC2130Stepper::small_hysterisis(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set small_hysterisis: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_small_hysterisis = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 14, (uint32_t)0b1 << 14);
}

bool TMC2130Stepper::stop_enable() {return val_stop_enable;}

void TMC2130Stepper::stop_enable(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set stop_enable: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_stop_enable = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)value << 15, (uint32_t)0b1 << 15);
}

bool TMC2130Stepper::direct_mode() {return val_direct_mode;}

void TMC2130Stepper::direct_mode(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set direct_mode: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_direct_mode = value;
	send2130(WRITE|REG_GCONF, &cur_GCONF, (uint32_t)(uint32_t)value << 16, (uint32_t)0b1 << 16);
}

/*
bit 18 not implemented:
test_mode 0: 
Normal operation 1:
Enable analog test output on pin DCO. IHOLD[1..0] selects the function of DCO: 
0…2: T120, DAC, VDDH Attention:
Not for user, set to 0 for normal operation! 
*/