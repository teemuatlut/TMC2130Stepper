#ifndef TMC2310Stepper_h
#define TMC2310Stepper_h

//#define TMC2130DEBUG

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#endif

class TMC2130Stepper {
	public:
		TMC2130Stepper(uint8_t pinEN, uint8_t pinDIR, uint8_t pinStep, uint8_t pinCS);
		void begin();
		void checkStatus();
		void SilentStepStick2130(uint16_t);
		void setCurrent(uint16_t mah, float Rsense, float multiplier);
		bool checkOT();
		// REG_GCONF
		uint32_t GCONF();
		void GCONF(uint32_t value);
		bool external_ref();
		void external_ref(bool value);
		bool internal_sense_R();
		void internal_sense_R(bool value);
		bool stealthChop();
		void stealthChop(bool value);
		bool commutation();
		void commutation(bool value);
		bool shaft_dir();
		void shaft_dir(bool value);
		bool diag0_errors();
		void diag0_errors(bool value);
		bool diag0_temp_prewarn();
		void diag0_temp_prewarn(bool value);
		bool diag0_stall();
		void diag0_stall(bool value);
		bool diag1_stall();
		void diag1_stall(bool value);
		bool diag1_index();
		void diag1_index(bool value);
		bool diag1_chopper_on();
		void diag1_chopper_on(bool value);
		bool diag1_steps_skipped();
		void diag1_steps_skipped(bool value);
		bool diag0_active_high();
		void diag0_active_high(bool value);
		bool diag1_active_high();
		void diag1_active_high(bool value);
		bool small_hysterisis();
		void small_hysterisis(bool value);
		bool stop_enable();
		void stop_enable(bool value);
		bool direct_mode();
		void direct_mode(bool value);
		// REG_IHOLD_IRUN
		uint8_t hold_current();
		void hold_current(uint8_t value);
		uint8_t run_current();
		void run_current(uint8_t value);
		uint8_t hold_delay();
		void hold_delay(uint8_t value);
		// REG_TPOWERDOWN
		uint8_t power_down_delay();
		void power_down_delay(uint8_t value);
		// REG_TSTEP
		uint32_t microstep_time();
		// REG_TPWMTHRS
		uint32_t stealth_max_speed();
		void stealth_max_speed(uint32_t value);
		// REG_TCOOLTHRS
		uint32_t coolstep_min_speed();
		void coolstep_min_speed(uint32_t value);
		// REG_THIGH
		uint32_t mode_sw_speed();
		void mode_sw_speed(uint32_t value);
		// REG_XDRIRECT
		int16_t coil_A_current();
		void coil_A_current(int16_t value);
		int16_t coil_B_current();
		void coil_B_current(int16_t value);
		// REG_VDCMIN
		uint32_t DCstep_min_speed();
		void DCstep_min_speed(uint32_t value);
		// REG_CHOPCONF
		uint32_t CHOPCONF();
		void CHOPCONF(uint32_t value);
		uint8_t off_time();
		void off_time(uint8_t value);
		uint8_t hysterisis_start();
		void hysterisis_start(uint8_t value);
		uint8_t fast_decay_time();
		void fast_decay_time(uint8_t value);
		int8_t hysterisis_low();
		void hysterisis_low(int8_t value);
		int8_t sine_offset();
		void sine_offset(int8_t value);
		bool disable_I_comparator();
		void disable_I_comparator(bool value);
		bool random_off_time();
		void random_off_time(bool value);
		uint8_t chopper_mode();
		void chopper_mode(uint8_t value);
		uint8_t blank_time();
		void blank_time(uint8_t value);
		bool high_sense_R();
		void high_sense_R(bool value);
		bool fullstep_threshold();
		void fullstep_threshold(bool value);
		bool high_speed_mode();
		void high_speed_mode(bool value);
		uint8_t sync_phases();
		void sync_phases(uint8_t value);
		uint8_t microsteps();
		void microsteps(uint8_t value);
		bool interpolate();
		void interpolate(bool value);
		bool double_edge_step();
		void double_edge_step(bool value);
		bool disable_short_protection();
		void disable_short_protection(bool value);
		// REG_COOLCONF
		void COOLCONF(uint32_t value);
		uint8_t sg_min();
		void sg_min(uint8_t value);
		uint8_t sg_step_width();
		void sg_step_width(uint8_t value);
		uint8_t sg_max();
		void sg_max(uint8_t value);
		uint8_t sg_current_decrease();
		void sg_current_decrease(uint8_t value);
		uint8_t smart_min_current();
		void smart_min_current(uint8_t value);
		int8_t sg_stall_value();
		void sg_stall_value(int8_t value);
		bool sg_filter();
		void sg_filter(bool value);
		// REG_PWMCONF
		void PWMCONF(uint32_t value);
		uint8_t stealth_amplitude();
		void stealth_amplitude(uint8_t value);
		uint8_t stealth_gradient();
		void stealth_gradient(uint8_t value);
		uint8_t stealth_freq();
		void stealth_freq(uint8_t value);
		bool stealth_autoscale();
		void stealth_autoscale(bool value);
		bool stealth_symmetric();
		void stealth_symmetric(bool value);
		uint8_t standstill_mode();
		void standstill_mode(uint8_t value);
		// REG_DRVSTATUS
		uint32_t DRVSTATUS();
		// REG_PWM_SCALE
		uint32_t PWM_SCALE();
		// REG_ENCM_CTRL
		bool invert_encoder();
		void invert_encoder(bool value);
		bool maxspeed();
		void maxspeed(bool value);
		// REG_LOST_STEPS
		uint32_t LOST_STEPS();

