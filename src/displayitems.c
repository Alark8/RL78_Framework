/*
 * displayitems.c
 *
 *  Created on: 13-Apr-2021
 *      Author: alarkm
 */


#include "rl78_d1a_head.h"
#include "displayitems.h"


/* For AAEN there are few segments which are always turned ON, to Enable them this function is called */
void DisplayAlwaysOnSegments(void)
{
	//S3, S7, S9, S10, S17, S18, S19, S20, S21, S22, S23, S24
	LCD_DATA->SEG48 |= 0x09;																	//Enable S3 and S9
	LCD_DATA->SEG37 |= ENABLE_ALL_MASK;															//Enable S19, S20, S22 and S23
	LCD_DATA->SEG33 |= COM2_MASK;																//Enable S21
	LCD_DATA->SEG39 |= COM3_MASK;																//Enable S10
	LCD_DATA->SEG30 |= COM0_MASK;																//Enable S7
	LCD_DATA->SEG47 |= 0x07;																	//Enable S17, S18 and S24
}



/*-----------------------------------------------------------------Speed Display-----------------------------------------------------------------*/

/* Displays the speed figure at required position
 * Units
 * Tens
 * Hundreds */
void DisplaySpeedFigure(uint8_t figure, uint8_t idx)
{
	uint8_t *seg1, *seg2, *segment_base_address = (uint8_t *)&LCD_DATA->SEG49;

	seg1 = (segment_base_address + (idx<<1));				//Segment based address is different as per idx
	seg2 = seg1 + 1;

	*seg1 = 0x00;
	*seg2 &= ~0x07;

	switch(figure)
	{
	case 0: *seg1 = 0x0F; *seg2 |= 0x05;
		break;
	case 1: *seg1 = 0x06;
		break;
	case 2: *seg1 = 0x0B; *seg2 |= 0x06;
		break;
	case 3: *seg1 = 0x0F; *seg2 |= 0x02;
		break;
	case 4: *seg1 = 0x06; *seg2 |= 0x03;
		break;
	case 5: *seg1 = 0x0D; *seg2 |= 0x03;
		break;
	case 6: *seg1 = 0x0D; *seg2 |= 0x07;
		break;
	case 7: *seg1 = 0x07;
		break;
	case 8: *seg1 = 0x0F; *seg2 |= 0x07;
		break;
	case 9: *seg1 = 0x0F; *seg2 |= 0x03;
		break;
	default: break;
	}
}



/* Display speed as a whole */
void DisplaySpeed(uint8_t speed)
{
	uint8_t idx=0;

	if(speed > TWO_DIGIT_MAX_VALUE) LCD_DATA->SEG40 |= COM2_MASK;								//Enable hunndred's place segment if speed above 100
	else LCD_DATA->SEG40 &= ~COM2_MASK;

	while(idx != 2)
	{
		if(idx) (speed) ? DisplaySpeedFigure(speed%10, idx) : DisplaySpeedFigure(CLEAR_FIGURE, idx);
		else DisplaySpeedFigure(speed%10, idx);

		++idx;
		speed /= 10;
	}
}



/* Display ECO string segment */
void DisplayECOString(SEGMENT_DISPLAY mode)
{
	if(mode) LCD_DATA->SEG48 |= COM1_MASK;														//Enable S1
	else LCD_DATA->SEG48 &= ~COM1_MASK;															//Clear S1
}



/* Display service reminder segment */
void DisplayServiceReminder(SEGMENT_DISPLAY mode)
{
	if(mode) LCD_DATA->SEG48 |= COM2_MASK;														//Enable S2
	else LCD_DATA->SEG48 &= ~COM2_MASK;															//Clear S2
}


/*------------------------------------------------------------------BT Display-------------------------------------------------------------------*/

/* Display BT calling segment */
void DisplayBTCalling(SEGMENT_DISPLAY mode)
{
	if(mode) LCD_DATA->SEG38 |= COM3_MASK;														//S13 Enable and Disable
	else LCD_DATA->SEG38 &= ~COM3_MASK;
}


/* Display BT missed message segment */
void DisplayBTMissedMessage(SEGMENT_DISPLAY mode)
{
	if(mode) LCD_DATA->SEG38 |= COM2_MASK;														//S11 Enable and Disable
	else LCD_DATA->SEG38 &= ~COM2_MASK;
}



