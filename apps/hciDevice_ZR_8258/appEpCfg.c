#if (__PROJECT_TL_GW__)

/**********************************************************************
 * INCLUDES
 */
#include "tl_common.h"
#include "zcl_include.h"
#include "main.h"

#include "zb_custom/zb_custom.h"

/**********************************************************************
 * LOCAL CONSTANTS
 */
#ifndef ZCL_BASIC_MFG_NAME
//-- LilyGo
#define ZCL_BASIC_MFG_NAME {6,'L','i','l','y','G','o'}
#endif
#ifndef ZCL_BASIC_MODEL_ID
//-- APP.ESP32-C3
#define ZCL_BASIC_MODEL_ID {13,'M','I','K','E','.','E','S','P','3','2','-','C','3'}
#endif


/**********************************************************************
 * TYPEDEFS
 */


/**********************************************************************
 * GLOBAL VARIABLES
 */
/**
 *  @brief Definition for Incoming cluster / Sever Cluster
 */
const u16 app_inClusterList[] =
{
  ZCL_CLUSTER_GEN_BASIC,
  ZCL_CLUSTER_GEN_IDENTIFY,
  #ifdef ZCL_OTA
    ZCL_CLUSTER_OTA,
  #endif
  #ifdef ZCL_TEMPERATURE_MEASUREMENT
    //-- address = 0x0402
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
  #endif
  #ifdef ZCL_RELATIVE_HUMIDITY_MEASUREMENT
    //-- address = 0x0405
    ZCL_CLUSTER_MS_RELATIVE_HUMIDITY,
  #endif
  #ifdef ZCL_PRESSURE_MEASUREMENT
    //-- address = 0x0403
    ZCL_CLUSTER_MS_PRESSURE_MEASUREMENT,
  #endif
  #ifdef ZCL_ILLUMINANCE_MEASUREMENT
    //-- address = 0x0400
    ZCL_CLUSTER_MS_ILLUMINANCE_MEASUREMENT,
  #endif
  #ifdef ZCL_OCCUPANCY_SENSING
    //-- address = 0x0406
	  ZCL_CLUSTER_MS_OCCUPANCY_SENSING,
  #endif
  #ifdef ZCL_CO2_MEASUREMENT
    //-- address = 0x040D
    ZCL_CLUSTER_MS_CO2,
  #endif
};


/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const u16 app_outClusterList[] =
{
};

const u16 app_inClusterListExtra[] =
{
  #ifdef ZCL_TEMPERATURE_MEASUREMENT
    //-- address = 0x0402
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
  #endif
  #ifdef ZCL_RELATIVE_HUMIDITY_MEASUREMENT
    //-- address = 0x0405
    ZCL_CLUSTER_MS_RELATIVE_HUMIDITY,
  #endif
  #ifdef ZCL_PRESSURE_MEASUREMENT
    //-- address = 0x0403
    ZCL_CLUSTER_MS_PRESSURE_MEASUREMENT,
  #endif
  #ifdef ZCL_ILLUMINANCE_MEASUREMENT
    //-- address = 0x0400
    ZCL_CLUSTER_MS_ILLUMINANCE_MEASUREMENT,
  #endif
  #ifdef ZCL_OCCUPANCY_SENSING
    //-- address = 0x0406
	  ZCL_CLUSTER_MS_OCCUPANCY_SENSING,
  #endif
  #ifdef ZCL_CO2_MEASUREMENT
    //-- address = 0x040D
    ZCL_CLUSTER_MS_CO2,
  #endif
};
const u16 app_outClusterListExtra[] =
{
};


/**
 *  @brief Definition for Server cluster number and Client cluster number
 */
#define APPGW_IN_CLUSTER_NUM  (sizeof(app_inClusterList)/sizeof(app_inClusterList[0]))
#define APPGW_OUT_CLUSTER_NUM (sizeof(app_outClusterList)/sizeof(app_outClusterList[0]))

#define APPGW_IN_CLUSTER_NUM_EXTRA  (sizeof(app_inClusterListExtra)/sizeof(app_inClusterListExtra[0]))
#define APPGW_OUT_CLUSTER_NUM_EXTRA (sizeof(app_outClusterListExtra)/sizeof(app_outClusterListExtra[0]))

/**
 *  @brief Definition for simple description for HA profile
 */
