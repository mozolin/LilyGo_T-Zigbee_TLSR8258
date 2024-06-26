#if (__PROJECT_TL_GW__)

/**********************************************************************
 * INCLUDES
 */
#include "tl_common.h"
#include "zb_api.h"
#include "zcl_include.h"
#include "bdb.h"
#include "main.h"
#if ZBHCI_EN
#include "zbhci.h"
#endif

/**********************************************************************
 * LOCAL CONSTANTS
 */
#define DEBUG_HEART    0

/**********************************************************************
 * TYPEDEFS
 */


/**********************************************************************
 * LOCAL FUNCTIONS
 */
void zbdemo_bdbInitCb(u8 status, u8 joinedNetwork);
void zbdemo_bdbCommissioningCb(u8 status, void *arg);
void zbdemo_bdbIdentifyCb(u8 endpoint, u16 srcAddr, u16 identifyTime);

/**********************************************************************
 * GLOBAL VARIABLES
 */
bdb_appCb_t g_zbDemoBdbCb = {zbdemo_bdbInitCb, zbdemo_bdbCommissioningCb, zbdemo_bdbIdentifyCb, NULL};

#if ZBHCI_EN
bool app_macAssocReqIndHandler(void *arg);
mac_appIndCb_t macAppIndCbList = {NULL, NULL, app_macAssocReqIndHandler};
#endif


/**********************************************************************
 * LOCAL VARIABLES
 */
u32 heartInterval = 0;

#if DEBUG_HEART
ev_timer_event_t *heartTimerEvt = NULL;
#endif

/**********************************************************************
 * FUNCTIONS
 */
#if DEBUG_HEART
static s32 heartTimerCb(void *arg){
  if(heartInterval == 0){
    heartTimerEvt = NULL;
    return -1;
  }

  gpio_toggle(LED_POWER);

  return heartInterval;
}
#endif

/*********************************************************************
 * @fn      zbdemo_bdbInitCb
 *
 * @brief   application callback for bdb initiation
 *
 * @param   status - the status of bdb init BDB_INIT_STATUS_SUCCESS or BDB_INIT_STATUS_FAILURE
 *
 * @param   joinedNetwork  - 1: node is on a network, 0: node isn't on a network
 *
 * @return  None
 */
void zbdemo_bdbInitCb(u8 status, u8 joinedNetwork){
  if(status == BDB_INIT_STATUS_SUCCESS){
    /*
     * for a non-factory-new device:
     *     steer a network
     *
     * for a factory-new device:
     *      do nothing until receiving the command from host if HCI is enabled,
     *     forms a central network if HCI is disabled.
     *
     */
    if(joinedNetwork){
      heartInterval = 1000;
    }else{
#if  (!ZBHCI_EN) && ZB_COORDINATOR_ROLE
      bdb_networkFormationStart();
#endif
      heartInterval = 500;
    }
  }else{
    heartInterval = 200;
  }

#if DEBUG_HEART
  if(heartTimerEvt){
    TL_ZB_TIMER_CANCEL(&heartTimerEvt);
  }
  heartTimerEvt = TL_ZB_TIMER_SCHEDULE(heartTimerCb, NULL, heartInterval);
#endif
}

/*********************************************************************
 * @fn      zbdemo_bdbCommissioningCb
 *
 * @brief   application callback for bdb commissioning
 *
 * @param   status - the status of bdb commissioning
 *
 * @param   arg
 *
 * @return  None
 */