/* Display BT missed call segment */
void DisplayBTMissedCall(SEGMENT_DISPLAY mode)
{
	if(mode) LCD_DATA->SEG38 |= COM1_MASK;														//S12 Enable and Disable
	else LCD_DATA->SEG38 &= ~COM1_MASK;
}



/* Display BT connected segment */
void DisplayBTConnected(SEGMENT_DISPLAY mode)
{
	if(mode) LCD_DATA->SEG47 |= COM3_MASK;														//S14 Enable and Disable
	else LCD_DATA->SEG47 &= ~COM3_MASK;
}



/* Display BT battery segment */
void DisplayBTBatteryStatus(SEGMENT_DISPLAY mode, BATTERY_BAR bars)
{
	if(mode)
	{
		LCD_DATA->SEG39 &= ~0x03;																//Clear X0 and X1
		LCD_DATA->SEG40 &= ~0x0B;																//Clear X4, X3 and X2

		switch(bars)
		{
		case PERCENT100: LCD_DATA->SEG39 |= COM0_MASK; 	// @suppress("No break at end of case")				//Enable X1
		case PERCENT75: LCD_DATA->SEG40 |= COM1_MASK; 	// @suppress("No break at end of case")				//Enable X2
		case PERCENT50: LCD_DATA->SEG40 |= COM0_MASK; 	// @suppress("No break at end of case")				//Enable X3
		case PERCENT25: LCD_DATA->SEG40 |= COM3_MASK; 	// @suppress("No break at end of case")				//Enable X4
		case PERCENT0: LCD_DATA->SEG39 |= COM1_MASK;														//Enable X0
			break;
		default: break;
		}
	}
	else
	{
		LCD_DATA->SEG39 &= ~0x03;																//Clear X0 and X1
		LCD_DATA->SEG40 &= ~0x0B;																//Clear X4, X3 and X2
	}
}



/*------------------------------------------------------------------Fuel Display-----------------------------------------------------------------*/

/* Display Fuel bars segment */
void DisplayFuelLevel(SEGMENT_DISPLAY mode, FUEL_SEGMENT segment)
{
	LCD_DATA->SEG33 |= 0x03;																	//Enable P7 and P8
	LCD_DATA->SEG34 |= 0x03;																	//Enable P5 and P6
	LCD_DATA->SEG35 |= 0x03;																	//Enable P3 and P4
	LCD_DATA->SEG36 |= 0x03;																	//Enable P1 and P2

	if(mode)
	{
		LCD_DATA->SEG33 &= ~COM3_MASK;															//Clear T7
		LCD_DATA->SEG34 &= ~0x0C;																//Clear T5 and T6
		LCD_DATA->SEG35 &= ~0x0C;																//Clear T3 and T4
		LCD_DATA->SEG36 &= ~0x0C;																//Clear T1 and T2

		switch(segment)
		{
		case SEG7: LCD_DATA->SEG33 |= COM3_MASK; // @suppress("No break at end of case")		//Enable T7
		case SEG6: LCD_DATA->SEG34 |= COM3_MASK; // @suppress("No break at end of case")		//Enable T6
		case SEG5: LCD_DATA->SEG34 |= COM2_MASK; // @suppress("No break at end of case")		//Enable T5
		case SEG4: LCD_DATA->SEG35 |= COM2_MASK; // @suppress("No break at end of case")		//Enable T4
		case SEG3: LCD_DATA->SEG35 |= COM3_MASK; // @suppress("No break at end of case")		//Enable T3
		case SEG2: LCD_DATA->SEG36 |= COM3_MASK; // @suppress("No break at end of case")		//Enable T2
		case SEG1: LCD_DATA->SEG36 |= COM2_MASK;												//Enable T1
			break;
		default: break;
		}
	}
	else
	{
		LCD_DATA->SEG33 &= ~COM3_MASK;															//Clear T7
		LCD_DATA->SEG34 &= ~0x0C;																//Clear T5 and T6
		LCD_DATA->SEG35 &= ~0x0C;																//Clear T3 and T4
		LCD_DATA->SEG36 &= ~0x0C;																//Clear T1 and T2
	}
}


