#if (__PROJECT_TL_GW__)

/**********************************************************************
 * INCLUDES
 */
#include "tl_common.h"
#include "zb_api.h"
#include "zcl_include.h"
#include "main.h"
#include "app_ui.h"
#if ZBHCI_EN
#include "zbhci.h"
#endif

/**********************************************************************
 * LOCAL CONSTANTS
 */



/**********************************************************************
 * TYPEDEFS
 */


/**********************************************************************
 * LOCAL FUNCTIONS
 */
#ifdef ZCL_READ
static void app_zclReadRspCmd(zclIncoming_t *pInHdlrMsg);
#endif
#ifdef ZCL_WRITE
static void app_zclWriteReqCmd(zclIncoming_t *pInMsg);
static void app_zclWriteRspCmd(zclIncoming_t *pInMsg);
#endif
//#ifdef ZCL_REPORT
static void app_zclCfgReportCmd(zclIncoming_t *pInMsg);
static void app_zclCfgReportRspCmd(zclIncoming_t *pInHdlrMsg);
static void app_zclReportCmd(zclIncoming_t *pInMsg);
static void app_zclCfgReadRspCmd(zclIncoming_t *pInHdlrMsg);
//#endif
static void app_zclDfltRspCmd(zclIncoming_t *pInHdlrMsg);

/**********************************************************************
 * GLOBAL VARIABLES
 */


/**********************************************************************
 * LOCAL VARIABLES
 */
#ifdef ZCL_IDENTIFY
static ev_timer_event_t *identifyTimerEvt = NULL;
#endif


/**********************************************************************
 * FUNCTIONS
 */

/*********************************************************************
 * @fn      app_zclProcessIncomingMsg
 *
 * @brief   Process ZCL Foundation incoming message.
 *
 * @param   pInMsg - pointer to the received message
 *
 * @return  None
 */
void app_zclProcessIncomingMsg(zclIncoming_t *pInHdlrMsg)
{
  printf("Process ZCL Foundation incoming message.\n");

  switch(pInHdlrMsg->hdr.cmd)
  {
#ifdef ZCL_READ
    case ZCL_CMD_READ_RSP:
      printf("Process ZCL Read RSP\n");
      app_zclReadRspCmd(pInHdlrMsg);
      break;
#endif
#ifdef ZCL_WRITE
    case ZCL_CMD_WRITE:
        case ZCL_CMD_WRITE_NO_RSP:
      app_zclWriteReqCmd(pInHdlrMsg);
      break;
    case ZCL_CMD_WRITE_RSP:
      printf("Process ZCL Write RSP\n");
      app_zclWriteRspCmd(pInHdlrMsg);
      break;
#endif
//#ifdef ZCL_REPORT
    case ZCL_CMD_CONFIG_REPORT:
      printf("Process ZCL Config REPORT\n");
      app_zclCfgReportCmd(pInHdlrMsg);
      break;
    case ZCL_CMD_CONFIG_REPORT_RSP:
      printf("Process ZCL Config RSP\n");
      app_zclCfgReportRspCmd(pInHdlrMsg);
      break;
    case ZCL_CMD_READ_REPORT_CFG_RSP:
      printf("Process ZCL Read Report Config RSP\n");
      app_zclCfgReadRspCmd(pInHdlrMsg);
      break;
    case ZCL_CMD_REPORT:
      printf("Process ZCL Report\n");
      app_zclReportCmd(pInHdlrMsg);
      break;
//#endif
    case ZCL_CMD_DEFAULT_RSP:
      printf("Process ZCL Default Report\n");
      app_zclDfltRspCmd(pInHdlrMsg);
      break;
    default:
      printf("Unknown ZCL command\n");
      break;
  }
}

#ifdef ZCL_READ
/*********************************************************************
 * @fn      app_zclReadRspCmd
 *
 * @brief   Handler for ZCL Read Response command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */
