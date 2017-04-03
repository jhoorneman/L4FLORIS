/* Include files */

#include <stddef.h>
#include "blas.h"
#include "NREL5MW_Baseline_loads_IPC_1P_v3_2014b_sfun.h"
#include "c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "NREL5MW_Baseline_loads_IPC_1P_v3_2014b_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static real_T _sfTime_;
static const char * c3_debug_family_names[11] = { "aVarTruthTableCondition_1",
  "aVarTruthTableCondition_2", "nargin", "nargout", "ErrorSpeed", "GenSpeed",
  "MeasTorque", "MeasPitch", "Demanded_torque", "SpeedError", "KillIntegrator" };

/* Function Declarations */
static void initialize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void initialize_params_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void enable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void disable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void c3_update_debugger_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_201
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void set_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_st);
static void finalize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void sf_gateway_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void mdl_start_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void initSimStructsc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber);
static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData);
static real_T c3_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_b_KillIntegrator, const char_T *c3_identifier);
static real_T c3_b_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static boolean_T c3_c_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static void c3_info_helper(const mxArray **c3_info);
static const mxArray *c3_emlrt_marshallOut(const char * c3_u);
static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u);
static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData);
static int32_T c3_d_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData);
static uint8_T c3_e_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_b_is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b,
   const char_T *c3_identifier);
static uint8_T c3_f_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId);
static void init_dsm_address_info
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);
static void init_simulink_io_address
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance);

/* Function Definitions */
static void initialize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  chartInstance->c3_sfEvent = CALL_EVENT;
  _sfTime_ = sf_get_time(chartInstance->S);
  chartInstance->c3_is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b = 0U;
  chartInstance->c3_omega_C = 0.0;
}

static void initialize_params_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  real_T c3_d0;
  sf_mex_import_named("Demanded_torque", sf_mex_get_sfun_param(chartInstance->S,
    0, 0), &c3_d0, 0, 0, 0U, 0, 0U, 0);
  chartInstance->c3_Demanded_torque = c3_d0;
}

static void enable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void disable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  _sfTime_ = sf_get_time(chartInstance->S);
}

static void c3_update_debugger_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_201
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static const mxArray *get_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  const mxArray *c3_st;
  const mxArray *c3_y = NULL;
  real_T c3_hoistedGlobal;
  real_T c3_u;
  const mxArray *c3_b_y = NULL;
  real_T c3_b_hoistedGlobal;
  real_T c3_b_u;
  const mxArray *c3_c_y = NULL;
  real_T c3_c_hoistedGlobal;
  real_T c3_c_u;
  const mxArray *c3_d_y = NULL;
  uint8_T c3_d_hoistedGlobal;
  uint8_T c3_d_u;
  const mxArray *c3_e_y = NULL;
  c3_st = NULL;
  c3_st = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_createcellmatrix(4, 1), false);
  c3_hoistedGlobal = *chartInstance->c3_KillIntegrator;
  c3_u = c3_hoistedGlobal;
  c3_b_y = NULL;
  sf_mex_assign(&c3_b_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 0, c3_b_y);
  c3_b_hoistedGlobal = *chartInstance->c3_SpeedError;
  c3_b_u = c3_b_hoistedGlobal;
  c3_c_y = NULL;
  sf_mex_assign(&c3_c_y, sf_mex_create("y", &c3_b_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 1, c3_c_y);
  c3_c_hoistedGlobal = chartInstance->c3_omega_C;
  c3_c_u = c3_c_hoistedGlobal;
  c3_d_y = NULL;
  sf_mex_assign(&c3_d_y, sf_mex_create("y", &c3_c_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 2, c3_d_y);
  c3_d_hoistedGlobal =
    chartInstance->c3_is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  c3_d_u = c3_d_hoistedGlobal;
  c3_e_y = NULL;
  sf_mex_assign(&c3_e_y, sf_mex_create("y", &c3_d_u, 3, 0U, 0U, 0U, 0), false);
  sf_mex_setcell(c3_y, 3, c3_e_y);
  sf_mex_assign(&c3_st, c3_y, false);
  return c3_st;
}

static void set_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_st)
{
  const mxArray *c3_u;
  chartInstance->c3_doneDoubleBufferReInit = true;
  c3_u = sf_mex_dup(c3_st);
  *chartInstance->c3_KillIntegrator = c3_emlrt_marshallIn(chartInstance,
    sf_mex_dup(sf_mex_getcell(c3_u, 0)), "KillIntegrator");
  *chartInstance->c3_SpeedError = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 1)), "SpeedError");
  chartInstance->c3_omega_C = c3_emlrt_marshallIn(chartInstance, sf_mex_dup
    (sf_mex_getcell(c3_u, 2)), "omega_C");
  chartInstance->c3_is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b =
    c3_e_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell(c3_u, 3)),
    "is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b");
  sf_mex_destroy(&c3_u);
  c3_update_debugger_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_201(chartInstance);
  sf_mex_destroy(&c3_st);
}

