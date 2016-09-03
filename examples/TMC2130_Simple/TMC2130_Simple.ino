#define EN_PIN    38  // Nano v3:	16 Mega:	38	//enable (CFG6)
#define DIR_PIN   55  //			19			55	//direction
#define STEP_PIN  54  //			18			54	//step
#define CS_PIN    64  //			17			64	//chip select

bool dir = false;


#include <TMC2130Stepper.h>
TMC2130Stepper TMC2130 = TMC2130Stepper(pinEN, pinDIR, pinStep, pinCS);

void setup() {
	Serial.begin(9600);
	TMC2130.begin();
	TMC2130.SilentStepStick2130(1000);
	
	digitalWrite(pinEN, LOW);
	Serial.println(TMC2130.external_ref());
}

void loop() {
	digitalWrite(pinStep, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinStep, LOW);
	delayMicroseconds(10);
	uint32_t ms = millis();
	static uint32_t last_time = 0;
	if ((ms - last_time) > 4000) {
		if (dir) {
			Serial.println("Dir -> 1");
			TMC2130.GCONF(0b10001);
			Serial.println(TMC2130.GCONF(), BIN);
			dir = false;
		} else {
			Serial.println("Dir -> 0");
			TMC2130.GCONF(0b1);
			Serial.println(TMC2130.GCONF(), BIN);
			dir = true;
		}
		last_time = ms;
	}
}
