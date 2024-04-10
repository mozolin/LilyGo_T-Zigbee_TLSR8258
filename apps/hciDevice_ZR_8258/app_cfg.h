/********************************************************************************************************
 * @file  app_cfg.h
 *******************************************************************************************************/
#pragma once

/* Enable C linkage for C++ Compilers: */
#if defined(__cplusplus)
extern "C" {
#endif


/**********************************************************************
 * Version configuration
 */
#include "version_cfg.h"

/**********************************************************************
 * Product Information
 */
/* PA */
#define PA_ENABLE                  0

/* Debug mode */
#define UART_PRINTF_MODE                            1
#define USB_PRINTF_MODE                             0

/* HCI interface */
#define ZBHCI_UART                                  1
#define ZBHCI_USB_CDC                               0
#define ZBHCI_USB_HID                               0

/* BDB */
#define TOUCHLINK_SUPPORT                           1
#define FIND_AND_BIND_SUPPORT                       0

/* Board ID */
/*
#define BOARD_826x_EVK                              0
#define BOARD_826x_DONGLE                           1
#define BOARD_826x_DONGLE_PA                        2
#define BOARD_8258_EVK                              3
#define BOARD_8258_EVK_V1P2                         4//C1T139A30_V1.2
#define BOARD_8258_DONGLE                           5
#define BOARD_8278_EVK                              6
#define BOARD_8278_DONGLE                           7
#define BOARD_9518_EVK                              8
#define BOARD_9518_DONGLE                           9
*/
#define BOARD_8258                                  10

/* Board define */
/*
#if defined(MCU_CORE_826x)
#if !PA_ENABLE
  #define BOARD            BOARD_826x_DONGLE
#else
  #define BOARD            BOARD_826x_DONGLE_PA
#endif
  #define CLOCK_SYS_CLOCK_HZ      32000000
#elif defined(MCU_CORE_8258)
#if (CHIP_TYPE == TLSR_8258_1M)
  #define FLASH_CAP_SIZE_1M      1
#endif
*/
#define BOARD                                       BOARD_8258
#define CLOCK_SYS_CLOCK_HZ                          48000000
/*
#elif defined(MCU_CORE_8278)
  #define FLASH_CAP_SIZE_1M      1
  #define BOARD            BOARD_8278_DONGLE//BOARD_8278_EVK
  #define CLOCK_SYS_CLOCK_HZ      48000000
#elif defined(MCU_CORE_B91)
  #define FLASH_CAP_SIZE_1M      1
  #define BOARD            BOARD_9518_DONGLE//BOARD_9518_EVK
  #define CLOCK_SYS_CLOCK_HZ      48000000
#else
  #error "MCU is undefined!"
#endif
*/

/* Board include */
#include "board_8258.h"

/* Voltage detect module */
#define VOLTAGE_DETECT_ENABLE                       1

/* Watch dog module */
#define MODULE_WATCHDOG_ENABLE                      0

/* UART module */
#if ZBHCI_UART
#define  MODULE_UART_ENABLE                         1
#endif

/* USB module */
#if (ZBHCI_USB_CDC || ZBHCI_USB_HID)
#define MODULE_USB_ENABLE                           1
#if ZBHCI_USB_CDC
  #define USB_CDC_ENABLE                            1
  #define USB_VENDOR_ENABLE                         0
#elif ZBHCI_USB_HID
  #define USB_CDC_ENABLE                            0
  #define USB_VENDOR_ENABLE                         1
#endif
#endif

#if (ZBHCI_USB_PRINT || ZBHCI_USB_CDC || ZBHCI_USB_HID || ZBHCI_UART)
  #define ZBHCI_EN                                  1
#endif


/**********************************************************************
 * ZCL cluster support setting
 */
#define ZCL_ON_OFF_SUPPORT                          1
#define ZCL_LEVEL_CTRL_SUPPORT                      1
#define ZCL_LIGHT_COLOR_CONTROL_SUPPORT             1
#define ZCL_DOOR_LOCK_SUPPORT                       1
#define ZCL_TEMPERATURE_MEASUREMENT_SUPPORT         1
#define ZCL_ILLUMINANCE_MEASUREMENT_SUPPORT         1
#define ZCL_RELATIVE_HUMIDITY_MEASUREMENT_SUPPORT   1
#define ZCL_PRESSURE_MEASUREMENT_SUPPORT            1
#define ZCL_IAS_ZONE_SUPPORT                        1
#define ZCL_POLL_CTRL_SUPPORT                       1
#define ZCL_GROUP_SUPPORT                           1
#define ZCL_SCENE_SUPPORT                           1
#define ZCL_ON_OFF_SUPPORT                          1
#define ZCL_LEVEL_CTRL_SUPPORT                      1
#define ZCL_LIGHT_COLOR_CONTROL_SUPPORT             1
#define ZCL_OTA_SUPPORT                             1

#define AF_TEST_ENABLE                              0


/**********************************************************************
 * Stack configuration
 */
#include "stack_cfg.h"


/**********************************************************************
 * EV configuration
 */
typedef enum{
  EV_POLL_ED_DETECT,
  EV_POLL_HCI,
  EV_POLL_IDLE,
  EV_POLL_MAX,
}ev_poll_e;

/* Disable C linkage for C++ Compilers: */
#if defined(__cplusplus)
}
#endif