static void finalize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void sf_gateway_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  real_T c3_hoistedGlobal;
  real_T c3_b_hoistedGlobal;
  real_T c3_c_hoistedGlobal;
  real_T c3_d_hoistedGlobal;
  real_T c3_e_hoistedGlobal;
  real_T c3_b_ErrorSpeed;
  real_T c3_b_GenSpeed;
  real_T c3_b_MeasTorque;
  real_T c3_b_MeasPitch;
  real_T c3_b_Demanded_torque;
  uint32_T c3_debug_family_var_map[11];
  boolean_T c3_aVarTruthTableCondition_1;
  boolean_T c3_aVarTruthTableCondition_2;
  real_T c3_nargin = 5.0;
  real_T c3_nargout = 2.0;
  real_T c3_b_SpeedError;
  real_T c3_b_KillIntegrator;
  boolean_T guard1 = false;
  boolean_T guard2 = false;
  boolean_T guard3 = false;
  _SFD_SYMBOL_SCOPE_PUSH(0U, 0U);
  _sfTime_ = sf_get_time(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_ErrorSpeed, 0U);
  chartInstance->c3_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  c3_hoistedGlobal = *chartInstance->c3_ErrorSpeed;
  c3_b_hoistedGlobal = *chartInstance->c3_GenSpeed;
  c3_c_hoistedGlobal = *chartInstance->c3_MeasTorque;
  c3_d_hoistedGlobal = *chartInstance->c3_MeasPitch;
  c3_e_hoistedGlobal = chartInstance->c3_Demanded_torque;
  c3_b_ErrorSpeed = c3_hoistedGlobal;
  c3_b_GenSpeed = c3_b_hoistedGlobal;
  c3_b_MeasTorque = c3_c_hoistedGlobal;
  c3_b_MeasPitch = c3_d_hoistedGlobal;
  c3_b_Demanded_torque = c3_e_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 11U, 11U, c3_debug_family_names,
    c3_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_1, 0U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_aVarTruthTableCondition_2, 1U,
    c3_b_sf_marshallOut, c3_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargin, 2U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_nargout, 3U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_ErrorSpeed, 4U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_GenSpeed, 5U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_MeasTorque, 6U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c3_b_MeasPitch, 7U, c3_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_Demanded_torque, 8U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_SpeedError, 9U, c3_sf_marshallOut,
    c3_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c3_b_KillIntegrator, 10U,
    c3_sf_marshallOut, c3_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 3);
  c3_aVarTruthTableCondition_1 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 4);
  c3_aVarTruthTableCondition_2 = false;
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 9);
  c3_aVarTruthTableCondition_1 = (c3_b_GenSpeed >= chartInstance->c3_omega_C *
    0.10471975511965977);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 13);
  c3_aVarTruthTableCondition_2 = (c3_b_MeasTorque >= c3_b_Demanded_torque *
    0.999);
  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 15);
  guard1 = false;
  if (!CV_EML_COND(0, 1, 0, c3_aVarTruthTableCondition_1)) {
    if (!CV_EML_COND(0, 1, 1, c3_aVarTruthTableCondition_2)) {
      CV_EML_MCDC(0, 1, 0, true);
      CV_EML_IF(0, 1, 0, true);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 16);
      CV_EML_FCN(0, 1);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
      c3_b_SpeedError = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
      c3_b_KillIntegrator = 0.0;
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -30);
    } else {
      guard1 = true;
    }
  } else {
    guard1 = true;
  }

  if (guard1 == true) {
    CV_EML_MCDC(0, 1, 0, false);
    CV_EML_IF(0, 1, 0, false);
    _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 17);
    guard2 = false;
    if (!CV_EML_COND(0, 1, 2, c3_aVarTruthTableCondition_1)) {
      if (CV_EML_COND(0, 1, 3, c3_aVarTruthTableCondition_2)) {
        CV_EML_MCDC(0, 1, 1, true);
        CV_EML_IF(0, 1, 1, true);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 18);
        CV_EML_FCN(0, 1);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
        c3_b_SpeedError = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
        c3_b_KillIntegrator = 0.0;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -30);
      } else {
        guard2 = true;
      }
    } else {
      guard2 = true;
    }

    if (guard2 == true) {
      CV_EML_MCDC(0, 1, 1, false);
      CV_EML_IF(0, 1, 1, false);
      _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 19);
      guard3 = false;
      if (CV_EML_COND(0, 1, 4, c3_aVarTruthTableCondition_1)) {
        if (!CV_EML_COND(0, 1, 5, c3_aVarTruthTableCondition_2)) {
          CV_EML_MCDC(0, 1, 2, true);
          CV_EML_IF(0, 1, 2, true);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 20);
          CV_EML_FCN(0, 1);
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 29);
          c3_b_SpeedError = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 30);
          c3_b_KillIntegrator = 0.0;
          _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -30);
        } else {
          guard3 = true;
        }
      } else {
        guard3 = true;
      }

      if (guard3 == true) {
        CV_EML_MCDC(0, 1, 2, false);
        CV_EML_IF(0, 1, 2, false);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 22);
        CV_EML_FCN(0, 2);
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 36);
        c3_b_SpeedError = c3_b_ErrorSpeed;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, 37);
        c3_b_KillIntegrator = 1.0;
        _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -37);
      }
    }
  }

  _SFD_EML_CALL(0U, chartInstance->c3_sfEvent, -22);
  _SFD_SYMBOL_SCOPE_POP();
  *chartInstance->c3_SpeedError = c3_b_SpeedError;
  *chartInstance->c3_KillIntegrator = c3_b_KillIntegrator;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 2U, chartInstance->c3_sfEvent);
  _SFD_SYMBOL_SCOPE_POP();
  _SFD_CHECK_FOR_STATE_INCONSISTENCY
    (_NREL5MW_Baseline_loads_IPC_1P_v3_2014bMachineNumber_,
     chartInstance->chartNumber, chartInstance->instanceNumber);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_SpeedError, 1U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_GenSpeed, 2U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_MeasTorque, 3U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_MeasPitch, 4U);
  _SFD_DATA_RANGE_CHECK(*chartInstance->c3_KillIntegrator, 5U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_omega_C, 6U);
  _SFD_DATA_RANGE_CHECK(chartInstance->c3_Demanded_torque, 7U);
}

