#ifndef TMC2310Stepper_h
#define TMC2310Stepper_h

//#define TMC2130DEBUG

#if defined(ARDUINO) && ARDUINO >= 100
	#include <Arduino.h>
#endif

const uint32_t TMC2130Stepper_version = 0x10100; // v1.1.0

class TMC2130Stepper {
	public:
		TMC2130Stepper(uint8_t pinEN, uint8_t pinDIR, uint8_t pinStep, uint8_t pinCS);
		void begin();
		void checkStatus();
		void SilentStepStick2130(uint16_t);
		void setCurrent(uint16_t mA, float Rsense, float multiplier);
		uint16_t getCurrent();
		bool checkOT();
		bool getOTPW();
		void clear_otpw();
		bool isEnabled();
//    void takeSteps(int steps);
//    void step(int steps, int speed);
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
		// REG_GSTAT
		uint32_t status_flags();
		// REG_IOIN
		uint32_t input();
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
		uint16_t microsteps();
		void microsteps(uint16_t value);
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

		// Aliases

		// RW: GCONF
		inline bool			I_scale_analog()									__attribute__((always_inline)) { return external_ref(); 						}
		inline void			I_scale_analog(				bool value)	__attribute__((always_inline)) { 				external_ref(value); 				}
		inline bool 		internal_Rsense()									__attribute__((always_inline)) { return internal_sense_R(); 				}
		inline void 		internal_Rsense(			bool value)	__attribute__((always_inline)) {				internal_sense_R(value); 		}
		inline bool 		en_pwm_mode()											__attribute__((always_inline)) { return stealthChop(); 							}
		inline void 		en_pwm_mode(					bool value)	__attribute__((always_inline)) {				stealthChop(value); 				}
		inline bool 		enc_commutation()									__attribute__((always_inline)) { return commutation(); 							}
		inline void 		enc_commutation(			bool value)	__attribute__((always_inline)) {				commutation(value); 				}
		inline bool 		shaft()														__attribute__((always_inline)) { return shaft_dir(); 								}
		inline void 		shaft(								bool value)	__attribute__((always_inline)) {				shaft_dir(value); 					}
		inline bool 		diag0_error()											__attribute__((always_inline)) { return diag0_errors(); 						}
		inline void 		diag0_error(					bool value)	__attribute__((always_inline)) {				diag0_errors(value); 				}
		inline bool 		diag0_otpw()											__attribute__((always_inline)) { return diag0_temp_prewarn();				}
		inline void 		diag0_otpw(						bool value)	__attribute__((always_inline)) {				diag0_temp_prewarn(value);	}
		inline bool 		diag1_onstate()										__attribute__((always_inline)) { return diag1_chopper_on(); 				}
		inline void 		diag1_onstate(				bool value)	__attribute__((always_inline)) {				diag1_chopper_on(value); 		}
		inline bool 		diag0_int_pushpull()							__attribute__((always_inline)) { return diag0_active_high(); 				}
		inline void 		diag0_int_pushpull(		bool value)	__attribute__((always_inline)) {				diag0_active_high(value); 	}
		inline bool 		diag1_int_pushpull()							__attribute__((always_inline)) { return diag1_active_high(); 				}
		inline void 		diag1_int_pushpull(		bool value)	__attribute__((always_inline)) {				diag1_active_high(value); 	}
		// RC
		inline uint32_t GSTAT()														__attribute__((always_inline)) { return status_flags(); 						}
		// R
		inline uint32_t IOIN()														__attribute__((always_inline)) { return input(); 										}
		// W: IHOLD_IRUN
		inline uint8_t 	IHOLD()														__attribute__((always_inline)) { return hold_current(); 						}
		inline void 		IHOLD(							uint8_t value)__attribute__((always_inline)) {				hold_current(value); 				}
		inline uint8_t 	IRUN()														__attribute__((always_inline)) { return run_current(); 							}
		inline void 		IRUN(								uint8_t value)__attribute__((always_inline)) {				run_current(value); 				}
		inline uint8_t 	IHOLDDELAY()											__attribute__((always_inline)) { return hold_delay(); 							}
		inline void 		IHOLDDELAY(					uint8_t value)__attribute__((always_inline)) {				hold_delay(value); 					}
		// W
		inline uint8_t 	TPOWERDOWN()											__attribute__((always_inline)) { return power_down_delay(); 				}
		inline void 		TPOWERDOWN(					uint8_t value)__attribute__((always_inline)) { return power_down_delay(value); 		}
		// R
		inline uint32_t TSTEP()														__attribute__((always_inline)) { return microstep_time(); 					}
		// W
		inline uint32_t TPWMTHRS()												__attribute__((always_inline)) { return stealth_max_speed(); 				}
		inline void 		TPWMTHRS(					uint32_t value)	__attribute__((always_inline)) {				stealth_max_speed(value); 	}
		// W
		inline uint32_t TCOOLTHRS()												__attribute__((always_inline)) { return coolstep_min_speed(); 			}
		inline void     TCOOLTHRS(				uint32_t value) __attribute__((always_inline)) {				coolstep_min_speed(value); 	}
		// W
		inline uint32_t THIGH()														__attribute__((always_inline)) { return mode_sw_speed(); 						}
		inline void 		THIGH(						uint32_t value)	__attribute__((always_inline)) {				mode_sw_speed(value); 			}
		// RW: XDIRECT
		inline int16_t 	XDIRECT_A()												__attribute__((always_inline)) { return coil_A_current(); 					}
		inline void 		XDIRECT_A(				int16_t value)	__attribute__((always_inline)) {				coil_A_current(value); 			}
		inline int16_t 	XDIRECT_B()												__attribute__((always_inline)) { return coil_B_current(); 					}
		inline void 		XDIRECT_B(				int16_t value)	__attribute__((always_inline)) {				coil_B_current(value); 			}
		// W
		inline uint32_t VDCMIN()													__attribute__((always_inline)) { return DCstep_min_speed(); 				}
		inline void 		VDCMIN(						uint32_t value)	__attribute__((always_inline)) {				DCstep_min_speed(value); 		}
		// RW: CHOPCONF
		inline uint8_t 	toff()														__attribute__((always_inline)) { return off_time(); 								}
		inline void 		toff(							uint8_t value)	__attribute__((always_inline)) {				off_time(value); 						}
		inline uint8_t 	hstrt()														__attribute__((always_inline)) { return hysterisis_start(); 				}
		inline void 		hstrt(						uint8_t value)	__attribute__((always_inline)) {				hysterisis_start(value); 		}
		inline int8_t 	hend()														__attribute__((always_inline)) { return hysterisis_low(); 					}
		inline void 		hend(							int8_t value)		__attribute__((always_inline)) {				hysterisis_low(value); 			}
		inline uint8_t 	fd()															__attribute__((always_inline)) { return fast_decay_time(); 					}
		inline void 		fd(								uint8_t value)	__attribute__((always_inline)) {				fast_decay_time(value); 		}
		inline bool 		disfdcc()													__attribute__((always_inline)) { return disable_I_comparator(); 		}
		inline void 		disfdcc(					bool value)			__attribute__((always_inline)) {				disable_I_comparator(value);}
		inline bool 		rndtf()														__attribute__((always_inline)) { return random_off_time(); 					}
		inline void 		rndtf(						bool value)			__attribute__((always_inline)) {				random_off_time(value); 		}
		inline uint8_t 	chm()															__attribute__((always_inline)) { return chopper_mode(); 						}
		inline void 		chm(							uint8_t value)	__attribute__((always_inline)) {				chopper_mode(value); 				}
		inline uint8_t 	tbl()															__attribute__((always_inline)) { return blank_time(); 							}
		inline void 		tbl(							uint8_t value)	__attribute__((always_inline)) {				blank_time(value); 					}
		inline bool 		vsense()													__attribute__((always_inline)) { return high_sense_R(); 						}
		inline void 		vsense(						bool value)			__attribute__((always_inline)) {				high_sense_R(value); 				}
		inline bool 		vhighfs()													__attribute__((always_inline)) { return fullstep_threshold(); 			}
		inline void 		vhighfs(					bool value)			__attribute__((always_inline)) {				fullstep_threshold(value); 	}
		inline bool 		vhighchm()												__attribute__((always_inline)) { return high_speed_mode(); 					}
		inline void 		vhighchm(					bool value)			__attribute__((always_inline)) {				high_speed_mode(value); 		}
		inline uint8_t 	sync()														__attribute__((always_inline)) { return sync_phases(); 							}
		inline void 		sync(							uint8_t value)	__attribute__((always_inline)) {				sync_phases(value); 				}
		inline uint16_t mres()														__attribute__((always_inline)) { return microsteps(); 							}
		inline void			mres(							uint16_t value)	__attribute__((always_inline)) {				microsteps(value); 					}
		inline bool 		intpol()													__attribute__((always_inline)) { return interpolate(); 							}
		inline void 		intpol(						bool value)			__attribute__((always_inline)) {				interpolate(value); 				}
		inline bool 		dedge()														__attribute__((always_inline)) { return double_edge_step(); 				}
		inline void 		dedge(						bool value)			__attribute__((always_inline)) {				double_edge_step(value); 		}
		inline bool 		diss2g()													__attribute__((always_inline)) { return disable_short_protection(); }
		inline void 		diss2g(						bool value)			__attribute__((always_inline)) {				disable_short_protection(); }
		// W: COOLCONF
		inline uint8_t 	semin()														__attribute__((always_inline)) { return sg_min(); 									}
		inline void 		semin(						uint8_t value)	__attribute__((always_inline)) {				sg_min(value); 							}
		inline uint8_t 	seup()														__attribute__((always_inline)) { return sg_step_width(); 						}
		inline void 		seup(							uint8_t value)	__attribute__((always_inline)) {				sg_step_width(value); 			}
		inline uint8_t 	semax()														__attribute__((always_inline)) { return sg_max(); 									}
		inline void 		semax(						uint8_t value)	__attribute__((always_inline)) {				sg_max(value); 							}
		inline uint8_t 	sedn()														__attribute__((always_inline)) { return sg_current_decrease(); 			}
		inline void 		sedn(							uint8_t value)	__attribute__((always_inline)) {				sg_current_decrease(value); }
		inline uint8_t 	seimin()													__attribute__((always_inline)) { return smart_min_current(); 				}
		inline void 		seimin(						uint8_t value)	__attribute__((always_inline)) {				smart_min_current(value); 	}
		inline int8_t 	sgt()															__attribute__((always_inline)) { return sg_stall_value(); 					}
		inline void 		sgt(							int8_t value)		__attribute__((always_inline)) {				sg_stall_value(value); 			}
		inline bool 		sfilt()														__attribute__((always_inline)) { return sg_filter(); 								}
		inline void 		sfilt(						bool value)			__attribute__((always_inline)) {				sg_filter(value); 					}
		// W: PWMCONF
		inline uint8_t 	PWM_AMPL()												__attribute__((always_inline)) { return stealth_amplitude(); 				}
		inline void 		PWM_AMPL(					uint8_t value)	__attribute__((always_inline)) {				stealth_amplitude(value); 	}
		inline uint8_t 	PWM_GRAD()												__attribute__((always_inline)) { return stealth_gradient(); 				}
		inline void 		PWM_GRAD(					uint8_t value)	__attribute__((always_inline)) {				stealth_gradient(value); 		}
		inline uint8_t 	pwm_freq()												__attribute__((always_inline)) { return stealth_freq(); 						}
		inline void 		pwm_freq(					uint8_t value)	__attribute__((always_inline)) {				stealth_freq(value); 				}
		inline bool 		pwm_autoscale()										__attribute__((always_inline)) { return stealth_autoscale(); 				}
		inline void 		pwm_autoscale(		bool value)			__attribute__((always_inline)) {				stealth_autoscale(value); 	}
		inline bool 		pwm_symmetric()										__attribute__((always_inline)) { return stealth_symmetric(); 				}
		inline void 		pwm_symmetric(		bool value)			__attribute__((always_inline)) {				stealth_symmetric(value); 	}
		inline uint8_t 	freewheel()												__attribute__((always_inline)) { return standstill_mode(); 					}
		inline void 		freewheel(				uint8_t value)	__attribute__((always_inline)) {				standstill_mode(value); 		}
		// W: ENCM_CTRL
		inline bool 		ENCM_CTRL0()											__attribute__((always_inline)) { return invert_encoder(); 					}
		inline void 		ENCM_CTRL0(				bool value)			__attribute__((always_inline)) {				invert_encoder(value); 			}
		inline bool 		ENCM_CTRL1()											__attribute__((always_inline)) { return maxspeed(); 								}
		inline void 		ENCM_CTRL1(				bool value)			__attribute__((always_inline)) {				maxspeed(value); 						}

