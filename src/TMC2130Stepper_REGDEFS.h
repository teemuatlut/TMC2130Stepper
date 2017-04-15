#ifndef TMC2130Stepper_REGDEFS_h
#define TMC2130Stepper_REGDEFS_h

#define TMC2130_READ 			0x00
#define TMC2130_WRITE 			0x80

// Register memory positions
#define REG_GCONF 				0x00
#define REG_GSTAT 				0x01
#define REG_IOIN 				0x04
#define REG_IHOLD_IRUN 			0x10
#define REG_TPOWERDOWN 			0x11
#define REG_TSTEP 				0x12
#define REG_TPWMTHRS 			0x13
#define REG_TCOOLTHRS			0x14
#define REG_THIGH				0x15
#define REG_XDIRECT				0x2D
#define REG_VDCMIN				0x33
#define REG_MSLUT0				0x60
#define REG_MSLUT1				0x61
#define REG_MSLUT2				0x62
#define REG_MSLUT3				0x63
#define REG_MSLUT4				0x64
#define REG_MSLUT5				0x65
#define REG_MSLUT6				0x66
#define REG_MSLUT7				0x67
#define REG_MSLUTSEL			0x68
#define REG_MSLUTSTART			0x69
#define REG_MSCNT 				0x6A
#define REG_MSCURACT 			0x6B
#define REG_CHOPCONF 			0x6C
#define REG_COOLCONF			0x6D
#define REG_DCCTRL				0x6E
#define REG_DRV_STATUS 			0x6F
#define REG_PWMCONF 			0x70
#define REG_PWM_SCALE 			0x71
#define REG_ENCM_CTRL 			0x72
#define REG_LOST_STEPS			0x73

