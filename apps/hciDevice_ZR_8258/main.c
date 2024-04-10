#if (__PROJECT_TL_GW__)

/**********************************************************************
 * INCLUDES
 */
#include "tl_common.h"
#include "zb_api.h"
#include "zcl_include.h"
#include "bdb.h"
#include "ota.h"
#include "gp.h"
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
 * GLOBAL VARIABLES
 */
app_ctx_t g_appGwCtx;


#if ZBHCI_EN
extern mac_appIndCb_t macAppIndCbList;
#endif

#ifdef ZCL_OTA
//running code firmware information
ota_preamble_t app_otaInfo = {
  .fileVer          = FILE_VERSION,
  .imageType        = IMAGE_TYPE,
  .manufacturerCode = MANUFACTURER_CODE_TELINK,
};
#endif


//Must declare the application call back function which used by ZDO layer
const zdo_appIndCb_t appCbLst = {
  bdb_zdoStartDevCnf,          //start device cnf cb
  NULL,                //reset cnf cb
  app_devAnnHandler,        //device announce indication cb
  app_leaveIndHandler,      //leave ind cb
  app_leaveCnfHandler,      //leave cnf cb
  app_nwkUpdateIndicateHandler,  //nwk update ind cb
  NULL,                //permit join ind cb
  NULL,                //nlme sync cnf cb
  app_tcJoinIndHandler,      //tc join ind cb
  app_tcFrameCntReachedHandler,  //tc detects that the frame counter is near limit
};


/**
 *  @brief Definition for bdb commissioning setting
 */
bdb_commissionSetting_t g_bdbCommissionSetting = {
  .linkKey.tcLinkKey.keyType = SS_GLOBAL_LINK_KEY,
  .linkKey.tcLinkKey.key = (u8 *)tcLinkKeyCentralDefault,           //can use unique link key stored in NV

  .linkKey.distributeLinkKey.keyType = MASTER_KEY,
  .linkKey.distributeLinkKey.key = (u8 *)linkKeyDistributedMaster,    //use linkKeyDistributedCertification before testing

  .linkKey.touchLinkKey.keyType = MASTER_KEY,
  .linkKey.touchLinkKey.key = (u8 *)touchLinkKeyMaster,         //use touchLinkKeyCertification before testing

  .touchlinkEnable = 0,                         //disable touch link for coordinator
};

/**********************************************************************
 * LOCAL VARIABLES
 */


/**********************************************************************
 * FUNCTIONS
 */

/*********************************************************************
 * @fn      stack_init
 *
 * @brief   This function initialize the ZigBee stack and related profile. If HA/ZLL profile is
 *          enabled in this application, related cluster should be registered here.
 *
 * @param   None
 *
 * @return  None
 */
void stack_init(void)
{
  zb_init();

#if ZBHCI_EN
  zb_macCbRegister((mac_appIndCb_t *)&macAppIndCbList);
#endif
  zb_zdoCbRegister((zdo_appIndCb_t *)&appCbLst);
}

/*********************************************************************
 * @fn      user_app_init
 *
 * @brief   This function initialize the application(Endpoint) information for this node.
 * @param   None
 * @return  None
 */
void user_app_init(void)
{
  af_nodeDescManuCodeUpdate(MANUFACTURER_CODE_TELINK);

  /* Initialize ZCL layer */
  /* Register Incoming ZCL Foundation command/response messages */
  zcl_init(app_zclProcessIncomingMsg);

  /* Register endPoint */
  af_endpointRegister(APP_GW_ENDPOINT, (af_simple_descriptor_t *)&app_simpleDesc, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT2, (af_simple_descriptor_t *)&app_simpleDesc2, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT3, (af_simple_descriptor_t *)&app_simpleDesc3, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT4, (af_simple_descriptor_t *)&app_simpleDesc4, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT5, (af_simple_descriptor_t *)&app_simpleDesc5, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT6, (af_simple_descriptor_t *)&app_simpleDesc6, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT7, (af_simple_descriptor_t *)&app_simpleDesc7, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT8, (af_simple_descriptor_t *)&app_simpleDesc8, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT9, (af_simple_descriptor_t *)&app_simpleDesc9, zcl_rx_handler, NULL);
  af_endpointRegister(APP_GW_ENDPOINT10, (af_simple_descriptor_t *)&app_simpleDesc10, zcl_rx_handler, NULL);
  
 	/* Initialize or restore attributes, this must before 'zcl_register()' */
	zcl_reportingTabInit();
  
  /* Register ZCL specific cluster information */
  zcl_register(APP_GW_ENDPOINT, APP_GW_CB_CLUSTER_NUM, (zcl_specClusterInfo_t *)g_appClusterList);
  zcl_register(APP_GW_ENDPOINT2, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT3, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT4, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT5, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT6, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT7, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT8, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT9, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);
  zcl_register(APP_GW_ENDPOINT10, APP_GW_CB_CLUSTER_NUM_EXTRA, (zcl_specClusterInfo_t *)g_appClusterListExtra);

//#ifdef ZCL_GREEN_POWER
//  gp_init();
//#endif

#ifdef ZCL_OTA
  ota_init(OTA_TYPE_SERVER, (af_simple_descriptor_t *)&app_simpleDesc, &app_otaInfo, NULL);
#endif
}


void led_init(void)
{
  led_off(LED_PERMIT);
  light_init();
}

void app_task(void)
{
  static bool assocPermit = 0;
  if(assocPermit != zb_getMacAssocPermit()){
    assocPermit = zb_getMacAssocPermit();
    if(assocPermit){
      led_on(LED_PERMIT);
    }else{
      led_off(LED_PERMIT);
    }
  }

  if(BDB_STATE_GET() == BDB_STATE_IDLE){
    app_key_handler();
  }
}

static void appSysException(void)
{
  // SYSTEM_RESET();

  while(1){
    gpio_toggle(LED_POWER);
    WaitMs(100);
  }
}



/*********************************************************************
 * @fn      user_init
 *
 * @brief   User level initialization code.
 *
 * @param   isRetention - if it is waking up with ram retention.
 *
 * @return  None
 */
void user_init(bool isRetention)
{
  (void)isRetention;

  printf("user init\n");

#if defined(MCU_CORE_8258) || defined(MCU_CORE_8278) || defined(MCU_CORE_B91)
  extern u8 firmwareCheckWithUID(void);
  if(firmwareCheckWithUID()){
    while(1);
  }
#endif

  /* Initialize LEDs*/
  led_init();

#if PA_ENABLE
  /* external RF PA used */
  rf_paInit(PA_TX, PA_RX);
#endif

  /* Initialize Stack */
  stack_init();

  sys_exceptHandlerRegister(appSysException);

  /* Initialize user application */
  user_app_init();

  /* User's Task */
#if ZBHCI_EN
  /*
   * define ZBHCI_USB_PRINT, ZBHCI_USB_CDC or ZBHCI_UART as 1 in app_cfg.h
   * if needing to enable ZBHCI_EN
   *
   * */
  zbhciInit();
  ev_on_poll(EV_POLL_HCI, zbhciTask);
#endif
  ev_on_poll(EV_POLL_IDLE, app_task);

  //af_nodeDescStackRevisionSet(20);

  /*
   * bdb initialization start,
   * once initialization is done, the g_zbDemoBdbCb.bdbInitCb() will be called
   *
   * */
  bdb_init((af_simple_descriptor_t *)&app_simpleDesc, &g_bdbCommissionSetting, &g_zbDemoBdbCb, 1);
}

#endif  /* __PROJECT_TL_GW__ */
