/********************************************************************************************************
 * @file	zcl_pressure_measurement_attr.c
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
#ifdef ZCL_PRESSURE_MEASUREMENT

u16 zcl_attr_measuredVal = 0;
u16 zcl_attr_minMeasuredVal = 0;
u16 zcl_attr_maxMeasuredVal = 0;

/* Attribute record list */
const zclAttrInfo_t pressure_measure_attrTbl[] =
{
	{ ZCL_PRESSURE_ATTRID_MEASURED_VALUE,      ZCL_DATA_TYPE_UINT16,     ACCESS_CONTROL_READ,  (u8*)&zcl_attr_measuredVal },
	{ ZCL_PRESSURE_ATTRID_MIN_MEASURED_VALUE,  ZCL_DATA_TYPE_UINT16,     ACCESS_CONTROL_READ,  (u8*)&zcl_attr_minMeasuredVal },
	{ ZCL_PRESSURE_ATTRID_MAX_MEASURED_VALUE,  ZCL_DATA_TYPE_UINT16,     ACCESS_CONTROL_READ,  (u8*)&zcl_attr_maxMeasuredVal },
	{ ZCL_ATTRID_GLOBAL_CLUSTER_REVISION, ZCL_DATA_TYPE_UINT16,  ACCESS_CONTROL_READ,  (u8*)&zcl_attr_global_clusterRevision},
};

const u8 zcl_pressure_measure_attrNum = ( sizeof(pressure_measure_attrTbl) / sizeof(zclAttrInfo_t) );

#endif    /* ZCL_PRESSURE_MEASUREMENT */

#endif
