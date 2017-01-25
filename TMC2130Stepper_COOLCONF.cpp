#include "TMC2130Stepper.h"

#define REG_COOLCONF 0X6D

///////////////////////////////////////////////////////////////////////////////////////
// REG_COOLCONF

void TMC2130Stepper::COOLCONF(uint32_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set COOLCONF: ");
	Serial.println(value);
#endif
	send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, value, 0xFFFFFFFF);
}

uint8_t TMC2130Stepper::sg_min() {return val_semin;}

void TMC2130Stepper::sg_min(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set semin: ");
	Serial.println(value);
#endif
	if (value > 15) value = 15;
	val_semin = value;
	send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, value, 0xF);
}

uint8_t TMC2130Stepper::sg_step_width() {return val_seup;}

void TMC2130Stepper::sg_step_width(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set seup: ");
	Serial.println(value);
#endif
	uint8_t valid[] = {8, 4, 2, 1};

	if (value < valid[3]) value = valid[3]; // Make sure we find a match for low values
	for (int i = 0; i<4; i++) {
		if (value >= valid[i]) {
			value = valid[i];
			break;
		}
	}

	val_seup = value;
	send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, (uint32_t)value << 5, 0x60);
}

uint8_t TMC2130Stepper::sg_max() {return val_semax;}

void TMC2130Stepper::sg_max(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set semax: ");
	Serial.println(value);
#endif
	if (value > 15) value = 15;
	val_semin = value;
	send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, (uint32_t)value << 8, 0xF00);
}

uint8_t TMC2130Stepper::sg_current_decrease() {return val_sedn;}

void TMC2130Stepper::sg_current_decrease(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set sedn: ");
	Serial.println(value);
#endif
	uint8_t valid[] = {32, 8, 2, 1};

	if (value < valid[3]) value = valid[3]; // Make sure we find a match for low values
	for (int i = 0; i<4; i++) {
		if (value >= valid[i]) {
			value = valid[i];
			break;
		}
	}

	val_sedn = value;
	send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, (uint32_t)value << 13, 0x6000);
}

uint8_t TMC2130Stepper::smart_min_current() {return val_seimin;}

void TMC2130Stepper::smart_min_current(uint8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set seimin: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_seimin = value;
	send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, (uint32_t)value << 15, 0x8000);
}

int8_t TMC2130Stepper::sg_stall_value() {return val_sgt;}

void TMC2130Stepper::sg_stall_value(int8_t value) {
#ifdef TMC2130DEBUG
	Serial.print("Set sgt: ");
	Serial.println(value);
#endif
	if (value < -64) value = -64;
	else if (value > 63) value = 63;
	val_sgt = value;
	if (value < 0)
		send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, (uint32_t)(value & 0x40) << 16, 0x7F0000UL);
	else
		send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, (uint32_t)(value) << 16, 0x7F0000UL);
}

bool TMC2130Stepper::sg_filter() {return val_sfilt;}

void TMC2130Stepper::sg_filter(bool value) {
#ifdef TMC2130DEBUG
	Serial.print("Set sfilt: ");
	Serial.println(value);
#endif
	if (value > 1) value = 1;
	val_sfilt = value;
	send2130(WRITE|REG_COOLCONF, &cur_COOLCONF, (uint32_t)value << 24, 0b1UL << 24);
}