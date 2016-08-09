#ifndef TMC2310Stepper_h
#define TMC2310Stepper_h

class TMC2130Stepper {
	public:
		TMC2130Stepper(uint8_t pinEN, uint8_t pinDIR, uint8_t pinStep, uint8_t pinCS);
		void begin();
		void checkStatus();
		void setSSSCurrent();
		void setCurrent(uint16_t mah, float Rsense);
		// REG_GCONF
		uint32_t get_GCONF();
		void set_GCONF(uint32_t value);
		uint8_t get_I_SCALE_ANALOG();
		void set_I_SCALE_ANALOG(uint8_t value);
		uint8_t get_INTERNAL_R_SENSE();
		void set_INTERNAL_R_SENSE(uint8_t value);
		uint8_t get_EN_PWM_MODE();
		void set_EN_PWM_MODE(uint8_t value);
		uint8_t get_ENC_COMMUTATION();
		void set_ENC_COMMUTATION(uint8_t value);
		uint8_t get_SHAFT();
		void set_SHAFT(uint8_t value);
		uint8_t get_DIAG0_ERROR();
		void set_DIAG0_ERROR(uint8_t value);
		uint8_t get_DIAG0_OTPW();
		void set_DIAG0_OTPW(uint8_t value);
		uint8_t get_DIAG0_STALL();
		void set_DIAG0_STALL(uint8_t value);
		uint8_t get_DIAG1_STALL();
		void set_DIAG1_STALL(uint8_t value);
		uint8_t get_DIAG1_INDEX();
		void set_DIAG1_INDEX(uint8_t value);
		uint8_t get_DIAG1_ONSTATE();
		void set_DIAG1_ONSTATE(uint8_t value);
		uint8_t get_DIAG1_STEPS_SKIPPED();
		void set_DIAG1_STEPS_SKIPPED(uint8_t value);
		uint8_t get_DIAG0_INT_PUSHPULL();
		void set_DIAG0_INT_PUSHPULL(uint8_t value);
		uint8_t get_DIAG1_PUSHPULL();
		void set_DIAG1_PUSHPULL(uint8_t value);
		uint8_t get_SMALL_HYSTERISIS();
		void set_SMALL_HYSTERISIS(uint8_t value);
		uint8_t get_STOP_ENABLE();
		void set_STOP_ENABLE(uint8_t value);
		uint8_t get_DIRECT_MODE();
		void set_DIRECT_MODE(uint8_t value);
		// REG_IHOLD_IRUN
		uint8_t get_IHOLD();
		void set_IHOLD(uint8_t value);
		uint8_t get_IRUN();
		void set_IRUN(uint8_t value);
		uint8_t get_IHOLD_DELAY();
		void set_IHOLD_DELAY(uint8_t value);
		// REG_TPOWERDOWN
		uint8_t get_TPOWERDOWN();
		void set_TPOWERDOWN(uint8_t value);
		// REG_TSTEP
		uint32_t get_TSTEP();
		// REG_TPWMTHRS
		uint32_t get_TPWMTHRS();
		void set_TPWMTHRS(uint32_t value);
		// REG_TCOOLTHRS
		uint32_t get_TCOOLTHRS();
		void set_TCOOLTHRS(uint32_t value);
		// REG_THIGH
		uint32_t get_THIGH();
		void set_THIGH(uint32_t value);
		// REG_XDRIRECT
		int16_t get_XDIRECT_A();
		void set_XDIRECT_A(int16_t value);
		int16_t get_XDIRECT_B();
		void set_XDIRECT_B(int16_t value);
		// REG_VDCMIN
		uint32_t get_VDCMIN();
		void set_VDCMIN(uint32_t value);
		// REG_CHOPCONF
		uint32_t get_CHOPCONF();
		void set_CHOPCONF(uint32_t value);
		uint8_t get_TOFF();
		void set_TOFF(uint8_t value);
		uint8_t get_HSTRT();
		void set_HSTRT(uint8_t value);
		uint8_t get_TFD();
		void set_TFD(uint8_t value);
		int8_t get_HEND();
		void set_HEND(int8_t value);
		int8_t get_OFFSET();
		void set_OFFSET(int8_t value);
		uint8_t get_DISFDCC();
		void set_DISFDCC(uint8_t value);
		uint8_t get_RNDTF();
		void set_rndtf(uint8_t value);
		uint8_t get_CHM();
		void set_CHM(uint8_t value);
		uint8_t get_TBL();
		void set_TBL(uint8_t value);
		uint8_t get_VSENSE();
		void set_VSENSE(uint8_t value);
		uint8_t get_VHIGHFS();
		void set_VHIGHFS(uint8_t value);
		uint8_t get_VHIGHCHM();
		void set_VHIGHCHM(uint8_t value);
		uint8_t get_SYNC();
		void set_SYNC(uint8_t value);
		uint8_t get_MRES();
		void set_MRES(uint8_t value);
		uint8_t get_INTPOL();
		void set_INTPOL(uint8_t value);
		uint8_t get_DEDGE();
		void set_DEDGE(uint8_t value);
		uint8_t get_DISS2G();
		void set_DISS2G(uint8_t value);
		// REG_COOLCONF
		void set_COOLCONF(uint32_t value);
		uint8_t get_SEMIN();
		void set_SEMIN(uint8_t value);
		uint8_t get_SEUP();
		void set_SEUP(uint8_t value);
		uint8_t get_SEMAX();
		void set_SEMAX(uint8_t value);
		uint8_t get_SEDN();
		void set_SEDN(uint8_t value);
		uint8_t get_SEIMIN();
		void set_SEIMIN(uint8_t value);
		int8_t get_SGT();
		void set_SGT(int8_t value);
		uint8_t get_SFILT();
		void set_SFILT(uint8_t value);
		// REG_PWMCONF
		void set_PWMCONF(uint32_t value);
		uint8_t get_PWM_AMPL();
		void set_PWM_AMPL(uint8_t value);
		uint8_t get_PWM_GRAD();
		void set_PWM_GRAD(uint8_t value);
		uint8_t get_PWM_FREQ();
		void set_PWM_FREQ(uint8_t value);
		uint8_t get_PWM_AUTOSCALE();
		void set_PWM_AUTOSCALE(uint8_t value);
		uint8_t get_PWM_SYMMETRIC();
		void set_PWM_SYMMETRIC(uint8_t value);
		uint8_t get_FREEWHEEL();
		void set_FREEWHEEL(uint8_t value);
		// REG_DRVSTATUS
		uint32_t get_DRVSTATUS();

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