static void mdl_start_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void initSimStructsc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_script_number_translation(uint32_T c3_machineNumber, uint32_T
  c3_chartNumber, uint32_T c3_instanceNumber)
{
  (void)c3_machineNumber;
  (void)c3_chartNumber;
  (void)c3_instanceNumber;
}

static const mxArray *c3_sf_marshallOut(void *chartInstanceVoid, void *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  real_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
  chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(real_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 0, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static real_T c3_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_b_KillIntegrator, const char_T *c3_identifier)
{
  real_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_KillIntegrator),
    &c3_thisId);
  sf_mex_destroy(&c3_b_KillIntegrator);
  return c3_y;
}

static real_T c3_b_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  real_T c3_y;
  real_T c3_d1;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_d1, 1, 0, 0U, 0, 0U, 0);
  c3_y = c3_d1;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_KillIntegrator;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  real_T c3_y;
  SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
  chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
    chartInstanceVoid;
  c3_b_KillIntegrator = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_KillIntegrator),
    &c3_thisId);
  sf_mex_destroy(&c3_b_KillIntegrator);
  *(real_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static const mxArray *c3_b_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  boolean_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
  chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(boolean_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 11, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static boolean_T c3_c_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  boolean_T c3_y;
  boolean_T c3_b0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_b0, 1, 11, 0U, 0, 0U, 0);
  c3_y = c3_b0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_aVarTruthTableCondition_2;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  boolean_T c3_y;
  SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
  chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
    chartInstanceVoid;
  c3_aVarTruthTableCondition_2 = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_c_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_aVarTruthTableCondition_2), &c3_thisId);
  sf_mex_destroy(&c3_aVarTruthTableCondition_2);
  *(boolean_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

const mxArray
  *sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_get_eml_resolved_functions_info
  (void)
{
  const mxArray *c3_nameCaptureInfo = NULL;
  c3_nameCaptureInfo = NULL;
  sf_mex_assign(&c3_nameCaptureInfo, sf_mex_createstruct("structure", 2, 7, 1),
                false);
  c3_info_helper(&c3_nameCaptureInfo);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c3_nameCaptureInfo);
  return c3_nameCaptureInfo;
}

