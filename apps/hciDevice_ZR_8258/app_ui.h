/********************************************************************************************************
 * @file	app_ui.h
 *******************************************************************************************************/
#ifndef _APP_UI_H_
#define _APP_UI_H_


/**********************************************************************
 * CONSTANT
 */
#define LED_ON						1
#define LED_OFF						0


/**********************************************************************
 * TYPEDEFS
 */
enum{
	APP_STATE_NORMAL,
	APP_FACTORY_NEW_SET_CHECK
};


/**********************************************************************
 * FUNCTIONS
 */
void light_blink_start(u8 times, u16 ledOnTime, u16 ledOffTime);
void light_blink_stop(void);

void light_init(void);
void light_on(void);
void light_off(void);

void led_on(u32 pin);
void led_off(u32 pin);

void app_key_handler(void);

#endif	/* _APP_UI_H_ */
