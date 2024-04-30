/********************************************************************************************************
 * @file	zcl_co2_measurement_attr.c
 *******************************************************************************************************/
#if 0
#include "tl_common.h"

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
#ifdef ZCL_CO2_MEASUREMENT

u16 zcl_attr_measuredVal = 0;
u16 zcl_attr_minMeasuredVal = 0;
u16 zcl_attr_maxMeasuredVal = 0;
u16 zcl_attr_sprutCO2Calibration = 0;
u16 zcl_attr_sprutCO2AutoCalibration = 0;

/* Attribute record list */
const zclAttrInfo_t co2_measure_attrTbl[] =
{
	{ ZCL_HUMIDITY_ATTRID_MEASURED_VALUE,      ZCL_DATA_TYPE_UINT16,  ACCESS_CONTROL_READ,  (u8*)&zcl_attr_measuredVal },
	{ ZCL_HUMIDITY_ATTRID_MIN_MEASURED_VALUE,  ZCL_DATA_TYPE_UINT16,  ACCESS_CONTROL_READ,  (u8*)&zcl_attr_minMeasuredVal },
	{ ZCL_HUMIDITY_ATTRID_MAX_MEASURED_VALUE,  ZCL_DATA_TYPE_UINT16,  ACCESS_CONTROL_READ,  (u8*)&zcl_attr_maxMeasuredVal },
	{ ZCL_SPRUT_CO2_CALIBRATION_VALUE,         ZCL_DATA_TYPE_UINT16,  ACCESS_CONTROL_READ,  (u8*)&zcl_attr_sprutCO2Calibration },
  { ZCL_SPRUT_CO2_AUTO_CALIBRATION,          ZCL_DATA_TYPE_UINT16,  ACCESS_CONTROL_READ,  (u8*)&zcl_attr_sprutCO2AutoCalibration },
	{ ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,      ZCL_DATA_TYPE_UINT16,  ACCESS_CONTROL_READ,  (u8*)&zcl_attr_global_clusterRevision},
};

const u8 zcl_co2_measure_attrNum = ( sizeof(co2_measure_attrTbl) / sizeof(zclAttrInfo_t) );

#endif    /* ZCL_CO2_MEASUREMENT */

#endif
