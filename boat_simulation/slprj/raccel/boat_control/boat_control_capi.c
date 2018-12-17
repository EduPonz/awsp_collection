#include "__cf_boat_control.h"
#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "boat_control_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)    
#else
#include "builtin_typeid_types.h"
#include "boat_control.h"
#include "boat_control_capi.h"
#include "boat_control_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST                  
#define TARGET_STRING(s)               (NULL)                    
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 2 , TARGET_STRING (
"boat_control/Position calculator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
0 } , { 1 , 2 , TARGET_STRING ( "boat_control/Position calculator" ) ,
TARGET_STRING ( "" ) , 1 , 0 , 0 , 0 , 0 } , { 2 , 0 , TARGET_STRING (
"boat_control/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 3 ,
0 , TARGET_STRING ( "boat_control/Product1" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 4 , 0 , TARGET_STRING ( "boat_control/Sum1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 , TARGET_STRING (
"boat_control/Sum2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0
, TARGET_STRING ( "boat_control/Sum3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 7 , 0 , TARGET_STRING ( "boat_control/Transfer Fcn" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 8 , 0 , TARGET_STRING (
"boat_control/Transfer Fcn2" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } ,
{ 9 , 0 , TARGET_STRING ( "boat_control/Atan2" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"boat_control/PID Controller1/D Gain/Internal Parameters/Derivative Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 11 , 0 , TARGET_STRING (
"boat_control/PID Controller1/Filter/Cont. Filter/Filter" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 12 , 0 , TARGET_STRING (
"boat_control/PID Controller1/Filter/Cont. Filter/SumD" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 13 , 0 , TARGET_STRING (
"boat_control/PID Controller1/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 14 , 0 , TARGET_STRING (
"boat_control/PID Controller1/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 15 , 0 , TARGET_STRING (
"boat_control/PID Controller1/N Gain/Internal Parameters/Filter Coefficient"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 16 , 0 , TARGET_STRING (
 "boat_control/PID Controller1/Parallel P Gain/Internal Parameters/Proportional Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 17 , 0 , TARGET_STRING (
"boat_control/PID Controller1/Sum/Sum_PID/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 18 , 0 , TARGET_STRING (
"boat_control/PID Controller2/D Gain/Internal Parameters/Derivative Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 19 , 0 , TARGET_STRING (
"boat_control/PID Controller2/Filter/Cont. Filter/Filter" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 20 , 0 , TARGET_STRING (
"boat_control/PID Controller2/Filter/Cont. Filter/SumD" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 0 } , { 21 , 0 , TARGET_STRING (
"boat_control/PID Controller2/I Gain/Internal Parameters/Integral Gain" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 22 , 0 , TARGET_STRING (
"boat_control/PID Controller2/Integrator/Continuous/Integrator" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 23 , 0 , TARGET_STRING (
"boat_control/PID Controller2/N Gain/Internal Parameters/Filter Coefficient"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 24 , 0 , TARGET_STRING (
 "boat_control/PID Controller2/Parallel P Gain/Internal Parameters/Proportional Gain"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 25 , 0 , TARGET_STRING (
"boat_control/PID Controller2/Sum/Sum_PID/Sum" ) , TARGET_STRING ( "" ) , 0 ,
0 , 0 , 0 , 0 } , { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ;
static const rtwCAPI_BlockParameters rtBlockParameters [ ] = { { 26 ,
TARGET_STRING ( "boat_control/PID Controller1" ) , TARGET_STRING ( "P" ) , 0
, 0 , 0 } , { 27 , TARGET_STRING ( "boat_control/PID Controller1" ) ,
TARGET_STRING ( "I" ) , 0 , 0 , 0 } , { 28 , TARGET_STRING (
"boat_control/PID Controller1" ) , TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 29
, TARGET_STRING ( "boat_control/PID Controller1" ) , TARGET_STRING ( "N" ) ,
0 , 0 , 0 } , { 30 , TARGET_STRING ( "boat_control/PID Controller1" ) ,
TARGET_STRING ( "InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 31 ,
TARGET_STRING ( "boat_control/PID Controller1" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 32 , TARGET_STRING (
"boat_control/PID Controller2" ) , TARGET_STRING ( "P" ) , 0 , 0 , 0 } , { 33
, TARGET_STRING ( "boat_control/PID Controller2" ) , TARGET_STRING ( "I" ) ,
0 , 0 , 0 } , { 34 , TARGET_STRING ( "boat_control/PID Controller2" ) ,
TARGET_STRING ( "D" ) , 0 , 0 , 0 } , { 35 , TARGET_STRING (
"boat_control/PID Controller2" ) , TARGET_STRING ( "N" ) , 0 , 0 , 0 } , { 36
, TARGET_STRING ( "boat_control/PID Controller2" ) , TARGET_STRING (
"InitialConditionForIntegrator" ) , 0 , 0 , 0 } , { 37 , TARGET_STRING (
"boat_control/PID Controller2" ) , TARGET_STRING (
"InitialConditionForFilter" ) , 0 , 0 , 0 } , { 38 , TARGET_STRING (
"boat_control/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 39 ,
TARGET_STRING ( "boat_control/Constant1" ) , TARGET_STRING ( "Value" ) , 0 ,
0 , 0 } , { 40 , TARGET_STRING ( "boat_control/Constant2" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 41 , TARGET_STRING ( "boat_control/Constant3" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 42 , TARGET_STRING (
"boat_control/Transfer Fcn" ) , TARGET_STRING ( "A" ) , 0 , 1 , 0 } , { 43 ,
TARGET_STRING ( "boat_control/Transfer Fcn" ) , TARGET_STRING ( "C" ) , 0 , 2
, 0 } , { 44 , TARGET_STRING ( "boat_control/Transfer Fcn2" ) , TARGET_STRING
( "A" ) , 0 , 1 , 0 } , { 45 , TARGET_STRING ( "boat_control/Transfer Fcn2" )
, TARGET_STRING ( "C" ) , 0 , 2 , 0 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 , 0
} } ; static const rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , (
NULL ) , 0 , 0 , 0 } } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . pvpe0104cy , & rtB . gl3fqrttyk ,
& rtB . lyhxgu33xz , & rtB . lflglxiue0 , & rtB . n4wofe3ie0 , & rtB .
dawdc2g0pv , & rtB . g05wpr0rrp , & rtB . oshtlabmc5 , & rtB . i5iza0wzhm , &
rtB . jfbplommsg , & rtB . i520p42axt , & rtB . nl5uic2lwz , & rtB .
dcgqna2ixl , & rtB . gjjaboaewe , & rtB . pgd5jyrxfw , & rtB . eb1szirxc5 , &
rtB . lyep2u22xj , & rtB . l4yg5vogac , & rtB . hh0jnwyaeu , & rtB .
g1lfzu0ene , & rtB . flo1u4pz55 , & rtB . eficrjdtnw , & rtB . avkuuvjjai , &
rtB . kc4xhuqqmg , & rtB . nyjovcmu1f , & rtB . m0t4zoneuz , & rtP .
PIDController1_P , & rtP . PIDController1_I , & rtP . PIDController1_D , &
rtP . PIDController1_N , & rtP . PIDController1_InitialConditionForIntegrator
, & rtP . PIDController1_InitialConditionForFilter , & rtP . PIDController2_P
, & rtP . PIDController2_I , & rtP . PIDController2_D , & rtP .
PIDController2_N , & rtP . PIDController2_InitialConditionForIntegrator , &
rtP . PIDController2_InitialConditionForFilter , & rtP . Constant_Value , &
rtP . Constant1_Value , & rtP . Constant2_Value , & rtP . Constant3_Value , &
rtP . TransferFcn_A [ 0 ] , & rtP . TransferFcn_C [ 0 ] , & rtP .
TransferFcn2_A [ 0 ] , & rtP . TransferFcn2_C [ 0 ] , } ; static int32_T *
rtVarDimsAddrMap [ ] = { ( NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , SS_DOUBLE , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } } ; static const uint_T rtDimensionArray [ ] = {
1 , 1 , 2 , 1 , 1 , 2 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0
} ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { ( NULL ) , ( NULL ) ,
rtwCAPI_FIX_RESERVED , 0 , 0 , 0 } , } ; static const rtwCAPI_SampleTimeMap
rtSampleTimeMap [ ] = { { ( const void * ) & rtcapiStoredFloats [ 0 ] , (
const void * ) & rtcapiStoredFloats [ 0 ] , 0 , 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 26 , ( NULL )
, 0 , ( NULL ) , 0 } , { rtBlockParameters , 20 , rtModelParameters , 0 } , {
( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap , rtFixPtMap , rtElementMap
, rtSampleTimeMap , rtDimensionArray } , "float" , { 3145587776U ,
3571904463U , 3333901365U , 4037844916U } , ( NULL ) , 0 , 0 } ; const
rtwCAPI_ModelMappingStaticInfo * boat_control_GetCAPIStaticMap ( void ) {
return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void boat_control_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion ( ( *
rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void boat_control_host_InitializeDataMapInfo (
boat_control_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , NULL ) ; rtwCAPI_SetPath (
dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap -> mmi , NULL ) ;
rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
