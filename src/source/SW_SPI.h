#pragma once

#include <Arduino.h>

class SW_SPI {
	public:
		SW_SPI(uint8_t sw_mosi_pin=28, uint8_t sw_miso_pin=26, uint8_t sw_sck_pin=27);
		void begin() {};
		byte transfer(uint8_t ulVal, uint8_t ulBitOrder=MSBFIRST);
		uint16_t transfer16(uint16_t data);
		void endTransaction() {};
	private:
		uint8_t mosi_pin,
				miso_pin,
				sck_pin;
};