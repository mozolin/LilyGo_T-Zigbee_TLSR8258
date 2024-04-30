/********************************************************************************************************
 * @file  zcl_analog_output.c
 *******************************************************************************************************/
/**********************************************************************
 * INCLUDES
 */
#include "../../../../zigbee/zcl/zcl_include.h"
#include "../zb_custom.h"


#ifdef ZCL_ANALOG_OUTPUT_MEASUREMENT
/**********************************************************************
 * LOCAL CONSTANTS
 */


/**********************************************************************
 * LOCAL TYPES
 */


/**********************************************************************
 * LOCAL VARIABLES
 */
 

/**********************************************************************
 * LOCAL FUNCTIONS
 */

_CODE_ZCL_ status_t zcl_analog_output_register(u8 endpoint, u16 manuCode, u8 attrNum, const zclAttrInfo_t attrTbl[], cluster_forAppCb_t cb)
{
  return zcl_registerCluster(endpoint, ZCL_CLUSTER_GEN_ANALOG_OUTPUT_BASIC, manuCode, attrNum, attrTbl, NULL, cb);
}

#endif  /* ZCL_ANALOG_OUTPUT_MEASUREMENT */

