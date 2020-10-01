/*
 * Del1_RIKTIG_presentasjon.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "Del1_RIKTIG_presentasjon".
 *
 * Model version              : 1.65
 * Simulink Coder version : 8.9 (R2015b) 13-Aug-2015
 * C source code generated on : Thu Oct 01 09:06:31 2020
 *
 * Target selection: quarc_win64.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "Del1_RIKTIG_presentasjon.h"
#include "Del1_RIKTIG_presentasjon_private.h"
#include "Del1_RIKTIG_presentasjon_dt.h"

/* Block signals (auto storage) */
B_Del1_RIKTIG_presentasjon_T Del1_RIKTIG_presentasjon_B;

/* Continuous states */
X_Del1_RIKTIG_presentasjon_T Del1_RIKTIG_presentasjon_X;

/* Block states (auto storage) */
DW_Del1_RIKTIG_presentasjon_T Del1_RIKTIG_presentasjon_DW;

/* Real-time model */
RT_MODEL_Del1_RIKTIG_presenta_T Del1_RIKTIG_presentasjon_M_;
RT_MODEL_Del1_RIKTIG_presenta_T *const Del1_RIKTIG_presentasjon_M =
  &Del1_RIKTIG_presentasjon_M_;
static void rate_monotonic_scheduler(void);

/*
 * Writes out MAT-file header.  Returns success or failure.
 * Returns:
 *      0 - success
 *      1 - failure
 */
