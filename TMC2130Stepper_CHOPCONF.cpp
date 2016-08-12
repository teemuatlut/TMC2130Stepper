#include "TMC2130Stepper.h"

#define REG_CHOPCONF 0x6C

///////////////////////////////////////////////////////////////////////////////////////
// REG_CHOPCONF

uint32_t TMC2130Stepper::CHOPCONF() {
	uint32_t data = 0x0;
	send2130(READ|REG_CHOPCONF, &data, 0x0, 0x0);
	return data;
}

void TMC2130Stepper::CHOPCONF(uint32_t value) {
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, value, 0xFFFFFFFF);
}

uint8_t TMC2130Stepper::off_time() {return val_toff;}

void TMC2130Stepper::off_time(uint8_t value) {
	if (value > 15) value = 15;
	val_toff = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, value, 0xF);
}

uint8_t TMC2130Stepper::hysterisis_start() {return val_hstrt;}

void TMC2130Stepper::hysterisis_start(uint8_t value) {
	if (val_chm	== 0) {
		if (value < 1) value = 1;
		else if (value > 8) value = 8;
		val_hstrt = value;
		send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (value-1) << 4, 0x70);
	}
#ifdef TMC2130DEBUG
	else {Serial.println("chopper_mode bit is set to 1 -> fast_decay_time is in use. No change made.");}
#endif	
}

uint8_t TMC2130Stepper::fast_decay_time() {return val_tfd;}

void TMC2130Stepper::fast_decay_time(uint8_t value) {
	if (val_chm == 1) {
		if (value > 15) value = 15;
		val_tfd = value;
		value = ((uint32_t)value << 4) | (value & 0b111); // Create space between MSB and the bits 0..2
		send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)value << 4, 0x870);
	}
#ifdef TMC2130DEBUG
	else {Serial.println("chopper_mode bit is set to 0 -> hysterisis_start is in use. No change made.");}
#endif	
}

int8_t TMC2130Stepper::hysterisis_low() {return val_hend;}

void TMC2130Stepper::hysterisis_low(int8_t value) {
	if (val_chm == 0) {
		if (value < -3) value = -3;
		if (value > 12) value = 12;
		val_hend = value;
		send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (value+3) << 7, 0x780);
	}
#ifdef TMC2130DEBUG
	else {Serial.println("chopper_mode bit is set to 1 -> sine_offset is in use. No change made.");}
#endif	
}

int8_t TMC2130Stepper::sine_offset() {return val_offset;}

void TMC2130Stepper::sine_offset(int8_t value) {
	if (val_chm == 1) {
		if (value < -3) value = -3;
		if (value > 12) value = 12;
		val_hend = value;
		send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (value+3) << 7, 0x780);
	}
#ifdef TMC2130DEBUG
	else {Serial.println("chopper_mode bit is set to 0 -> hysterisis_low is in use. No change made.");}
#endif	
}

uint8_t TMC2130Stepper::disable_I_comparator() {return val_disfdcc;}

void TMC2130Stepper::disable_I_comparator(uint8_t value) {
	if (val_chm == 1) {
		if (value > 1) value = 1;
		val_disfdcc = value;
		send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)value << 12, (uint32_t)0b1 << 12);
	}
#ifdef TMC2130DEBUG
	else {Serial.println("chopper_mode bit is set to 0 -> No change made.");}
#endif
}

uint8_t TMC2130Stepper::random_off_time() {return val_rndtf;}

void TMC2130Stepper::random_off_time(uint8_t value) {
	if (value > 1) value = 1;
	val_rndtf = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)value << 13, (uint32_t)0b1 << 13);
}

uint8_t TMC2130Stepper::chopper_mode() {return val_chm;}

void TMC2130Stepper::chopper_mode(uint8_t value) {
	if (value > 1) value = 1;
	val_chm = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)value << 14, (uint32_t)0b1 << 14);
}

uint8_t TMC2130Stepper::blank_time() {return val_tbl;}

void TMC2130Stepper::blank_time(uint8_t value) {
	uint8_t valid[] = {54, 36, 24, 16};

	if (value < valid[3]) value = valid[3]; // Make sure we find a match for low values
	for (int i = 0; i<4; i++) {
		if (value >= valid[i]) {
			value = valid[i];
			break;
		}
	}

	val_tbl = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)value << 15, 0x18000);
}

uint8_t TMC2130Stepper::high_sense_R() {return val_vsense;}

void TMC2130Stepper::high_sense_R(uint8_t value) {
	if (value > 1) value = 1;
	val_vsense = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)(uint32_t)value << 17, (uint32_t)0b1 << 17);
}

uint8_t TMC2130Stepper::fullstep_threshold() {return val_vhighfs;}

void TMC2130Stepper::fullstep_threshold(uint8_t value) {
	if (value > 1) value = 1;
	val_vhighfs = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)(uint32_t)value << 18, (uint32_t)0b1 << 18);
}

uint8_t TMC2130Stepper::high_speed_mode() {return val_vhighchm;}

void TMC2130Stepper::high_speed_mode(uint8_t value) {
	if (value > 1) value = 1;
	val_vhighchm = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)(uint32_t)value << 19, (uint32_t)0b1 << 19);
}

uint8_t TMC2130Stepper::sync_phases() {return val_sync;}

void TMC2130Stepper::sync_phases(uint8_t value) {
	if (value > 15) value = 15;
	val_sync = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)(uint32_t)value << 20, 0xF00000);
}

uint8_t TMC2130Stepper::microsteps() {return val_mres;}

void TMC2130Stepper::microsteps(uint8_t value) {
	int valid[] 	= {		256, 	128, 	 64, 	 32, 	 16, 	  8, 	  4, 	  2, 	  0 };
	uint32_t _hex[] = {  0b0000, 0b0001, 0b0010, 0b0011, 0b0100, 0b0101, 0b0110, 0b0111, 0b1000 };

	for (int i = 0; i<9; i++) {
		if (value >= valid[i]) {
			val_mres = valid[i];
			send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, _hex[i] << 24, 0xF000000);
			break;
		}
	}
}

uint8_t TMC2130Stepper::interpolate() {return val_intpol;}

void TMC2130Stepper::interpolate(uint8_t value) {
	if (value > 1) value = 1;
	val_intpol = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)(uint32_t)value << 28, (uint32_t)0b1 << 28);
}

uint8_t TMC2130Stepper::double_edge_step() {return val_dedge;}

void TMC2130Stepper::double_edge_step(uint8_t value) {
	if (value > 1) value = 1;
	val_dedge = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)(uint32_t)value << 29, (uint32_t)0b1 << 29);
}

uint8_t TMC2130Stepper::disable_short_protection() {return val_diss2g;}

void TMC2130Stepper::disable_short_protection(uint8_t value) {
	if (value > 1) value = 1;
	val_diss2g = value;
	send2130(WRITE|REG_CHOPCONF, &cur_CHOPCONF, (uint32_t)(uint32_t)value << 30, (uint32_t)0b1 << 30);
}