static void app_zclReadRspCmd(zclIncoming_t *pInHdlrMsg)
{
#if ZBHCI_EN
  u8 array[64] = { 0 };
  u16 dataLen = 0;
  u8 *pBuf = array;

  zclReadRspCmd_t *pReadRspCmd = (zclReadRspCmd_t *)pInHdlrMsg->attrCmd;

  *pBuf++ = pInHdlrMsg->hdr.seqNum;
  *pBuf++ = HI_UINT16(pInHdlrMsg->msg->indInfo.src_short_addr);
  *pBuf++ = LO_UINT16(pInHdlrMsg->msg->indInfo.src_short_addr);
  *pBuf++ = pInHdlrMsg->msg->indInfo.src_ep;
  *pBuf++ = HI_UINT16(pInHdlrMsg->msg->indInfo.cluster_id);
  *pBuf++ = LO_UINT16(pInHdlrMsg->msg->indInfo.cluster_id);
  *pBuf++ = pReadRspCmd->numAttr;
  for(u8 i = 0; i < pReadRspCmd->numAttr; i++){
    *pBuf++ = HI_UINT16(pReadRspCmd->attrList[i].attrID);
    *pBuf++ = LO_UINT16(pReadRspCmd->attrList[i].attrID);
    *pBuf++ = pReadRspCmd->attrList[i].status;
    if(pReadRspCmd->attrList[i].status == ZCL_STA_SUCCESS){
      *pBuf++ = pReadRspCmd->attrList[i].dataType;
      dataLen = zcl_getAttrSize(pReadRspCmd->attrList[i].dataType, pReadRspCmd->attrList[i].data);
      memcpy(pBuf, pReadRspCmd->attrList[i].data, dataLen);
      if( (pReadRspCmd->attrList[i].dataType != ZCL_DATA_TYPE_LONG_CHAR_STR) && \
        (pReadRspCmd->attrList[i].dataType != ZCL_DATA_TYPE_LONG_OCTET_STR) &&
        (pReadRspCmd->attrList[i].dataType != ZCL_DATA_TYPE_CHAR_STR) && \
        (pReadRspCmd->attrList[i].dataType != ZCL_DATA_TYPE_OCTET_STR) &&
        (pReadRspCmd->attrList[i].dataType != ZCL_DATA_TYPE_STRUCT) ){
          ZB_LEBESWAP(pBuf, dataLen);
      }
      pBuf += dataLen;
    }
  }

  zbhciTx(ZBHCI_CMD_ZCL_ATTR_READ_RSP, pBuf - array, array);
#endif
}
#endif  /* ZCL_READ */

#ifdef ZCL_WRITE
/*********************************************************************
 * @fn      app_zclWriteReqCmd
 *
 * @brief   Handler for ZCL Write Req command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */
static void app_zclWriteReqCmd(zclIncoming_t *pInMsg)
{
#if ZBHCI_EN
    u8 array[64] = { 0 };
    u8 *pBuf = array;
    u8 dataLen = 0;

    zclWriteCmd_t *pWriteReq = (zclWriteCmd_t *)pInMsg->attrCmd;

    // SQN
    *pBuf++ = pInMsg->hdr.seqNum;
    // dst addr mode
    *pBuf++ = pInMsg->msg->indInfo.dst_addr_mode;
    // dst addr
    *pBuf++ = HI_UINT16(pInMsg->msg->indInfo.dst_addr);
    *pBuf++ = LO_UINT16(pInMsg->msg->indInfo.dst_addr);
    // dst ep
    *pBuf++ = pInMsg->msg->indInfo.dst_ep;
    // cluster id
    *pBuf++ = HI_UINT16(pInMsg->msg->indInfo.cluster_id);
    *pBuf++ = LO_UINT16(pInMsg->msg->indInfo.cluster_id);
    // num Attr
    *pBuf++ = pWriteReq->numAttr;

    for (u8 i = 0; i < pWriteReq->numAttr; i++) {
        // attr id
        *pBuf++ = HI_UINT16(pWriteReq->attrList[i].attrID);
        *pBuf++ = LO_UINT16(pWriteReq->attrList[i].attrID);
        // type
        *pBuf++ = pWriteReq->attrList[i].dataType;
        // data
        dataLen = zcl_getAttrSize(pWriteReq->attrList[i].dataType, pWriteReq->attrList[i].attrData);
        memcpy(pBuf, pWriteReq->attrList[i].attrData, dataLen);
        if((pWriteReq->attrList[i].dataType != ZCL_DATA_TYPE_LONG_CHAR_STR)  && \
           (pWriteReq->attrList[i].dataType != ZCL_DATA_TYPE_LONG_OCTET_STR) && \
           (pWriteReq->attrList[i].dataType != ZCL_DATA_TYPE_CHAR_STR)       && \
           (pWriteReq->attrList[i].dataType != ZCL_DATA_TYPE_OCTET_STR)      && \
           (pWriteReq->attrList[i].dataType != ZCL_DATA_TYPE_STRUCT)) {
            ZB_LEBESWAP(pBuf, dataLen);
        }
        pBuf += dataLen;
    }

    zbhciTx(ZBHCI_CMD_ZCL_ATTR_WRITE_RCV, pBuf - array, array);
#endif
}

