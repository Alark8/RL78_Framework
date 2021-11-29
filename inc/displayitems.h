#ifndef DISPLAYITEMS_H
#define DISPLAYITEMS_H


#define COM0_SHIFT									0x00
#define COM1_SHIFT									0x01
#define COM2_SHIFT									0x02
#define COM3_SHIFT									0x03
#define COM0_MASK									0x01
#define COM1_MASK									0x02
#define COM2_MASK									0x04
#define COM3_MASK									0x08
#define ENABLE_ALL_MASK								0x0F
#define CLEAR_FIGURE								0xFF
#define TWO_DIGIT_MAX_VALUE							0x63				//99
#define THREE_DIGIT_MAX_VALUE					   0x3E7				//999


typedef enum {OFF, ON} SEGMENT_DISPLAY;
typedef enum {PERCENT0, PERCENT25, PERCENT50, PERCENT75, PERCENT100} BATTERY_BAR;
typedef enum {SEG0, SEG1, SEG2, SEG3, SEG4, SEG5, SEG6, SEG7} FUEL_SEGMENT;
typedef enum {TRIPA, TRIPB} TRIP_MODE;


void DisplayDefaultRTMi(void);
void DisplaySpeed(uint8_t speed);
void DisplayAlwaysOnSegments(void);
void DisplayOdo(uint32_t odo_value);
void DisplayRTMi(uint16_t rtmi_value);
void DisplayOdoString(SEGMENT_DISPLAY mode);
void DisplayECOString(SEGMENT_DISPLAY mode);
void DisplayBTCalling(SEGMENT_DISPLAY mode);
void DisplayBTConnected(SEGMENT_DISPLAY mode);
void DisplayFuelOpenCktAnimationScreen1(void);
void DisplayFuelOpenCktAnimationScreen2(void);
void DisplayFuelOpenCktAnimationScreen3(void);
void DisplayFuelOpenCktAnimationScreen4(void);
void DisplayFuelOpenCktAnimationScreen5(void);
void DisplayFuelOpenCktAnimationScreen6(void);
void DisplayFuelOpenCktAnimationScreen7(void);
void DisplayFuelOpenCktAnimationScreen8(void);
void DisplayBTMissedCall(SEGMENT_DISPLAY mode);
void DisplayServiceReminder(SEGMENT_DISPLAY mode);
void DisplayBTMissedMessage(SEGMENT_DISPLAY mode);
void DisplayOdoFigure(uint8_t figure, uint8_t idx);
void DisplayRTMiFigure(uint8_t figure, uint8_t idx);
void DisplaySpeedFigure(uint8_t figure, uint8_t idx);
void DisplayAlphaFigure(uint8_t figure, uint8_t idx);
void DisplayTripString(SEGMENT_DISPLAY mode, TRIP_MODE trip_x);
void DisplayFuelLevel(SEGMENT_DISPLAY mode, FUEL_SEGMENT segment);
void DisplayBTBatteryStatus(SEGMENT_DISPLAY mode, BATTERY_BAR bars);

#endif