int_T rt_WriteMat4FileHeader(FILE *fp, int32_T m, int32_T n, const char *name)
{
  typedef enum { ELITTLE_ENDIAN, EBIG_ENDIAN } ByteOrder;

  int16_T one = 1;
  ByteOrder byteOrder = (*((int8_T *)&one)==1) ? ELITTLE_ENDIAN : EBIG_ENDIAN;
  int32_T type = (byteOrder == ELITTLE_ENDIAN) ? 0: 1000;
  int32_T imagf = 0;
  int32_T name_len = (int32_T)strlen(name) + 1;
  if ((fwrite(&type, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&m, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&n, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&imagf, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(&name_len, sizeof(int32_T), 1, fp) == 0) ||
      (fwrite(name, sizeof(char), name_len, fp) == 0)) {
    return(1);
  } else {
    return(0);
  }
}                                      /* end rt_WriteMat4FileHeader */

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(Del1_RIKTIG_presentasjon_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(Del1_RIKTIG_presentasjon_M, 2);
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
  if (Del1_RIKTIG_presentasjon_M->Timing.TaskCounters.TID[1] == 0) {
    Del1_RIKTIG_presentasjon_M->Timing.RateInteraction.TID1_2 =
      (Del1_RIKTIG_presentasjon_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    Del1_RIKTIG_presentasjon_M->Timing.perTaskSampleHits[5] =
      Del1_RIKTIG_presentasjon_M->Timing.RateInteraction.TID1_2;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (Del1_RIKTIG_presentasjon_M->Timing.TaskCounters.TID[2])++;
  if ((Del1_RIKTIG_presentasjon_M->Timing.TaskCounters.TID[2]) > 4) {/* Sample time: [0.01s, 0.0s] */
    Del1_RIKTIG_presentasjon_M->Timing.TaskCounters.TID[2] = 0;
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
  int_T nXc = 4;
  rtsiSetSimTimeStep(si,MINOR_TIME_STEP);
  rtsiSetdX(si, f0);
  Del1_RIKTIG_presentasjon_derivatives();
  rtsiSetT(si, tnew);
  for (i = 0; i < nXc; ++i) {
    x[i] += h * f0[i];
  }

  rtsiSetSimTimeStep(si,MAJOR_TIME_STEP);
}

/* Model output function for TID0 */
void Del1_RIKTIG_presentasjon_output0(void) /* Sample time: [0.0s, 0.0s] */
{
  /* local block i/o variables */
  real_T rtb_HILReadEncoderTimebase_o1;
  real_T rtb_TmpSignalConversionAtToFile[6];
  real_T rtb_Sum_k;
  real_T rtb_Sum1;
  real_T rtb_Backgain;
  real_T u0;
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    /* set solver stop time */
    if (!(Del1_RIKTIG_presentasjon_M->Timing.clockTick0+1)) {
      rtsiSetSolverStopTime(&Del1_RIKTIG_presentasjon_M->solverInfo,
                            ((Del1_RIKTIG_presentasjon_M->Timing.clockTickH0 + 1)
        * Del1_RIKTIG_presentasjon_M->Timing.stepSize0 * 4294967296.0));
    } else {
      rtsiSetSolverStopTime(&Del1_RIKTIG_presentasjon_M->solverInfo,
                            ((Del1_RIKTIG_presentasjon_M->Timing.clockTick0 + 1)
        * Del1_RIKTIG_presentasjon_M->Timing.stepSize0 +
        Del1_RIKTIG_presentasjon_M->Timing.clockTickH0 *
        Del1_RIKTIG_presentasjon_M->Timing.stepSize0 * 4294967296.0));
    }

    {                                  /* Sample time: [0.0s, 0.0s] */
      rate_monotonic_scheduler();
    }
  }                                    /* end MajorTimeStep */

  /* Update absolute time of base rate at minor time step */
  if (rtmIsMinorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    Del1_RIKTIG_presentasjon_M->Timing.t[0] = rtsiGetT
      (&Del1_RIKTIG_presentasjon_M->solverInfo);
  }

  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    /* S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

    /* S-Function Block: Del1_RIKTIG_presentasjon/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
    {
      t_error result;
      result = hil_task_read_encoder
        (Del1_RIKTIG_presentasjon_DW.HILReadEncoderTimebase_Task, 1,
         &Del1_RIKTIG_presentasjon_DW.HILReadEncoderTimebase_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
      } else {
        rtb_HILReadEncoderTimebase_o1 =
          Del1_RIKTIG_presentasjon_DW.HILReadEncoderTimebase_Buffer[0];
        rtb_Sum_k = Del1_RIKTIG_presentasjon_DW.HILReadEncoderTimebase_Buffer[1];
        rtb_Sum1 = Del1_RIKTIG_presentasjon_DW.HILReadEncoderTimebase_Buffer[2];
      }
    }

    /* Gain: '<S3>/Travel: Count to rad' */
    Del1_RIKTIG_presentasjon_B.TravelCounttorad =
      Del1_RIKTIG_presentasjon_P.TravelCounttorad_Gain *
      rtb_HILReadEncoderTimebase_o1;

    /* Gain: '<S3>/Pitch: Count to rad' */
    Del1_RIKTIG_presentasjon_B.PitchCounttorad =
      Del1_RIKTIG_presentasjon_P.PitchCounttorad_Gain * rtb_Sum_k;
  }

  /* TransferFcn: '<S3>/Travel: Transfer Fcn' */
  Del1_RIKTIG_presentasjon_B.TravelTransferFcn = 0.0;
  Del1_RIKTIG_presentasjon_B.TravelTransferFcn +=
    Del1_RIKTIG_presentasjon_P.TravelTransferFcn_C *
    Del1_RIKTIG_presentasjon_X.TravelTransferFcn_CSTATE;
  Del1_RIKTIG_presentasjon_B.TravelTransferFcn +=
    Del1_RIKTIG_presentasjon_P.TravelTransferFcn_D *
    Del1_RIKTIG_presentasjon_B.TravelCounttorad;

  /* TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  Del1_RIKTIG_presentasjon_B.PitchTransferFcn = 0.0;
  Del1_RIKTIG_presentasjon_B.PitchTransferFcn +=
    Del1_RIKTIG_presentasjon_P.PitchTransferFcn_C *
    Del1_RIKTIG_presentasjon_X.PitchTransferFcn_CSTATE;
  Del1_RIKTIG_presentasjon_B.PitchTransferFcn +=
    Del1_RIKTIG_presentasjon_P.PitchTransferFcn_D *
    Del1_RIKTIG_presentasjon_B.PitchCounttorad;
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    /* Gain: '<S3>/Elevation: Count to rad' */
    Del1_RIKTIG_presentasjon_B.ElevationCounttorad =
      Del1_RIKTIG_presentasjon_P.ElevationCounttorad_Gain * rtb_Sum1;

    /* Sum: '<S3>/Sum' incorporates:
     *  Constant: '<S3>/Constant'
     */
    Del1_RIKTIG_presentasjon_B.Sum = -Del1_RIKTIG_presentasjon_P.e_0 +
      Del1_RIKTIG_presentasjon_B.ElevationCounttorad;
  }

  /* TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  Del1_RIKTIG_presentasjon_B.ElevationTransferFcn = 0.0;
  Del1_RIKTIG_presentasjon_B.ElevationTransferFcn +=
    Del1_RIKTIG_presentasjon_P.ElevationTransferFcn_C *
    Del1_RIKTIG_presentasjon_X.ElevationTransferFcn_CSTATE;
  Del1_RIKTIG_presentasjon_B.ElevationTransferFcn +=
    Del1_RIKTIG_presentasjon_P.ElevationTransferFcn_D *
    Del1_RIKTIG_presentasjon_B.ElevationCounttorad;
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    /* SignalConversion: '<Root>/TmpSignal ConversionAtTo FileInport1' */
    rtb_TmpSignalConversionAtToFile[0] =
      Del1_RIKTIG_presentasjon_B.TravelCounttorad;
    rtb_TmpSignalConversionAtToFile[1] =
      Del1_RIKTIG_presentasjon_B.TravelTransferFcn;
    rtb_TmpSignalConversionAtToFile[2] =
      Del1_RIKTIG_presentasjon_B.PitchCounttorad;
    rtb_TmpSignalConversionAtToFile[3] =
      Del1_RIKTIG_presentasjon_B.PitchTransferFcn;
    rtb_TmpSignalConversionAtToFile[4] = Del1_RIKTIG_presentasjon_B.Sum;
    rtb_TmpSignalConversionAtToFile[5] =
      Del1_RIKTIG_presentasjon_B.ElevationTransferFcn;

    /* ToFile: '<Root>/To File' */
    if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
      {
        if (!(++Del1_RIKTIG_presentasjon_DW.ToFile_IWORK.Decimation % 1) &&
            (Del1_RIKTIG_presentasjon_DW.ToFile_IWORK.Count*7)+1 < 100000000 ) {
          FILE *fp = (FILE *) Del1_RIKTIG_presentasjon_DW.ToFile_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[7];
            Del1_RIKTIG_presentasjon_DW.ToFile_IWORK.Decimation = 0;
            u[0] = Del1_RIKTIG_presentasjon_M->Timing.t[1];
            u[1] = rtb_TmpSignalConversionAtToFile[0];
            u[2] = rtb_TmpSignalConversionAtToFile[1];
            u[3] = rtb_TmpSignalConversionAtToFile[2];
            u[4] = rtb_TmpSignalConversionAtToFile[3];
            u[5] = rtb_TmpSignalConversionAtToFile[4];
            u[6] = rtb_TmpSignalConversionAtToFile[5];
            if (fwrite(u, sizeof(real_T), 7, fp) != 7) {
              rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                                "Error writing to MAT-file test21.mat");
              return;
            }

            if (((++Del1_RIKTIG_presentasjon_DW.ToFile_IWORK.Count)*7)+1 >=
                100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file test21.mat.\n");
            }
          }
        }
      }
    }

    /* RateTransition: '<S4>/Rate Transition: x' */
    if (Del1_RIKTIG_presentasjon_M->Timing.RateInteraction.TID1_2) {
      Del1_RIKTIG_presentasjon_B.RateTransitionx =
        Del1_RIKTIG_presentasjon_DW.RateTransitionx_Buffer0;
    }

    /* End of RateTransition: '<S4>/Rate Transition: x' */

    /* DeadZone: '<S4>/Dead Zone: x' */
    if (Del1_RIKTIG_presentasjon_B.RateTransitionx >
        Del1_RIKTIG_presentasjon_P.DeadZonex_End) {
      rtb_Sum1 = Del1_RIKTIG_presentasjon_B.RateTransitionx -
        Del1_RIKTIG_presentasjon_P.DeadZonex_End;
    } else if (Del1_RIKTIG_presentasjon_B.RateTransitionx >=
               Del1_RIKTIG_presentasjon_P.DeadZonex_Start) {
      rtb_Sum1 = 0.0;
    } else {
      rtb_Sum1 = Del1_RIKTIG_presentasjon_B.RateTransitionx -
        Del1_RIKTIG_presentasjon_P.DeadZonex_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: x' */

    /* Gain: '<S4>/Joystick_gain_x' incorporates:
     *  Gain: '<S4>/Gain: x'
     */
    Del1_RIKTIG_presentasjon_B.Joystick_gain_x =
      Del1_RIKTIG_presentasjon_P.Gainx_Gain * rtb_Sum1 *
      Del1_RIKTIG_presentasjon_P.Joystick_gain_x;

    /* Sum: '<Root>/Sum1' */
    rtb_Sum1 = Del1_RIKTIG_presentasjon_B.Joystick_gain_x;

    /* ToFile: '<Root>/To File1' */
    if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
      {
        if (!(++Del1_RIKTIG_presentasjon_DW.ToFile1_IWORK.Decimation % 1) &&
            (Del1_RIKTIG_presentasjon_DW.ToFile1_IWORK.Count*2)+1 < 100000000 )
        {
          FILE *fp = (FILE *) Del1_RIKTIG_presentasjon_DW.ToFile1_PWORK.FilePtr;
          if (fp != (NULL)) {
            real_T u[2];
            Del1_RIKTIG_presentasjon_DW.ToFile1_IWORK.Decimation = 0;
            u[0] = Del1_RIKTIG_presentasjon_M->Timing.t[1];
            u[1] = rtb_Sum1;
            if (fwrite(u, sizeof(real_T), 2, fp) != 2) {
              rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                                "Error writing to MAT-file test21ref.mat");
              return;
            }

            if (((++Del1_RIKTIG_presentasjon_DW.ToFile1_IWORK.Count)*2)+1 >=
                100000000) {
              (void)fprintf(stdout,
                            "*** The ToFile block will stop logging data before\n"
                            "    the simulation has ended, because it has reached\n"
                            "    the maximum number of elements (100000000)\n"
                            "    allowed in MAT-file test21ref.mat.\n");
            }
          }
        }
      }
    }

    /* Constant: '<Root>/Constant' */
    Del1_RIKTIG_presentasjon_B.Constant = Del1_RIKTIG_presentasjon_P.V_s0;
  }

  /* Integrator: '<S6>/Integrator' */
  /* Limited  Integrator  */
  if (Del1_RIKTIG_presentasjon_X.Integrator_CSTATE >=
      Del1_RIKTIG_presentasjon_P.Integrator_UpperSat) {
    Del1_RIKTIG_presentasjon_X.Integrator_CSTATE =
      Del1_RIKTIG_presentasjon_P.Integrator_UpperSat;
  } else {
    if (Del1_RIKTIG_presentasjon_X.Integrator_CSTATE <=
        Del1_RIKTIG_presentasjon_P.Integrator_LowerSat) {
      Del1_RIKTIG_presentasjon_X.Integrator_CSTATE =
        Del1_RIKTIG_presentasjon_P.Integrator_LowerSat;
    }
  }

  /* RateTransition: '<S4>/Rate Transition: y' */
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    if (Del1_RIKTIG_presentasjon_M->Timing.RateInteraction.TID1_2) {
      Del1_RIKTIG_presentasjon_B.RateTransitiony =
        Del1_RIKTIG_presentasjon_DW.RateTransitiony_Buffer0;
    }

    /* DeadZone: '<S4>/Dead Zone: y' */
    if (Del1_RIKTIG_presentasjon_B.RateTransitiony >
        Del1_RIKTIG_presentasjon_P.DeadZoney_End) {
      rtb_Sum_k = Del1_RIKTIG_presentasjon_B.RateTransitiony -
        Del1_RIKTIG_presentasjon_P.DeadZoney_End;
    } else if (Del1_RIKTIG_presentasjon_B.RateTransitiony >=
               Del1_RIKTIG_presentasjon_P.DeadZoney_Start) {
      rtb_Sum_k = 0.0;
    } else {
      rtb_Sum_k = Del1_RIKTIG_presentasjon_B.RateTransitiony -
        Del1_RIKTIG_presentasjon_P.DeadZoney_Start;
    }

    /* End of DeadZone: '<S4>/Dead Zone: y' */

    /* Gain: '<S4>/Joystick_gain_y' incorporates:
     *  Gain: '<S4>/Gain: y'
     */
    Del1_RIKTIG_presentasjon_B.Joystick_gain_y =
      Del1_RIKTIG_presentasjon_P.Gainy_Gain * rtb_Sum_k *
      Del1_RIKTIG_presentasjon_P.Joystick_gain_y;

    /* Sum: '<S2>/Sum' */
    rtb_Sum_k = Del1_RIKTIG_presentasjon_B.Joystick_gain_y -
      Del1_RIKTIG_presentasjon_B.Sum;

    /* Gain: '<S6>/K_ep' */
    Del1_RIKTIG_presentasjon_B.K_ep = Del1_RIKTIG_presentasjon_P.K_ep_Gain *
      rtb_Sum_k;
  }

  /* End of RateTransition: '<S4>/Rate Transition: y' */

  /* Sum: '<Root>/Sum' incorporates:
   *  Gain: '<S6>/K_ed'
   *  Integrator: '<S6>/Integrator'
   *  Sum: '<S6>/Sum'
   */
  Del1_RIKTIG_presentasjon_B.Sum_o =
    ((Del1_RIKTIG_presentasjon_X.Integrator_CSTATE +
      Del1_RIKTIG_presentasjon_B.K_ep) - Del1_RIKTIG_presentasjon_P.K_ed_Gain *
     Del1_RIKTIG_presentasjon_B.ElevationTransferFcn) +
    Del1_RIKTIG_presentasjon_B.Constant;
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    /* Gain: '<S5>/proportional gain' incorporates:
     *  Sum: '<S5>/Sum'
     */
    Del1_RIKTIG_presentasjon_B.proportionalgain = (rtb_Sum1 -
      Del1_RIKTIG_presentasjon_B.PitchCounttorad) *
      Del1_RIKTIG_presentasjon_P.K_pp;
  }

  /* Sum: '<S5>/Sum1' incorporates:
   *  Gain: '<S5>/derivative gain'
   */
  rtb_Backgain = Del1_RIKTIG_presentasjon_B.proportionalgain -
    Del1_RIKTIG_presentasjon_P.K_pd *
    Del1_RIKTIG_presentasjon_B.PitchTransferFcn;
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    /* Gain: '<S6>/K_ei' */
    Del1_RIKTIG_presentasjon_B.K_ei = Del1_RIKTIG_presentasjon_P.K_ei_Gain *
      rtb_Sum_k;
  }

  /* Gain: '<S1>/Front gain' incorporates:
   *  Sum: '<S1>/Add'
   */
  u0 = (Del1_RIKTIG_presentasjon_B.Sum_o - rtb_Backgain) *
    Del1_RIKTIG_presentasjon_P.Frontgain_Gain;

  /* Saturate: '<S3>/Front motor: Saturation' */
  if (u0 > Del1_RIKTIG_presentasjon_P.FrontmotorSaturation_UpperSat) {
    Del1_RIKTIG_presentasjon_B.FrontmotorSaturation =
      Del1_RIKTIG_presentasjon_P.FrontmotorSaturation_UpperSat;
  } else if (u0 < Del1_RIKTIG_presentasjon_P.FrontmotorSaturation_LowerSat) {
    Del1_RIKTIG_presentasjon_B.FrontmotorSaturation =
      Del1_RIKTIG_presentasjon_P.FrontmotorSaturation_LowerSat;
  } else {
    Del1_RIKTIG_presentasjon_B.FrontmotorSaturation = u0;
  }

  /* End of Saturate: '<S3>/Front motor: Saturation' */

  /* Gain: '<S1>/Back gain' incorporates:
   *  Sum: '<S1>/Subtract'
   */
  u0 = (Del1_RIKTIG_presentasjon_B.Sum_o + rtb_Backgain) *
    Del1_RIKTIG_presentasjon_P.Backgain_Gain;

  /* Saturate: '<S3>/Back motor: Saturation' */
  if (u0 > Del1_RIKTIG_presentasjon_P.BackmotorSaturation_UpperSat) {
    Del1_RIKTIG_presentasjon_B.BackmotorSaturation =
      Del1_RIKTIG_presentasjon_P.BackmotorSaturation_UpperSat;
  } else if (u0 < Del1_RIKTIG_presentasjon_P.BackmotorSaturation_LowerSat) {
    Del1_RIKTIG_presentasjon_B.BackmotorSaturation =
      Del1_RIKTIG_presentasjon_P.BackmotorSaturation_LowerSat;
  } else {
    Del1_RIKTIG_presentasjon_B.BackmotorSaturation = u0;
  }

  /* End of Saturate: '<S3>/Back motor: Saturation' */
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    /* S-Function (hil_write_analog_block): '<S3>/HIL Write Analog' */

    /* S-Function Block: Del1_RIKTIG_presentasjon/Heli 3D/HIL Write Analog (hil_write_analog_block) */
    {
      t_error result;
      Del1_RIKTIG_presentasjon_DW.HILWriteAnalog_Buffer[0] =
        Del1_RIKTIG_presentasjon_B.FrontmotorSaturation;
      Del1_RIKTIG_presentasjon_DW.HILWriteAnalog_Buffer[1] =
        Del1_RIKTIG_presentasjon_B.BackmotorSaturation;
      result = hil_write_analog(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
        Del1_RIKTIG_presentasjon_P.HILWriteAnalog_channels, 2,
        &Del1_RIKTIG_presentasjon_DW.HILWriteAnalog_Buffer[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
      }
    }
  }
}