/*********************************************************************
 * @fn      app_zclWriteRspCmd
 *
 * @brief   Handler for ZCL Write Response command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */
static void app_zclWriteRspCmd(zclIncoming_t *pInMsg)
{
#if ZBHCI_EN
  u8 array[64];
  memset(array, 0, 64);

  u8 *pBuf = array;
  zclWriteRspCmd_t *pWriteRsp = (zclWriteRspCmd_t *)pInMsg->attrCmd;

  *pBuf++ = pInMsg->hdr.seqNum;
  *pBuf++ = HI_UINT16(pInMsg->msg->indInfo.src_short_addr);
  *pBuf++ = LO_UINT16(pInMsg->msg->indInfo.src_short_addr);
  *pBuf++ = pInMsg->msg->indInfo.src_ep;
  *pBuf++ = HI_UINT16(pInMsg->msg->indInfo.cluster_id);
  *pBuf++ = LO_UINT16(pInMsg->msg->indInfo.cluster_id);
  *pBuf++ = pWriteRsp->numAttr;

  if(pInMsg->dataLen == 1){//the case of successful writing of all attributes
    *pBuf++ = pWriteRsp->attrList[0].status;
    *pBuf++ = 0xFF;
    *pBuf++ = 0xFF;
  }else{
    for(u8 i = 0; i < pWriteRsp->numAttr; i++){
      *pBuf++ = pWriteRsp->attrList[i].status;
      *pBuf++ = HI_UINT16(pWriteRsp->attrList[i].attrID);
      *pBuf++ = LO_UINT16(pWriteRsp->attrList[i].attrID);
    }
  }

  zbhciTx(ZBHCI_CMD_ZCL_ATTR_WRITE_RSP, pBuf - array, array);
#endif
}
#endif  /* ZCL_WRITE */

/*********************************************************************
 * @fn      app_zclDfltRspCmd
 *
 * @brief   Handler for ZCL Default Response command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */
static void app_zclDfltRspCmd(zclIncoming_t *pInHdlrMsg)
{
}

//#ifdef ZCL_REPORT
/*********************************************************************
 * @fn      app_zclCfgReportCmd
 *
 * @brief   Handler for ZCL Configure Report command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */
static void app_zclCfgReportCmd(zclIncoming_t *pInMsg)
{
}

/*********************************************************************
 * @fn      app_zclCfgReportRspCmd
 *
 * @brief   Handler for ZCL Configure Report Response command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */
static void app_zclCfgReportRspCmd(zclIncoming_t *pInHdlrMsg)
{
#if ZBHCI_EN
  u8 array[64] = { 0 };
  u8 *pBuf = array;

  zclCfgReportRspCmd_t *pCfgReportRspCmd = (zclCfgReportRspCmd_t *)pInHdlrMsg->attrCmd;

  *pBuf++ = pInHdlrMsg->hdr.seqNum;
  *pBuf++ = HI_UINT16(pInHdlrMsg->msg->indInfo.src_short_addr);
  *pBuf++ = LO_UINT16(pInHdlrMsg->msg->indInfo.src_short_addr);
  *pBuf++ = pInHdlrMsg->msg->indInfo.src_ep;
  *pBuf++ = HI_UINT16(pInHdlrMsg->msg->indInfo.cluster_id);
  *pBuf++ = LO_UINT16(pInHdlrMsg->msg->indInfo.cluster_id);
  *pBuf++ = pCfgReportRspCmd->numAttr;

  for(u8 i = 0; i < pCfgReportRspCmd->numAttr; i++){
    *pBuf++ = pCfgReportRspCmd->attrList[i].status;
    *pBuf++ = pCfgReportRspCmd->attrList[i].direction;
    *pBuf++ = HI_UINT16(pCfgReportRspCmd->attrList[i].attrID);
    *pBuf++ = LO_UINT16(pCfgReportRspCmd->attrList[i].attrID);
  }

  zbhciTx(ZBHCI_CMD_ZCL_CONFIG_REPORT_RSP, pBuf - array, array);
#endif
}

/*********************************************************************
 * @fn      app_zclReportCmd
 *
 * @brief   Handler for ZCL Report command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */
static void app_zclReportCmd(zclIncoming_t *pInMsg)
{
//    printf("app_zclReportCmd\n");
#if ZBHCI_EN
  zclReportCmd_t *pReportCmd = (zclReportCmd_t *)pInMsg->attrCmd;

  u8 array[64];
  memset(array, 0, 64);

  u16 dataLen = 0;
  u8 *pBuf = array;

  *pBuf++ = pInMsg->hdr.seqNum;
  *pBuf++ = HI_UINT16(pInMsg->msg->indInfo.src_short_addr);
  *pBuf++ = LO_UINT16(pInMsg->msg->indInfo.src_short_addr);
  *pBuf++ = pInMsg->msg->indInfo.src_ep;
  *pBuf++ = HI_UINT16(pInMsg->msg->indInfo.cluster_id);
  *pBuf++ = LO_UINT16(pInMsg->msg->indInfo.cluster_id);

  *pBuf++ = pReportCmd->numAttr;
  for(u8 i = 0; i < pReportCmd->numAttr; i++){
    *pBuf++ = HI_UINT16(pReportCmd->attrList[i].attrID);
    *pBuf++ = LO_UINT16(pReportCmd->attrList[i].attrID);
    *pBuf++ = pReportCmd->attrList[i].dataType;
    dataLen = zcl_getAttrSize(pReportCmd->attrList[i].dataType, pReportCmd->attrList[i].attrData);
    memcpy(pBuf, pReportCmd->attrList[i].attrData, dataLen);
    if( (pReportCmd->attrList[i].dataType != ZCL_DATA_TYPE_LONG_CHAR_STR) && (pReportCmd->attrList[i].dataType != ZCL_DATA_TYPE_LONG_OCTET_STR) &&
      (pReportCmd->attrList[i].dataType != ZCL_DATA_TYPE_CHAR_STR) && (pReportCmd->attrList[i].dataType != ZCL_DATA_TYPE_OCTET_STR) &&
      (pReportCmd->attrList[i].dataType != ZCL_DATA_TYPE_STRUCT) ){
        ZB_LEBESWAP(pBuf, dataLen);
    }
    pBuf += dataLen;
  }

  zbhciTx(ZBHCI_CMD_ZCL_REPORT_MSG_RCV, pBuf - array, array);
#endif
}

/*********************************************************************
 * @fn      app_zclCfgReadRspCmd
 *
 * @brief   Handler for ZCL Report Configure Read command.
 *
 * @param   pInHdlrMsg - incoming message to process
 *
 * @return  None
 */