/* To clear the content of fuel */
void DisplayFuelOpenCktAnimationScreen1(void)
{
	LCD_DATA->SEG33 &= ~0x0B;																	//Clear T7, P7 and P8
	LCD_DATA->SEG34 = 0x00;																		//Clear T5, T6, P5 and P6
	LCD_DATA->SEG35 = 0x00;																		//Clear T3, T4, P3 and P4
	LCD_DATA->SEG36 = 0x00;																		//Clear T1, T2, P1 and P2
}



/* Will display when function: DisplayFuelOpenCktAnimationScreen1() is called before this function */
void DisplayFuelOpenCktAnimationScreen2(void)
{
	LCD_DATA->SEG34 = 0x02;																		//Enable P5
	LCD_DATA->SEG35 = 0x06;																		//Enable T4 and P4
}



/* Will display when function: DisplayFuelOpenCktAnimationScreen1() is called before this function */
void DisplayFuelOpenCktAnimationScreen3(void)
{
	LCD_DATA->SEG34 = 0x07;																		//Enable T5, P5 and P6
	LCD_DATA->SEG35 = 0x0F;																		//Enable T3, T4, P3 and P4
}



/* Will display when function: DisplayFuelOpenCktAnimationScreen1() is called before this function */
void DisplayFuelOpenCktAnimationScreen4(void)
{
	LCD_DATA->SEG33 |= 0x01;																	//Enable P7
	LCD_DATA->SEG34 = 0x0F;																		//Enable T5, T6, P5 and P6
	LCD_DATA->SEG35 = 0x0F;																		//Enable T3, T4, P3 and P4
	LCD_DATA->SEG36 = 0x09;																		//Enable T2 and P2
}



/* Will display when function: DisplayFuelOpenCktAnimationScreen1() is called before this function */
void DisplayFuelOpenCktAnimationScreen5(void)
{
	LCD_DATA->SEG33 |= 0x0B;																	//Enable T7, P7 and P8
	LCD_DATA->SEG34 = 0x0F;																		//Enable T5, T6, P5 and P6
	LCD_DATA->SEG35 = 0x0F;																		//Enable T3, T4, P3 and P4
	LCD_DATA->SEG36 = 0x0F;																		//Enable T1, T2, P1 and P2
}



/* Will display when function: DisplayFuelOpenCktAnimationScreen1() is called before this function */
void DisplayFuelOpenCktAnimationScreen6(void)
{
	LCD_DATA->SEG33 |= 0x0B;																	//Enable T7, P7 and P8
	LCD_DATA->SEG34 = 0x0F;																		//Enable T5, T6, P5 and P6
	LCD_DATA->SEG35 = 0x0B;																		//Clear T4
	LCD_DATA->SEG36 = 0x0F;																		//Enable T1, T2, P1 and P2
}



/* Will display when function: DisplayFuelOpenCktAnimationScreen1() is called before this function */
void DisplayFuelOpenCktAnimationScreen7(void)
{
	LCD_DATA->SEG33 |= 0x0B;																	//Enable T7, P7 and P8
	LCD_DATA->SEG34 = 0x09;																		//Clear T5 and P5
	LCD_DATA->SEG35 = 0x01;																		//Clear T3 and P4
	LCD_DATA->SEG36 = 0x0F;																		//Enable T1, T2, P1 and P2
}



/* Will display when function: DisplayFuelOpenCktAnimationScreen1() is called before this function */
void DisplayFuelOpenCktAnimationScreen8(void)
{
	LCD_DATA->SEG33 |= 0x0B;																	//Enable T7, P7 and P8
	LCD_DATA->SEG36 = 0x07;																		//Clear T2
}



/*-----------------------------------------------------------------RTMi Display-----------------------------------------------------------------*/


/* Display default RTMi "--.-" segment */
void DisplayDefaultRTMi(void)
{
	LCD_DATA->SEG41 = 0x02;
	LCD_DATA->SEG42 = 0x00;
	LCD_DATA->SEG43 = 0x02;
	LCD_DATA->SEG44 = 0x00;
	LCD_DATA->SEG45 = 0x05;
	LCD_DATA->SEG46 = 0x00;
}



/* Display RTMi figure on required place
 * Units
 * Tens
 * Hundreds
 * Thousands */
