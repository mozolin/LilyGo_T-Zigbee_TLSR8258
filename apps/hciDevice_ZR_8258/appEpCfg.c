#if (__PROJECT_TL_GW__)

/**********************************************************************
 * INCLUDES
 */
#include "tl_common.h"
#include "zcl_include.h"
#include "main.h"

/**********************************************************************
 * LOCAL CONSTANTS
 */
#ifndef ZCL_BASIC_MFG_NAME
//#define ZCL_BASIC_MFG_NAME {6,'T','E','L','I','N','K'}
//-- LilyGo
#define ZCL_BASIC_MFG_NAME {6,'L','i','l','y','G','o'}
#endif
#ifndef ZCL_BASIC_MODEL_ID
//#define ZCL_BASIC_MODEL_ID {8,'T','L','S','R','8','2','x','x'}
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
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
/*
#ifdef ZCL_GROUP
    ZCL_CLUSTER_GEN_GROUPS,
#endif
#ifdef ZCL_SCENE
    ZCL_CLUSTER_GEN_SCENES,
#endif
#ifdef ZCL_ON_OFF
    ZCL_CLUSTER_GEN_ON_OFF,
#endif
#ifdef ZCL_LEVEL_CTRL
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
#endif
#ifdef ZCL_LIGHT_COLOR_CONTROL
    ZCL_CLUSTER_LIGHTING_COLOR_CONTROL,
#endif
*/
};


/**
 *  @brief Definition for Outgoing cluster / Client Cluster
 */
const u16 app_outClusterList[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
/*
#ifdef ZCL_GROUP
    ZCL_CLUSTER_GEN_GROUPS,
#endif
#ifdef ZCL_SCENE
    ZCL_CLUSTER_GEN_SCENES,
#endif
#ifdef ZCL_ON_OFF
    ZCL_CLUSTER_GEN_ON_OFF,
#endif
#ifdef ZCL_LEVEL_CTRL
    ZCL_CLUSTER_GEN_LEVEL_CONTROL,
#endif
#ifdef ZCL_LIGHT_COLOR_CONTROL
    ZCL_CLUSTER_LIGHTING_COLOR_CONTROL,
#endif
#ifdef ZCL_DOOR_LOCK
    ZCL_CLUSTER_CLOSURES_DOOR_LOCK,
#endif
#ifdef ZCL_TEMPERATURE_MEASUREMENT
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
#endif
#ifdef ZCL_IAS_ZONE
    ZCL_CLUSTER_SS_IAS_ZONE,
#endif
#ifdef ZCL_POLL_CTRL
    ZCL_CLUSTER_GEN_POLL_CONTROL,
#endif
*/
};

const u16 app_inClusterList2[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};
const u16 app_outClusterList2[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};

const u16 app_inClusterList3[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};
const u16 app_outClusterList3[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};

const u16 app_inClusterList4[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};
const u16 app_outClusterList4[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};

const u16 app_inClusterList5[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};
const u16 app_outClusterList5[] =
{
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
};


/**
 *  @brief Definition for Server cluster number and Client cluster number
 */
#define APPGW_IN_CLUSTER_NUM  (sizeof(app_inClusterList)/sizeof(app_inClusterList[0]))
#define APPGW_OUT_CLUSTER_NUM (sizeof(app_outClusterList)/sizeof(app_outClusterList[0]))

#define APPGW_IN_CLUSTER_NUM2  (sizeof(app_inClusterList2)/sizeof(app_inClusterList2[0]))
#define APPGW_OUT_CLUSTER_NUM2 (sizeof(app_outClusterList2)/sizeof(app_outClusterList2[0]))

#define APPGW_IN_CLUSTER_NUM3  (sizeof(app_inClusterList3)/sizeof(app_inClusterList3[0]))
#define APPGW_OUT_CLUSTER_NUM3 (sizeof(app_outClusterList3)/sizeof(app_outClusterList3[0]))

#define APPGW_IN_CLUSTER_NUM4  (sizeof(app_inClusterList4)/sizeof(app_inClusterList4[0]))
#define APPGW_OUT_CLUSTER_NUM4 (sizeof(app_outClusterList4)/sizeof(app_outClusterList4[0]))

