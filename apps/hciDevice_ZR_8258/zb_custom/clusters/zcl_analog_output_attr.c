/********************************************************************************************************
 * @file  zcl_analog_output_attr.c
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
#ifdef ZCL_ANALOG_OUTPUT_MEASUREMENT

u8 zcl_attr_analogOutput_description[ZCL_ANALOG_OUTPUT_MAX_LENGTH] = {0};
u16 zcl_attr_analogOutput_maxPresentValue = 0;
u16 zcl_attr_analogOutput_minPresentValue = 0;
bool zcl_attr_analogOutput_outOfService = FALSE;
u16 zcl_attr_analogOutput_presentValue = 0;
zcl_analogOutput_priorityArray_t zcl_attr_analogOutput_priorityArray[16] = {0};
u8 zcl_attr_analogOutput_reliability = 0;
bool zcl_attr_binOutput_relinquishDefault = 0;
u8 zcl_attr_binoutput_resolution = 0;
u8 zcl_attr_analogOutput_statusFlags = 0;
u8 zcl_attr_analogOutput_engineeringUnits = 0;
u32 zcl_attr_analogOutput_appType = 0;

const zclAttrInfo_t analog_output_attrTbl[] =
{
  { ZCL_ANALOG_OUTPUT_ATTRID_DESCRIPTION,        ZCL_DATA_TYPE_CHAR_STR, ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_analogOutput_description},
  { ZCL_ANALOG_OUTPUT_ATTRID_MAX_PRESENT_VALUE,  ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_analogOutput_maxPresentValue},
  { ZCL_ANALOG_OUTPUT_ATTRID_MIN_PRESENT_VALUE,  ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_analogOutput_minPresentValue},
  { ZCL_ANALOG_OUTPUT_ATTRID_OUT_OF_SERVICE,     ZCL_DATA_TYPE_BOOLEAN,  ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_analogOutput_outOfService},
  { ZCL_ANALOG_OUTPUT_ATTRID_PRESENT_VALUE,      ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_analogOutput_presentValue},
	{ ZCL_ANALOG_OUTPUT_ATTRID_PRIORITY_ARRAY,		 ZCL_DATA_TYPE_ARRAY,   	ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)zcl_attr_binOutput_priorityArray},
  { ZCL_ANALOG_OUTPUT_ATTRID_RELIABILITY,        ZCL_DATA_TYPE_ENUM8,    ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_analogOutput_reliability},
	{ ZCL_ANALOG_OUTPUT_ATTRID_RELINQUISH_DEFAULT, ZCL_DATA_TYPE_BOOLEAN, 	ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE, (u8*)&zcl_attr_binOutput_relinquishDefault},
  { ZCL_ANALOG_OUTPUT_ATTRID_RESOLUTION,         ZCL_DATA_TYPE_UINT8,    ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_binoutput_resolution},
  { ZCL_ANALOG_OUTPUT_ATTRID_STATUS_FLAGS,       ZCL_DATA_TYPE_UINT8,    ACCESS_CONTROL_READ,                         (u8*)zcl_attr_analogOutput_statusFlags},
  { ZCL_ANALOG_OUTPUT_ATTRID_ENGINEERING_UNITS,  ZCL_DATA_TYPE_ENUM16,   ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,  (u8*)zcl_attr_analogOutput_engineeringUnits},
  { ZCL_ANALOG_OUTPUT_ATTRID_APP_TYPE,           ZCL_DATA_TYPE_UINT32,   ACCESS_CONTROL_READ,                         (u8*)zcl_attr_analogOutput_appType},
  { ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,          ZCL_DATA_TYPE_UINT16,   ACCESS_CONTROL_READ,                         (u8*)&zcl_attr_global_clusterRevision},
};

const u8 zcl_analog_output_attrNum = ( sizeof(analog_output_attrTbl) / sizeof(zclAttrInfo_t) );

#endif  /* ZCL_ANALOG_OUTPUT_MEASUREMENT */

#endif