static void c3_info_helper(const mxArray **c3_info)
{
  const mxArray *c3_rhs0 = NULL;
  const mxArray *c3_lhs0 = NULL;
  const mxArray *c3_rhs1 = NULL;
  const mxArray *c3_lhs1 = NULL;
  const mxArray *c3_rhs2 = NULL;
  const mxArray *c3_lhs2 = NULL;
  const mxArray *c3_rhs3 = NULL;
  const mxArray *c3_lhs3 = NULL;
  const mxArray *c3_rhs4 = NULL;
  const mxArray *c3_lhs4 = NULL;
  const mxArray *c3_rhs5 = NULL;
  const mxArray *c3_lhs5 = NULL;
  const mxArray *c3_rhs6 = NULL;
  const mxArray *c3_lhs6 = NULL;
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(""), "context", "context", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("mrdivide"), "name", "name", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "resolved",
                  "resolved", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410807648U), "fileTimeLo",
                  "fileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1370009886U), "mFileTimeLo",
                  "mFileTimeLo", 0);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 0);
  sf_mex_assign(&c3_rhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs0, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs0), "rhs", "rhs", 0);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs0), "lhs", "lhs", 0);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.assert"),
                  "name", "name", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("char"), "dominantType",
                  "dominantType", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/assert.m"),
                  "resolved", "resolved", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1389717774U), "fileTimeLo",
                  "fileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 1);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 1);
  sf_mex_assign(&c3_rhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs1, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs1), "rhs", "rhs", 1);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs1), "lhs", "lhs", 1);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p"), "context",
                  "context", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("rdivide"), "name", "name", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "resolved",
                  "resolved", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1363713880U), "fileTimeLo",
                  "fileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 2);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 2);
  sf_mex_assign(&c3_rhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs2, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs2), "rhs", "rhs", 2);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs2), "lhs", "lhs", 2);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "coder.internal.isBuiltInNumeric"), "name", "name", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/shared/coder/coder/+coder/+internal/isBuiltInNumeric.m"),
                  "resolved", "resolved", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1395931856U), "fileTimeLo",
                  "fileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 3);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 3);
  sf_mex_assign(&c3_rhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs3, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs3), "rhs", "rhs", 3);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs3), "lhs", "lhs", 3);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_scalexp_compatible"),
                  "name", "name", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m"),
                  "resolved", "resolved", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1286818796U), "fileTimeLo",
                  "fileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 4);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 4);
  sf_mex_assign(&c3_rhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs4, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs4), "rhs", "rhs", 4);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs4), "lhs", "lhs", 4);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m"), "context",
                  "context", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("eml_div"), "name", "name", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "resolved",
                  "resolved", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1386423952U), "fileTimeLo",
                  "fileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 5);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 5);
  sf_mex_assign(&c3_rhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs5, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs5), "rhs", "rhs", 5);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs5), "lhs", "lhs", 5);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m"), "context",
                  "context", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("coder.internal.div"), "name",
                  "name", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut("double"), "dominantType",
                  "dominantType", 6);
  sf_mex_addfield(*c3_info, c3_emlrt_marshallOut(
    "[ILXE]$matlabroot$/toolbox/coder/coder/+coder/+internal/div.p"), "resolved",
                  "resolved", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(1410807770U), "fileTimeLo",
                  "fileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "fileTimeHi",
                  "fileTimeHi", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeLo",
                  "mFileTimeLo", 6);
  sf_mex_addfield(*c3_info, c3_b_emlrt_marshallOut(0U), "mFileTimeHi",
                  "mFileTimeHi", 6);
  sf_mex_assign(&c3_rhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_assign(&c3_lhs6, sf_mex_createcellmatrix(0, 1), false);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_rhs6), "rhs", "rhs", 6);
  sf_mex_addfield(*c3_info, sf_mex_duplicatearraysafe(&c3_lhs6), "lhs", "lhs", 6);
  sf_mex_destroy(&c3_rhs0);
  sf_mex_destroy(&c3_lhs0);
  sf_mex_destroy(&c3_rhs1);
  sf_mex_destroy(&c3_lhs1);
  sf_mex_destroy(&c3_rhs2);
  sf_mex_destroy(&c3_lhs2);
  sf_mex_destroy(&c3_rhs3);
  sf_mex_destroy(&c3_lhs3);
  sf_mex_destroy(&c3_rhs4);
  sf_mex_destroy(&c3_lhs4);
  sf_mex_destroy(&c3_rhs5);
  sf_mex_destroy(&c3_lhs5);
  sf_mex_destroy(&c3_rhs6);
  sf_mex_destroy(&c3_lhs6);
}

