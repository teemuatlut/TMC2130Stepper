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
		uint32_t GCONF();
		void GCONF(uint32_t value);
		uint8_t I_SCALE_ANALOG();
		void I_SCALE_ANALOG(uint8_t value);
		uint8_t INTERNAL_R_SENSE();
		void INTERNAL_R_SENSE(uint8_t value);
		uint8_t EN_PWM_MODE();
		void EN_PWM_MODE(uint8_t value);
		uint8_t ENC_COMMUTATION();
		void ENC_COMMUTATION(uint8_t value);
		uint8_t SHAFT();
		void SHAFT(uint8_t value);
		uint8_t DIAG0_ERROR();
		void DIAG0_ERROR(uint8_t value);
		uint8_t DIAG0_OTPW();
		void DIAG0_OTPW(uint8_t value);
		uint8_t DIAG0_STALL();
		void DIAG0_STALL(uint8_t value);
		uint8_t DIAG1_STALL();
		void DIAG1_STALL(uint8_t value);
		uint8_t DIAG1_INDEX();
		void DIAG1_INDEX(uint8_t value);
		uint8_t DIAG1_ONSTATE();
		void DIAG1_ONSTATE(uint8_t value);
		uint8_t DIAG1_STEPS_SKIPPED();
		void DIAG1_STEPS_SKIPPED(uint8_t value);
		uint8_t DIAG0_INT_PUSHPULL();
		void DIAG0_INT_PUSHPULL(uint8_t value);
		uint8_t DIAG1_PUSHPULL();
		void DIAG1_PUSHPULL(uint8_t value);
		uint8_t SMALL_HYSTERISIS();
		void SMALL_HYSTERISIS(uint8_t value);
		uint8_t STOP_ENABLE();
		void STOP_ENABLE(uint8_t value);
		uint8_t DIRECT_MODE();
		void DIRECT_MODE(uint8_t value);
		// REG_IHOLD_IRUN
		uint8_t IHOLD();
		void IHOLD(uint8_t value);
		uint8_t IRUN();
		void IRUN(uint8_t value);
		uint8_t IHOLD_DELAY();
		void IHOLD_DELAY(uint8_t value);
		// REG_TPOWERDOWN
		uint8_t TPOWERDOWN();
		void TPOWERDOWN(uint8_t value);
		// REG_TSTEP
		uint32_t TSTEP();
		// REG_TPWMTHRS
		uint32_t TPWMTHRS();
		void TPWMTHRS(uint32_t value);
		// REG_TCOOLTHRS
		uint32_t TCOOLTHRS();
		void TCOOLTHRS(uint32_t value);
		// REG_THIGH
		uint32_t THIGH();
		void THIGH(uint32_t value);
		// REG_XDRIRECT
		int16_t XDIRECT_A();
		void XDIRECT_A(int16_t value);
		int16_t XDIRECT_B();
		void XDIRECT_B(int16_t value);
		// REG_VDCMIN
		uint32_t VDCMIN();
		void VDCMIN(uint32_t value);
		// REG_CHOPCONF
		uint32_t CHOPCONF();
		void CHOPCONF(uint32_t value);
		uint8_t TOFF();
		void TOFF(uint8_t value);
		uint8_t HSTRT();
		void HSTRT(uint8_t value);
		uint8_t TFD();
		void TFD(uint8_t value);
		int8_t HEND();
		void HEND(int8_t value);
		int8_t OFFSET();
		void OFFSET(int8_t value);
		uint8_t DISFDCC();
		void DISFDCC(uint8_t value);
		uint8_t RNDTF();
		void rndtf(uint8_t value);
		uint8_t CHM();
		void CHM(uint8_t value);
		uint8_t TBL();
		void TBL(uint8_t value);
		uint8_t VSENSE();
		void VSENSE(uint8_t value);
		uint8_t VHIGHFS();
		void VHIGHFS(uint8_t value);
		uint8_t VHIGHCHM();
		void VHIGHCHM(uint8_t value);
		uint8_t SYNC();
		void SYNC(uint8_t value);
		uint8_t MRES();
		void MRES(uint8_t value);
		uint8_t INTPOL();
		void INTPOL(uint8_t value);
		uint8_t DEDGE();
		void DEDGE(uint8_t value);
		uint8_t DISS2G();
		void DISS2G(uint8_t value);
		// REG_COOLCONF
		void COOLCONF(uint32_t value);
		uint8_t SEMIN();
		void SEMIN(uint8_t value);
		uint8_t SEUP();
		void SEUP(uint8_t value);
		uint8_t SEMAX();
		void SEMAX(uint8_t value);
		uint8_t SEDN();
		void SEDN(uint8_t value);
		uint8_t SEIMIN();
		void SEIMIN(uint8_t value);
		int8_t SGT();
		void SGT(int8_t value);
		uint8_t SFILT();
		void SFILT(uint8_t value);
		// REG_PWMCONF
		void PWMCONF(uint32_t value);
		uint8_t PWM_AMPL();
		void PWM_AMPL(uint8_t value);
		uint8_t PWM_GRAD();
		void PWM_GRAD(uint8_t value);
		uint8_t PWM_FREQ();
		void PWM_FREQ(uint8_t value);
		uint8_t PWM_AUTOSCALE();
		void PWM_AUTOSCALE(uint8_t value);
		uint8_t PWM_SYMMETRIC();
		void PWM_SYMMETRIC(uint8_t value);
		uint8_t FREEWHEEL();
		void FREEWHEEL(uint8_t value);
		// REG_DRVSTATUS
		uint32_t DRVSTATUS();

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