const af_simple_descriptor_t app_simpleDesc =
{
  //-- Application profile identifier
  HA_PROFILE_ID,
  //-- Application device identifier
  HA_DEV_HOME_GATEWAY,
  //-- Endpoint
  APP_GW_ENDPOINT,
  //-- Application device version
  0,
  //-- Reserved
  0,
  //-- Application input cluster count
  APPGW_IN_CLUSTER_NUM,
  //-- Application output cluster count
  APPGW_OUT_CLUSTER_NUM,
  //-- Application input cluster list
  (u16 *)app_inClusterList,
  //-- Application output cluster list
  (u16 *)app_outClusterList,
};
const af_simple_descriptor_t app_simpleDesc2 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT2,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc3 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT3,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc4 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT4,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc5 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT5,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc6 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT6,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc7 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT7,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc8 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT8,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc9 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT9,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};
const af_simple_descriptor_t app_simpleDesc10 =
{
  HA_PROFILE_ID,
  HA_DEV_HOME_GATEWAY,
  APP_GW_ENDPOINT10,
  0,
  0,
  APPGW_IN_CLUSTER_NUM_EXTRA,
  APPGW_OUT_CLUSTER_NUM_EXTRA,
  (u16 *)app_inClusterListExtra,
  (u16 *)app_outClusterListExtra,
};


//-- Basic
zcl_basicAttr_t g_zcl_basicAttrs =
{
  .zclVersion   = 0x03,
  .appVersion   = 0x00,
  .stackVersion = 0x02,
  .hwVersion    = 0x00,
  .manuName     = ZCL_BASIC_MFG_NAME,
  .modelId      = ZCL_BASIC_MODEL_ID,
  .powerSource  = POWER_SOURCE_MAINS_1_PHASE,
  .deviceEnable = TRUE,
};

const zclAttrInfo_t basic_attrTbl[] =
{
  {
    ZCL_ATTRID_BASIC_ZCL_VER,
    ZCL_DATA_TYPE_UINT8,
    ACCESS_CONTROL_READ,
    (u8*)&g_zcl_basicAttrs.zclVersion
  },
  {
    ZCL_ATTRID_BASIC_APP_VER,
    ZCL_DATA_TYPE_UINT8,
    ACCESS_CONTROL_READ,
    (u8*)&g_zcl_basicAttrs.appVersion
  },
  {
    ZCL_ATTRID_BASIC_STACK_VER,
    ZCL_DATA_TYPE_UINT8,
    ACCESS_CONTROL_READ,
    (u8*)&g_zcl_basicAttrs.stackVersion
  },
  {
    ZCL_ATTRID_BASIC_HW_VER,
    ZCL_DATA_TYPE_UINT8,
    ACCESS_CONTROL_READ,
    (u8*)&g_zcl_basicAttrs.hwVersion
  },
  {
    ZCL_ATTRID_BASIC_MFR_NAME,
    ZCL_DATA_TYPE_CHAR_STR,
    ACCESS_CONTROL_READ,
    (u8*)g_zcl_basicAttrs.manuName
  },
  {
    ZCL_ATTRID_BASIC_MODEL_ID,
    ZCL_DATA_TYPE_CHAR_STR,
    ACCESS_CONTROL_READ,
    (u8*)g_zcl_basicAttrs.modelId
  },
  {
    ZCL_ATTRID_BASIC_POWER_SOURCE,
    ZCL_DATA_TYPE_ENUM8,
    ACCESS_CONTROL_READ,
    (u8*)&g_zcl_basicAttrs.powerSource
  },
  {
    ZCL_ATTRID_BASIC_DEV_ENABLED,
    ZCL_DATA_TYPE_BOOLEAN,
    ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,
    (u8*)&g_zcl_basicAttrs.deviceEnable
  },

  {
    ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,
    ZCL_DATA_TYPE_UINT16,
    ACCESS_CONTROL_READ,
    (u8*)&zcl_attr_global_clusterRevision
  },
};

#define ZCL_BASIC_ATTR_NUM sizeof(basic_attrTbl) / sizeof(zclAttrInfo_t)


//-- Identify
zcl_identifyAttr_t g_zcl_identifyAttrs =
{
  .identifyTime = 0x0000,
};

const zclAttrInfo_t identify_attrTbl[] =
{
  {
    ZCL_ATTRID_IDENTIFY_TIME,
    ZCL_DATA_TYPE_UINT16,
    ACCESS_CONTROL_READ | ACCESS_CONTROL_WRITE,
    (u8*)&g_zcl_identifyAttrs.identifyTime
  },

  {
    ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,
    ZCL_DATA_TYPE_UINT16,
    ACCESS_CONTROL_READ,
    (u8*)&zcl_attr_global_clusterRevision
  },
};