static const mxArray *c3_emlrt_marshallOut(const char * c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", c3_u, 15, 0U, 0U, 0U, 2, 1, strlen
    (c3_u)), false);
  return c3_y;
}

static const mxArray *c3_b_emlrt_marshallOut(const uint32_T c3_u)
{
  const mxArray *c3_y = NULL;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 7, 0U, 0U, 0U, 0), false);
  return c3_y;
}

static const mxArray *c3_c_sf_marshallOut(void *chartInstanceVoid, void
  *c3_inData)
{
  const mxArray *c3_mxArrayOutData = NULL;
  int32_T c3_u;
  const mxArray *c3_y = NULL;
  SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
  chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
    chartInstanceVoid;
  c3_mxArrayOutData = NULL;
  c3_u = *(int32_T *)c3_inData;
  c3_y = NULL;
  sf_mex_assign(&c3_y, sf_mex_create("y", &c3_u, 6, 0U, 0U, 0U, 0), false);
  sf_mex_assign(&c3_mxArrayOutData, c3_y, false);
  return c3_mxArrayOutData;
}

static int32_T c3_d_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  int32_T c3_y;
  int32_T c3_i0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_i0, 1, 6, 0U, 0, 0U, 0);
  c3_y = c3_i0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void c3_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c3_mxArrayInData, const char_T *c3_varName, void *c3_outData)
{
  const mxArray *c3_b_sfEvent;
  const char_T *c3_identifier;
  emlrtMsgIdentifier c3_thisId;
  int32_T c3_y;
  SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
  chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
    chartInstanceVoid;
  c3_b_sfEvent = sf_mex_dup(c3_mxArrayInData);
  c3_identifier = c3_varName;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c3_b_sfEvent),
    &c3_thisId);
  sf_mex_destroy(&c3_b_sfEvent);
  *(int32_T *)c3_outData = c3_y;
  sf_mex_destroy(&c3_mxArrayInData);
}

