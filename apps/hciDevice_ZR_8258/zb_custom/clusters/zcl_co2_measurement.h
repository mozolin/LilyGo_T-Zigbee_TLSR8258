/********************************************************************************************************
 * @file	zcl_co2_measurement.h
 *******************************************************************************************************/
#ifndef ZCL_CO2_MEASUREMENT_H
#define ZCL_CO2_MEASUREMENT_H


/*********************************************************************
 * CONSTANTS
 */


/* Attribute ID */
#define ZCL_CO2_ATTRID_MEASURED_VALUE       0x0000
#define ZCL_CO2_ATTRID_MIN_MEASURED_VALUE   0x0001
#define ZCL_CO2_ATTRID_MAX_MEASURED_VALUE   0x0002
#define ZCL_SPRUT_CO2_CALIBRATION_VALUE     0x6600
#define ZCL_SPRUT_CO2_AUTO_CALIBRATION      0x6601

#if 0
extern const zclAttrInfo_t co2_measure_attrTbl[];
extern const u8 zcl_co2_measure_attrNum;
#endif



status_t zcl_co2_measurement_register(u8 endpoint, u16 manuCode, u8 attrNum, const zclAttrInfo_t attrTbl[], cluster_forAppCb_t cb);


#endif	/* ZCL_CO2_MEASUREMENT_H */
