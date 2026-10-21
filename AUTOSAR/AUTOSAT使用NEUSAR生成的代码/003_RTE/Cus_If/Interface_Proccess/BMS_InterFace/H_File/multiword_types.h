/*
 * File: multiword_types.h
 *
 * Code generated for Simulink model 'swc_SetInputInterface'.
 *
 * Model version                  : 1.55
 * Simulink Coder version         : 9.6 (R2021b) 14-May-2021
 * C/C++ source code generated on : Fri Apr 24 15:30:30 2026
 */

#ifndef MULTIWORD_TYPES_H
#define MULTIWORD_TYPES_H
#include "rtwtypes.h"

/*
 * MultiWord supporting definitions
 */
typedef long int long_T;

/*
 * MultiWord types
 */
typedef struct {
  uint32 chunks[2];
} int64m_T;

typedef struct {
  uint32 chunks[2];
} uint64m_T;

typedef struct {
  uint32 chunks[3];
} int96m_T;

typedef struct {
  uint32 chunks[3];
} uint96m_T;

typedef struct {
  uint32 chunks[4];
} int128m_T;

typedef struct {
  uint32 chunks[4];
} uint128m_T;

typedef struct {
  uint32 chunks[5];
} int160m_T;

typedef struct {
  uint32 chunks[5];
} uint160m_T;

typedef struct {
  uint32 chunks[6];
} int192m_T;

typedef struct {
  uint32 chunks[6];
} uint192m_T;

typedef struct {
  uint32 chunks[7];
} int224m_T;

typedef struct {
  uint32 chunks[7];
} uint224m_T;

typedef struct {
  uint32 chunks[8];
} int256m_T;

typedef struct {
  uint32 chunks[8];
} uint256m_T;

#endif                                 /* MULTIWORD_TYPES_H */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