/* Model update function for TID0 */
void Del1_RIKTIG_presentasjon_update0(void) /* Sample time: [0.0s, 0.0s] */
{
  if (rtmIsMajorTimeStep(Del1_RIKTIG_presentasjon_M)) {
    rt_ertODEUpdateContinuousStates(&Del1_RIKTIG_presentasjon_M->solverInfo);
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
  if (!(++Del1_RIKTIG_presentasjon_M->Timing.clockTick0)) {
    ++Del1_RIKTIG_presentasjon_M->Timing.clockTickH0;
  }

  Del1_RIKTIG_presentasjon_M->Timing.t[0] = rtsiGetSolverStopTime
    (&Del1_RIKTIG_presentasjon_M->solverInfo);

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Del1_RIKTIG_presentasjon_M->Timing.clockTick1)) {
    ++Del1_RIKTIG_presentasjon_M->Timing.clockTickH1;
  }

  Del1_RIKTIG_presentasjon_M->Timing.t[1] =
    Del1_RIKTIG_presentasjon_M->Timing.clockTick1 *
    Del1_RIKTIG_presentasjon_M->Timing.stepSize1 +
    Del1_RIKTIG_presentasjon_M->Timing.clockTickH1 *
    Del1_RIKTIG_presentasjon_M->Timing.stepSize1 * 4294967296.0;
}