static void app_zclCfgReadRspCmd(zclIncoming_t *pInHdlrMsg)
{
#if ZBHCI_EN
  u8 array[64] = { 0 };
  u16 dataLen = 0;
  u8 *pBuf = array;

  zclReadReportCfgRspCmd_t *pReadCfgRspCmd = (zclReadReportCfgRspCmd_t *)pInHdlrMsg->attrCmd;
  *pBuf++ = pInHdlrMsg->hdr.seqNum;
  *pBuf++ = HI_UINT16(pInHdlrMsg->msg->indInfo.src_short_addr);
  *pBuf++ = LO_UINT16(pInHdlrMsg->msg->indInfo.src_short_addr);
  *pBuf++ = pInHdlrMsg->msg->indInfo.src_ep;
  *pBuf++ = HI_UINT16(pInHdlrMsg->msg->indInfo.cluster_id);
  *pBuf++ = LO_UINT16(pInHdlrMsg->msg->indInfo.cluster_id);
  *pBuf++ = pReadCfgRspCmd->numAttr;

  for(u8 i = 0; i < pReadCfgRspCmd->numAttr; i++){
    *pBuf++ = pReadCfgRspCmd->attrList[i].status;
    *pBuf++ = pReadCfgRspCmd->attrList[i].direction;
    *pBuf++ = HI_UINT16(pReadCfgRspCmd->attrList[i].attrID);
    *pBuf++ = LO_UINT16(pReadCfgRspCmd->attrList[i].attrID);

    if(pReadCfgRspCmd->attrList[i].direction == ZCL_SEND_ATTR_REPORTS){
      *pBuf++ = pReadCfgRspCmd->attrList[i].dataType;
      *pBuf++ = HI_UINT16(pReadCfgRspCmd->attrList[i].minReportInt);
      *pBuf++ = LO_UINT16(pReadCfgRspCmd->attrList[i].minReportInt);
      *pBuf++ = HI_UINT16(pReadCfgRspCmd->attrList[i].maxReportInt);
      *pBuf++ = LO_UINT16(pReadCfgRspCmd->attrList[i].maxReportInt);

      if(zcl_analogDataType(pReadCfgRspCmd->attrList[i].dataType)){
        dataLen = zcl_getAttrSize(pReadCfgRspCmd->attrList[i].dataType, pReadCfgRspCmd->attrList[i].reportableChange);
        memcpy(pBuf, pReadCfgRspCmd->attrList[i].reportableChange, dataLen);
        pBuf += dataLen;
      }
    }else{
      *pBuf++ = HI_UINT16(pReadCfgRspCmd->attrList[i].timeoutPeriod);
      *pBuf++ = LO_UINT16(pReadCfgRspCmd->attrList[i].timeoutPeriod);
    }
  }

  zbhciTx(ZBHCI_CMD_ZCL_READ_REPORT_CFG_RSP, pBuf - array, array);
#endif
}
//#endif  /* ZCL_REPORT */

#ifdef ZCL_BASIC
/*********************************************************************
 * @fn      app_basicCb
 *
 * @brief   Handler for ZCL Basic Reset command.
 *
 * @param   pAddrInfo
 * @param   cmdId
 * @param   cmdPayload
 *
 * @return  status_t
 */
status_t app_basicCb(zclIncomingAddrInfo_t *pAddrInfo, u8 cmdId, void *cmdPayload)
{
  if(cmdId == ZCL_CMD_BASIC_RESET_FAC_DEFAULT){
    //Reset all the attributes of all its clusters to factory defaults
    //zcl_nv_attr_reset();
  }

  return ZCL_STA_SUCCESS;
}
#endif  /* ZCL_BASIC */

#ifdef ZCL_IDENTIFY
s32 app_zclIdentifyTimerCb(void *arg)
{
  if(g_zcl_identifyAttrs.identifyTime <= 0){
    identifyTimerEvt = NULL;
    return -1;
  }
  g_zcl_identifyAttrs.identifyTime--;
  return 0;
}

void app_zclIdentifyTimerStop(void)
{
  if(identifyTimerEvt){
    TL_ZB_TIMER_CANCEL(&identifyTimerEvt);
  }
}

/*********************************************************************
 * @fn      app_zclIdentifyCmdHandler
 *
 * @brief   Handler for ZCL Identify command. This function will set blink LED.
 *
 * @param   endpoint
 * @param   srcAddr
 * @param   identifyTime
 *
 * @return  None
 */
