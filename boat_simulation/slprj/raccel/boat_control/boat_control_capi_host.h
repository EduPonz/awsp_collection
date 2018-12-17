#include "__cf_boat_control.h"
#ifndef RTW_HEADER_boat_control_cap_host_h_
#define RTW_HEADER_boat_control_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"
typedef struct { rtwCAPI_ModelMappingInfo mmi ; }
boat_control_host_DataMapInfo_T ;
#ifdef __cplusplus
extern "C" {
#endif
void boat_control_host_InitializeDataMapInfo (
boat_control_host_DataMapInfo_T * dataMap , const char * path ) ;
#ifdef __cplusplus
}
#endif
#endif
#endif