void DisplayRTMiFigure(uint8_t figure, uint8_t idx)
{
	uint8_t *seg1, *seg2, *segment_base_address = (uint8_t *)&LCD_DATA->SEG46;

	seg2 = (segment_base_address - (idx<<1));
	seg1 = seg2 - 1;

	*seg1 &= ~(0x0E >> ((idx)?1:0));
	*seg2 = 0x00;

	switch(figure)
	{
	case 0: *seg2 = 0x0F; *seg1 |= (0x0A >> ((idx)?1:0));
		break;
	case 1: *seg2 = 0x06;
		break;
	case 2: *seg2 = 0x0D; *seg1 |= (0x06 >> ((idx)?1:0));
		break;
	case 3: *seg2 = 0x0F; *seg1 |= (0x04 >> ((idx)?1:0));
		break;
	case 4: *seg2 = 0x06; *seg1 |= (0x0C >> ((idx)?1:0));
		break;
	case 5: *seg2 = 0x0B; *seg1 |= (0x0C >> ((idx)?1:0));
		break;
	case 6: *seg2 = 0x0B; *seg1 |= (0x0E >> ((idx)?1:0));
		break;
	case 7: *seg2 = 0x0E;
		break;
	case 8: *seg2 = 0x0F; *seg1 |= (0x0E >> ((idx)?1:0));
		break;
	case 9: *seg2 = 0x0F; *seg1 |= (0x0C >> ((idx)?1:0));
		break;
	default: break;
	}
}


/* Display RTMi as a whole */
void DisplayRTMi(uint16_t rtmi_value)
{
	uint8_t idx=0;

	if(rtmi_value > THREE_DIGIT_MAX_VALUE) LCD_DATA->SEG41 |= COM3_MASK;
	else LCD_DATA->SEG41 &= ~COM3_MASK;

	while(idx != 3)
	{
		switch(idx)
		{
		case 0: DisplayRTMiFigure(rtmi_value%10, idx);
			break;
		case 1: DisplayRTMiFigure(rtmi_value%10, idx);
			break;
		case 2: (rtmi_value) ? DisplayRTMiFigure(rtmi_value%10, idx) : DisplayRTMiFigure(CLEAR_FIGURE, idx);
			break;
		default: break;
		}

		++idx;
		rtmi_value /= 10;
	}
}



/*------------------------------------------------------------------Odo Display-----------------------------------------------------------------*/

uint8_t* odo_figure_address[6][5] = {{(uint8_t *)&LCD_DATA->SEG22, (uint8_t *)&LCD_DATA->SEG25, (uint8_t *)&LCD_DATA->SEG26, (uint8_t *)&LCD_DATA->SEG27, (uint8_t *)&LCD_DATA->SEG30},
									 {(uint8_t *)&LCD_DATA->SEG18, (uint8_t *)&LCD_DATA->SEG19, (uint8_t *)&LCD_DATA->SEG20, (uint8_t *)&LCD_DATA->SEG21, (uint8_t *)&LCD_DATA->SEG22},
									 {(uint8_t *)&LCD_DATA->SEG12, (uint8_t *)&LCD_DATA->SEG13, (uint8_t *)&LCD_DATA->SEG16, (uint8_t *)&LCD_DATA->SEG17, (uint8_t *)&LCD_DATA->SEG18},
									 {(uint8_t *)&LCD_DATA->SEG8, (uint8_t *)&LCD_DATA->SEG9, (uint8_t *)&LCD_DATA->SEG10, (uint8_t *)&LCD_DATA->SEG11, (uint8_t *)&LCD_DATA->SEG12},
									 {(uint8_t *)&LCD_DATA->SEG4, (uint8_t *)&LCD_DATA->SEG5, (uint8_t *)&LCD_DATA->SEG6, (uint8_t *)&LCD_DATA->SEG7, (uint8_t *)&LCD_DATA->SEG8},
									 {(uint8_t *)&LCD_DATA->SEG0, (uint8_t *)&LCD_DATA->SEG1, (uint8_t *)&LCD_DATA->SEG2, (uint8_t *)&LCD_DATA->SEG3, (uint8_t *)&LCD_DATA->SEG4}
									};