// GCONF
#define I_SCALE_ANALOG_bp		0
#define INTERNAL_RSENSE_bp		1
#define EN_PWM_MODE_bp			2
#define ENC_COMMUTATION_bp		3
#define SHAFT_bp				4
#define DIAG0_ERROR_bp			5
#define DIAG0_OTPW_bp			6
#define DIAG0_STALL_bp			7
#define DIAG1_STALL_bp			8
#define DIAG1_INDEX_bp			9
#define DIAG1_ONSTATE_bp	   10
#define DIAG1_STEPS_SKIPPED_bp 11
#define DIAG0_INT_PUSHPULL_bp  12
#define DIAG1_PUSHPULL_bp	   13
#define SMALL_HYSTERISIS_bp    14
#define STOP_ENABLE_bp		   15
#define DIRECT_MODE_bp		   16
#define GCONF_bm				0x3FFFF
#define I_SCALE_ANALOG_bm		0x1
#define INTERNAL_RSENSE_bm		0x2
#define EN_PWM_MODE_bm			0x4
#define ENC_COMMUTATION_bm		0x8
#define SHAFT_bm				0x10
#define DIAG0_ERROR_bm			0x20
#define DIAG0_OTPW_bm			0x40
#define DIAG0_STALL_bm			0x80
#define DIAG1_STALL_bm			0x100
#define DIAG1_INDEX_bm			0x200
#define DIAG1_ONSTATE_bm	    0x400
#define DIAG1_STEPS_SKIPPED_bm  0x800
#define DIAG0_INT_PUSHPULL_bm   0x1000
#define DIAG1_PUSHPULL_bm	    0x2000
#define SMALL_HYSTERISIS_bm     0x4000
#define STOP_ENABLE_bm		    0x8000
#define DIRECT_MODE_bm		    0x10000
// GSTAT
#define RESET_bp 			0
#define DRV_ERR_bp			1
#define UV_CP_bp			2
#define GSTAT_bm			0x7
#define RESET_bm 			0b1
#define DRV_ERR_bm			0b10
#define UV_CP_bm			0b100
// IOIN
#define STEP_bp 			0
#define DIR_bp				1
#define DCEN_CFG4_bp		2
#define DCIN_CFG5_bp		3
#define DRV_ENN_CFG6_bp		4
#define DCO_bp 				5
#define VERSION_bp		   24
#define IOIN_bm				0xFF00003F
#define STEP_bm 			0x1
#define DIR_bm				0x2
#define DCEN_CFG4_bm		0x4
#define DCIN_CFG5_bm		0x8
#define DRV_ENN_CFG6_bm		0x10
#define DCO_bm 				0x20
#define VERSION_bm			0xFF000000
// IHOLD_IRUN
#define IHOLD_bp 			0
#define IRUN_bp				8
#define IHOLDDELAY_bp	   16
#define IHOLD_IRUN_bm		0xF1F1F
#define IHOLD_bm 			0x1F
#define IRUN_bm				0x1F00
#define IHOLDDELAY_bm	    0xF0000
// TPOWERDOWN
#define TPOWERDOWN_bp		0
#define TPOWERDOWN_bm		0xFF
// TSTEP
#define TSTEP_bp			0
#define TSTEP_bm			0xFFFFF
// TPWMTHRS
#define TPWMTHRS_bp 		0
#define TPWMTHRS_bm			0xFFFFF
// TCOOLTHRS
#define TCOOLTHRS_bp		0
#define TCOOLTHRS_bm		0xFFFFF
// THIGH
#define THIGH_bp 			0
#define THIGH_bm			0xFFFFF
// XDIRECT
#define XDIRECT_bp			0
#define XDIRECT_bm			0xFFFFFFFF
#define COIL_A_bp			0
#define COIL_B_bp			16
#define COIL_A_bm			0x1FF
#define COIL_B_bm			0x1FF0000
// VDCMIN
#define VDCMIN_bp			0
#define VDCMIN_bm			0x7FFFFF
// MSLUT0
#define MSLUT0_bp			0
#define MSLUT0_bm			0xFFFFFFFF
// MSLUT1
#define MSLUT1_bp			0
#define MSLUT1_bm			0xFFFFFFFF
// MSLUT2
#define MSLUT2_bp			0
#define MSLUT2_bm			0xFFFFFFFF
// MSLUT3
#define MSLUT3_bp			0
#define MSLUT3_bm			0xFFFFFFFF
// MSLUT4
#define MSLUT4_bp			0
#define MSLUT4_bm			0xFFFFFFFF
// MSLUT5
#define MSLUT5_bp			0
#define MSLUT5_bm			0xFFFFFFFF
// MSLUT6
#define MSLUT6_bp			0
#define MSLUT6_bm			0xFFFFFFFF
// MSLUT7
#define MSLUT7_bp			0
#define MSLUT7_bm			0xFFFFFFFF
// MSLUTSEL
#define MSLUTSEL_bp			0
#define MSLUTSEL_bm			0xFFFFFFFF
// MSLUTSTART
#define START_SIN_bp		0
#define START_SIN90_bp	   16
#define START_SIN_bm 		0xFF
#define START_SIN90_bm 		0xFF0000
// MSCNT
#define MSCNT_bp			0
#define MSCNT_bm			0x3FF
// MSCURACT
#define CUR_A_bp			0
#define CUR_B_bp		   16
#define CUR_A_bm			0x1FF
#define CUR_B_bm			0x1FF0000
// CHOPCONF
#define TOFF_bp				0
#define HSTRT_bp			4
#define FD_bp			    4
#define HEND_bp				7
#define DISFDCC_bp		   12
#define RNDTF_bp		   13
#define CHM_bp			   14
#define TBL_bp 			   15
#define VSENSE_bp		   17
#define VHIGHFS_bp		   18
#define VHIGHCHM_bp		   19
#define SYNC_bp			   20
#define MRES_bp 		   24
#define INTPOL_bp		   28
#define DEDGE_bp		   29
#define DISS2G_bp		   30
#define CHOPCONF_bm			0xFFFFFFFF
#define TOFF_bm			  	0xF
#define HSTRT_bm		 	0x70
#define FD_bm				0x830
#define HEND_bm				0x780
#define DISFDCC_bm			0x1000
#define RNDTF_bm			0x2000
#define CHM_bm				0x4000
#define TBL_bm		  		0x18000
#define VSENSE_bm	  		0x20000
#define VHIGHFS_bm			0x40000
#define VHIGHCHM_bm			0x80000
#define SYNC_bm				0xF00000
#define MRES_bm				0xF000000
#define INTPOL_bm  			0x10000000
#define DEDGE_bm   			0x20000000
#define DISS2G_bm  			0x40000000
// COOLCONF
#define SEMIN_bp			0
#define SEUP_bp				5
#define SEMAX_bp			8
#define SEDN_bp			   13
#define SEIMIN_bp		   15
#define SGT_bp			   16
#define SFILT_bp		   24
#define COOLCONF_bm			0x3FFFFFF
#define SEMIN_bm			0xF
#define SEUP_bm				0x60
#define SEMAX_bm			0xF00
#define SEDN_bm				0x6000
#define SEIMIN_bm			0x80000
#define SGT_bm				0x7F0000
#define SFILT_bm			0x1000000
// DCCTRL
#define DC_TIME_bp			0
#define DC_SG_bp		   16
#define DC_TIME_bm			0x3FF
#define DC_SG_bm			0xFF0000
// DRV_STATUS
#define SG_RESULT_bp		0
#define FSACTIVE_bp		   15
#define CS_ACTUAL_bp	   16
#define STALLGUARD_bp	   24
#define OT_bp			   25
#define OTPW_bp			   26
#define S2GA_bp			   27
#define S2GB_bp			   28
#define OLA_bp			   29
#define OLB_bp			   30
#define STST_bp			   31
#define DRV_STATUS_bm		0xFFFFFFFF
#define SG_RESULT_bm		0x3FF
#define FSACTIVE_bm			0x8000
#define CS_ACTUAL_bm		0x1F0000
#define STALLGUARD_bm		0x1000000
#define OT_bm				0x2000000
#define OTPW_bm				0x4000000
#define S2GA_bm				0x8000000
#define S2GB_bm				0x10000000
#define OLA_bm				0x20000000
#define OLB_bm				0x40000000
#define STST_bm				0x80000000
// PWMCONF
#define PWM_AMPL_bp 		0
#define PWM_GRAD_bp 		8
#define PWM_FREQ_bp 	   16
#define PWM_AUTOSCALE_bp   18
#define PWM_SYMMETRIC_bp   19
#define FREEWHEEL_bp 	   20
#define PWMCONF_bm			0x7FFFFF
#define PWM_AMPL_bm 		0xFF
#define PWM_GRAD_bm 		0xFF00
#define PWM_FREQ_bm 		0x30000
#define PWM_AUTOSCALE_bm	0x40000
#define PWM_SYMMETRIC_bm	0x80000
#define FREEWHEEL_bm 		0x300000
// PWM_SCALE
#define PWM_SCALE_bp		0
#define PWM_SCALE_bm		0xFF
// ENCM_CTRL
#define INV_bp				0
#define MAXSPEED_bp			1
#define INV_bm				0x1
#define MAXSPEED_bm			0x2
// LOST_STEPS
#define LOST_STEPS_bp		0
#define LOST_STEPS_bm		0xFFFFF

#endif