		bool _started;

	private:
		const uint8_t WRITE     = 0b10000000;
		const uint8_t READ      = 0b00000000;
		uint8_t _pinEN        = 16;
		uint8_t _pinSTEP      = 18;
		uint8_t _pinCS        = 17;
		//const int MOSI_PIN    = 12;
		//const int MISO_PIN    = 11;
		//const int SCK_PIN     = 13;
		uint8_t _pinDIR       = 19;

		// Current register values
		uint32_t cur_GCONF      = 0x00;
		uint32_t cur_GSTAT      = 0x00;
		uint32_t cur_IOIN     = 0x00;
		uint32_t cur_IHOLD_IRUN   = 0x00;
		uint32_t cur_TPOWERDOWN   = 0x00;
		uint32_t cur_TSTEP      = 0x00;
		uint32_t cur_TPWMTHRS   = 0x00;
		uint32_t cur_TCOOLTHRS    = 0x00;
		uint32_t cur_THIGH      = 0x00;
		uint32_t cur_XDIRECT    = 0x00;
		uint32_t cur_VDCMIN     = 0x00;
		uint32_t cur_MSCNT      = 0x00;
		uint32_t cur_MSCURACT   = 0x00;
		uint32_t cur_CHOPCONF   = 0x00;
		uint32_t cur_COOLCONF   = 0x00;
		uint32_t cur_DCCTRL     = 0x00;
		uint32_t cur_DRVSTATUS    = 0x00;
		uint32_t cur_PWMCONF    = 0x00;
		uint32_t cur_PWMSCALE   = 0x00;
		uint32_t cur_ENCMCTRL   = 0x00;
		uint32_t cur_LOSTSTEPS    = 0x00;

