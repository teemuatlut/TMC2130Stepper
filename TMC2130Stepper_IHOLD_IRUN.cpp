#include "TMC2130Stepper.h"

#define REG_IHOLD_IRUN 0x10

///////////////////////////////////////////////////////////////////////////////////////
// REG_IHOLD_IRUN

uint8_t TMC2130Stepper::hold_current() {return val_ihold;}

void TMC2130Stepper::hold_current(uint8_t value) {
	if (value > 31) value = 31;
	val_ihold = value;
	send2130(WRITE|REG_IHOLD_IRUN, &cur_IHOLD_IRUN, value, 0x1F);
}

uint8_t TMC2130Stepper::run_current() {return val_irun;}

void TMC2130Stepper::run_current(uint8_t value) {
	if (value > 31) value = 31;
	val_irun = value;
	send2130(WRITE|REG_IHOLD_IRUN, &cur_IHOLD_IRUN, (uint32_t)value << 8, 0x1F00);
}

uint8_t TMC2130Stepper::hold_delay() {return val_ihold_delay;}

void TMC2130Stepper::hold_delay(uint8_t value) {
	if (value > 15) value = 15;
	val_ihold_delay = value;
	send2130(WRITE|REG_IHOLD_IRUN, &cur_IHOLD_IRUN, (uint32_t)(uint32_t)value << 16, 0xF000);
}