/* Display ODO and accordingly display Trip segment */
void DisplayOdoString(SEGMENT_DISPLAY mode)
{
	if(mode)
	{
		DisplayTripString(OFF,TRIPA);															//Turn OFF TRIPA segment
		LCD_DATA->SEG50 |= COM3_MASK;															//Enable S6
	}
	else LCD_DATA->SEG50 &= ~COM3_MASK;															//Clear S6
}




/* Display Trip and accordingly display ODO segment */
void DisplayTripString(SEGMENT_DISPLAY mode, TRIP_MODE trip_x)
{
	if(mode)
	{
		DisplayOdoString(OFF);																	//Turn Off ODO
		LCD_DATA->SEG0 |= COM2_MASK;															//Enable S4
		LCD_DATA->SEG22 |= COM0_MASK;															//Enable S8

		if(trip_x)
		{
			LCD_DATA->SEG52 &= ~COM3_MASK;														//Clear R
			LCD_DATA->SEG0 |= COM1_MASK;														//Enable S5
		}
		else
		{
			LCD_DATA->SEG0 &= ~COM1_MASK;														//Clear S5
			LCD_DATA->SEG52 |= COM3_MASK;														//Enable R
		}
	}
	else
	{
		LCD_DATA->SEG0 &= ~COM2_MASK;															//Clear S4
		LCD_DATA->SEG0 &= ~COM1_MASK;															//Clear S5
		LCD_DATA->SEG52 &= ~COM3_MASK;															//Clear R
		LCD_DATA->SEG22 &= ~COM0_MASK;															//Clear S8
	}
}



/* Display ODO figure at the desired place
 * Units
 * Tens
 * Hundreds
 * Thousands */
void DisplayOdoFigure(uint8_t figure, uint8_t idx)
{
	uint8_t *seg1, *seg2, *seg3, *seg4, *seg5;

	seg1 = odo_figure_address[idx][0];
	seg2 = odo_figure_address[idx][1];
	seg3 = odo_figure_address[idx][2];
	seg4 = odo_figure_address[idx][3];
	seg5 = odo_figure_address[idx][4];

	*seg2 = 0x00; *seg3 = 0x00; *seg4 = 0x00;

	if(idx){
		*seg1 &= ~0x09; *seg5 &= ~0x06;
	}
	else{
		*seg1 &= ~COM3_MASK; *seg5 &= ~0x0E;
	}

	switch(figure)
	{
	case 0: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM3_MASK; *seg5 |= 0x06;
			}
			else{
				*seg1 |= COM3_MASK; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM0_MASK; *seg5 |= 0x0E;
			}
		break;

	case 1:	*seg5 |= 0x06;
		break;

	case 2: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x05; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= 0x04;
			}
			else{
				*seg1 |= COM3_MASK; *seg2 |= 0x05; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0C;
			}
		break;

	case 3: if(idx){
				*seg1 |= COM3_MASK; *seg2 |= 0x05; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= 0x06;
			}
			else{
				*seg1 |= COM3_MASK; *seg2 |= 0x04; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0E;
			}

		break;

	case 4: if(idx){
				*seg2 |= 0x0C; *seg4 |= COM1_MASK; *seg5 |= 0x06;
			}
			else{
				*seg2 |= 0x0C; *seg4 |= 0x04; *seg5 |= 0x06;
			}
		break;

	case 5: if(idx){
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= 0x02;
			}
			else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0C; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0A;
			}
		break;

	case 6: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= 0x02;
			}
			else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0A;
			}
		break;

	case 7: if(idx){
				*seg1 |= COM3_MASK; *seg4 |= COM3_MASK; *seg5 |= 0x06;
			}
			else{
				*seg1 |= COM3_MASK; *seg5 |= 0x0E;
			}
		break;

	case 8: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= 0x06;
			}
			else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0E;
			}
		break;

	case 9: if(idx){
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= 0x06;
			}
			else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0C; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0E;
			}
		break;

	default: break;
	}
}



/* Display Odo value as a whole */
void DisplayOdo(uint32_t odo_value)
{
	uint8_t idx=0;

	while(idx != 6)
	{
		if(idx) (odo_value) ? DisplayOdoFigure(odo_value%10, idx) : DisplayOdoFigure(CLEAR_FIGURE, idx);
		else DisplayOdoFigure(odo_value%10, idx);

		++idx;
		odo_value /= 10;
	}
}


/*-----------------------------------------------------------------Alpha Display----------------------------------------------------------------*/


