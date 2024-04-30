/********************************************************************************************************
 * @file  version_cfg.h
 *******************************************************************************************************/
#pragma once

#include "../common/comm_cfg.h"

/*
#if defined(MCU_CORE_826x)
  #if (CHIP_8269)
    #define CHIP_TYPE          TLSR_8269
  #else
    #define CHIP_TYPE          TLSR_8267
  #endif
#elif defined(MCU_CORE_8258)
*/
    #define CHIP_TYPE          TLSR_8258_512K//TLSR_8258_1M
/*
#elif defined(MCU_CORE_8278)
    #define CHIP_TYPE          TLSR_8278
#elif defined(MCU_CORE_B91)
    #define CHIP_TYPE          TLSR_9518
#endif
*/

#define APP_RELEASE            0x10//app release 1.0
#define APP_BUILD              0x01//app build 01
#define STACK_RELEASE          0x30//stack release 3.0
#define STACK_BUILD            0x01//stack build 01

/*********************************************************************************************
 * During OTA upgrade, the upgraded device will check the rules of the following three fields.
 * Refer to ZCL OTA specification for details.
 */
#define MANUFACTURER_CODE_TELINK    0x1141//Telink ID
#define IMAGE_TYPE                  ((CHIP_TYPE << 8) | IMAGE_TYPE_GW)
#define FILE_VERSION                ((APP_RELEASE << 24) | (APP_BUILD << 16) | (STACK_RELEASE << 8) | STACK_BUILD)

/* Pre-compiled link configuration. */
#define IS_BOOT_LOADER_IMAGE        0
#define RESV_FOR_APP_RAM_CODE_SIZE  0
#define IMAGE_OFFSET                APP_IMAGE_ADDR
