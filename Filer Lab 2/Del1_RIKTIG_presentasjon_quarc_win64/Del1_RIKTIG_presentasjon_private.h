/*
 * Del1_RIKTIG_presentasjon_private.h
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

#ifndef RTW_HEADER_Del1_RIKTIG_presentasjon_private_h_
#define RTW_HEADER_Del1_RIKTIG_presentasjon_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* A global buffer for storing error messages (defined in quanser_common library) */
EXTERN char _rt_error_message[512];
int_T rt_WriteMat4FileHeader(FILE *fp,
  int32_T m,
  int32_T n,
  const char_T *name);
void Del1_RIKTIG_presentasjon_output0(void);
void Del1_RIKTIG_presentasjon_update0(void);
void Del1_RIKTIG_presentasjon_output2(void);
void Del1_RIKTIG_presentasjon_update2(void);/* private model entry point functions */
extern void Del1_RIKTIG_presentasjon_derivatives(void);

#endif                                 /* RTW_HEADER_Del1_RIKTIG_presentasjon_private_h_ */