static uint8_T c3_e_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_b_is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b,
   const char_T *c3_identifier)
{
  uint8_T c3_y;
  emlrtMsgIdentifier c3_thisId;
  c3_thisId.fIdentifier = c3_identifier;
  c3_thisId.fParent = NULL;
  c3_y = c3_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c3_b_is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b), &c3_thisId);
  sf_mex_destroy(&c3_b_is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b);
  return c3_y;
}

static uint8_T c3_f_emlrt_marshallIn
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance,
   const mxArray *c3_u, const emlrtMsgIdentifier *c3_parentId)
{
  uint8_T c3_y;
  uint8_T c3_u0;
  (void)chartInstance;
  sf_mex_import(c3_parentId, sf_mex_dup(c3_u), &c3_u0, 1, 3, 0U, 0, 0U, 0);
  c3_y = c3_u0;
  sf_mex_destroy(&c3_u);
  return c3_y;
}

static void init_dsm_address_info
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  (void)chartInstance;
}

static void init_simulink_io_address
  (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance)
{
  chartInstance->c3_ErrorSpeed = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 0);
  chartInstance->c3_SpeedError = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_GenSpeed = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 1);
  chartInstance->c3_MeasTorque = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 2);
  chartInstance->c3_MeasPitch = (real_T *)ssGetInputPortSignal_wrapper
    (chartInstance->S, 3);
  chartInstance->c3_KillIntegrator = (real_T *)ssGetOutputPortSignal_wrapper
    (chartInstance->S, 2);
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(1097909501U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(2789940171U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(902370418U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(2873561980U);
}

mxArray* sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_get_post_codegen_info(void);
mxArray *sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_get_autoinheritance_info
  (void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals", "postCodegenInfo" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1, 1, sizeof
    (autoinheritanceFields)/sizeof(autoinheritanceFields[0]),
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("c6C4BcieakepycdJZXUfn");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,1,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxData);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,2,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  {
    mxArray* mxPostCodegenInfo =
      sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_get_post_codegen_info();
    mxSetField(mxAutoinheritanceInfo,0,"postCodegenInfo",mxPostCodegenInfo);
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

mxArray *sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_jit_fallback_info(void)
{
  const char *infoFields[] = { "fallbackType", "fallbackReason",
    "incompatibleSymbol", };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 3, infoFields);
  mxArray *fallbackReason = mxCreateString("feature_off");
  mxArray *incompatibleSymbol = mxCreateString("");
  mxArray *fallbackType = mxCreateString("early");
  mxSetField(mxInfo, 0, infoFields[0], fallbackType);
  mxSetField(mxInfo, 0, infoFields[1], fallbackReason);
  mxSetField(mxInfo, 0, infoFields[2], incompatibleSymbol);
  return mxInfo;
}

mxArray *sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_updateBuildInfo_args_info
  (void)
{
  mxArray *mxBIArgs = mxCreateCellMatrix(1,0);
  return mxBIArgs;
}

mxArray* sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_get_post_codegen_info(void)
{
  const char* fieldNames[] = { "exportedFunctionsUsedByThisChart",
    "exportedFunctionsChecksum" };

  mwSize dims[2] = { 1, 1 };

  mxArray* mxPostCodegenInfo = mxCreateStructArray(2, dims, sizeof(fieldNames)/
    sizeof(fieldNames[0]), fieldNames);

  {
    mxArray* mxExportedFunctionsChecksum = mxCreateString("");
    mwSize exp_dims[2] = { 0, 1 };

    mxArray* mxExportedFunctionsUsedByThisChart = mxCreateCellArray(2, exp_dims);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsUsedByThisChart",
               mxExportedFunctionsUsedByThisChart);
    mxSetField(mxPostCodegenInfo, 0, "exportedFunctionsChecksum",
               mxExportedFunctionsChecksum);
  }

  return mxPostCodegenInfo;
}

static const mxArray
  *sf_get_sim_state_info_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x4'type','srcId','name','auxInfo'{{M[1],M[10],T\"KillIntegrator\",},{M[1],M[5],T\"SpeedError\",},{M[3],M[11],T\"omega_C\",},{M[8],M[0],T\"is_active_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 4, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
      chartInfo->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _NREL5MW_Baseline_loads_IPC_1P_v3_2014bMachineNumber_,
           3,
           1,
           1,
           0,
           8,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           (void *)S);

        /* Each instance must initialize its own list of scripts */
        init_script_number_translation
          (_NREL5MW_Baseline_loads_IPC_1P_v3_2014bMachineNumber_,
           chartInstance->chartNumber,chartInstance->instanceNumber);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,
             _NREL5MW_Baseline_loads_IPC_1P_v3_2014bMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _NREL5MW_Baseline_loads_IPC_1P_v3_2014bMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"ErrorSpeed");
          _SFD_SET_DATA_PROPS(1,2,0,1,"SpeedError");
          _SFD_SET_DATA_PROPS(2,1,1,0,"GenSpeed");
          _SFD_SET_DATA_PROPS(3,1,1,0,"MeasTorque");
          _SFD_SET_DATA_PROPS(4,1,1,0,"MeasPitch");
          _SFD_SET_DATA_PROPS(5,2,0,1,"KillIntegrator");
          _SFD_SET_DATA_PROPS(6,0,0,0,"omega_C");
          _SFD_SET_DATA_PROPS(7,10,0,0,"Demanded_torque");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,3,3,0,0,0,0,0,6,3);
        _SFD_CV_INIT_EML_FCN(0,0,"tt_blk_kernel",0,-1,692);
        _SFD_CV_INIT_EML_FCN(0,1,"aFcnTruthTableAction_1",692,-1,779);
        _SFD_CV_INIT_EML_FCN(0,2,"aFcnTruthTableAction_2",779,-1,871);
        _SFD_CV_INIT_EML_IF(0,1,0,360,421,452,690);
        _SFD_CV_INIT_EML_IF(0,1,1,452,516,547,690);
        _SFD_CV_INIT_EML_IF(0,1,2,547,611,642,690);

        {
          static int condStart[] = { 365, 395 };

          static int condEnd[] = { 390, 420 };

          static int pfixExpr[] = { 0, -1, 1, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,0,364,420,2,0,&(condStart[0]),&(condEnd[0]),
                                5,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 461, 490 };

          static int condEnd[] = { 486, 515 };

          static int pfixExpr[] = { 0, -1, 1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,1,460,515,2,2,&(condStart[0]),&(condEnd[0]),
                                4,&(pfixExpr[0]));
        }

        {
          static int condStart[] = { 555, 585 };

          static int condEnd[] = { 580, 610 };

          static int pfixExpr[] = { 0, 1, -1, -3 };

          _SFD_CV_INIT_EML_MCDC(0,1,2,555,610,2,4,&(condStart[0]),&(condEnd[0]),
                                4,&(pfixExpr[0]));
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(7,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c3_sf_marshallOut,(MexInFcnForType)c3_sf_marshallIn);
        _SFD_SET_DATA_VALUE_PTR(0U, chartInstance->c3_ErrorSpeed);
        _SFD_SET_DATA_VALUE_PTR(1U, chartInstance->c3_SpeedError);
        _SFD_SET_DATA_VALUE_PTR(2U, chartInstance->c3_GenSpeed);
        _SFD_SET_DATA_VALUE_PTR(3U, chartInstance->c3_MeasTorque);
        _SFD_SET_DATA_VALUE_PTR(4U, chartInstance->c3_MeasPitch);
        _SFD_SET_DATA_VALUE_PTR(5U, chartInstance->c3_KillIntegrator);
        _SFD_SET_DATA_VALUE_PTR(6U, &chartInstance->c3_omega_C);
        _SFD_SET_DATA_VALUE_PTR(7U, &chartInstance->c3_Demanded_torque);
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _NREL5MW_Baseline_loads_IPC_1P_v3_2014bMachineNumber_,
        chartInstance->chartNumber,chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "KckI4s8UIEI8OVHICGhj7C";
}

