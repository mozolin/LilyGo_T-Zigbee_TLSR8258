
#ifndef ZB_CUSTOM_H
#define ZB_CUSTOM_H


#define ZCL_CLUSTER_MS_CO2        0x040D


/********************* Analog Input Measurement ************************/
#if ZCL_ANALOG_INPUT_MEASUREMENT_SUPPORT
  #define ZCL_ANALOG_INPUT_MEASUREMENT
#endif
/********************* Analog Output Measurement ************************/
#if ZCL_ANALOG_OUTPUT_MEASUREMENT_SUPPORT
  #define ZCL_ANALOG_OUTPUT_MEASUREMENT
#endif
/********************* CO2 Measurement ************************/
#if ZCL_CO2_MEASUREMENT_SUPPORT
  #define ZCL_CO2_MEASUREMENT
#endif


#include "clusters/zcl_analog_input.h"
#include "clusters/zcl_analog_output.h"
#include "clusters/zcl_co2_measurement.h"
#include "clusters/zcl_humidity_measurement.h"
#include "clusters/zcl_pressure_measurement.h"


#endif /* ZB_CUSTOM_H */