		uint8_t val_i_scale_analog 			= 0;
		uint8_t val_internal_r_sense		= 0;
		uint8_t val_en_pwm_mode				= 0;
		uint8_t val_enc_commutation			= 0;
		uint8_t val_shaft					= 0;
		uint8_t val_diag0_error				= 0;
		uint8_t val_diag0_otpw				= 0;
		uint8_t val_diag0_stall				= 0;
		uint8_t val_diag1_stall				= 0;
		uint8_t val_diag1_index				= 0;
		uint8_t val_diag1_onstate			= 0;
		uint8_t val_diag1_steps_skipped		= 0;
		uint8_t val_diag0_int_pushpull		= 0;
		uint8_t val_diag1_pushpull			= 0;
		uint8_t val_small_hysterisis		= 0;
		uint8_t val_stop_enable				= 0;
		uint8_t val_direct_mode				= 0;
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
		uint8_t val_disfdcc					= 0;
		uint8_t val_rndtf					= 0;
		uint8_t val_chm						= 0;
		uint8_t val_tbl						= 0;
		uint8_t val_vsense					= 0;
		uint8_t val_vhighfs					= 0;
		uint8_t val_vhighchm				= 0;
		uint8_t val_sync					= 0;
		uint8_t val_mres 					= 0;
		uint8_t val_intpol					= 0;
		uint8_t val_dedge					= 0;
		uint8_t val_diss2g					= 0;
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
		uint8_t val_pwm_autoscale			= 0;
		uint8_t val_pwm_symmetric			= 0;
		uint8_t val_freewheel				= 0;

		uint32_t send2130(uint8_t addressByte, uint32_t *config, uint32_t value, uint32_t mask);
};

#endif