/* Derivatives for root system: '<Root>' */
void Del1_RIKTIG_presentasjon_derivatives(void)
{
  boolean_T lsat;
  boolean_T usat;
  XDot_Del1_RIKTIG_presentasjon_T *_rtXdot;
  _rtXdot = ((XDot_Del1_RIKTIG_presentasjon_T *)
             Del1_RIKTIG_presentasjon_M->ModelData.derivs);

  /* Derivatives for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  _rtXdot->TravelTransferFcn_CSTATE = 0.0;
  _rtXdot->TravelTransferFcn_CSTATE +=
    Del1_RIKTIG_presentasjon_P.TravelTransferFcn_A *
    Del1_RIKTIG_presentasjon_X.TravelTransferFcn_CSTATE;
  _rtXdot->TravelTransferFcn_CSTATE +=
    Del1_RIKTIG_presentasjon_B.TravelCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  _rtXdot->PitchTransferFcn_CSTATE = 0.0;
  _rtXdot->PitchTransferFcn_CSTATE +=
    Del1_RIKTIG_presentasjon_P.PitchTransferFcn_A *
    Del1_RIKTIG_presentasjon_X.PitchTransferFcn_CSTATE;
  _rtXdot->PitchTransferFcn_CSTATE += Del1_RIKTIG_presentasjon_B.PitchCounttorad;

  /* Derivatives for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  _rtXdot->ElevationTransferFcn_CSTATE = 0.0;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    Del1_RIKTIG_presentasjon_P.ElevationTransferFcn_A *
    Del1_RIKTIG_presentasjon_X.ElevationTransferFcn_CSTATE;
  _rtXdot->ElevationTransferFcn_CSTATE +=
    Del1_RIKTIG_presentasjon_B.ElevationCounttorad;

  /* Derivatives for Integrator: '<S6>/Integrator' */
  lsat = (Del1_RIKTIG_presentasjon_X.Integrator_CSTATE <=
          Del1_RIKTIG_presentasjon_P.Integrator_LowerSat);
  usat = (Del1_RIKTIG_presentasjon_X.Integrator_CSTATE >=
          Del1_RIKTIG_presentasjon_P.Integrator_UpperSat);
  if (((!lsat) && (!usat)) || (lsat && (Del1_RIKTIG_presentasjon_B.K_ei > 0.0)) ||
      (usat && (Del1_RIKTIG_presentasjon_B.K_ei < 0.0))) {
    _rtXdot->Integrator_CSTATE = Del1_RIKTIG_presentasjon_B.K_ei;
  } else {
    /* in saturation */
    _rtXdot->Integrator_CSTATE = 0.0;
  }

  /* End of Derivatives for Integrator: '<S6>/Integrator' */
}

/* Model output function for TID2 */
void Del1_RIKTIG_presentasjon_output2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: Del1_RIKTIG_presentasjon/Joystick/Game Controller (game_controller_block) */
  {
    if (Del1_RIKTIG_presentasjon_P.GameController_Enabled) {
      t_game_controller_states state;
      t_boolean new_data;
      t_error result;
      result = game_controller_poll
        (Del1_RIKTIG_presentasjon_DW.GameController_Controller, &state,
         &new_data);
      if (result == 0) {
        Del1_RIKTIG_presentasjon_B.GameController_o4 = state.x;
        Del1_RIKTIG_presentasjon_B.GameController_o5 = state.y;
      }
    } else {
      Del1_RIKTIG_presentasjon_B.GameController_o4 = 0;
      Del1_RIKTIG_presentasjon_B.GameController_o5 = 0;
    }
  }
}

