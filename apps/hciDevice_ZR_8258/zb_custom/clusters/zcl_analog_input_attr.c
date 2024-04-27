/********************************************************************************************************
 * @file  zcl_analog_input_attr.c
 *******************************************************************************************************/
#if 0

/**********************************************************************
 * INCLUDES
 */
#include "../../../../zigbee/zcl/zcl_include.h"
#include "../zb_custom.h"


/**********************************************************************
 * LOCAL CONSTANTS
 */


/**********************************************************************
 * LOCAL TYPES
 */


/**********************************************************************
 * LOCAL VARIABLES
 */
#ifdef ZCL_ANALOG_INPUT_MEASUREMENT

u8 zcl_attr_analogInput_description[ZCL_ANALOG_INPUT_MAX_LENGTH] = {0};
u16 zcl_attr_analogInput_maxPresentValue = 0;
u16 zcl_attr_analogInput_minPresentValue = 0;
bool zcl_attr_analogInput_outOfService = FALSE;
u16 zcl_attr_analogInput_presentValue = 0;
u8 zcl_attr_analogInput_reliability = 0;
u8 zcl_attr_bininput_resolution = 0;
u8 zcl_attr_analogInput_statusFlags = 0;
u8 zcl_attr_analogInput_engineeringUnits = 0;
u32 zcl_attr_analogInput_appType = 0;

const zclAttrInfo_t analog_input_attrTbl[] =
{
  { ZCL_ANALOG_INPUT_ATTRID_DESCRIPTION,       ZCL_DATA_TYPE_CHAR_STR, ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_analogInput_description},
  { ZCL_ANALOG_INPUT_ATTRID_MAX_PRESENT_VALUE, ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_analogInput_maxPresentValue},
  { ZCL_ANALOG_INPUT_ATTRID_MIN_PRESENT_VALUE, ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_analogInput_minPresentValue},
  { ZCL_ANALOG_INPUT_ATTRID_OUT_OF_SERVICE,    ZCL_DATA_TYPE_BOOLEAN,  ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_analogInput_outOfService},
  { ZCL_ANALOG_INPUT_ATTRID_PRESENT_VALUE,     ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_analogInput_presentValue},
  { ZCL_ANALOG_INPUT_ATTRID_RELIABILITY,       ZCL_DATA_TYPE_ENUM8,    ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_analogInput_reliability},
  { ZCL_ANALOG_INPUT_ATTRID_RESOLUTION,        ZCL_DATA_TYPE_UINT8,    ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_bininput_resolution},
  { ZCL_ANALOG_INPUT_ATTRID_STATUS_FLAGS,      ZCL_DATA_TYPE_UINT8,    ACCESS_CONTROL_READ,                        (u8*)zcl_attr_analogInput_statusFlags},
  { ZCL_ANALOG_INPUT_ATTRID_ENGINEERING_UNITS, ZCL_DATA_TYPE_ENUM16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_analogInput_engineeringUnits},
  { ZCL_ANALOG_INPUT_ATTRID_APP_TYPE,          ZCL_DATA_TYPE_UINT32,   ACCESS_CONTROL_READ,                        (u8*)zcl_attr_analogInput_appType},
  { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,        ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ,                        (u8*)&zcl_attr_global_clusterRevision},
};

const u8 zcl_analog_input_attrNum = ( sizeof(analog_input_attrTbl) / sizeof(zclAttrInfo_t) );

#endif  /* ZCL_ANALOG_INPUT_MEASUREMENT */

#endif
