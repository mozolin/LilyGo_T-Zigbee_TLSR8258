/********************************************************************************************************
 * @file	zcl_pressure_measurement.h
 *******************************************************************************************************/
#ifndef ZCL_PRESSURE_MEASUREMENT_H
#define ZCL_PRESSURE_MEASUREMENT_H


/*********************************************************************
 * CONSTANTS
 */


/* Attribute ID */
#define ZCL_PRESSURE_ATTRID_MEASURED_VALUE                         0x0000
#define ZCL_PRESSURE_ATTRID_MIN_MEASURED_VALUE                     0x0001
#define ZCL_PRESSURE_ATTRID_MAX_MEASURED_VALUE                     0x0002


#if 0
extern const zclAttrInfo_t pressure_measure_attrTbl[];
extern const u8 zcl_pressure_measure_attrNum;
#endif



status_t zcl_pressure_measurement_register(u8 endpoint, u16 manuCode, u8 attrNum, const zclAttrInfo_t attrTbl[], cluster_forAppCb_t cb);


#endif	/* ZCL_PRESSURE_MEASUREMENT_H */