/* Model update function for TID2 */
void Del1_RIKTIG_presentasjon_update2(void) /* Sample time: [0.01s, 0.0s] */
{
  /* Update for RateTransition: '<S4>/Rate Transition: x' */
  Del1_RIKTIG_presentasjon_DW.RateTransitionx_Buffer0 =
    Del1_RIKTIG_presentasjon_B.GameController_o4;

  /* Update for RateTransition: '<S4>/Rate Transition: y' */
  Del1_RIKTIG_presentasjon_DW.RateTransitiony_Buffer0 =
    Del1_RIKTIG_presentasjon_B.GameController_o5;

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++Del1_RIKTIG_presentasjon_M->Timing.clockTick2)) {
    ++Del1_RIKTIG_presentasjon_M->Timing.clockTickH2;
  }

  Del1_RIKTIG_presentasjon_M->Timing.t[2] =
    Del1_RIKTIG_presentasjon_M->Timing.clockTick2 *
    Del1_RIKTIG_presentasjon_M->Timing.stepSize2 +
    Del1_RIKTIG_presentasjon_M->Timing.clockTickH2 *
    Del1_RIKTIG_presentasjon_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
void Del1_RIKTIG_presentasjon_output(int_T tid)
{
  switch (tid) {
   case 0 :
    Del1_RIKTIG_presentasjon_output0();
    break;

   case 2 :
    Del1_RIKTIG_presentasjon_output2();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
void Del1_RIKTIG_presentasjon_update(int_T tid)
{
  switch (tid) {
   case 0 :
    Del1_RIKTIG_presentasjon_update0();
    break;

   case 2 :
    Del1_RIKTIG_presentasjon_update2();
    break;

   default :
    break;
  }
}

/* Model initialize function */
void Del1_RIKTIG_presentasjon_initialize(void)
{
  /* Start for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Del1_RIKTIG_presentasjon/HIL Initialize (hil_initialize_block) */
  {
    t_int result;
    t_boolean is_switching;
    result = hil_open("q8_usb", "0",
                      &Del1_RIKTIG_presentasjon_DW.HILInitialize_Card);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
      return;
    }

    is_switching = false;
    result = hil_set_card_specific_options
      (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
       "update_rate=normal;decimation=1", 32);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
      return;
    }

    result = hil_watchdog_clear(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card);
    if (result < 0 && result != -QERR_HIL_WATCHDOG_CLEAR) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
      return;
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_input_ &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_inpu_m &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AIMinimums =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_AIMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMinimums[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_analog_input_mini;
        }
      }

      {
        int_T i1;
        real_T *dw_AIMaximums =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_AIMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AIMaximums[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_analog_input_maxi;
        }
      }

      result = hil_set_analog_input_ranges
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_analog_input_chan, 8U,
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_AIMinimums[0],
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_AIMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_output &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_outp_b &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOMinimums =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOMinimums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMinimums[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_analog_output_min;
        }
      }

      {
        int_T i1;
        real_T *dw_AOMaximums =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOMaximums[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOMaximums[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_analog_output_max;
        }
      }

      result = hil_set_analog_output_ranges
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_analog_output_cha, 8U,
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOMinimums[0],
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOMaximums[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_outp_e &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_outp_j &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_initial_analog_ou;
        }
      }

      result = hil_write_analog(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
        Del1_RIKTIG_presentasjon_P.HILInitialize_analog_output_cha, 8U,
        &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if (Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_outp_p) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_watchdog_analog_o;
        }
      }

      result = hil_watchdog_set_analog_expiration_state
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_analog_output_cha, 8U,
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_encoder_param &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_encoder_par_m &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_QuadratureModes =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_QuadratureModes[0];
        for (i1=0; i1 < 8; i1++) {
          dw_QuadratureModes[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_quadrature;
        }
      }

      result = hil_set_encoder_quadrature_mode
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_encoder_channels, 8U,
         (t_encoder_quadrature_mode *)
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_QuadratureModes[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_encoder_count &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_encoder_cou_k &&
         is_switching)) {
      {
        int_T i1;
        int32_T *dw_InitialEICounts =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_InitialEICounts[0];
        for (i1=0; i1 < 8; i1++) {
          dw_InitialEICounts[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_initial_encoder_c;
        }
      }

      result = hil_set_encoder_counts
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_encoder_channels, 8U,
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_InitialEICounts[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_pwm_params_at &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_pwm_params__f &&
         is_switching)) {
      uint32_T num_duty_cycle_modes = 0;
      uint32_T num_frequency_modes = 0;

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_modes;
        }
      }

      result = hil_set_pwm_mode(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
        Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels, 8U, (t_pwm_mode *)
        &Del1_RIKTIG_presentasjon_DW.HILInitialize_POModeValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        const uint32_T *p_HILInitialize_pwm_channels =
          Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels;
        int32_T *dw_POModeValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          if (dw_POModeValues[i1] == PWM_DUTY_CYCLE_MODE || dw_POModeValues[i1] ==
              PWM_ONE_SHOT_MODE || dw_POModeValues[i1] == PWM_TIME_MODE) {
            Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedChans[num_duty_cycle_modes]
              = p_HILInitialize_pwm_channels[i1];
            Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]
              = Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_frequency;
            num_duty_cycle_modes++;
          } else {
            Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedChans[7U -
              num_frequency_modes] = p_HILInitialize_pwm_channels[i1];
            Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedFreqs[7U -
              num_frequency_modes] =
              Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_frequency;
            num_frequency_modes++;
          }
        }
      }

      if (num_duty_cycle_modes > 0) {
        result = hil_set_pwm_frequency
          (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
           &Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedChans[0],
           num_duty_cycle_modes,
           &Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedFreqs[0]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
          return;
        }
      }

      if (num_frequency_modes > 0) {
        result = hil_set_pwm_duty_cycle
          (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
           &Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedChans[num_duty_cycle_modes],
           num_frequency_modes,
           &Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedFreqs[num_duty_cycle_modes]);
        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
          return;
        }
      }

      {
        int_T i1;
        int32_T *dw_POModeValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POModeValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POModeValues[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_configuration;
        }
      }

      {
        int_T i1;
        int32_T *dw_POAlignValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POAlignValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POAlignValues[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_alignment;
        }
      }

      {
        int_T i1;
        int32_T *dw_POPolarityVals =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POPolarityVals[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POPolarityVals[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_polarity;
        }
      }

      result = hil_set_pwm_configuration
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels, 8U,
         (t_pwm_configuration *)
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_POModeValues[0],
         (t_pwm_alignment *)
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_POAlignValues[0],
         (t_pwm_polarity *)
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_POPolarityVals[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }

      {
        int_T i1;
        real_T *dw_POSortedFreqs =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedFreqs[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POSortedFreqs[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_leading_deadb;
        }
      }

      {
        int_T i1;
        real_T *dw_POValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_trailing_dead;
        }
      }

      result = hil_set_pwm_deadband
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels, 8U,
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedFreqs[0],
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_pwm_outputs_a &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_pwm_outputs_g &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_initial_pwm_outpu;
        }
      }

      result = hil_write_pwm(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
        Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels, 8U,
        &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }

    if (Del1_RIKTIG_presentasjon_P.HILInitialize_set_pwm_outputs_o) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_watchdog_pwm_outp;
        }
      }

      result = hil_watchdog_set_pwm_expiration_state
        (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
         Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels, 8U,
         &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0]);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        return;
      }
    }
  }

  /* Start for S-Function (hil_read_encoder_timebase_block): '<S3>/HIL Read Encoder Timebase' */

  /* S-Function Block: Del1_RIKTIG_presentasjon/Heli 3D/HIL Read Encoder Timebase (hil_read_encoder_timebase_block) */
  {
    t_error result;
    result = hil_task_create_encoder_reader
      (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
       Del1_RIKTIG_presentasjon_P.HILReadEncoderTimebase_samples_,
       Del1_RIKTIG_presentasjon_P.HILReadEncoderTimebase_channels, 3,
       &Del1_RIKTIG_presentasjon_DW.HILReadEncoderTimebase_Task);
    if (result < 0) {
      msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
        (_rt_error_message));
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
    }
  }

  /* Start for ToFile: '<Root>/To File' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "test21.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                        "Error creating .mat file test21.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,7,0,"ans")) {
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                        "Error writing mat file header to file test21.mat");
      return;
    }

    Del1_RIKTIG_presentasjon_DW.ToFile_IWORK.Count = 0;
    Del1_RIKTIG_presentasjon_DW.ToFile_IWORK.Decimation = -1;
    Del1_RIKTIG_presentasjon_DW.ToFile_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S4>/Rate Transition: x' */
  Del1_RIKTIG_presentasjon_B.RateTransitionx =
    Del1_RIKTIG_presentasjon_P.RateTransitionx_X0;

  /* Start for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (NULL);
    char fileName[509] = "test21ref.mat";
    if ((fp = fopen(fileName, "wb")) == (NULL)) {
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                        "Error creating .mat file test21ref.mat");
      return;
    }

    if (rt_WriteMat4FileHeader(fp,2,0,"ans")) {
      rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                        "Error writing mat file header to file test21ref.mat");
      return;
    }

    Del1_RIKTIG_presentasjon_DW.ToFile1_IWORK.Count = 0;
    Del1_RIKTIG_presentasjon_DW.ToFile1_IWORK.Decimation = -1;
    Del1_RIKTIG_presentasjon_DW.ToFile1_PWORK.FilePtr = fp;
  }

  /* Start for RateTransition: '<S4>/Rate Transition: y' */
  Del1_RIKTIG_presentasjon_B.RateTransitiony =
    Del1_RIKTIG_presentasjon_P.RateTransitiony_X0;

  /* Start for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: Del1_RIKTIG_presentasjon/Joystick/Game Controller (game_controller_block) */
  {
    if (Del1_RIKTIG_presentasjon_P.GameController_Enabled) {
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

      result = game_controller_open
        (Del1_RIKTIG_presentasjon_P.GameController_ControllerNumber,
         Del1_RIKTIG_presentasjon_P.GameController_BufferSize, deadzone,
         saturation, Del1_RIKTIG_presentasjon_P.GameController_AutoCenter, 0,
         1.0, &Del1_RIKTIG_presentasjon_DW.GameController_Controller);
      if (result < 0) {
        msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
          (_rt_error_message));
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
      }
    }
  }

  /* InitializeConditions for TransferFcn: '<S3>/Travel: Transfer Fcn' */
  Del1_RIKTIG_presentasjon_X.TravelTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Pitch: Transfer Fcn' */
  Del1_RIKTIG_presentasjon_X.PitchTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for TransferFcn: '<S3>/Elevation: Transfer Fcn' */
  Del1_RIKTIG_presentasjon_X.ElevationTransferFcn_CSTATE = 0.0;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: x' */
  Del1_RIKTIG_presentasjon_DW.RateTransitionx_Buffer0 =
    Del1_RIKTIG_presentasjon_P.RateTransitionx_X0;

  /* InitializeConditions for Integrator: '<S6>/Integrator' */
  Del1_RIKTIG_presentasjon_X.Integrator_CSTATE =
    Del1_RIKTIG_presentasjon_P.Integrator_IC;

  /* InitializeConditions for RateTransition: '<S4>/Rate Transition: y' */
  Del1_RIKTIG_presentasjon_DW.RateTransitiony_Buffer0 =
    Del1_RIKTIG_presentasjon_P.RateTransitiony_X0;
}