static void sf_opaque_initialize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(void *
  chartInstanceVar)
{
  chart_debug_initialization
    (((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
      chartInstanceVar)->S,0);
  initialize_params_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInstanceVar);
  initialize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_enable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(void
  *chartInstanceVar)
{
  enable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_disable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(void
  *chartInstanceVar)
{
  disable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInstanceVar);
}

static void sf_opaque_gateway_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(void
  *chartInstanceVar)
{
  sf_gateway_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInstanceVar);
}

static const mxArray*
  sf_opaque_get_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(SimStruct* S)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  return get_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInfo->chartInstance);        /* raw sim ctx */
}

static void sf_opaque_set_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SimStruct* S, const mxArray *st)
{
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
  ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
  set_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInfo->chartInstance, st);
}

static void sf_opaque_terminate_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(void
  *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
                    chartInstanceVar)->S;
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_optimization_info();
    }

    finalize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
      ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
       chartInstanceVar);
    utFree(chartInstanceVar);
    if (crtInfo != NULL) {
      utFree(crtInfo);
    }

    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
    ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
     chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
  (SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)(ssGetUserData(S));
    ChartInfoStruct * chartInfo = (ChartInfoStruct *)(crtInfo->instanceInfo);
    initialize_params_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b
      ((SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct*)
       (chartInfo->chartInstance));
  }
}