		bool _started;

	private:
		const uint8_t WRITE 		= 0b10000000;
		const uint8_t READ 			= 0b00000000;
		uint8_t _pinEN 				= 16;
		uint8_t _pinSTEP 			= 18;
		uint8_t _pinCS				= 17;
		//const int MOSI_PIN		= 12;
		//const int MISO_PIN		= 11;
		//const int SCK_PIN			= 13;
		uint8_t _pinDIR				= 19;

		// Current register values
		uint32_t cur_GCONF			= 0x00;
		uint32_t cur_GSTAT			= 0x00;
		uint32_t cur_IOIN			= 0x00;
		uint32_t cur_IHOLD_IRUN		= 0x00;
		uint32_t cur_TPOWERDOWN		= 0x00;
		uint32_t cur_TSTEP 			= 0x00;
		uint32_t cur_TPWMTHRS		= 0x00;
		uint32_t cur_TCOOLTHRS		= 0x00;
		uint32_t cur_THIGH			= 0x00;
		uint32_t cur_XDIRECT		= 0x00;
		uint32_t cur_VDCMIN			= 0x00;
		uint32_t cur_MSCNT			= 0x00;
		uint32_t cur_MSCURACT		= 0x00;
		uint32_t cur_CHOPCONF		= 0x00;
		uint32_t cur_COOLCONF		= 0x00;
		uint32_t cur_DCCTRL			= 0x00;
		uint32_t cur_DRVSTATUS		= 0x00;
		uint32_t cur_PWMCONF		= 0x00;
		uint32_t cur_PWMSCALE		= 0x00;
		uint32_t cur_ENCMCTRL		= 0x00;
		uint32_t cur_LOSTSTEPS		= 0x00;

		bool val_i_scale_analog 			= 0;
		bool val_internal_r_sense			= 0;
		bool val_en_pwm_mode				= 0;
		bool val_enc_commutation			= 0;
		bool val_shaft						= 0;
		bool val_diag0_error				= 0;
		bool val_diag0_otpw					= 0;
		bool val_diag0_stall				= 0;
		bool val_diag1_stall				= 0;
		bool val_diag1_index				= 0;
		bool val_diag1_onstate				= 0;
		bool val_diag1_steps_skipped		= 0;
		bool val_diag0_int_pushpull			= 0;
		bool val_diag1_pushpull				= 0;
		bool val_small_hysterisis			= 0;
		bool val_stop_enable				= 0;
		bool val_direct_mode				= 0;
		uint8_t val_ihold 					= 0;
		uint8_t val_irun 					= 0;
		uint8_t val_ihold_delay				= 0;
		uint8_t val_tpowerdown				= 0;
		uint8_t val_tpwmthrs				= 0;
		uint8_t val_tcoolthrs				= 0;
		uint8_t val_thigh					= 0;
		uint8_t val_xdirect_a				= 0;
		uint8_t val_xdirect_b				= 0;
		uint8_t val_vdcmin					= 0;
		uint8_t val_toff					= 0;
		uint8_t val_hstrt					= 0;
		uint8_t val_tfd						= 0;
		uint8_t val_hend					= 0;
		uint8_t val_offset					= 0;
		bool val_disfdcc					= 0;
		bool val_rndtf						= 0;
		uint8_t val_chm						= 0;
		uint8_t val_tbl						= 0;
		bool val_vsense						= 0;
		bool val_vhighfs					= 0;
		bool val_vhighchm					= 0;
		uint8_t val_sync					= 0;
		uint8_t val_mres 					= 0;
		bool val_intpol						= 0;
		bool val_dedge						= 0;
		bool val_diss2g						= 0;
		uint8_t val_semin					= 0;
		uint8_t val_seup					= 0;
		uint8_t val_semax					= 0;
		uint8_t val_sedn					= 0;
		uint8_t val_seimin					= 0;
		uint8_t val_sgt						= 0;
		uint8_t val_sfilt					= 0;
		uint8_t val_pwm_ampl				= 0;
		uint8_t val_pwm_grad				= 0;
		uint8_t val_pwm_freq				= 0;
		bool val_pwm_autoscale				= 0;
		bool val_pwm_symmetric				= 0;
		uint8_t val_freewheel				= 0;
		bool val_invert_encoder				= 0;
		bool val_maxspeed					= 0;

		uint32_t send2130(uint8_t addressByte, uint32_t *config, uint32_t value, uint32_t mask);
};

#endif