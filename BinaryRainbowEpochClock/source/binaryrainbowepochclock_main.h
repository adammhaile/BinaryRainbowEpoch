//-------------------------------------------------------------------
#ifndef __binaryrainbowepochclock_main_H__
#define __binaryrainbowepochclock_main_H__
//-------------------------------------------------------------------
 
#include <arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "RTClib.h"
 
//-------------------------------------------------------------------
 
//-------------------------------------------------------------------
 
// Put yout declarations here
 
//-------------------------------------------------------------------
 
//===================================================================
// -> DO NOT WRITE ANYTHING BETWEEN HERE...
// 		This section is reserved for automated code generation
// 		This process tries to detect all user-created
// 		functions in main_sketch.cpp, and inject their
// 		declarations into this file.
// 		If you do not want to use this automated process,
//		simply delete the lines below, with "&MM_DECLA" text
//===================================================================
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_BEG@---------------------
void loop();
void showTime();
void setPixel(uint8_t pixel, bool state, DateTime now);
void setup();
//---- DO NOT DELETE THIS LINE -- @MM_DECLA_END@---------------------
// -> ...AND HERE. This space is reserved for automated code generation!
//===================================================================
 
 
//-------------------------------------------------------------------
#endif
//-------------------------------------------------------------------
 
 
