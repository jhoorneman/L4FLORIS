#ifndef __c2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014b_h__
#define __c2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014b_h__

/* Include files */
#include "sf_runtime/sfc_sf.h"
#include "sf_runtime/sfc_mex.h"
#include "rtwtypes.h"
#include "multiword_types.h"

/* Type Definitions */
#ifndef typedef_SFc2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014bInstanceStruct
#define typedef_SFc2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014bInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014b;
  real_T c2_DT;
  real_T c2_y;
  boolean_T c2_y_not_empty;
  real_T *c2_u;
  real_T *c2_MinSaturation;
  real_T *c2_y_out;
  real_T *c2_MaxSaturation;
} SFc2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014bInstanceStruct;

#endif                                 /*typedef_SFc2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014bInstanceStruct*/

/* Named Constants */

/* Variable Declarations */
extern struct SfDebugInstanceStruct *sfGlobalDebugInstanceStruct;

/* Variable Definitions */

/* Function Declarations */
extern const mxArray
  *sf_c2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014b_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014b_get_check_sum
  (mxArray *plhs[]);
extern void c2_NREL5MW_Baseline_loads_IPC_1P_2P_v1_2014b_method_dispatcher
  (SimStruct *S, int_T method, void *data);

#endif