/* Model terminate function */
void Del1_RIKTIG_presentasjon_terminate(void)
{
  /* Terminate for S-Function (hil_initialize_block): '<Root>/HIL Initialize' */

  /* S-Function Block: Del1_RIKTIG_presentasjon/HIL Initialize (hil_initialize_block) */
  {
    t_boolean is_switching;
    t_int result;
    t_uint32 num_final_analog_outputs = 0;
    t_uint32 num_final_pwm_outputs = 0;
    hil_task_stop_all(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card);
    hil_monitor_stop_all(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card);
    is_switching = false;
    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_out_ex &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_analog_outp_c &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_AOVoltages =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[0];
        for (i1=0; i1 < 8; i1++) {
          dw_AOVoltages[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_final_analog_outp;
        }
      }

      num_final_analog_outputs = 8U;
    }

    if ((Del1_RIKTIG_presentasjon_P.HILInitialize_set_pwm_output_ap &&
         !is_switching) ||
        (Del1_RIKTIG_presentasjon_P.HILInitialize_set_pwm_outputs_p &&
         is_switching)) {
      {
        int_T i1;
        real_T *dw_POValues =
          &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0];
        for (i1=0; i1 < 8; i1++) {
          dw_POValues[i1] =
            Del1_RIKTIG_presentasjon_P.HILInitialize_final_pwm_outputs;
        }
      }

      num_final_pwm_outputs = 8U;
    }

    if (0
        || num_final_analog_outputs > 0
        || num_final_pwm_outputs > 0
        ) {
      /* Attempt to write the final outputs atomically (due to firmware issue in old Q2-USB). Otherwise write channels individually */
      result = hil_write(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card
                         ,
                         Del1_RIKTIG_presentasjon_P.HILInitialize_analog_output_cha,
                         num_final_analog_outputs
                         , Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels,
                         num_final_pwm_outputs
                         , NULL, 0
                         , NULL, 0
                         ,
                         &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[0]
                         , &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0]
                         , (t_boolean *) NULL
                         , NULL
                         );
      if (result == -QERR_HIL_WRITE_NOT_SUPPORTED) {
        t_error local_result;
        result = 0;

        /* The hil_write operation is not supported by this card. Write final outputs for each channel type */
        if (num_final_analog_outputs > 0) {
          local_result = hil_write_analog
            (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
             Del1_RIKTIG_presentasjon_P.HILInitialize_analog_output_cha,
             num_final_analog_outputs,
             &Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (num_final_pwm_outputs > 0) {
          local_result = hil_write_pwm
            (Del1_RIKTIG_presentasjon_DW.HILInitialize_Card,
             Del1_RIKTIG_presentasjon_P.HILInitialize_pwm_channels,
             num_final_pwm_outputs,
             &Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[0]);
          if (local_result < 0) {
            result = local_result;
          }
        }

        if (result < 0) {
          msg_get_error_messageA(NULL, result, _rt_error_message, sizeof
            (_rt_error_message));
          rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M, _rt_error_message);
        }
      }
    }

    hil_task_delete_all(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card);
    hil_monitor_delete_all(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card);
    hil_close(Del1_RIKTIG_presentasjon_DW.HILInitialize_Card);
    Del1_RIKTIG_presentasjon_DW.HILInitialize_Card = NULL;
  }

  /* Terminate for ToFile: '<Root>/To File' */
  {
    FILE *fp = (FILE *) Del1_RIKTIG_presentasjon_DW.ToFile_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "test21.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error closing MAT-file test21.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error reopening MAT-file test21.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 7,
           Del1_RIKTIG_presentasjon_DW.ToFile_IWORK.Count, "ans")) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error writing header for ans to MAT-file test21.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error closing MAT-file test21.mat");
        return;
      }

      Del1_RIKTIG_presentasjon_DW.ToFile_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for ToFile: '<Root>/To File1' */
  {
    FILE *fp = (FILE *) Del1_RIKTIG_presentasjon_DW.ToFile1_PWORK.FilePtr;
    if (fp != (NULL)) {
      char fileName[509] = "test21ref.mat";
      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error closing MAT-file test21ref.mat");
        return;
      }

      if ((fp = fopen(fileName, "r+b")) == (NULL)) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error reopening MAT-file test21ref.mat");
        return;
      }

      if (rt_WriteMat4FileHeader(fp, 2,
           Del1_RIKTIG_presentasjon_DW.ToFile1_IWORK.Count, "ans")) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error writing header for ans to MAT-file test21ref.mat");
      }

      if (fclose(fp) == EOF) {
        rtmSetErrorStatus(Del1_RIKTIG_presentasjon_M,
                          "Error closing MAT-file test21ref.mat");
        return;
      }

      Del1_RIKTIG_presentasjon_DW.ToFile1_PWORK.FilePtr = (NULL);
    }
  }

  /* Terminate for S-Function (game_controller_block): '<S4>/Game Controller' */

  /* S-Function Block: Del1_RIKTIG_presentasjon/Joystick/Game Controller (game_controller_block) */
  {
    if (Del1_RIKTIG_presentasjon_P.GameController_Enabled) {
      game_controller_close
        (Del1_RIKTIG_presentasjon_DW.GameController_Controller);
      Del1_RIKTIG_presentasjon_DW.GameController_Controller = NULL;
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
  Del1_RIKTIG_presentasjon_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  Del1_RIKTIG_presentasjon_update(tid);
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
  Del1_RIKTIG_presentasjon_initialize();
}

void MdlTerminate(void)
{
  Del1_RIKTIG_presentasjon_terminate();
}

/* Registration function */
RT_MODEL_Del1_RIKTIG_presenta_T *Del1_RIKTIG_presentasjon(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* non-finite (run-time) assignments */
  Del1_RIKTIG_presentasjon_P.Integrator_UpperSat = rtInf;
  Del1_RIKTIG_presentasjon_P.Integrator_LowerSat = rtMinusInf;

  /* initialize real-time model */
  (void) memset((void *)Del1_RIKTIG_presentasjon_M, 0,
                sizeof(RT_MODEL_Del1_RIKTIG_presenta_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
                          &Del1_RIKTIG_presentasjon_M->Timing.simTimeStep);
    rtsiSetTPtr(&Del1_RIKTIG_presentasjon_M->solverInfo, &rtmGetTPtr
                (Del1_RIKTIG_presentasjon_M));
    rtsiSetStepSizePtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
                       &Del1_RIKTIG_presentasjon_M->Timing.stepSize0);
    rtsiSetdXPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
                 &Del1_RIKTIG_presentasjon_M->ModelData.derivs);
    rtsiSetContStatesPtr(&Del1_RIKTIG_presentasjon_M->solverInfo, (real_T **)
                         &Del1_RIKTIG_presentasjon_M->ModelData.contStates);
    rtsiSetNumContStatesPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
      &Del1_RIKTIG_presentasjon_M->Sizes.numContStates);
    rtsiSetNumPeriodicContStatesPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
      &Del1_RIKTIG_presentasjon_M->Sizes.numPeriodicContStates);
    rtsiSetPeriodicContStateIndicesPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
      &Del1_RIKTIG_presentasjon_M->ModelData.periodicContStateIndices);
    rtsiSetPeriodicContStateRangesPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
      &Del1_RIKTIG_presentasjon_M->ModelData.periodicContStateRanges);
    rtsiSetErrorStatusPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
                          (&rtmGetErrorStatus(Del1_RIKTIG_presentasjon_M)));
    rtsiSetRTModelPtr(&Del1_RIKTIG_presentasjon_M->solverInfo,
                      Del1_RIKTIG_presentasjon_M);
  }

  rtsiSetSimTimeStep(&Del1_RIKTIG_presentasjon_M->solverInfo, MAJOR_TIME_STEP);
  Del1_RIKTIG_presentasjon_M->ModelData.intgData.f[0] =
    Del1_RIKTIG_presentasjon_M->ModelData.odeF[0];
  Del1_RIKTIG_presentasjon_M->ModelData.contStates = ((real_T *)
    &Del1_RIKTIG_presentasjon_X);
  rtsiSetSolverData(&Del1_RIKTIG_presentasjon_M->solverInfo, (void *)
                    &Del1_RIKTIG_presentasjon_M->ModelData.intgData);
  rtsiSetSolverName(&Del1_RIKTIG_presentasjon_M->solverInfo,"ode1");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = Del1_RIKTIG_presentasjon_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    mdlTsMap[2] = 2;
    Del1_RIKTIG_presentasjon_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    Del1_RIKTIG_presentasjon_M->Timing.sampleTimes =
      (&Del1_RIKTIG_presentasjon_M->Timing.sampleTimesArray[0]);
    Del1_RIKTIG_presentasjon_M->Timing.offsetTimes =
      (&Del1_RIKTIG_presentasjon_M->Timing.offsetTimesArray[0]);

    /* task periods */
    Del1_RIKTIG_presentasjon_M->Timing.sampleTimes[0] = (0.0);
    Del1_RIKTIG_presentasjon_M->Timing.sampleTimes[1] = (0.002);
    Del1_RIKTIG_presentasjon_M->Timing.sampleTimes[2] = (0.01);

    /* task offsets */
    Del1_RIKTIG_presentasjon_M->Timing.offsetTimes[0] = (0.0);
    Del1_RIKTIG_presentasjon_M->Timing.offsetTimes[1] = (0.0);
    Del1_RIKTIG_presentasjon_M->Timing.offsetTimes[2] = (0.0);
  }

  rtmSetTPtr(Del1_RIKTIG_presentasjon_M,
             &Del1_RIKTIG_presentasjon_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = Del1_RIKTIG_presentasjon_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits =
      Del1_RIKTIG_presentasjon_M->Timing.perTaskSampleHitsArray;
    Del1_RIKTIG_presentasjon_M->Timing.perTaskSampleHits =
      (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    Del1_RIKTIG_presentasjon_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(Del1_RIKTIG_presentasjon_M, -1);
  Del1_RIKTIG_presentasjon_M->Timing.stepSize0 = 0.002;
  Del1_RIKTIG_presentasjon_M->Timing.stepSize1 = 0.002;
  Del1_RIKTIG_presentasjon_M->Timing.stepSize2 = 0.01;

  /* External mode info */
  Del1_RIKTIG_presentasjon_M->Sizes.checksums[0] = (3582025832U);
  Del1_RIKTIG_presentasjon_M->Sizes.checksums[1] = (643141041U);
  Del1_RIKTIG_presentasjon_M->Sizes.checksums[2] = (3687506309U);
  Del1_RIKTIG_presentasjon_M->Sizes.checksums[3] = (1509641569U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    Del1_RIKTIG_presentasjon_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(Del1_RIKTIG_presentasjon_M->extModeInfo,
      &Del1_RIKTIG_presentasjon_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(Del1_RIKTIG_presentasjon_M->extModeInfo,
                        Del1_RIKTIG_presentasjon_M->Sizes.checksums);
    rteiSetTPtr(Del1_RIKTIG_presentasjon_M->extModeInfo, rtmGetTPtr
                (Del1_RIKTIG_presentasjon_M));
  }

  Del1_RIKTIG_presentasjon_M->solverInfoPtr =
    (&Del1_RIKTIG_presentasjon_M->solverInfo);
  Del1_RIKTIG_presentasjon_M->Timing.stepSize = (0.002);
  rtsiSetFixedStepSize(&Del1_RIKTIG_presentasjon_M->solverInfo, 0.002);
  rtsiSetSolverMode(&Del1_RIKTIG_presentasjon_M->solverInfo,
                    SOLVER_MODE_MULTITASKING);

  /* block I/O */
  Del1_RIKTIG_presentasjon_M->ModelData.blockIO = ((void *)
    &Del1_RIKTIG_presentasjon_B);

  {
    Del1_RIKTIG_presentasjon_B.TravelCounttorad = 0.0;
    Del1_RIKTIG_presentasjon_B.TravelTransferFcn = 0.0;
    Del1_RIKTIG_presentasjon_B.PitchCounttorad = 0.0;
    Del1_RIKTIG_presentasjon_B.PitchTransferFcn = 0.0;
    Del1_RIKTIG_presentasjon_B.ElevationCounttorad = 0.0;
    Del1_RIKTIG_presentasjon_B.Sum = 0.0;
    Del1_RIKTIG_presentasjon_B.ElevationTransferFcn = 0.0;
    Del1_RIKTIG_presentasjon_B.RateTransitionx = 0.0;
    Del1_RIKTIG_presentasjon_B.Joystick_gain_x = 0.0;
    Del1_RIKTIG_presentasjon_B.Constant = 0.0;
    Del1_RIKTIG_presentasjon_B.RateTransitiony = 0.0;
    Del1_RIKTIG_presentasjon_B.Joystick_gain_y = 0.0;
    Del1_RIKTIG_presentasjon_B.K_ep = 0.0;
    Del1_RIKTIG_presentasjon_B.Sum_o = 0.0;
    Del1_RIKTIG_presentasjon_B.proportionalgain = 0.0;
    Del1_RIKTIG_presentasjon_B.K_ei = 0.0;
    Del1_RIKTIG_presentasjon_B.FrontmotorSaturation = 0.0;
    Del1_RIKTIG_presentasjon_B.BackmotorSaturation = 0.0;
    Del1_RIKTIG_presentasjon_B.GameController_o4 = 0.0;
    Del1_RIKTIG_presentasjon_B.GameController_o5 = 0.0;
  }

  /* parameters */
  Del1_RIKTIG_presentasjon_M->ModelData.defaultParam = ((real_T *)
    &Del1_RIKTIG_presentasjon_P);

  /* states (continuous) */
  {
    real_T *x = (real_T *) &Del1_RIKTIG_presentasjon_X;
    Del1_RIKTIG_presentasjon_M->ModelData.contStates = (x);
    (void) memset((void *)&Del1_RIKTIG_presentasjon_X, 0,
                  sizeof(X_Del1_RIKTIG_presentasjon_T));
  }

  /* states (dwork) */
  Del1_RIKTIG_presentasjon_M->ModelData.dwork = ((void *)
    &Del1_RIKTIG_presentasjon_DW);
  (void) memset((void *)&Del1_RIKTIG_presentasjon_DW, 0,
                sizeof(DW_Del1_RIKTIG_presentasjon_T));

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_AIMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_AIMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_AOMinimums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_AOMaximums[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_AOVoltages[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_FilterFrequency[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_POSortedFreqs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      Del1_RIKTIG_presentasjon_DW.HILInitialize_POValues[i] = 0.0;
    }
  }

  Del1_RIKTIG_presentasjon_DW.RateTransitionx_Buffer0 = 0.0;
  Del1_RIKTIG_presentasjon_DW.RateTransitiony_Buffer0 = 0.0;
  Del1_RIKTIG_presentasjon_DW.HILWriteAnalog_Buffer[0] = 0.0;
  Del1_RIKTIG_presentasjon_DW.HILWriteAnalog_Buffer[1] = 0.0;

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    Del1_RIKTIG_presentasjon_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 17;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.B = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.P = &rtPTransTable;
  }

  /* Initialize Sizes */
  Del1_RIKTIG_presentasjon_M->Sizes.numContStates = (4);/* Number of continuous states */
  Del1_RIKTIG_presentasjon_M->Sizes.numPeriodicContStates = (0);/* Number of periodic continuous states */
  Del1_RIKTIG_presentasjon_M->Sizes.numY = (0);/* Number of model outputs */
  Del1_RIKTIG_presentasjon_M->Sizes.numU = (0);/* Number of model inputs */
  Del1_RIKTIG_presentasjon_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  Del1_RIKTIG_presentasjon_M->Sizes.numSampTimes = (3);/* Number of sample times */
  Del1_RIKTIG_presentasjon_M->Sizes.numBlocks = (51);/* Number of blocks */
  Del1_RIKTIG_presentasjon_M->Sizes.numBlockIO = (20);/* Number of block outputs */
  Del1_RIKTIG_presentasjon_M->Sizes.numBlockPrms = (145);/* Sum of parameter "widths" */
  return Del1_RIKTIG_presentasjon_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