/* Display alpha figure at desired place
 * Units
 * Tens
 * Hundreds
 * Thousands */
void DisplayAlphaFigure(uint8_t figure, uint8_t idx)
{
	uint8_t *seg1, *seg2, *seg3, *seg4, *seg5;

	seg1 = odo_figure_address[idx][0];
	seg2 = odo_figure_address[idx][1];
	seg3 = odo_figure_address[idx][2];
	seg4 = odo_figure_address[idx][3];
	seg5 = odo_figure_address[idx][4];

	*seg2 = 0x00; *seg3 = 0x00; *seg4 = 0x00;

	if(idx){
		*seg1 &= ~0x09; *seg5 &= ~0x06;
	}
	else{
		*seg1 &= ~COM3_MASK; *seg5 &= ~0x0E;
	}

	switch(figure)
	{
	case 30: DisplayOdoFigure(0,idx);																										//0
		break;
	case 31: DisplayOdoFigure(1,idx);																										//1
		break;
	case 32: DisplayOdoFigure(2,idx);																										//2
		break;
	case 33: DisplayOdoFigure(3,idx);																										//3
		break;
	case 34: DisplayOdoFigure(4,idx);																										//4
		break;
	case 35: DisplayOdoFigure(5,idx);																										//5
		break;
	case 36: DisplayOdoFigure(6,idx);																										//6
		break;
	case 37: DisplayOdoFigure(7,idx);																										//7
		break;
	case 38: DisplayOdoFigure(8,idx);																										//8
		break;
	case 39: DisplayOdoFigure(9,idx);																										//9
		break;
	case 65: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x0C; *seg4 |= 0x0A; *seg5 |= 0x06;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg4 |= COM2_MASK; *seg5 |= 0x0E;														//A
			 }
		break;
	case 66: if(idx){
				*seg1 |= COM3_MASK; *seg2 |= COM0_MASK; *seg3 |= 0x0B; *seg4 |= 0x0A; *seg5 |= 0x06;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg3 |= 0x0B; *seg4 |= 0x05; *seg5 |= 0x0E;															//B
			 }
		break;
	case 67: if(idx){
				 *seg1 |= 0x09; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM3_MASK;
			 }
			 else{
				 *seg1 |= COM3_MASK; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM0_MASK; *seg5 |= COM3_MASK;								//C
			 }
		break;
	case 68: if(idx){
				 *seg1 |= COM3_MASK; *seg2 |= COM0_MASK; *seg3 |= 0x0B; *seg4 |= COM3_MASK; *seg5 |= 0x06;
			 }
			 else{
				 *seg1 |= COM3_MASK; *seg3 |= 0x0B; *seg4 |= COM0_MASK; *seg5 |= 0x0E;														//D
			 }
		break;
	case 69: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x0A;
			}
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= COM3_MASK;									//E
			}
		break;
	case 70: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x0C; *seg4 |= 0x0A;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg4 |= COM2_MASK; *seg5 |= COM3_MASK;													//F
			 }
		break;
	case 71: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= COM1_MASK;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0A;										//G
			 }
		break;
	case 72: if(idx){
				*seg1 |= COM0_MASK; *seg2 |= 0x0C; *seg4 |= COM1_MASK; *seg5 |= 0x06;
			 }
			 else{
				*seg2 |= 0x0D;*seg4 |= COM2_MASK; *seg5 |= 0x06;																			//H
			 }
		break;
	case 73: if(idx){
				*seg1 |= COM3_MASK; *seg2 |= COM0_MASK; *seg3 |= 0x0B; *seg4 |= COM3_MASK;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg3 |= 0x0B; *seg4 |= COM0_MASK; *seg5 |= COM3_MASK;													//I
			 }
		break;
	case 74: if(idx){
				*seg2 |= COM0_MASK; *seg3 |= COM0_MASK; *seg4 |= COM3_MASK; *seg5 |= 0x06;
			 }
			 else{
				*seg3 |= COM0_MASK; *seg4 |= COM0_MASK; *seg5 |= 0x0E;																		//J
			 }
		break;
	case 75: if(idx){
				*seg1 |= COM0_MASK; *seg2 |= 0x0C; *seg4 |= 0x05;
			 }
			 else{
				*seg2 |= 0x0D; *seg4 |= 0x0A;																								//K
			 }
		break;
	case 76: if(idx){
				*seg1 |= COM0_MASK; *seg2 |= 0x09; *seg3 |= COM0_MASK;
			 }
			 else{
				*seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM0_MASK;																		//L
			 }
		break;
	case 77: if(idx){
				*seg1 |= 0x09; *seg2 |= COM3_MASK; *seg3 |= COM3_MASK; *seg4 |= COM3_MASK; *seg5 |= 0x06;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x09; *seg3 |= COM3_MASK; *seg5 |= 0x0E;														//M
			 }
		break;
	case 78: if(idx){
				*seg1 |= COM0_MASK; *seg2 |= COM3_MASK; *seg3 |= COM2_MASK; *seg4 |= COM0_MASK; *seg5 |= 0x06;
			 }
			 else{
				*seg2 |= 0x09; *seg3 |= COM2_MASK; *seg4 |= COM1_MASK; *seg5 |= 0x06;														//N
			 }
		break;
	case 79: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM3_MASK; *seg5 |= 0x06;
			 }
			 else{
				 *seg1 |= COM3_MASK; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM0_MASK; *seg5 |= 0x0E;									//O
			 }
		break;
	case 80: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x0C; *seg4 |= 0x0A; *seg5 |= COM2_MASK;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg4 |= COM2_MASK; *seg5 |= 0x0C;														//P
			 }
		break;
	case 81: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= 0x09; *seg5 |= 0x06;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= 0x03; *seg5 |= 0x0E;										//Q
			 }
		break;
	case 82: if(idx){
				*seg1 |= 0x09; *seg2 |= 0x0C; *seg4 |= 0x0B; *seg5 |= COM2_MASK;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg4 |= 0x06; *seg5 |= 0x0C;															//R
			 }
		break;
	case 83: if(idx){
				*seg1 |= COM3_MASK; *seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= 0x0A; *seg5 |= 0x02;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= 0x0C; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x0A;										//S
			 }
		break;
	case 84: if(idx){
				*seg1 |= COM3_MASK; *seg3 |= 0x0A; *seg4 |= COM3_MASK;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg3 |= 0x0A; *seg5 |= COM3_MASK;																		//T
			 }
		break;
	case 85: if(idx){
				*seg1 |= COM0_MASK; *seg2 |= 0x09; *seg3 |= COM0_MASK; *seg5 |= 0x06;
			 }
			 else{
				*seg2 |= 0x09; *seg3 |= COM0_MASK; *seg4 |= COM0_MASK; *seg5 |= 0x06;														//U
			 }
		break;
	case 86: if(idx){
				*seg1 |= COM0_MASK; *seg2 |= 0x0A; *seg4 |= COM2_MASK;
			 }
			 else{
				*seg2 |= 0x0B; *seg4 |= COM3_MASK;																							//V
			 }
		break;
	case 87: if(idx){
				*seg1 |= COM0_MASK; *seg2 |= 0x09; *seg3 |= 0x03; *seg5 |= 0x06;
			 }
			 else{
				*seg2 |= 0x0B; *seg4 |= COM1_MASK; *seg5 |= 0x06;																			//W
			 }
		break;
	case 88: if(idx){
				*seg2 |= COM1_MASK; *seg3 |= COM2_MASK; *seg4 |= 0x05;
			 }
			 else{
				*seg2 |= COM1_MASK; *seg3 |= COM2_MASK; *seg4 |= 0x0A;																		//X
			 }
		break;
	case 89: if(idx){
				*seg2 |= 0x0D; *seg3 |= COM0_MASK; *seg4 |= COM1_MASK; *seg5 |= 0x06;
			 }
			 else{
				*seg2 |= 0x0C; *seg3 |= COM0_MASK; *seg4 |= 0x05; *seg5 |= 0x06;															//Y
			 }
		break;
	case 90: if(idx){
				*seg1 |= COM3_MASK; *seg2 |= 0x03; *seg3 |= COM0_MASK; *seg4 |= 0x0C;
			 }
			 else{
				*seg1 |= COM3_MASK; *seg2 |= COM1_MASK; *seg3 |= COM0_MASK; *seg4 |= 0x09; *seg5 |= COM3_MASK;								//Z
			 }
		break;
	default: break;
	}
}