void app_zclIdentifyCmdHandler(u8 endpoint, u16 srcAddr, u16 identifyTime)
{
  g_zcl_identifyAttrs.identifyTime = identifyTime;

  if(identifyTime == 0){
    app_zclIdentifyTimerStop();
    light_blink_stop();
  }else{
    if(!identifyTimerEvt){
      light_blink_start(identifyTime, 500, 500);
      identifyTimerEvt = TL_ZB_TIMER_SCHEDULE(app_zclIdentifyTimerCb, NULL, 1000);
    }
  }
}

/*********************************************************************
 * @fn      app_zcltriggerCmdHandler
 *
 * @brief   Handler for ZCL trigger command.
 *
 * @param   pTriggerEffect
 *
 * @return  None
 */
static void app_zcltriggerCmdHandler(zcl_triggerEffect_t *pTriggerEffect)
{
  u8 effectId = pTriggerEffect->effectId;
//  u8 effectVariant = pTriggerEffect->effectVariant;

  switch(effectId){
    case IDENTIFY_EFFECT_BLINK:
      light_blink_start(1, 500, 500);
      break;
    case IDENTIFY_EFFECT_BREATHE:
      light_blink_start(15, 300, 700);
      break;
    case IDENTIFY_EFFECT_OKAY:
      light_blink_start(2, 250, 250);
      break;
    case IDENTIFY_EFFECT_CHANNEL_CHANGE:
      light_blink_start(1, 500, 7500);
      break;
    case IDENTIFY_EFFECT_FINISH_EFFECT:
      light_blink_start(1, 300, 700);
      break;
    case IDENTIFY_EFFECT_STOP_EFFECT:
      light_blink_stop();
      break;
    default:
      break;
  }
}

/*********************************************************************
 * @fn      app_zclIdentifyQueryRspCmdHandler
 *
 * @brief   Handler for ZCL Identify command. This function will set blink LED.
 *
 * @param   srcAddr
 * @param   cmdPayload
 *
 * @return  None
 */
static void app_zclIdentifyQueryRspCmdHandler(u16 srcAddr, zcl_identifyRspCmd_t *cmdPayload)
{
#if ZBHCI_EN
  u8 array[4];
  memset(array, 0, 4);

  u8 *pBuf = array;

  *pBuf++ = HI_UINT16(srcAddr);
  *pBuf++ = LO_UINT16(srcAddr);
  *pBuf++ = HI_UINT16(cmdPayload->timeout);
  *pBuf++ = LO_UINT16(cmdPayload->timeout);

  zbhciTx(ZBHCI_CMD_ZCL_IDENTIFY_QUERY_RSP, pBuf - array, array);
#endif
}

/*********************************************************************
 * @fn      sampleLight_identifyCb
 *
 * @brief   Handler for ZCL Identify command.
 *
 * @param   pAddrInfo
 * @param   cmdId
 * @param   cmdPayload
 *
 * @return  status_t
 */
status_t app_identifyCb(zclIncomingAddrInfo_t *pAddrInfo, u8 cmdId, void *cmdPayload)
{
  if(pAddrInfo->dstEp == APP_GW_ENDPOINT){
    if(pAddrInfo->dirCluster == ZCL_FRAME_CLIENT_SERVER_DIR){
      switch(cmdId){
        case ZCL_CMD_IDENTIFY:
          app_zclIdentifyCmdHandler(pAddrInfo->dstEp, pAddrInfo->srcAddr, ((zcl_identifyCmd_t *)cmdPayload)->identifyTime);
          break;
        case ZCL_CMD_TRIGGER_EFFECT:
          app_zcltriggerCmdHandler((zcl_triggerEffect_t *)cmdPayload);
          break;
        default:
          break;
      }
    }else{
      if(cmdId == ZCL_CMD_IDENTIFY_QUERY_RSP){
        app_zclIdentifyQueryRspCmdHandler(pAddrInfo->srcAddr, (zcl_identifyRspCmd_t *)cmdPayload);
      }
    }
  }

  return ZCL_STA_SUCCESS;
}

#endif  /* ZCL_IDENTIFY */

#endif  /* __PROJECT_TL_GW__ */


