#ifndef _SI7021_SUPPORT_H
#define _SI7021_SUPPORT_H

#include <Arduino.h>
#include <Wire.h>
#include "HumidityGlobals.h"

#if (ARDUINO >= 100)
  #define SI7021_READ Wire.read
  #define SI7021_WRITE Wire.write
#else
  #define SI7021_READ Wire.receive
  #define SI7021_WRITE Wire.send
#endif

enum { Si7021Address = 0x40 };
enum
{
  Si7021_E0 = 0xE0,
  Si7021_E5 = 0xE5 
};

class Si7021
{
  public:
  
    Si7021();    
    void begin();
    
    const HumidityAnswer& read();
    
  private:
    HumidityAnswer dt;

    void setResolution();
    uint8_t read8(uint8_t reg);
    
    
};
#endif
