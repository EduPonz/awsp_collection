#include "__cf_boat_control.h"
#include "rt_logging_mmi.h"
#include "boat_control_capi.h"
#include <math.h>
#include "boat_control.h"
#include "boat_control_private.h"
#include "boat_control_dt.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; extern boolean_T
gblExtModeStartPktReceived ; void raccelForceExtModeShutdown ( ) { if ( !
gblExtModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 2 , & stopRequested ) ; }
rtExtModeShutdown ( 2 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 0 ; int_T gbl_raccel_NumST = 3 ; const char_T
* gbl_raccel_Version = "9.2 (R2018b) 24-May-2018" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const char * gblSlvrJacPatternFileName =
"slprj//raccel//boat_control//boat_control_Jpattern.mat" ; const int_T
gblNumRootInportBlks = 0 ; const int_T gblNumModelInputs = 0 ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
const int_T gblInportDataTypeIdx [ ] = { - 1 } ; const int_T gblInportDims [
] = { - 1 } ; const int_T gblInportComplex [ ] = { - 1 } ; const int_T
gblInportInterpoFlag [ ] = { - 1 } ; const int_T gblInportContinuous [ ] = {
- 1 } ; int_T enableFcnCallFlag [ ] = { 1 , 1 , 1 } ;
#include "simstruc.h"
#include "fixedpoint.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; void MdlInitialize ( void ) { rtX . mybxqtllvq [ 0 ] = 0.0 ; rtX
. kgvvguxqca [ 0 ] = 0.0 ; rtX . mybxqtllvq [ 1 ] = 0.0 ; rtX . kgvvguxqca [
1 ] = 0.0 ; rtX . dh2dovl5c2 = rtP . PIDController1_InitialConditionForFilter
; rtX . jksrnqqge5 = rtP . PIDController1_InitialConditionForIntegrator ; rtX
. cavw5nvkqb = rtP . PIDController2_InitialConditionForFilter ; rtX .
avlsrvqz00 = rtP . PIDController2_InitialConditionForIntegrator ; } void
MdlStart ( void ) { { void * * slioCatalogueAddr = rt_slioCatalogueAddr ( ) ;
void * r2 = ( NULL ) ; void * * pOSigstreamManagerAddr = ( NULL ) ; const int
maxErrorBufferSize = 16384 ; char errMsgCreatingOSigstreamManager [ 16384 ] ;
bool errorCreatingOSigstreamManager = false ; const char *
errorAddingR2SharedResource = ( NULL ) ; * slioCatalogueAddr =
rtwGetNewSlioCatalogue ( rt_GetMatSigLogSelectorFileName ( ) ) ;
errorAddingR2SharedResource = rtwAddR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) , 1 ) ; if (
errorAddingR2SharedResource != ( NULL ) ) { rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = ( NULL ) ; ssSetErrorStatus ( rtS
, errorAddingR2SharedResource ) ; return ; } r2 = rtwGetR2SharedResource (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ) ;
pOSigstreamManagerAddr = rt_GetOSigstreamManagerAddr ( ) ;
errorCreatingOSigstreamManager = rtwOSigstreamManagerCreateInstance (
rt_GetMatSigLogSelectorFileName ( ) , r2 , pOSigstreamManagerAddr ,
errMsgCreatingOSigstreamManager , maxErrorBufferSize ) ; if (
errorCreatingOSigstreamManager ) { * pOSigstreamManagerAddr = ( NULL ) ;
ssSetErrorStatus ( rtS , errMsgCreatingOSigstreamManager ) ; return ; } } {
bool externalInputIsInDatasetFormat = false ; void * pISigstreamManager =
rt_GetISigstreamManager ( ) ; rtwISigstreamManagerGetInputIsInDatasetFormat (
pISigstreamManager , & externalInputIsInDatasetFormat ) ; if (
externalInputIsInDatasetFormat ) { } } MdlInitialize ( ) ; } void MdlOutputs
( int_T tid ) { real_T aks4pw4oqk ; rtB . oshtlabmc5 = 0.0 ; rtB . oshtlabmc5
+= rtP . TransferFcn_C [ 0 ] * rtX . mybxqtllvq [ 0 ] ; rtB . oshtlabmc5 +=
rtP . TransferFcn_C [ 1 ] * rtX . mybxqtllvq [ 1 ] ; rtB . i5iza0wzhm = 0.0 ;
rtB . i5iza0wzhm += rtP . TransferFcn2_C [ 0 ] * rtX . kgvvguxqca [ 0 ] ; rtB
. i5iza0wzhm += rtP . TransferFcn2_C [ 1 ] * rtX . kgvvguxqca [ 1 ] ; rtB .
pvpe0104cy = muDoubleScalarCos ( rtB . i5iza0wzhm ) * rtB . oshtlabmc5 ; rtB
. gl3fqrttyk = muDoubleScalarSin ( rtB . i5iza0wzhm ) * rtB . oshtlabmc5 ;
rtB . g05wpr0rrp = rtP . Constant3_Value - rtB . gl3fqrttyk ; rtB .
dawdc2g0pv = rtP . Constant2_Value - rtB . pvpe0104cy ; rtB . jfbplommsg =
muDoubleScalarAtan2 ( rtB . g05wpr0rrp , rtB . dawdc2g0pv ) ; aks4pw4oqk =
muDoubleScalarSqrt ( rtB . dawdc2g0pv * rtB . dawdc2g0pv + rtB . g05wpr0rrp *
rtB . g05wpr0rrp ) ; rtB . i520p42axt = rtP . PIDController1_D * aks4pw4oqk ;
rtB . nl5uic2lwz = rtX . dh2dovl5c2 ; rtB . dcgqna2ixl = rtB . i520p42axt -
rtB . nl5uic2lwz ; rtB . gjjaboaewe = rtP . PIDController1_I * aks4pw4oqk ;
rtB . pgd5jyrxfw = rtX . jksrnqqge5 ; rtB . eb1szirxc5 = rtP .
PIDController1_N * rtB . dcgqna2ixl ; rtB . lyep2u22xj = rtP .
PIDController1_P * aks4pw4oqk ; rtB . l4yg5vogac = ( rtB . lyep2u22xj + rtB .
pgd5jyrxfw ) + rtB . eb1szirxc5 ; rtB . n4wofe3ie0 = rtB . jfbplommsg - rtB .
i5iza0wzhm ; rtB . hh0jnwyaeu = rtP . PIDController2_D * rtB . n4wofe3ie0 ;
rtB . g1lfzu0ene = rtX . cavw5nvkqb ; rtB . flo1u4pz55 = rtB . hh0jnwyaeu -
rtB . g1lfzu0ene ; rtB . eficrjdtnw = rtP . PIDController2_I * rtB .
n4wofe3ie0 ; rtB . avkuuvjjai = rtX . avlsrvqz00 ; rtB . kc4xhuqqmg = rtP .
PIDController2_N * rtB . flo1u4pz55 ; rtB . nyjovcmu1f = rtP .
PIDController2_P * rtB . n4wofe3ie0 ; rtB . m0t4zoneuz = ( rtB . nyjovcmu1f +
rtB . avkuuvjjai ) + rtB . kc4xhuqqmg ; rtB . lyhxgu33xz = rtP .
Constant_Value * rtB . l4yg5vogac ; rtB . lflglxiue0 = rtP . Constant1_Value
* rtB . m0t4zoneuz ; UNUSED_PARAMETER ( tid ) ; } void MdlUpdate ( int_T tid
) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID2 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> mybxqtllvq [ 0 ] = 0.0
; _rtXdot -> mybxqtllvq [ 0 ] += rtP . TransferFcn_A [ 0 ] * rtX . mybxqtllvq
[ 0 ] ; _rtXdot -> mybxqtllvq [ 1 ] = 0.0 ; _rtXdot -> mybxqtllvq [ 0 ] +=
rtP . TransferFcn_A [ 1 ] * rtX . mybxqtllvq [ 1 ] ; _rtXdot -> mybxqtllvq [
1 ] += rtX . mybxqtllvq [ 0 ] ; _rtXdot -> mybxqtllvq [ 0 ] += rtB .
lyhxgu33xz ; _rtXdot -> kgvvguxqca [ 0 ] = 0.0 ; _rtXdot -> kgvvguxqca [ 0 ]
+= rtP . TransferFcn2_A [ 0 ] * rtX . kgvvguxqca [ 0 ] ; _rtXdot ->
kgvvguxqca [ 1 ] = 0.0 ; _rtXdot -> kgvvguxqca [ 0 ] += rtP . TransferFcn2_A
[ 1 ] * rtX . kgvvguxqca [ 1 ] ; _rtXdot -> kgvvguxqca [ 1 ] += rtX .
kgvvguxqca [ 0 ] ; _rtXdot -> kgvvguxqca [ 0 ] += rtB . lflglxiue0 ; _rtXdot
-> dh2dovl5c2 = rtB . eb1szirxc5 ; _rtXdot -> jksrnqqge5 = rtB . gjjaboaewe ;
_rtXdot -> cavw5nvkqb = rtB . kc4xhuqqmg ; _rtXdot -> avlsrvqz00 = rtB .
eficrjdtnw ; } void MdlProjection ( void ) { } void MdlTerminate ( void ) {
if ( rt_slioCatalogue ( ) != ( NULL ) ) { void * * slioCatalogueAddr =
rt_slioCatalogueAddr ( ) ; rtwSaveDatasetsToMatFile (
rtwGetPointerFromUniquePtr ( rt_slioCatalogue ( ) ) ,
rt_GetMatSigstreamLoggingFileName ( ) ) ; rtwTerminateSlioCatalogue (
slioCatalogueAddr ) ; * slioCatalogueAddr = NULL ; } } void
MdlInitializeSizes ( void ) { ssSetNumContStates ( rtS , 8 ) ;
ssSetNumPeriodicContStates ( rtS , 0 ) ; ssSetNumY ( rtS , 0 ) ; ssSetNumU (
rtS , 0 ) ; ssSetDirectFeedThrough ( rtS , 0 ) ; ssSetNumSampleTimes ( rtS ,
2 ) ; ssSetNumBlocks ( rtS , 39 ) ; ssSetNumBlockIO ( rtS , 27 ) ;
ssSetNumBlockParams ( rtS , 24 ) ; } void MdlInitializeSampleTimes ( void ) {
ssSetSampleTime ( rtS , 0 , 0.0 ) ; ssSetSampleTime ( rtS , 1 , 0.0 ) ;
ssSetOffsetTime ( rtS , 0 , 0.0 ) ; ssSetOffsetTime ( rtS , 1 , 1.0 ) ; }
void raccel_set_checksum ( ) { ssSetChecksumVal ( rtS , 0 , 3145587776U ) ;
ssSetChecksumVal ( rtS , 1 , 3571904463U ) ; ssSetChecksumVal ( rtS , 2 ,
3333901365U ) ; ssSetChecksumVal ( rtS , 3 , 4037844916U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( void ) { static struct _ssMdlInfo mdlInfo
; ( void ) memset ( ( char * ) rtS , 0 , sizeof ( SimStruct ) ) ; ( void )
memset ( ( char * ) & mdlInfo , 0 , sizeof ( struct _ssMdlInfo ) ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 14 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
boat_control_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive ( rtS
, true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "boat_control" ) ;
ssSetPath ( rtS , "boat_control" ) ; ssSetTStart ( rtS , 0.0 ) ; ssSetTFinal
( rtS , 50.0 ) ; { static RTWLogInfo rt_DataLoggingInfo ; rt_DataLoggingInfo
. loggingInterval = NULL ; ssSetRTWLogInfo ( rtS , & rt_DataLoggingInfo ) ; }
{ rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogXSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; rtliSetLogT (
ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX ( ssGetRTWLogInfo ( rtS ) ,
"" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 8 ] ; static
real_T absTol [ 8 ] = { 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 , 1.0E-6 ,
1.0E-6 , 1.0E-6 } ; static uint8_T absTolControl [ 8 ] = { 0U , 0U , 0U , 0U
, 0U , 0U , 0U , 0U } ; ssSetSolverRelTol ( rtS , 0.001 ) ; ssSetStepSize (
rtS , 0.0 ) ; ssSetMinStepSize ( rtS , 0.0 ) ; ssSetMaxNumMinSteps ( rtS , -
1 ) ; ssSetMinStepViolatedError ( rtS , 0 ) ; ssSetMaxStepSize ( rtS , 1.0 )
; ssSetSolverMaxOrder ( rtS , - 1 ) ; ssSetSolverRefineFactor ( rtS , 1 ) ;
ssSetOutputTimes ( rtS , ( NULL ) ) ; ssSetNumOutputTimes ( rtS , 0 ) ;
ssSetOutputTimesOnly ( rtS , 0 ) ; ssSetOutputTimesIndex ( rtS , 0 ) ;
ssSetZCCacheNeedsReset ( rtS , 0 ) ; ssSetDerivCacheNeedsReset ( rtS , 0 ) ;
ssSetNumNonContDerivSigInfos ( rtS , 0 ) ; ssSetNonContDerivSigInfos ( rtS ,
( NULL ) ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ; ssSetSolverName ( rtS ,
"VariableStepAuto" ) ; ssSetVariableStepSolver ( rtS , 1 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 0 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ; ssSetAbsTolVector (
rtS , absTol ) ; ssSetAbsTolControlVector ( rtS , absTolControl ) ;
ssSetSolverAbsTol_Obsolete ( rtS , absTol ) ;
ssSetSolverAbsTolControl_Obsolete ( rtS , absTolControl ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelLogData ( rtS ,
rt_UpdateTXYLogVars ) ; ssSetModelLogDataIfInInterval ( rtS ,
rt_UpdateTXXFYLogVars ) ; ssSetModelUpdate ( rtS , MdlUpdate ) ;
ssSetModelDerivatives ( rtS , MdlDerivatives ) ;
ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ;
ssSetSolverShapePreserveControl ( rtS , 2 ) ; ssSetTNextTid ( rtS , INT_MIN )
; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; ssSetSolverMaxConsecutiveMinStep ( rtS , 1 ) ; }
ssSetChecksumVal ( rtS , 0 , 3145587776U ) ; ssSetChecksumVal ( rtS , 1 ,
3571904463U ) ; ssSetChecksumVal ( rtS , 2 , 3333901365U ) ; ssSetChecksumVal
( rtS , 3 , 4037844916U ) ; { static const sysRanDType rtAlwaysEnabled =
SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo rt_ExtModeInfo ; static const
sysRanDType * systemRan [ 4 ] ; gblRTWExtModeInfo = & rt_ExtModeInfo ;
ssSetRTWExtModeInfo ( rtS , & rt_ExtModeInfo ) ;
rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo , systemRan ) ;
systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = & rtAlwaysEnabled ;
systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } return rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 2 ; void MdlOutputsParameterSampleTime (
int_T tid ) { UNUSED_PARAMETER ( tid ) ; }
