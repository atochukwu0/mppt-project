/*
 * mppt.h
 *
 *  Created on: Apr 3, 2017
 *      Author: nipri
 */

#ifndef MPPT_H_
#define MPPT_H_

// voltage related constants
#define HALF_VOLT      		0x7b	// 123 counts corresponding to 0.5 V
#define TWO_VOLT       		0x1ec	// 492 counts corresponding to 2.0 Volts
#define ONE_AND_HALF_VOLT 	0x171	// 369 counts corresponding to 1.5 Volts
#define LOW_BATTERY2   		0xa7c	// 2684 counts corresponding to 10.9 Volts
#define LOW_BATTERY1   		0xa94	// 2708 counts corresponding to 11.0 Volts
#define LOAD_ON1       		0xb8b	// 2955 counts corresponding to 12 Volts
#define LOAD_ON2       		0xeb7	// 3767 counts corresponding to 15.3 Volts
#define LOAD_OFF1      		0xa4a	// 2634 counts corresponding to 10.7 Volts
#define LOAD_OFF2      		0xee8	// 3816 counts corresponding to 15.5 Volts
#define MAX_START_VOLT 		0xc81	// 3201 counts corresponding to 13.0 Volts

// Threshold voltage calculations
#define TV_0        		0xe30	// 3632 thresh. volt count at  0C (14.75V)
#define TV_40      			0xcd7	// 3287 thresh. volt count at 40C (13.35V)

//the two rates given below are in counts, and are 10 times larger than actual.
#define RATE1       		434		// TV rate between 0C and 40C (-35 mV/degree)
#define RATE2       		124		// TV rate above 40C (-10 mV/degree)

#define TEMP_0      		0xd3c	// 3388 count corrensponding to 0 C
#define TEMP_40	    		0xf2c	// 3884 count corrensponding to 40 C

/* This is the MOSFET temperature at which the fan is switched on. Change as necessary */
#define mosfetFanTemp		0xfaa 	// 4010 counts for 50 C

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);
void HD44780_Init(void);
void HD44780_WriteData(uint8_t row, uint8_t col, char *data);
void HD44780_WriteCommand(uint8_t);
void HD44780_GotoXY(uint8_t, uint8_t);
static void getADCreadings(uint8_t);

char *rx;
uint8_t myChar;
char inBuffer[16];
uint8_t charCount;


double vBat, iBat, vSolar, iSolar, loadVoltage, loadCurrent, ambientTemp, mosfetTemp;

#endif /* MPPT_H_ */