#define ZCL_IDENTIFY_ATTR_NUM sizeof(identify_attrTbl) / sizeof(zclAttrInfo_t)

/**
 *  @brief Definition for simple GW ZCL specific cluster
 */
const zcl_specClusterInfo_t g_appClusterList[] =
{
  {
    ZCL_CLUSTER_GEN_BASIC,
    MANUFACTURER_CODE_NONE,
    ZCL_BASIC_ATTR_NUM,
    basic_attrTbl,
    zcl_basic_register,
    app_basicCb
  },
  {
    ZCL_CLUSTER_GEN_IDENTIFY,
    MANUFACTURER_CODE_NONE,
    ZCL_IDENTIFY_ATTR_NUM,
    identify_attrTbl,
    zcl_identify_register,
    app_identifyCb
  },
  #ifdef ZCL_TEMPERATURE_MEASUREMENT
    {
      ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_temperature_measurement_register,
      NULL
    },
  #endif
  #ifdef ZCL_RELATIVE_HUMIDITY_MEASUREMENT
    {
      //-- address = 0x0405
      ZCL_CLUSTER_MS_RELATIVE_HUMIDITY,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_humidity_measurement_register,
      NULL
    },
  #endif
  #ifdef ZCL_PRESSURE_MEASUREMENT
    {
      //-- address = 0x0403
      ZCL_CLUSTER_MS_PRESSURE_MEASUREMENT,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_pressure_measurement_register,
      NULL
    },
  #endif
  #ifdef ZCL_ILLUMINANCE_MEASUREMENT
    {
      //-- address = 0x0400
      ZCL_CLUSTER_MS_ILLUMINANCE_MEASUREMENT,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_illuminanceMeasure_register,
      NULL
    },
  #endif
  #ifdef ZCL_OCCUPANCY_SENSING
    {
      //-- address = 0x0406
      ZCL_CLUSTER_MS_OCCUPANCY_SENSING,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_occupancySensing_register,
      NULL
    },
  #endif
  #ifdef ZCL_CO2_MEASUREMENT
    {
      //-- address = 0x040D
      ZCL_CLUSTER_MS_CO2,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_co2_measurement_register,
      NULL
    },
  #endif
};

const zcl_specClusterInfo_t g_appClusterListExtra[] =
{
  #ifdef ZCL_TEMPERATURE_MEASUREMENT
    {
      ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_temperature_measurement_register,
      NULL
    },
  #endif
  #ifdef ZCL_RELATIVE_HUMIDITY_MEASUREMENT
    {
      //-- address = 0x0405
      ZCL_CLUSTER_MS_RELATIVE_HUMIDITY,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_humidity_measurement_register,
      NULL
    },
  #endif
  #ifdef ZCL_PRESSURE_MEASUREMENT
    {
      //-- address = 0x0403
      ZCL_CLUSTER_MS_PRESSURE_MEASUREMENT,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_pressure_measurement_register,
      NULL
    },
  #endif
  #ifdef ZCL_ILLUMINANCE_MEASUREMENT
    {
      //-- address = 0x0400
      ZCL_CLUSTER_MS_ILLUMINANCE_MEASUREMENT,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_illuminanceMeasure_register,
      NULL
    },
  #endif
  #ifdef ZCL_OCCUPANCY_SENSING
    {
      //-- address = 0x0406
      ZCL_CLUSTER_MS_OCCUPANCY_SENSING,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_occupancySensing_register,
      NULL
    },
  #endif
  #ifdef ZCL_CO2_MEASUREMENT
    {
      //-- address = 0x040D
      ZCL_CLUSTER_MS_CO2,
      MANUFACTURER_CODE_NONE,
      0,
      NULL,
      zcl_co2_measurement_register,
      NULL
    },
  #endif
};

u8 APP_GW_CB_CLUSTER_NUM  = (sizeof(g_appClusterList)/sizeof(g_appClusterList[0]));
u8 APP_GW_CB_CLUSTER_NUM_EXTRA = (sizeof(g_appClusterListExtra)/sizeof(g_appClusterListExtra[0]));


/**********************************************************************
 * FUNCTIONS
 */

//-- __PROJECT_TL_GW__
#endif
