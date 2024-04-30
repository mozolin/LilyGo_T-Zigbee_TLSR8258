#ifndef _APP_GW_H_
#define _APP_GW_H_


//------------------------------------------------
// sets ZCL_BASIC_MODEL_ID to:
//   - "MIKE.ESP32-C3"   (MIKE_BOARD_NUMBER = 1)
//   - "MIKE.ESP32-C3-2" (MIKE_BOARD_NUMBER = 2)
//------------------------------------------------
#define MIKE_BOARD_NUMBER   2


/**********************************************************************
 * CONSTANT
 */
#define APP_GW_ENDPOINT     1
#define APP_GW_ENDPOINT2    2
#define APP_GW_ENDPOINT3    3
#define APP_GW_ENDPOINT4    4
#define APP_GW_ENDPOINT5    5
#define APP_GW_ENDPOINT6    6
#define APP_GW_ENDPOINT7    7
#define APP_GW_ENDPOINT8    8
#define APP_GW_ENDPOINT9    9
#define APP_GW_ENDPOINT10   10

/**********************************************************************
 * TYPEDEFS
 */
typedef struct{
  ev_timer_event_t *timerLedEvt;
  u32 keyPressedTime;

  u16 ledOnTime;
  u16 ledOffTime;
  u8  oriSta;    //original state before blink
  u8  sta;       //current state in blink
  u8  times;     //blink times
  u8  state;
  u8  keyPressed;
}app_ctx_t;

/**
 *  @brief Defined for basic cluster attributes
 */
typedef struct{
  u8  zclVersion;
  u8  appVersion;
  u8  stackVersion;
  u8  hwVersion;
  u8  manuName[ZCL_BASIC_MAX_LENGTH];
  u8  modelId[ZCL_BASIC_MAX_LENGTH];
  u8  powerSource;
  u8  deviceEnable;
}zcl_basicAttr_t;

/**
 *  @brief Defined for identify cluster attributes
 */
typedef struct{
  u16  identifyTime;
}zcl_identifyAttr_t;

/**
 *  @brief Defined for group cluster attributes
 */
typedef struct{
  u8  nameSupport;
}zcl_groupAttr_t;

/**********************************************************************
 * GLOBAL VARIABLES
 */
extern app_ctx_t g_appGwCtx;

extern bdb_appCb_t g_zbDemoBdbCb;

extern u8 APP_GW_CB_CLUSTER_NUM;
extern u8 APP_GW_CB_CLUSTER_NUM_EXTRA;

extern const zcl_specClusterInfo_t g_appClusterList[];
extern const zcl_specClusterInfo_t g_appClusterListExtra[];

extern const af_simple_descriptor_t app_simpleDesc;
extern const af_simple_descriptor_t app_simpleDesc2;
extern const af_simple_descriptor_t app_simpleDesc3;
extern const af_simple_descriptor_t app_simpleDesc4;
extern const af_simple_descriptor_t app_simpleDesc5;
extern const af_simple_descriptor_t app_simpleDesc6;
extern const af_simple_descriptor_t app_simpleDesc7;
extern const af_simple_descriptor_t app_simpleDesc8;
extern const af_simple_descriptor_t app_simpleDesc9;
extern const af_simple_descriptor_t app_simpleDesc10;

/* Attributes */
extern zcl_basicAttr_t g_zcl_basicAttrs;
extern zcl_identifyAttr_t g_zcl_identifyAttrs;

/**********************************************************************
 * FUNCTIONS
 */
void app_zclProcessIncomingMsg(zclIncoming_t *pInHdlrMsg);

status_t app_basicCb(zclIncomingAddrInfo_t *pAddrInfo, u8 cmdId, void *cmdPayload);
status_t app_identifyCb(zclIncomingAddrInfo_t *pAddrInfo, u8 cmdId, void *cmdPayload);

void app_devAnnHandler(zdo_device_annce_req_t *pDevAnnceReq);
void app_leaveCnfHandler(nlme_leave_cnf_t *pLeaveCnf);
void app_leaveIndHandler(nlme_leave_ind_t *pLeaveInd);
bool app_nwkUpdateIndicateHandler(nwkCmd_nwkUpdate_t *pNwkUpdateCmd);
bool app_tcJoinIndHandler(zdo_tc_join_ind_t *pTcJoinInd);
void app_tcFrameCntReachedHandler(void);
void app_dataSendConfirm(void *arg);

#endif /* _APP_GW_H_ */
