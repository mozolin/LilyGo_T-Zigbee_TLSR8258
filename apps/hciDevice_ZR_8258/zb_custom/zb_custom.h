
#ifndef ZB_CUSTOM_H
#define ZB_CUSTOM_H


#define ZCL_CLUSTER_MS_CO2        0x040D


/********************* CO2 Measurement ************************/
#if ZCL_CO2_MEASUREMENT_SUPPORT
#define ZCL_CO2_MEASUREMENT
#endif


/* Measurement and Sensing */
#include "measument_sensing/zcl_co2_measurement.h"
#include "measument_sensing/zcl_humidity_measurement.h"
#include "measument_sensing/zcl_pressure_measurement.h"


#endif /* ZB_CUSTOM_H */