#define APPGW_IN_CLUSTER_NUM5  (sizeof(app_inClusterList5)/sizeof(app_inClusterList5[0]))
#define APPGW_OUT_CLUSTER_NUM5 (sizeof(app_outClusterList5)/sizeof(app_outClusterList5[0]))


/**
 *  @brief Definition for simple description for HA profile
 */
const af_simple_descriptor_t app_simpleDesc =
{
    HA_PROFILE_ID,                  /* Application profile identifier */
    HA_DEV_TEMPERATURE_SENSOR, //HA_DEV_HOME_GATEWAY,            /* Application device identifier */
    APP_GW_ENDPOINT,             /* Endpoint */
    0,                              /* Application device version */
    0,                              /* Reserved */
    APPGW_IN_CLUSTER_NUM,        /* Application input cluster count */
    APPGW_OUT_CLUSTER_NUM,       /* Application output cluster count */
    (u16 *)app_inClusterList,  /* Application input cluster list */
    (u16 *)app_outClusterList, /* Application output cluster list */
};
const af_simple_descriptor_t app_simpleDesc2 =
{
    HA_PROFILE_ID,
    HA_DEV_TEMPERATURE_SENSOR, //HA_DEV_HOME_GATEWAY,
    APP_GW_ENDPOINT2,
    0,
    0,
    APPGW_IN_CLUSTER_NUM2,
    APPGW_OUT_CLUSTER_NUM2,
    (u16 *)app_inClusterList2,
    (u16 *)app_outClusterList2,
};
const af_simple_descriptor_t app_simpleDesc3 =
{
    HA_PROFILE_ID,
    HA_DEV_TEMPERATURE_SENSOR, //HA_DEV_HOME_GATEWAY,
    APP_GW_ENDPOINT3,
    0,
    0,
    APPGW_IN_CLUSTER_NUM3,
    APPGW_OUT_CLUSTER_NUM3,
    (u16 *)app_inClusterList3,
    (u16 *)app_outClusterList3,
};
const af_simple_descriptor_t app_simpleDesc4 =
{
    HA_PROFILE_ID,
    HA_DEV_TEMPERATURE_SENSOR, //HA_DEV_HOME_GATEWAY,
    APP_GW_ENDPOINT4,
    0,
    0,
    APPGW_IN_CLUSTER_NUM4,
    APPGW_OUT_CLUSTER_NUM4,
    (u16 *)app_inClusterList4,
    (u16 *)app_outClusterList4,
};
const af_simple_descriptor_t app_simpleDesc5 =
{
    HA_PROFILE_ID,
    HA_DEV_TEMPERATURE_SENSOR, //HA_DEV_HOME_GATEWAY,
    APP_GW_ENDPOINT5,
    0,
    0,
    APPGW_IN_CLUSTER_NUM5,
    APPGW_OUT_CLUSTER_NUM5,
    (u16 *)app_inClusterList5,
    (u16 *)app_outClusterList5,
};


/* Basic */
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


/* Identify */
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


#ifdef ZCL_GROUP
/* Group */
zcl_groupAttr_t g_zcl_groupAttrs =
{
    .nameSupport = 0,
};

const zclAttrInfo_t group_attrTbl[] =
{
    {
        ZCL_ATTRID_GROUP_NAME_SUPPORT,
        ZCL_DATA_TYPE_BITMAP8,
        ACCESS_CONTROL_READ,
        (u8*)&g_zcl_groupAttrs.nameSupport },

    {
        ZCL_ATTRID_GLOBAL_CLUSTER_REVISION,
        ZCL_DATA_TYPE_UINT16,
        ACCESS_CONTROL_READ,
        (u8*)&zcl_attr_global_clusterRevision
    },
};

