#include "__cf_flightControlSystem.h"
#ifndef RTW_HEADER_flightControlSystem_private_h_
#define RTW_HEADER_flightControlSystem_private_h_
#include "rtwtypes.h"
#include "model_reference_types.h"
#include "multiword_types.h"
#ifndef rtmIsSampleHit
#define rtmIsSampleHit(sti, tid) (hvmvol3vsk->taskCounter[nmtwkzsqud[sti]] == _PIqWtbzrbQqv_KS_31HnE2)
#endif
#ifndef rtmIsSpecialSampleHit
#define rtmIsSpecialSampleHit(sti, prom_sti, tid) ( *((hvmvol3vsk->rateTransition)[nmtwkzsqud[sti] + hvmvol3vsk->nTasks*nmtwkzsqud[prom_sti]]) )
#endif
#ifndef rtmGetClockTick0
#define rtmGetClockTick0() ( *((hvmvol3vsk->clockTick[nmtwkzsqud[_PIqWtbzrbQqv_KS_31HnE2]])) )
#endif
#ifndef rtmGetClockTick1
#define rtmGetClockTick1() ( *((hvmvol3vsk->clockTick[nmtwkzsqud[_QHNSjd8JBrVVYZAcs7Zm32]])) )
#endif
#ifndef rtmGetClockTickH0
#define rtmGetClockTickH0() ( *(hvmvol3vsk->clockTickH[nmtwkzsqud[_PIqWtbzrbQqv_KS_31HnE2]]) )
#endif
#ifndef rtmGetClockTickH1
#define rtmGetClockTickH1() ( *(hvmvol3vsk->clockTickH[nmtwkzsqud[_QHNSjd8JBrVVYZAcs7Zm32]]) )
#endif
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm) (*((rtm)->errorStatus))
#endif
#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val) (*((rtm)->errorStatus) = (val))
#endif
#ifndef rtmGetErrorStatusPointer
#define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif
#ifndef rtmSetErrorStatusPointer
#define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif
#ifndef rtmGetT
#define rtmGetT() (*(hvmvol3vsk->taskTime[_PIqWtbzrbQqv_KS_31HnE2]))
#endif
extern uint8_T * imRGB ; extern int_T nmtwkzsqud [ _gN74BbsU5wqNjkJbC9b672 ]
; extern const rtTimingBridge * hvmvol3vsk ;
#ifndef flightControlSystem_MDLREF_HIDE_CHILD_
extern ileg2v2ld1r b1hr2q0zjh ;
#endif
#endif
