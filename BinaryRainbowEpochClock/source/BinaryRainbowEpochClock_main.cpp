/*************************************************************
project: <type project name here>
author: <type your name here>
description: <type what this file does>
*************************************************************/

#include "BinaryRainbowEpochClock_main.h"

#include "LPD8806.h"
#include "SPI.h"
#include <Wire.h>
#include "TimerOne.h"
#include "colortable.h"

const int nLEDs = 32; //32 bits, so 32 LEDs

LPD8806 strip = LPD8806(nLEDs + 2);//Not using dataPin and clockPin, because Software SPI is lame

RTC_DS1307 RTC;

void setup() { 
	strip.begin();
    strip.setBrightness(1.0f);
    strip.show();
    for(int i=0; i<nLEDs; i++)
    {
		strip.setPixelColor(i, strip.Color(255, 0, 0));
    }
    strip.show();
    delay(500);

    Wire.begin();
    RTC.begin();
 
	RTC.adjust(DateTime(__DATE__, __TIME__));
}

void setPixel(uint8_t pixel, bool state, DateTime now)
{
	static RGB color = {0,0,0};

	
	uint8_t pos = pixel;
	
    if(pos >= 0 && pos <= 10)
    {    
		color = color24h[now.hour()];
    }
    else if(pos >= 11 && pos <= 21)
    {
		color = colorMinSec[now.minute()];
    }
    else if(pos >= 22 && pos <= 31)
    {
		color = colorMinSec[now.second()];
    }
    
	strip.setPixelColor(pixel, state ? strip.Color(color.r, color.g, color.b) : strip.Color(0,0,0));
}

void showTime()
{
	static DateTime now;
	now = RTC.now();
	static uint32_t unix;
	unix = now.unixtime();
	static bool state;
	static int i;
	for(i=31; i>=0; i--)
	{
		state = unix & (1UL<<i);
		setPixel(31 - i, state, now);
	}
	strip.show();
}

DateTime lastTime = DateTime();
void loop() {
	static bool update;
	update = false;
	
	DateTime now = RTC.now();

	update = (now.hour() != lastTime.hour()) ||
			 (now.minute() != lastTime.minute()) ||
			 (now.second() != lastTime.second());
			 
    
	if(update)
	{
		showTime();
	}
    
    lastTime = now;
    
    delay(500);
}