#define ZCL_GROUP_ATTR_NUM sizeof(group_attrTbl) / sizeof(zclAttrInfo_t)
#endif



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
/*
#ifdef ZCL_GROUP
    {
        ZCL_CLUSTER_GEN_GROUPS,
        MANUFACTURER_CODE_NONE,
        0,
        NULL,
        zcl_group_register,
        app_groupCb
    },
#endif
#ifdef ZCL_SCENE
    {
        ZCL_CLUSTER_GEN_SCENES,
        MANUFACTURER_CODE_NONE,
        0,
        NULL,
        zcl_scene_register,
        app_sceneCb
    },
#endif
#ifdef ZCL_ON_OFF
    {
        ZCL_CLUSTER_GEN_ON_OFF,
        MANUFACTURER_CODE_NONE,
        ZCL_ONOFF_ATTR_NUM,
        onOff_attrTbl,
        zcl_onOff_register,
        sampleLight_onOffCb
    },
#endif
#ifdef ZCL_LEVEL_CTRL
    {
        ZCL_CLUSTER_GEN_LEVEL_CONTROL,
        MANUFACTURER_CODE_NONE,
        ZCL_LEVEL_ATTR_NUM,
        level_attrTbl,
        zcl_level_register,
        sampleLight_levelCb
    },
#endif
#ifdef ZCL_LIGHT_COLOR_CONTROL
    {
        ZCL_CLUSTER_LIGHTING_COLOR_CONTROL,
        MANUFACTURER_CODE_NONE,
        ZCL_COLOR_ATTR_NUM,
        lightColorCtrl_attrTbl,
        zcl_lightColorCtrl_register,
        sampleLight_colorCtrlCb
    },
#endif
#ifdef ZCL_DOOR_LOCK
    {
        ZCL_CLUSTER_CLOSURES_DOOR_LOCK,
        MANUFACTURER_CODE_NONE,
        0,
        NULL,
        zcl_doorLock_register,
        app_doorLockCb
    },
#endif
*/
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
/*
#ifdef ZCL_IAS_ZONE
    {
        ZCL_CLUSTER_SS_IAS_ZONE,
        MANUFACTURER_CODE_NONE,
        0,
        NULL,
        zcl_iasZone_register,
        app_iasZoneCb
    },
#endif
#ifdef ZCL_POLL_CTRL
    {
        ZCL_CLUSTER_GEN_POLL_CONTROL,
        MANUFACTURER_CODE_NONE,
        0,
        NULL,
        zcl_pollCtrl_register,
        app_pollCtrlCb},
#endif
*/
};

const zcl_specClusterInfo_t g_appClusterList2[] =
{
  {
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
    MANUFACTURER_CODE_NONE,
    0,
    NULL,
    zcl_temperature_measurement_register,
    NULL
  },
};

const zcl_specClusterInfo_t g_appClusterList3[] =
{
  {
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
    MANUFACTURER_CODE_NONE,
    0,
    NULL,
    zcl_temperature_measurement_register,
    NULL
  },
};

const zcl_specClusterInfo_t g_appClusterList4[] =
{
  {
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
    MANUFACTURER_CODE_NONE,
    0,
    NULL,
    zcl_temperature_measurement_register,
    NULL
  },
};

const zcl_specClusterInfo_t g_appClusterList5[] =
{
  {
    ZCL_CLUSTER_MS_TEMPERATURE_MEASUREMENT,
    MANUFACTURER_CODE_NONE,
    0,
    NULL,
    zcl_temperature_measurement_register,
    NULL
  },
};


u8 APP_GW_CB_CLUSTER_NUM  = (sizeof(g_appClusterList)/sizeof(g_appClusterList[0]));
u8 APP_GW_CB_CLUSTER_NUM2 = (sizeof(g_appClusterList2)/sizeof(g_appClusterList2[0]));
u8 APP_GW_CB_CLUSTER_NUM3 = (sizeof(g_appClusterList3)/sizeof(g_appClusterList3[0]));
u8 APP_GW_CB_CLUSTER_NUM4 = (sizeof(g_appClusterList4)/sizeof(g_appClusterList4[0]));
u8 APP_GW_CB_CLUSTER_NUM5 = (sizeof(g_appClusterList5)/sizeof(g_appClusterList5[0]));


/**********************************************************************
 * FUNCTIONS
 */


#endif    /* __PROJECT_TL_GW__ */
