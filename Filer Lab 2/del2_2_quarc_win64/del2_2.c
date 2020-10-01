/*
 * del2_2.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "del2_2".
 *
 * Model version              : 1.69
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Oct 01 15:53:20 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "del2_2.h"
#include "del2_2_private.h"
#include "del2_2_dt.h"

/* Block signals (auto storage) */
B_del2_2_T del2_2_B;

/* Continuous states */
X_del2_2_T del2_2_X;

/* Block states (auto storage) */
DW_del2_2_T del2_2_DW;

/* Real-time model */
RT_MODEL_del2_2_T del2_2_M_;
RT_MODEL_del2_2_T *const del2_2_M = &del2_2_M_;
static void rate_monotonic_scheduler(void);
time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(del2_2_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(del2_2_M, 2);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rate: 2 */
  if (del2_2_M->Timing.TaskCounters.TID[1] == 0) {
    del2_2_M->Timing.RateInteraction.TID1_2 = (del2_2_M->
      Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    del2_2_M->Timing.perTaskSampleHits[5] =
      del2_2_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (del2_2_M->Timing.TaskCounters.TID[2])++;
  if ((del2_2_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    del2_2_M->Timing.TaskCounters.TID[2] = 0;
  }
}

/*
 * This function updates continuous states using the ODE1 fixed-step
 * solver algorithm
 */
static void rt_ertODEUpdateContinuousStates(RTWSolverInfo *si )
{
  time_T tnew = rtsiGetSolverStopTime(si);
  time_T h = rtsiGetStepSize(si);
  real_T *x = rtsiGetContStates(si);
  ODE1_IntgData *id = (ODE1_IntgData *)rtsiGetSolverData(si);
  real_T *f0 = id->f[0];
  int_T i;
  int_T nXc = 3;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  del2_2_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void del2_2_output0(void)              /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_HILReadEncoderTimebase_o2;
  real_T rtb_DeadZonex;
  real_T rtb_Backgain;
  real_T u0;
  if (rtmIsMajorTimeStep(del2_2_M)) {
    /* set solver stop time */
    if (!(del2_2_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&del2_2_M->solverInfo,
                            ((del2_2_M->Timing.clockTickH0 + 1) *
        del2_2_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&del2_2_M->solverInfo, ((del2_2_M->Timing.clockTick0
        + 1) * del2_2_M->Timing.stepSize0 + del2_2_M->Timing.clockTickH0 *
        del2_2_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(del2_2_M)) {
    del2_2_M->Timing.t[0] = rtsiGetT(&del2_2_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(del2_2_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: del2_2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder(del2_2_DW.HILReadEncoderTimebase_Task, 1,
        &del2_2_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 = del2_2_DW.HILReadEncoderTimebase_Buffer
          [0];
        rtb_HILReadEncoderTimebase_o2 = del2_2_DW.HILReadEncoderTimebase_Buffer
          [1];
        rtb_DeadZonex = del2_2_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S3>/Elevation: Count to rad' */
    del2_2_B.ElevationCounttorad = del2_2_P.ElevationCounttorad_Gain *
      rtb_DeadZonex;
  }

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  del2_2_B.ElevationTransferFcn = 0.0;
  del2_2_B.ElevationTransferFcn += del2_2_P.ElevationTransferFcn_C *
    del2_2_X.ElevationTransferFcn_CSTATE;
  del2_2_B.ElevationTransferFcn += del2_2_P.ElevationTransferFcn_D *
    del2_2_B.ElevationCounttorad;

  /* RateTransition: '<S4>/Rate Transition: y' incorporates:
   *  Constant: '<Root>/Constant'
   */
  if (rtmIsMajorTimeStep(del2_2_M)) {
    if (del2_2_M->Timing.RateInteraction.TID1_2) {
      del2_2_B.RateTransitiony = del2_2_DW.RateTransitiony_Buffer0;
    }

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (del2_2_B.RateTransitiony > del2_2_P.DeadZoney_End) {
      rtb_DeadZonex = del2_2_B.RateTransitiony - del2_2_P.DeadZoney_End;
    } else if (del2_2_B.RateTransitiony >= del2_2_P.DeadZoney_Start) {
      rtb_DeadZonex = 0.0;
    } else {
      rtb_DeadZonex = del2_2_B.RateTransitiony - del2_2_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    del2_2_B.Joystick_gain_y = del2_2_P.Gainy_Gain * rtb_DeadZonex *
      del2_2_P.Joystick_gain_y;

    /* Sum: '<Root>/Sum2' */
    del2_2_B.Sum2 = del2_2_B.Joystick_gain_y;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    del2_2_B.Sum = del2_2_P.e_0 + del2_2_B.ElevationCounttorad;
    del2_2_B.Constant = del2_2_P.V_s0;
  }

  /* End of RateTransition: '<S4>/Rate Transition: y' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S2>/Gain'
   *  Sum: '<S2>/Sum'
   *  Sum: '<S2>/Sum1'
   */
  del2_2_B.Sum_o = ((del2_2_B.Sum2 - del2_2_B.ElevationTransferFcn) *
                    del2_2_P.Gain_Gain + del2_2_B.Sum) + del2_2_B.Constant;
  if (rtmIsMajorTimeStep(del2_2_M)) {
    /* RateTransition: '<S4>/Rate Transition: x' */
    if (del2_2_M->Timing.RateInteraction.TID1_2) {
      del2_2_B.RateTransitionx = del2_2_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (del2_2_B.RateTransitionx > del2_2_P.DeadZonex_End) {
      rtb_DeadZonex = del2_2_B.RateTransitionx - del2_2_P.DeadZonex_End;
    } else if (del2_2_B.RateTransitionx >= del2_2_P.DeadZonex_Start) {
      rtb_DeadZonex = 0.0;
    } else {
      rtb_DeadZonex = del2_2_B.RateTransitionx - del2_2_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    del2_2_B.Joystick_gain_x = del2_2_P.Gainx_Gain * rtb_DeadZonex *
      del2_2_P.Joystick_gain_x;

    /* Gain: '<S3>/Pitch: Count to rad' */
    del2_2_B.PitchCounttorad = del2_2_P.PitchCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o2;

    /* Gain: '<S5>/proportional gain' incorporates:
     *  Sum: '<Root>/Sum4'
     *  Sum: '<S5>/Sum'
     */
    del2_2_B.proportionalgain = (del2_2_B.Joystick_gain_x -
      del2_2_B.PitchCounttorad) * del2_2_P.proportionalgain_Gain;
  }

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  del2_2_B.PitchTransferFcn = 0.0;
  del2_2_B.PitchTransferFcn += del2_2_P.PitchTransferFcn_C *
    del2_2_X.PitchTransferFcn_CSTATE;
  del2_2_B.PitchTransferFcn += del2_2_P.PitchTransferFcn_D *
    del2_2_B.PitchCounttorad;

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/derivative gain'
   */
  rtb_Backgain = del2_2_B.proportionalgain - del2_2_P.derivativegain_Gain *
    del2_2_B.PitchTransferFcn;
  if (rtmIsMajorTimeStep(del2_2_M)) {
    /* Gain: '<S3>/Travel: Count to rad' */
    del2_2_B.TravelCounttorad = del2_2_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  del2_2_B.TravelTransferFcn = 0.0;
  del2_2_B.TravelTransferFcn += del2_2_P.TravelTransferFcn_C *
    del2_2_X.TravelTransferFcn_CSTATE;
  del2_2_B.TravelTransferFcn += del2_2_P.TravelTransferFcn_D *
    del2_2_B.TravelCounttorad;
  if (rtmIsMajorTimeStep(del2_2_M)) {
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (del2_2_B.Sum_o - rtb_Backgain) * del2_2_P.Frontgain_Gain;

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (u0 > del2_2_P.FrontmotorSaturation_UpperSat) {
    del2_2_B.FrontmotorSaturation = del2_2_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < del2_2_P.FrontmotorSaturation_LowerSat) {
    del2_2_B.FrontmotorSaturation = del2_2_P.FrontmotorSaturation_LowerSat;
  } else {
    del2_2_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (del2_2_B.Sum_o + rtb_Backgain) * del2_2_P.Backgain_Gain;

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (u0 > del2_2_P.BackmotorSaturation_UpperSat) {
    del2_2_B.BackmotorSaturation = del2_2_P.BackmotorSaturation_UpperSat;
  } else if (u0 < del2_2_P.BackmotorSaturation_LowerSat) {
    del2_2_B.BackmotorSaturation = del2_2_P.BackmotorSaturation_LowerSat;
  } else {
    del2_2_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(del2_2_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: del2_2/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      del2_2_DW.HILWriteAnalog_Buffer[0] = del2_2_B.FrontmotorSaturation;
      del2_2_DW.HILWriteAnalog_Buffer[1] = del2_2_B.BackmotorSaturation;
      result = hil_write_analog(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILWriteAnalog_channels, 2, &del2_2_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
      }
    }
  }
}

/* Model update function for TID0 */
void del2_2_update0(void)              /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(del2_2_M)) {
    rt_ertODEUpdateContinuousStates(&del2_2_M->solverInfo);
  }

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++del2_2_M->Timing.clockTick0)) {
    ++del2_2_M->Timing.clockTickH0;
  }

  del2_2_M->Timing.t[0] = rtsiGetSolverStopTime(&del2_2_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++del2_2_M->Timing.clockTick1)) {
    ++del2_2_M->Timing.clockTickH1;
  }

  del2_2_M->Timing.t[1] = del2_2_M->Timing.clockTick1 *
    del2_2_M->Timing.stepSize1 + del2_2_M->Timing.clockTickH1 *
    del2_2_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void del2_2_derivatives(void)
{
  XDot_del2_2_T *_rtXdot;
  _rtXdot = ((XDot_del2_2_T *) del2_2_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE += del2_2_P.ElevationTransferFcn_A *
    del2_2_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE += del2_2_B.ElevationCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE += del2_2_P.PitchTransferFcn_A *
    del2_2_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += del2_2_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE += del2_2_P.TravelTransferFcn_A *
    del2_2_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE += del2_2_B.TravelCounttorad;
}

/* Model output function for TID2 */
void del2_2_output2(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: del2_2/Joystick/Game Controller (game_controller_block) */
  {
    if (del2_2_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll(del2_2_DW.GameController_Controller, &state,
        &new_data);
      if (result == 0) {
        del2_2_B.GameController_o4 = state.x;
        del2_2_B.GameController_o5 = state.y;
      }
    } else {
      del2_2_B.GameController_o4 = 0;
      del2_2_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void del2_2_update2(void)              /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  del2_2_DW.RateTransitiony_Buffer0 = del2_2_B.GameController_o5;

  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  del2_2_DW.RateTransitionx_Buffer0 = del2_2_B.GameController_o4;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++del2_2_M->Timing.clockTick2)) {
    ++del2_2_M->Timing.clockTickH2;
  }

  del2_2_M->Timing.t[2] = del2_2_M->Timing.clockTick2 *
    del2_2_M->Timing.stepSize2 + del2_2_M->Timing.clockTickH2 *
    del2_2_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void del2_2_output(int_T tid)
{
  switch (tid) {
   case 0 :
    del2_2_output0();
    break;

   case 2 :
    del2_2_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void del2_2_update(int_T tid)
{
  switch (tid) {
   case 0 :
    del2_2_update0();
    break;

   case 2 :
    del2_2_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void del2_2_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: del2_2/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0", &del2_2_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(del2_2_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options(del2_2_DW.HILInitialize_Card,
      "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(del2_2_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(del2_2_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(del2_2_M, _rt_error_message);
      return;
    }

    if ((del2_2_P.HILInitialize_set_analog_input_ && !is_switching) ||
        (del2_2_P.HILInitialize_set_analog_inpu_m && is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums = &del2_2_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] = del2_2_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums = &del2_2_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] = del2_2_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_analog_input_chan, 8U,
        &del2_2_DW.HILInitialize_AIMinimums[0],
        &del2_2_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if ((del2_2_P.HILInitialize_set_analog_output && !is_switching) ||
        (del2_2_P.HILInitialize_set_analog_outp_b && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums = &del2_2_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] = del2_2_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums = &del2_2_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] = del2_2_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_analog_output_cha, 8U,
        &del2_2_DW.HILInitialize_AOMinimums[0],
        &del2_2_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if ((del2_2_P.HILInitialize_set_analog_outp_e && !is_switching) ||
        (del2_2_P.HILInitialize_set_analog_outp_j && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &del2_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = del2_2_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_analog_output_cha, 8U,
        &del2_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if (del2_2_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &del2_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = del2_2_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (del2_2_DW.HILInitialize_Card, del2_2_P.HILInitialize_analog_output_cha,
         8U, &del2_2_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if ((del2_2_P.HILInitialize_set_encoder_param && !is_switching) ||
        (del2_2_P.HILInitialize_set_encoder_par_m && is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes = &del2_2_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] = del2_2_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_encoder_channels, 8U, (t_encoder_quadrature_mode *)
        &del2_2_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if ((del2_2_P.HILInitialize_set_encoder_count && !is_switching) ||
        (del2_2_P.HILInitialize_set_encoder_cou_k && is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts = &del2_2_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] = del2_2_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_encoder_channels, 8U,
        &del2_2_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if ((del2_2_P.HILInitialize_set_pwm_params_at && !is_switching) ||
        (del2_2_P.HILInitialize_set_pwm_params__f && is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues = &del2_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = del2_2_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &del2_2_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          del2_2_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues = &del2_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            del2_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes] =
              p_HILInitialize_pwm_channels[i1];
            del2_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes] =
              del2_2_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            del2_2_DW.HILInitialize_POSortedChans[7U - num_frequency_modes] =
              p_HILInitialize_pwm_channels[i1];
            del2_2_DW.HILInitialize_POSortedFreqs[7U - num_frequency_modes] =
              del2_2_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency(del2_2_DW.HILInitialize_Card,
          &del2_2_DW.HILInitialize_POSortedChans[0], num_duty_cycle_modes,
          &del2_2_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(del2_2_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle(del2_2_DW.HILInitialize_Card,
          &del2_2_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
          num_frequency_modes,
          &del2_2_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(del2_2_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues = &del2_2_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] = del2_2_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues = &del2_2_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] = del2_2_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals = &del2_2_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] = del2_2_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_pwm_channels, 8U,
        (t_pwm_configuration *) &del2_2_DW.HILInitialize_POModeValues[0],
        (t_pwm_alignment *) &del2_2_DW.HILInitialize_POAlignValues[0],
        (t_pwm_polarity *) &del2_2_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs = &del2_2_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] = del2_2_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues = &del2_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = del2_2_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_pwm_channels, 8U,
        &del2_2_DW.HILInitialize_POSortedFreqs[0],
        &del2_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if ((del2_2_P.HILInitialize_set_pwm_outputs_a && !is_switching) ||
        (del2_2_P.HILInitialize_set_pwm_outputs_g && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &del2_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = del2_2_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(del2_2_DW.HILInitialize_Card,
        del2_2_P.HILInitialize_pwm_channels, 8U,
        &del2_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }

    if (del2_2_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues = &del2_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = del2_2_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (del2_2_DW.HILInitialize_Card, del2_2_P.HILInitialize_pwm_channels, 8U,
         &del2_2_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: del2_2/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader(del2_2_DW.HILInitialize_Card,
      del2_2_P.HILReadEncoderTimebase_samples_,
      del2_2_P.HILReadEncoderTimebase_channels, 3,
      &del2_2_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(del2_2_M, _rt_error_message);
    }
  }

  /* Start for RateTransition: '<S4>/Rate Transition: y' */
  del2_2_B.RateTransitiony = del2_2_P.RateTransitiony_X0;

  /* Start for RateTransition: '<S4>/Rate Transition: x' */
  del2_2_B.RateTransitionx = del2_2_P.RateTransitionx_X0;

  /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: del2_2/Joystick/Game Controller (game_controller_block) */
  {
    if (del2_2_P.GameController_Enabled) {
      t_double deadzone[6];
      t_double saturation[6];
      t_int index;
      t_error result;
      for (index = 0; index < 6; index++) {
        deadzone[index] = -1;
      }

      for (index = 0; index < 6; index++) {
        saturation[index] = -1;
      }

      result = game_controller_open(del2_2_P.GameController_ControllerNumber,
        del2_2_P.GameController_BufferSize, deadzone, saturation,
        del2_2_P.GameController_AutoCenter, 0, 1.0,
        &del2_2_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(del2_2_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  del2_2_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
  del2_2_DW.RateTransitiony_Buffer0 = del2_2_P.RateTransitiony_X0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
  del2_2_DW.RateTransitionx_Buffer0 = del2_2_P.RateTransitionx_X0;

  /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  del2_2_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  del2_2_X.TravelTransferFcn_CSTATE = 0.0;
}

/* Model terminate function */
void del2_2_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: del2_2/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(del2_2_DW.HILInitialize_Card);
    hil_monitor_stop_all(del2_2_DW.HILInitialize_Card);
    is_switching = false;
    if ((del2_2_P.HILInitialize_set_analog_out_ex && !is_switching) ||
        (del2_2_P.HILInitialize_set_analog_outp_c && is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages = &del2_2_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] = del2_2_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((del2_2_P.HILInitialize_set_pwm_output_ap && !is_switching) ||
        (del2_2_P.HILInitialize_set_pwm_outputs_p && is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues = &del2_2_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] = del2_2_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(del2_2_DW.HILInitialize_Card
                         , del2_2_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , del2_2_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         , &del2_2_DW.HILInitialize_AOVoltages[0]
                         , &del2_2_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog(del2_2_DW.HILInitialize_Card,
            del2_2_P.HILInitialize_analog_output_cha, num_final_analog_outputs,
            &del2_2_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm(del2_2_DW.HILInitialize_Card,
            del2_2_P.HILInitialize_pwm_channels, num_final_pwm_outputs,
            &del2_2_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(del2_2_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(del2_2_DW.HILInitialize_Card);
    hil_monitor_delete_all(del2_2_DW.HILInitialize_Card);
    hil_close(del2_2_DW.HILInitialize_Card);
    del2_2_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: del2_2/Joystick/Game Controller (game_controller_block) */
  {
    if (del2_2_P.GameController_Enabled) {
      game_controller_close(del2_2_DW.GameController_Controller);
      del2_2_DW.GameController_Controller = NULL;
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/

/* Solver interface called by GRT_Main */
#ifndef USE_GENERATED_SOLVER

void rt_ODECreateIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEDestroyIntegrationData(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

void rt_ODEUpdateContinuousStates(RTWSolverInfo *si)
{
  UNUSED_PARAMETER(si);
  return;
}                                      /* do nothing */

#endif

void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  del2_2_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  del2_2_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  del2_2_initialize();
}

void MdlTerminate(void)
{
  del2_2_terminate();
}

/* Registration function */
RT_MODEL_del2_2_T *del2_2(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)del2_2_M, 0,
                sizeof(RT_MODEL_del2_2_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&del2_2_M->solverInfo, &del2_2_M->Timing.simTimeStep);
    rtsiSetTPtr(&del2_2_M->solverInfo, &rtmGetTPtr(del2_2_M));
    rtsiSetStepSizePtr(&del2_2_M->solverInfo, &del2_2_M->Timing.stepSize0);
    rtsiSetdXPtr(&del2_2_M->solverInfo, &del2_2_M->ModelData.derivs);
    rtsiSetContStatesPtr(&del2_2_M->solverInfo, (real_T **)
                         &del2_2_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&del2_2_M->solverInfo,
      &del2_2_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&del2_2_M->solverInfo,
      &del2_2_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&del2_2_M->solverInfo,
      &del2_2_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&del2_2_M->solverInfo,
      &del2_2_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&del2_2_M->solverInfo, (&rtmGetErrorStatus(del2_2_M)));
    rtsiSetRTModelPtr(&del2_2_M->solverInfo, del2_2_M);
  }

  rtsiSetSimTimeStep(&del2_2_M->solverInfo, MAJOR_TIME_STEP);
  del2_2_M->ModelData.intgData.f[0] = del2_2_M->ModelData.odeF[0];
  del2_2_M->ModelData.contStates = ((real_T *) &del2_2_X);
  rtsiSetSolverData(&del2_2_M->solverInfo, (void *)&del2_2_M->ModelData.intgData);
  rtsiSetSolverName(&del2_2_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = del2_2_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    del2_2_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    del2_2_M->Timing.sampleTimes = (&del2_2_M->Timing.sampleTimesArray[0]);
    del2_2_M->Timing.offsetTimes = (&del2_2_M->Timing.offsetTimesArray[0]);

    /* task periods */
    del2_2_M->Timing.sampleTimes[0] = (0.0);
    del2_2_M->Timing.sampleTimes[1] = (0.002);
    del2_2_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    del2_2_M->Timing.offsetTimes[0] = (0.0);
    del2_2_M->Timing.offsetTimes[1] = (0.0);
    del2_2_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(del2_2_M, &del2_2_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = del2_2_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = del2_2_M->Timing.perTaskSampleHitsArray;
    del2_2_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    del2_2_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(del2_2_M, -1);
  del2_2_M->Timing.stepSize0 = 0.002;
  del2_2_M->Timing.stepSize1 = 0.002;
  del2_2_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  del2_2_M->Sizes.checksums[0] = (241761384U);
  del2_2_M->Sizes.checksums[1] = (4058928561U);
  del2_2_M->Sizes.checksums[2] = (3875133459U);
  del2_2_M->Sizes.checksums[3] = (513982315U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    del2_2_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(del2_2_M->extModeInfo,
      &del2_2_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(del2_2_M->extModeInfo, del2_2_M->Sizes.checksums);
    rteiSetTPtr(del2_2_M->extModeInfo, rtmGetTPtr(del2_2_M));
  }

  del2_2_M->solverInfoPtr = (&del2_2_M->solverInfo);
  del2_2_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&del2_2_M->solverInfo, 0.002);
  rtsiSetSolverMode(&del2_2_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  del2_2_M->ModelData.blockIO = ((void *) &del2_2_B);

  {
    del2_2_B.ElevationCounttorad = 0.0;
    del2_2_B.ElevationTransferFcn = 0.0;
    del2_2_B.RateTransitiony = 0.0;
    del2_2_B.Joystick_gain_y = 0.0;
    del2_2_B.Sum2 = 0.0;
    del2_2_B.Sum = 0.0;
    del2_2_B.Constant = 0.0;
    del2_2_B.Sum_o = 0.0;
    del2_2_B.RateTransitionx = 0.0;
    del2_2_B.Joystick_gain_x = 0.0;
    del2_2_B.PitchCounttorad = 0.0;
    del2_2_B.proportionalgain = 0.0;
    del2_2_B.PitchTransferFcn = 0.0;
    del2_2_B.TravelCounttorad = 0.0;
    del2_2_B.TravelTransferFcn = 0.0;
    del2_2_B.FrontmotorSaturation = 0.0;
    del2_2_B.BackmotorSaturation = 0.0;
    del2_2_B.GameController_o4 = 0.0;
    del2_2_B.GameController_o5 = 0.0;
  }

  /* parameters */
  del2_2_M->ModelData.defaultParam = ((real_T *)&del2_2_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &del2_2_X;
    del2_2_M->ModelData.contStates = (x);
    (void) memset((void *)&del2_2_X, 0,
                  sizeof(X_del2_2_T));
  }

  /* states (dwork) */
  del2_2_M->ModelData.dwork = ((void *) &del2_2_DW);
  (void) memset((void *)&del2_2_DW, 0,
                sizeof(DW_del2_2_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      del2_2_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  del2_2_DW.RateTransitiony_Buffer0 = 0.0;
  del2_2_DW.RateTransitionx_Buffer0 = 0.0;
  del2_2_DW.HILWriteAnalog_Buffer[0] = 0.0;
  del2_2_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    del2_2_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  del2_2_M->Sizes.numContStates = (3); /* Number of continuous states */
  del2_2_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  del2_2_M->Sizes.numY = (0);          /* Number of model outputs */
  del2_2_M->Sizes.numU = (0);          /* Number of model inputs */
  del2_2_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  del2_2_M->Sizes.numSampTimes = (3);  /* Number of sample times */
  del2_2_M->Sizes.numBlocks = (47);    /* Number of blocks */
  del2_2_M->Sizes.numBlockIO = (19);   /* Number of block outputs */
  del2_2_M->Sizes.numBlockPrms = (140);/* Sum of parameter "widths" */
  return del2_2_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
