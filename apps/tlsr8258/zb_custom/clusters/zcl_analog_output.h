/********************************************************************************************************
 * @file  zcl_analog_output.h
 *******************************************************************************************************/
#ifndef ZCL_ANALOG_OUTPUT_H
#define ZCL_ANALOG_OUTPUT_H



/*********************************************************************
 * CONSTANTS
 */

/**
 *  @brief  analog output cluster Attribute IDs
 */
#define ZCL_ANALOG_OUTPUT_ATTRID_DESCRIPTION           0x001C
#define ZCL_ANALOG_OUTPUT_ATTRID_MAX_PRESENT_VALUE     0x0041
#define ZCL_ANALOG_OUTPUT_ATTRID_MIN_PRESENT_VALUE     0x0045
#define ZCL_ANALOG_OUTPUT_ATTRID_OUT_OF_SERVICE        0x0051
#define ZCL_ANALOG_OUTPUT_ATTRID_PRESENT_VALUE         0x0055
#define ZCL_ANALOG_OUTPUT_ATTRID_PRIORITY_ARRAY   		 0x0057
#define ZCL_ANALOG_OUTPUT_ATTRID_RELIABILITY           0x0067
#define ZCL_ANALOG_OUTPUT_ATTRID_RELINQUISH_DEFAULT    0x0068
#define ZCL_ANALOG_OUTPUT_ATTRID_RESOLUTION            0x006A
#define ZCL_ANALOG_OUTPUT_ATTRID_STATUS_FLAGS          0x006F
#define ZCL_ANALOG_OUTPUT_ATTRID_ENGINEERING_UNITS     0x0075
#define ZCL_ANALOG_OUTPUT_ATTRID_APP_TYPE              0x0100

/**
 *  @brief Max length of char string
 */
#define ZCL_ANALOG_OUTPUT_MAX_LENGTH             24

typedef struct {
	bool priority1;
	bool priority2;
} zcl_analogOutput_priorityArray_t;


#if 0
extern u8 zcl_attr_analogOutput_description[];
extern u16 zcl_attr_analogOutput_maxPresentValue;
extern u16 zcl_attr_analogOutput_minPresentValue;
extern bool zcl_attr_analogOutput_outOfService;
extern u16 zcl_attr_analogOutput_presentValue;
extern zcl_analogOutput_priorityArray_t zcl_attr_binOutput_priorityArray[];
extern u8 zcl_attr_analogOutput_reliability;
extern bool zcl_attr_analogOutput_relinquishDefault
extern u8 zcl_attr_binoutput_resolution;
extern u8 zcl_attr_analogOutput_statusFlags;
extern u8 zcl_attr_analogOutput_engineeringUnits;
extern u32 zcl_attr_analogOutput_appType;

extern const zclAttrInfo_t analog_output_attrTbl[];
extern const u8 zcl_analog_output_attrNum;
#endif


status_t zcl_analog_output_register(u8 endpoint, u16 manuCode, u8 attrNum, const zclAttrInfo_t attrTbl[], cluster_forAppCb_t cb);

#endif  /* ZCL_ANALOG_OUTPUT_H */