		bool val_i_scale_analog       = 0;
		bool val_internal_r_sense     = 0;
		bool val_en_pwm_mode        = 0;
		bool val_enc_commutation      = 0;
		bool val_shaft            = 0;
		bool val_diag0_error        = 0;
		bool val_diag0_otpw         = 0;
		bool val_diag0_stall        = 0;
		bool val_diag1_stall        = 0;
		bool val_diag1_index        = 0;
		bool val_diag1_onstate        = 0;
		bool val_diag1_steps_skipped    = 0;
		bool val_diag0_int_pushpull     = 0;
		bool val_diag1_pushpull       = 0;
		bool val_small_hysterisis     = 0;
		bool val_stop_enable        = 0;
		bool val_direct_mode        = 0;
		uint8_t val_ihold           = 0;
		uint8_t val_irun          = 0;
		uint8_t val_ihold_delay       = 0;
		uint8_t val_tpowerdown        = 0;
		uint8_t val_tpwmthrs        = 0;
		uint8_t val_tcoolthrs       = 0;
		uint8_t val_thigh         = 0;
		uint8_t val_xdirect_a       = 0;
		uint8_t val_xdirect_b       = 0;
		uint8_t val_vdcmin          = 0;
		uint8_t val_toff          = 0;
		uint8_t val_hstrt         = 0;
		uint8_t val_tfd           = 0;
		uint8_t val_hend          = 0;
		uint8_t val_offset          = 0;
		bool val_disfdcc          = 0;
		bool val_rndtf            = 0;
		uint8_t val_chm           = 0;
		uint8_t val_tbl           = 0;
		bool val_vsense           = 0;
		bool val_vhighfs          = 0;
		bool val_vhighchm         = 0;
		uint8_t val_sync          = 0;
		uint8_t val_mres          = 0;
		bool val_intpol           = 0;
		bool val_dedge            = 0;
		bool val_diss2g           = 0;
		uint8_t val_semin         = 0;
		uint8_t val_seup          = 0;
		uint8_t val_semax         = 0;
		uint8_t val_sedn          = 0;
		uint8_t val_seimin          = 0;
		uint8_t val_sgt           = 0;
		uint8_t val_sfilt         = 0;
		uint8_t val_pwm_ampl        = 0;
		uint8_t val_pwm_grad        = 0;
		uint8_t val_pwm_freq        = 0;
		bool val_pwm_autoscale        = 0;
		bool val_pwm_symmetric        = 0;
		uint8_t val_freewheel       = 0;
		bool val_invert_encoder       = 0;
		bool val_maxspeed         = 0;

		uint32_t send2130(uint8_t addressByte, uint32_t *config, uint32_t value, uint32_t mask);

		uint16_t val_mA           = 0;
		bool flag_otpw            = 0;
};

#endif