void zbdemo_bdbCommissioningCb(u8 status, void *arg){
  u8 array[64] = { 0 };
  u8 *pBuf = array;

  if(status == BDB_COMMISSION_STA_SUCCESS){
    printf("bdb evt: BDB_COMMISSION_STA_SUCCESS\n");
    heartInterval = 1000;
    *pBuf++ = HI_UINT16(g_zbInfo.nwkNib.nwkAddr);
    *pBuf++ = HI_UINT16(g_zbInfo.nwkNib.nwkAddr);

    memcpy(pBuf, g_zbInfo.nwkNib.ieeeAddr, 8);
    ZB_LEBESWAP(pBuf, 8);
    pBuf += 8;

    *pBuf++ = HI_UINT16(g_zbInfo.nwkNib.panId);
    *pBuf++ = HI_UINT16(g_zbInfo.nwkNib.panId);

    memcpy(pBuf, g_zbInfo.nwkNib.extPANId, 8);
    ZB_LEBESWAP(pBuf, 8);
    pBuf += 8;

    *pBuf++ = g_zbInfo.macPib.phyChannelCur;

    zbhciTx(ZBHCI_CMD_NETWORK_STATE_REPORT, pBuf - array, array);
  }else if(status == BDB_COMMISSION_STA_IN_PROGRESS){
    printf("bdb evt: BDB_COMMISSION_STA_IN_PROGRESS\n");
  }else if(status == BDB_COMMISSION_STA_NOT_AA_CAPABLE){
    printf("bdb evt: BDB_COMMISSION_STA_NOT_AA_CAPABLE\n");
  }else if(status == BDB_COMMISSION_STA_NO_NETWORK){
    printf("bdb evt: BDB_COMMISSION_STA_NO_NETWORK\n");
  }else if(status == BDB_COMMISSION_STA_TARGET_FAILURE){
    printf("bdb evt: BDB_COMMISSION_STA_TARGET_FAILURE\n");
  }else if(status == BDB_COMMISSION_STA_FORMATION_FAILURE){
    printf("bdb evt: BDB_COMMISSION_STA_TARGET_FAILURE\n");
  }else if(status == BDB_COMMISSION_STA_NO_IDENTIFY_QUERY_RESPONSE){
    printf("bdb evt: BDB_COMMISSION_STA_NO_IDENTIFY_QUERY_RESPONSE\n");
  }else if(status == BDB_COMMISSION_STA_BINDING_TABLE_FULL){
    printf("bdb evt: BDB_COMMISSION_STA_BINDING_TABLE_FULL\n");
  }else if(status == BDB_COMMISSION_STA_NO_SCAN_RESPONSE){
    printf("bdb evt: BDB_COMMISSION_STA_NO_SCAN_RESPONSE\n");
  }else if(status == BDB_COMMISSION_STA_NOT_PERMITTED){
    printf("bdb evt: BDB_COMMISSION_STA_NOT_PERMITTED\n");
  }else if(status == BDB_COMMISSION_STA_TCLK_EX_FAILURE){
    printf("bdb evt: BDB_COMMISSION_STA_TCLK_EX_FAILURE\n");
  }else if(status == BDB_COMMISSION_STA_FORMATION_DONE){
    printf("bdb evt: BDB_COMMISSION_STA_FORMATION_DONE\n");
#if ZBHCI_EN
  zbhciTx(ZBHCI_CMD_BDB_COMMISSION_FORMATION_RSP, 1, array);
#else
    /* If you comment out the channel setting,
     * this demo will automatically select a channel,
     * which is the result of the energy scan.
     */
      tl_zbMacChannelSet(DEFAULT_CHANNEL);  //set default channel
#endif
      heartInterval = 1000;
  }else{
    printf("bdb evt: %d\n", status);
  }
}


extern void app_zclIdentifyCmdHandler(u8 endpoint, u16 srcAddr, u16 identifyTime);
void zbdemo_bdbIdentifyCb(u8 endpoint, u16 srcAddr, u16 identifyTime){
  app_zclIdentifyCmdHandler(endpoint, srcAddr, identifyTime);
}



/*********************************************************************
 * @fn      app_devAnnHandler
 *
 * @brief   Handler for ZDO Device Announce message. When this function be called means
 *          there is new node join PAN or a node rejoin the PAN.
 *
 * @param   pDevAnnceReq - parameter of device announce indication
 *
 * @return  None
 */
void app_devAnnHandler(zdo_device_annce_req_t *pDevAnnceReq)
{
#if ZBHCI_EN
  printf("app_devAnnHandler\n");
  u8 array[64];
  memset(array, 0, 64);

  u8 *pBuf = array;

  *pBuf++ = HI_UINT16(pDevAnnceReq->nwk_addr_local);
  *pBuf++ = LO_UINT16(pDevAnnceReq->nwk_addr_local);
  memcpy(pBuf, pDevAnnceReq->ieee_addr_local, 8);
  ZB_LEBESWAP(pBuf, 8);
  pBuf += 8;
  memcpy(pBuf, (u8 *)&(pDevAnnceReq->mac_capability), 1);
  pBuf++;

  zbhciTx(ZBHCI_CMD_NODES_DEV_ANNCE_IND, pBuf - array, array);
#endif
}

