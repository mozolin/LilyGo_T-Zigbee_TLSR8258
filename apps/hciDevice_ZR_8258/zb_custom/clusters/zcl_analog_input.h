/********************************************************************************************************
 * @file  zcl_analog_input.h
 *******************************************************************************************************/
#ifndef ZCL_ANALOG_INPUT_H
#define ZCL_ANALOG_INPUT_H



/*********************************************************************
 * CONSTANTS
 */

/**
 *  @brief  analog input cluster Attribute IDs
 */
#define ZCL_ANALOG_INPUT_ATTRID_DESCRIPTION           0x001C
#define ZCL_ANALOG_INPUT_ATTRID_MAX_PRESENT_VALUE     0x0041
#define ZCL_ANALOG_INPUT_ATTRID_MIN_PRESENT_VALUE     0x0045
#define ZCL_ANALOG_INPUT_ATTRID_OUT_OF_SERVICE        0x0051
#define ZCL_ANALOG_INPUT_ATTRID_PRESENT_VALUE         0x0055
#define ZCL_ANALOG_INPUT_ATTRID_RELIABILITY           0x0067
#define ZCL_ANALOG_INPUT_ATTRID_RESOLUTION            0x006A
#define ZCL_ANALOG_INPUT_ATTRID_STATUS_FLAGS          0x006F
#define ZCL_ANALOG_INPUT_ATTRID_ENGINEERING_UNITS     0x0075
#define ZCL_ANALOG_INPUT_ATTRID_APP_TYPE              0x0100

/**
 *  @brief Max length of char string
 */
#define ZCL_ANALOG_INPUT_MAX_LENGTH             24

#if 0
extern u8 zcl_attr_analogInput_description[];
extern u16 zcl_attr_analogInput_maxPresentValue;
extern u16 zcl_attr_analogInput_minPresentValue;
extern bool zcl_attr_analogInput_outOfService;
extern u16 zcl_attr_analogInput_presentValue;
extern u8 zcl_attr_analogInput_reliability;
extern u8 zcl_attr_bininput_resolution;
extern u8 zcl_attr_analogInput_statusFlags;
extern u8 zcl_attr_analogInput_engineeringUnits;
extern u32 zcl_attr_analogInput_appType;

extern const zclAttrInfo_t analog_input_attrTbl[];
extern const u8 zcl_analog_input_attrNum;
#endif


status_t zcl_analog_input_register(u8 endpoint, u16 manuCode, u8 attrNum, const zclAttrInfo_t attrTbl[], cluster_forAppCb_t cb);

#endif  /* ZCL_ANALOG_INPUT_H */
