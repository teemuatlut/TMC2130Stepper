#ifdef ARDUINO_SAM_DUE
  #include "SW_SPI.h"

  void _digitalWrite(uint8_t pin, bool state) {
    if (state) {
      digitalPinToPort(pin) -> PIO_SODR = digitalPinToBitMask(pin);
    } else {
      digitalPinToPort(pin) -> PIO_CODR = digitalPinToBitMask(pin);
    }
  }
  bool _digitalRead(uint8_t pin) {
    return digitalPinToPort(pin) -> PIO_PDSR = digitalPinToBitMask(pin);
  }

  SW_SPI::SW_SPI(uint8_t sw_mosi_pin, uint8_t sw_miso_pin, uint8_t sw_sck_pin) {
    mosi_pin = sw_mosi_pin;
    miso_pin = sw_miso_pin;
    sck_pin = sw_sck_pin;
    pinMode(mosi_pin, OUTPUT);
    pinMode(sck_pin, OUTPUT);
    pinMode(miso_pin, INPUT);
  }

  //Combined shiftOut and shiftIn from Arduino wiring_shift.c
  byte SW_SPI::transfer(uint8_t ulVal, uint8_t ulBitOrder) {
    uint8_t value = 0;

    for (uint8_t i=0 ; i<8 ; ++i) {
      // Write bit
      if ( ulBitOrder == LSBFIRST ) {
        _digitalWrite( mosi_pin, !!(ulVal & (1 << i)) ) ;
      } else {
        _digitalWrite( mosi_pin, !!(ulVal & (1 << (7 - i))) ) ;
      }

      // Start clock pulse
      _digitalWrite( sck_pin, HIGH );

      // Read bit
      if ( ulBitOrder == LSBFIRST ) {
        value |= (digitalRead( miso_pin ) ? 1 : 0) << i ;
      } else {
        value |= (digitalRead( miso_pin ) ? 1 : 0) << (7 - i) ;
      }

      // Stop clock pulse
      _digitalWrite( sck_pin, LOW );
    }

    return value;
  }

  uint16_t SW_SPI::transfer16(uint16_t data) {
    uint16_t returnVal = 0x0000;
    returnVal |= transfer((data>>8)&0xFF) << 8;
    returnVal |= transfer(data&0xFF) & 0xFF;
    return returnVal;
  }
#endif