static void mdlSetWorkWidths_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(SimStruct
  *S)
{
  /* Actual parameters from chart:
     Demanded_torque
   */
  const char_T *rtParamNames[] = { "Demanded_torque" };

  ssSetNumRunTimeParams(S,ssGetSFcnParamsCount(S));

  /* registration for Demanded_torque*/
  ssRegDlgParamAsRunTimeParam(S, 0, 0, rtParamNames[0], SS_DOUBLE);
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct =
      load_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(sf_get_instance_specialization(),infoStruct,3);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(sf_get_instance_specialization(),
                infoStruct,3,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop
      (sf_get_instance_specialization(),infoStruct,3,
       "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(sf_get_instance_specialization(),infoStruct,3);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 3, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,3,4);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,3,2);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=2; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 4; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,3);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(2897846909U));
  ssSetChecksum1(S,(3179915780U));
  ssSetChecksum2(S,(446538875U));
  ssSetChecksum3(S,(1328889547U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Truth Table");
  }
}

static void mdlStart_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(SimStruct *S)
{
  SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *chartInstance;
  ChartRunTimeInfo * crtInfo = (ChartRunTimeInfo *)utMalloc(sizeof
    (ChartRunTimeInfo));
  chartInstance = (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct *)
    utMalloc(sizeof(SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct));
  memset(chartInstance, 0, sizeof
         (SFc3_NREL5MW_Baseline_loads_IPC_1P_v3_2014bInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 0;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.enableChart =
    sf_opaque_enable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW =
    mdlRTW_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.mdlStart =
    mdlStart_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->chartInfo.callAtomicSubchartUserFcn = NULL;
  chartInstance->chartInfo.callAtomicSubchartAutoFcn = NULL;
  chartInstance->chartInfo.debugInstance = sfGlobalDebugInstanceStruct;
  chartInstance->S = S;
  crtInfo->checksum = SF_RUNTIME_INFO_CHECKSUM;
  crtInfo->instanceInfo = (&(chartInstance->chartInfo));
  crtInfo->isJITEnabled = false;
  crtInfo->compiledInfo = NULL;
  ssSetUserData(S,(void *)(crtInfo));  /* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  init_simulink_io_address(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_method_dispatcher(SimStruct *S,
  int_T method, void *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c3_NREL5MW_Baseline_loads_IPC_1P_v3_2014b_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