/*********************************************************************
 * @fn      app_leaveCnfHandler
 *
 * @brief   Handler for ZDO Leave Confirm message.
 *
 * @param   pLeaveCnf - parameter of leave confirm
 *
 * @return  None
 */
void app_leaveCnfHandler(nlme_leave_cnf_t *pLeaveCnf)
{
//  printf("app_leaveCnfHandler, status = %x\n", pLeaveCnf->status);
}

/*********************************************************************
 * @fn      app_leaveIndHandler
 *
 * @brief   Handler for ZDO leave indication message.
 *
 * @param   pLeaveInd - parameter of leave indication
 *
 * @return  None
 */
void app_leaveIndHandler(nlme_leave_ind_t *pLeaveInd)
{
#if ZBHCI_EN
  //zbhciLeaveIndMsgPush(pLeaveInd);
  u8 array[64];
  u8 *pBuf = array;

  memset(array, 0, 64);

  memcpy(pBuf, pLeaveInd->deviceAddr, 8);
  ZB_LEBESWAP(pBuf, 8);
  pBuf += 8;
  *pBuf++ = pLeaveInd->rejoin;
  zbhciTx(ZBHCI_CMD_LEAVE_INDICATION, pBuf - array, array);
#if 0
  static u16 leaveNodeCnt = 0;
  zbhci_nodeLeaveInd_t ind;
  ind.totalCnt = leaveNodeCnt++;
  memcpy(ind.macAddr, pLeaveInd->device_address, 8);
  zbhciAppNodeLeaveIndPush((void *)&ind);
#endif
#endif
}

void app_dataSendConfirm(void *arg){
#if ZBHCI_EN
  apsdeDataConf_t *pApsDataCnf = (apsdeDataConf_t *)arg;

  zbhciAppDataSendConfirmPush((void *)pApsDataCnf);
#endif
}

#if ZBHCI_EN
bool app_macAssocReqIndHandler(void *arg){
  zb_mlme_associate_ind_t *ind = (zb_mlme_associate_ind_t *)arg;

  return zbhciMacAddrGetPush(ind->devAddress);
}
#endif

/*********************************************************************
 *
 * @brief   Receive notification of PAN ID conflict.
 *
 * @param   pNwkUpdateCmd - Conflicting PAN ID information
 *
 * @return  TRUE  - Allow PAN ID conflict handling
 *       FALSE - Truncate the execution of PAN ID conflict handling
 */
bool app_nwkUpdateIndicateHandler(nwkCmd_nwkUpdate_t *pNwkUpdateCmd){
  return FALSE;
}

/*********************************************************************
 *
 * @brief   Notification of trust center join.
 *
 * @param   pTcJoinInd - address information
 *
 * @return  TRUE  - Allow delivery of transport key
 *       FALSE - Truncate delivery transport key
 */
bool app_tcJoinIndHandler(zdo_tc_join_ind_t *pTcJoinInd){
  return TRUE;
}

/*********************************************************************
 *
 * @brief   Notification of frame counter near limit.
 *       The function will be called when the truster center detects
 *       the frame counter for any device in its neighbor table is
 *       grater than 0x80000000, or its outgoing frame counter
 *       reaches 0x40000000.
 *
 * @param   None
 *
 * @return  None
 */
void app_tcFrameCntReachedHandler(void){
  ss_tcUpdateNwkKey_t updateNwkKey;

  /* Broadcast NWK key updates. */
  ZB_IEEE_ADDR_ZERO(updateNwkKey.dstAddr);
  drv_generateRandomData(updateNwkKey.key, CCM_KEY_SIZE);

  zb_tcUpdateNwkKey(&updateNwkKey);
}

#endif  /* __PROJECT_TL_GW__ */
