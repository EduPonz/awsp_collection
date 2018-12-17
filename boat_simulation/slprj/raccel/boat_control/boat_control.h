#include "__cf_boat_control.h"
#ifndef RTW_HEADER_boat_control_h_
#define RTW_HEADER_boat_control_h_
#include <stddef.h>
#include <string.h>
#include "rtw_modelmap.h"
#ifndef boat_control_COMMON_INCLUDES_
#define boat_control_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "sigstream_rtw.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#endif
#include "boat_control_types.h"
#include "multiword_types.h"
#include "mwmathutil.h"
#include "rt_defines.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#define MODEL_NAME boat_control
#define NSAMPLE_TIMES (3) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (27) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (8)   
#elif NCSTATES != 8
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T oshtlabmc5 ; real_T i5iza0wzhm ; real_T g05wpr0rrp ;
real_T dawdc2g0pv ; real_T jfbplommsg ; real_T i520p42axt ; real_T nl5uic2lwz
; real_T dcgqna2ixl ; real_T gjjaboaewe ; real_T pgd5jyrxfw ; real_T
eb1szirxc5 ; real_T lyep2u22xj ; real_T l4yg5vogac ; real_T n4wofe3ie0 ;
real_T hh0jnwyaeu ; real_T g1lfzu0ene ; real_T flo1u4pz55 ; real_T eficrjdtnw
; real_T avkuuvjjai ; real_T kc4xhuqqmg ; real_T nyjovcmu1f ; real_T
m0t4zoneuz ; real_T lyhxgu33xz ; real_T lflglxiue0 ; real_T hoqjaab0qn [ 2 ]
; real_T pvpe0104cy ; real_T gl3fqrttyk ; } B ; typedef struct { struct {
void * LoggedData [ 2 ] ; } pzwd1gmdwf ; struct { void * LoggedData ; }
lmbrh5aup4 ; } DW ; typedef struct { real_T mybxqtllvq [ 2 ] ; real_T
kgvvguxqca [ 2 ] ; real_T dh2dovl5c2 ; real_T jksrnqqge5 ; real_T cavw5nvkqb
; real_T avlsrvqz00 ; } X ; typedef struct { real_T mybxqtllvq [ 2 ] ; real_T
kgvvguxqca [ 2 ] ; real_T dh2dovl5c2 ; real_T jksrnqqge5 ; real_T cavw5nvkqb
; real_T avlsrvqz00 ; } XDot ; typedef struct { boolean_T mybxqtllvq [ 2 ] ;
boolean_T kgvvguxqca [ 2 ] ; boolean_T dh2dovl5c2 ; boolean_T jksrnqqge5 ;
boolean_T cavw5nvkqb ; boolean_T avlsrvqz00 ; } XDis ; typedef struct {
real_T mybxqtllvq [ 2 ] ; real_T kgvvguxqca [ 2 ] ; real_T dh2dovl5c2 ;
real_T jksrnqqge5 ; real_T cavw5nvkqb ; real_T avlsrvqz00 ; } CStateAbsTol ;
typedef struct { rtwCAPI_ModelMappingInfo mmi ; } DataMapInfo ; struct P_ {
real_T PIDController1_D ; real_T PIDController2_D ; real_T PIDController1_I ;
real_T PIDController2_I ; real_T PIDController1_InitialConditionForFilter ;
real_T PIDController2_InitialConditionForFilter ; real_T
PIDController1_InitialConditionForIntegrator ; real_T
PIDController2_InitialConditionForIntegrator ; real_T PIDController1_N ;
real_T PIDController2_N ; real_T PIDController1_P ; real_T PIDController2_P ;
real_T TransferFcn_A [ 2 ] ; real_T TransferFcn_C [ 2 ] ; real_T
TransferFcn2_A [ 2 ] ; real_T TransferFcn2_C [ 2 ] ; real_T Constant3_Value ;
real_T Constant2_Value ; real_T Constant_Value ; real_T Constant1_Value ; } ;
extern const char * RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX
; extern DW rtDW ; extern P rtP ; extern const rtwCAPI_ModelMappingStaticInfo
* boat_control_GetCAPIStaticMap ( void ) ; extern SimStruct * const rtS ;
extern const int_T gblNumToFiles ; extern const int_T gblNumFrFiles ; extern
const int_T gblNumFrWksBlocks ; extern rtInportTUtable * gblInportTUtables ;
extern const char * gblInportFileName ; extern const int_T
gblNumRootInportBlks ; extern const int_T gblNumModelInputs ; extern const
int_T gblInportDataTypeIdx [ ] ; extern const int_T gblInportDims [ ] ;
extern const int_T gblInportComplex [ ] ; extern const int_T
gblInportInterpoFlag [ ] ; extern const int_T gblInportContinuous [ ] ;
extern const int_T gblParameterTuningTid ; extern DataMapInfo *
rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr ;
void MdlOutputs ( int_T tid ) ; void MdlOutputsParameterSampleTime ( int_T
tid ) ; void MdlUpdate ( int_T tid ) ; void MdlTerminate ( void ) ; void
MdlInitializeSizes ( void ) ; void MdlInitializeSampleTimes ( void ) ;
SimStruct * raccel_register_model ( void ) ;
#endif
