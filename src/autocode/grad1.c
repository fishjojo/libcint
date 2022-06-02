/*
 * Copyright (C) 2013-  Qiming Sun <osirpt.sun@gmail.com>
 * Description: code generated by  gen-code.cl
 */
#include <stdlib.h>
#include <stdio.h>
#include "cint_bas.h"
#include "cart2sph.h"
#include "g1e.h"
#include "g1e_grids.h"
#include "g2e.h"
#include "optimizer.h"
#include "cint1e.h"
#include "cint2e.h"
#include "misc.h"
#include "c2f.h"
/* <NABLA i|OVLP |j> */
void CINTgout1e_int1e_ipovlp(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double s[3];
G1E_D_I(g1, g0, envs->i_l+0, envs->j_l, 0);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
if (gout_empty) {
gout[n*3+0] = + s[0];
gout[n*3+1] = + s[1];
gout[n*3+2] = + s[2];
} else {
gout[n*3+0] += + s[0];
gout[n*3+1] += + s[1];
gout[n*3+2] += + s[2];
}}}
void int1e_ipovlp_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipovlp_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipovlp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 0);
} // int1e_ipovlp_cart
CACHE_SIZE_T int1e_ipovlp_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipovlp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 0);
} // int1e_ipovlp_sph
CACHE_SIZE_T int1e_ipovlp_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipovlp;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 0);
} // int1e_ipovlp_spinor
ALL_CINT1E(int1e_ipovlp)
ALL_CINT1E_FORTRAN_(int1e_ipovlp)
INTEGRAL_NAME_ALIAS(int1e_ipovlp, int1e_ovlp_ip10)
/* <i|OVLP |NABLA j> */
void CINTgout1e_int1e_ovlpip(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double s[3];
G1E_D_J(g1, g0, envs->i_l+0, envs->j_l+0, 0);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
s[0] = + g1[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g0[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g0[ix+0]*g0[iy+0]*g1[iz+0];
if (gout_empty) {
gout[n*3+0] = + s[0];
gout[n*3+1] = + s[1];
gout[n*3+2] = + s[2];
} else {
gout[n*3+0] += + s[0];
gout[n*3+1] += + s[1];
gout[n*3+2] += + s[2];
}}}
void int1e_ovlpip_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ovlpip_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ovlpip;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 0);
} // int1e_ovlpip_cart
CACHE_SIZE_T int1e_ovlpip_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ovlpip;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 0);
} // int1e_ovlpip_sph
CACHE_SIZE_T int1e_ovlpip_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 1, 0, 0, 1, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ovlpip;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 0);
} // int1e_ovlpip_spinor
ALL_CINT1E(int1e_ovlpip)
ALL_CINT1E_FORTRAN_(int1e_ovlpip)
INTEGRAL_NAME_ALIAS(int1e_ovlpip, int1e_ovlp_ip01)
/* <NABLA i|OVLP |P DOT P j> */
void CINTgout1e_int1e_ipkin(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
double s[27];
G1E_D_J(g1, g0, envs->i_l+1, envs->j_l+0, 0);
G1E_D_J(g2, g0, envs->i_l+1, envs->j_l+1, 0);
G1E_D_J(g3, g2, envs->i_l+1, envs->j_l+0, 0);
G1E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0);
G1E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0);
G1E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0);
G1E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
s[0] = + g7[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g6[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g6[ix+0]*g0[iy+0]*g1[iz+0];
s[3] = + g5[ix+0]*g2[iy+0]*g0[iz+0];
s[4] = + g4[ix+0]*g3[iy+0]*g0[iz+0];
s[5] = + g4[ix+0]*g2[iy+0]*g1[iz+0];
s[6] = + g5[ix+0]*g0[iy+0]*g2[iz+0];
s[7] = + g4[ix+0]*g1[iy+0]*g2[iz+0];
s[8] = + g4[ix+0]*g0[iy+0]*g3[iz+0];
s[9] = + g3[ix+0]*g4[iy+0]*g0[iz+0];
s[10] = + g2[ix+0]*g5[iy+0]*g0[iz+0];
s[11] = + g2[ix+0]*g4[iy+0]*g1[iz+0];
s[12] = + g1[ix+0]*g6[iy+0]*g0[iz+0];
s[13] = + g0[ix+0]*g7[iy+0]*g0[iz+0];
s[14] = + g0[ix+0]*g6[iy+0]*g1[iz+0];
s[15] = + g1[ix+0]*g4[iy+0]*g2[iz+0];
s[16] = + g0[ix+0]*g5[iy+0]*g2[iz+0];
s[17] = + g0[ix+0]*g4[iy+0]*g3[iz+0];
s[18] = + g3[ix+0]*g0[iy+0]*g4[iz+0];
s[19] = + g2[ix+0]*g1[iy+0]*g4[iz+0];
s[20] = + g2[ix+0]*g0[iy+0]*g5[iz+0];
s[21] = + g1[ix+0]*g2[iy+0]*g4[iz+0];
s[22] = + g0[ix+0]*g3[iy+0]*g4[iz+0];
s[23] = + g0[ix+0]*g2[iy+0]*g5[iz+0];
s[24] = + g1[ix+0]*g0[iy+0]*g6[iz+0];
s[25] = + g0[ix+0]*g1[iy+0]*g6[iz+0];
s[26] = + g0[ix+0]*g0[iy+0]*g7[iz+0];
if (gout_empty) {
gout[n*3+0] = - s[0] - s[4] - s[8];
gout[n*3+1] = - s[9] - s[13] - s[17];
gout[n*3+2] = - s[18] - s[22] - s[26];
} else {
gout[n*3+0] += - s[0] - s[4] - s[8];
gout[n*3+1] += - s[9] - s[13] - s[17];
gout[n*3+2] += - s[18] - s[22] - s[26];
}}}
void int1e_ipkin_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 2, 0, 0, 3, 1, 1, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipkin_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 2, 0, 0, 3, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipkin;
envs.common_factor *= 0.5;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 0);
} // int1e_ipkin_cart
CACHE_SIZE_T int1e_ipkin_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 2, 0, 0, 3, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipkin;
envs.common_factor *= 0.5;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 0);
} // int1e_ipkin_sph
CACHE_SIZE_T int1e_ipkin_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 2, 0, 0, 3, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipkin;
envs.common_factor *= 0.5;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 0);
} // int1e_ipkin_spinor
ALL_CINT1E(int1e_ipkin)
ALL_CINT1E_FORTRAN_(int1e_ipkin)
INTEGRAL_NAME_ALIAS(int1e_ipkin, int1e_kin_ip10)
/* <i|OVLP |P DOT P NABLA j> */
void CINTgout1e_int1e_kinip(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT ix, iy, iz, n;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
double s[27];
G1E_D_J(g1, g0, envs->i_l+0, envs->j_l+0, 0);
G1E_D_J(g2, g0, envs->i_l+0, envs->j_l+1, 0);
G1E_D_J(g3, g2, envs->i_l+0, envs->j_l+0, 0);
G1E_D_J(g4, g0, envs->i_l+0, envs->j_l+2, 0);
G1E_D_J(g5, g4, envs->i_l+0, envs->j_l+0, 0);
G1E_D_J(g6, g4, envs->i_l+0, envs->j_l+1, 0);
G1E_D_J(g7, g6, envs->i_l+0, envs->j_l+0, 0);
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
s[0] = + g7[ix+0]*g0[iy+0]*g0[iz+0];
s[1] = + g6[ix+0]*g1[iy+0]*g0[iz+0];
s[2] = + g6[ix+0]*g0[iy+0]*g1[iz+0];
s[3] = + g5[ix+0]*g2[iy+0]*g0[iz+0];
s[4] = + g4[ix+0]*g3[iy+0]*g0[iz+0];
s[5] = + g4[ix+0]*g2[iy+0]*g1[iz+0];
s[6] = + g5[ix+0]*g0[iy+0]*g2[iz+0];
s[7] = + g4[ix+0]*g1[iy+0]*g2[iz+0];
s[8] = + g4[ix+0]*g0[iy+0]*g3[iz+0];
s[9] = + g3[ix+0]*g4[iy+0]*g0[iz+0];
s[10] = + g2[ix+0]*g5[iy+0]*g0[iz+0];
s[11] = + g2[ix+0]*g4[iy+0]*g1[iz+0];
s[12] = + g1[ix+0]*g6[iy+0]*g0[iz+0];
s[13] = + g0[ix+0]*g7[iy+0]*g0[iz+0];
s[14] = + g0[ix+0]*g6[iy+0]*g1[iz+0];
s[15] = + g1[ix+0]*g4[iy+0]*g2[iz+0];
s[16] = + g0[ix+0]*g5[iy+0]*g2[iz+0];
s[17] = + g0[ix+0]*g4[iy+0]*g3[iz+0];
s[18] = + g3[ix+0]*g0[iy+0]*g4[iz+0];
s[19] = + g2[ix+0]*g1[iy+0]*g4[iz+0];
s[20] = + g2[ix+0]*g0[iy+0]*g5[iz+0];
s[21] = + g1[ix+0]*g2[iy+0]*g4[iz+0];
s[22] = + g0[ix+0]*g3[iy+0]*g4[iz+0];
s[23] = + g0[ix+0]*g2[iy+0]*g5[iz+0];
s[24] = + g1[ix+0]*g0[iy+0]*g6[iz+0];
s[25] = + g0[ix+0]*g1[iy+0]*g6[iz+0];
s[26] = + g0[ix+0]*g0[iy+0]*g7[iz+0];
if (gout_empty) {
gout[n*3+0] = - s[0] - s[12] - s[24];
gout[n*3+1] = - s[1] - s[13] - s[25];
gout[n*3+2] = - s[2] - s[14] - s[26];
} else {
gout[n*3+0] += - s[0] - s[12] - s[24];
gout[n*3+1] += - s[1] - s[13] - s[25];
gout[n*3+2] += - s[2] - s[14] - s[26];
}}}
void int1e_kinip_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {0, 3, 0, 0, 3, 1, 1, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_kinip_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 3, 0, 0, 3, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_kinip;
envs.common_factor *= 0.5;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 0);
} // int1e_kinip_cart
CACHE_SIZE_T int1e_kinip_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 3, 0, 0, 3, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_kinip;
envs.common_factor *= 0.5;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 0);
} // int1e_kinip_sph
CACHE_SIZE_T int1e_kinip_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {0, 3, 0, 0, 3, 1, 1, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_kinip;
envs.common_factor *= 0.5;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 0);
} // int1e_kinip_spinor
ALL_CINT1E(int1e_kinip)
ALL_CINT1E_FORTRAN_(int1e_kinip)
INTEGRAL_NAME_ALIAS(int1e_kinip, int1e_kin_ip01)
/* <NABLA i|NUC |j> */
void CINTgout1e_int1e_ipnuc(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
G2E_D_I(g1, g0, envs->i_l+0, envs->j_l, 0, 0);
double s[3];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 3; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];
}
if (gout_empty) {
gout[n*3+0] = + s[0];
gout[n*3+1] = + s[1];
gout[n*3+2] = + s[2];
} else {
gout[n*3+0] += + s[0];
gout[n*3+1] += + s[1];
gout[n*3+2] += + s[2];
}}}
void int1e_ipnuc_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipnuc_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipnuc;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_ipnuc_cart
CACHE_SIZE_T int1e_ipnuc_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipnuc;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_ipnuc_sph
CACHE_SIZE_T int1e_ipnuc_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipnuc;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_ipnuc_spinor
ALL_CINT1E(int1e_ipnuc)
ALL_CINT1E_FORTRAN_(int1e_ipnuc)
INTEGRAL_NAME_ALIAS(int1e_ipnuc, int1e_nuc_ip10)
/* <NABLA i|RINV |j> */
void CINTgout1e_int1e_iprinv(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
G2E_D_I(g1, g0, envs->i_l+0, envs->j_l, 0, 0);
double s[3];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 3; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g1[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g0[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g0[ix+i] * g0[iy+i] * g1[iz+i];
}
if (gout_empty) {
gout[n*3+0] = + s[0];
gout[n*3+1] = + s[1];
gout[n*3+2] = + s[2];
} else {
gout[n*3+0] += + s[0];
gout[n*3+1] += + s[1];
gout[n*3+2] += + s[2];
}}}
void int1e_iprinv_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_iprinv_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_iprinv;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_iprinv_cart
CACHE_SIZE_T int1e_iprinv_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_iprinv;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_iprinv_sph
CACHE_SIZE_T int1e_iprinv_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {1, 0, 0, 0, 1, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_iprinv;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_iprinv_spinor
ALL_CINT1E(int1e_iprinv)
ALL_CINT1E_FORTRAN_(int1e_iprinv)
INTEGRAL_NAME_ALIAS(int1e_iprinv, int1e_rinv_ip10)
/* <NABLA SIGMA DOT P i|NUC |SIGMA DOT P j> */
void CINTgout1e_int1e_ipspnucsp(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+2, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*12+0] = + s[11] - s[19];
gout[n*12+1] = + s[18] - s[2];
gout[n*12+2] = + s[1] - s[9];
gout[n*12+3] = + s[0] + s[10] + s[20];
gout[n*12+4] = + s[14] - s[22];
gout[n*12+5] = + s[21] - s[5];
gout[n*12+6] = + s[4] - s[12];
gout[n*12+7] = + s[3] + s[13] + s[23];
gout[n*12+8] = + s[17] - s[25];
gout[n*12+9] = + s[24] - s[8];
gout[n*12+10] = + s[7] - s[15];
gout[n*12+11] = + s[6] + s[16] + s[26];
} else {
gout[n*12+0] += + s[11] - s[19];
gout[n*12+1] += + s[18] - s[2];
gout[n*12+2] += + s[1] - s[9];
gout[n*12+3] += + s[0] + s[10] + s[20];
gout[n*12+4] += + s[14] - s[22];
gout[n*12+5] += + s[21] - s[5];
gout[n*12+6] += + s[4] - s[12];
gout[n*12+7] += + s[3] + s[13] + s[23];
gout[n*12+8] += + s[17] - s[25];
gout[n*12+9] += + s[24] - s[8];
gout[n*12+10] += + s[7] - s[15];
gout[n*12+11] += + s[6] + s[16] + s[26];
}}}
void int1e_ipspnucsp_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipspnucsp_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipspnucsp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_ipspnucsp_cart
CACHE_SIZE_T int1e_ipspnucsp_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipspnucsp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_ipspnucsp_sph
CACHE_SIZE_T int1e_ipspnucsp_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipspnucsp;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_si_1e, 2);
} // int1e_ipspnucsp_spinor
ALL_CINT1E(int1e_ipspnucsp)
ALL_CINT1E_FORTRAN_(int1e_ipspnucsp)
/* <NABLA SIGMA DOT P i|RINV |SIGMA DOT P j> */
void CINTgout1e_int1e_ipsprinvsp(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+2, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*12+0] = + s[11] - s[19];
gout[n*12+1] = + s[18] - s[2];
gout[n*12+2] = + s[1] - s[9];
gout[n*12+3] = + s[0] + s[10] + s[20];
gout[n*12+4] = + s[14] - s[22];
gout[n*12+5] = + s[21] - s[5];
gout[n*12+6] = + s[4] - s[12];
gout[n*12+7] = + s[3] + s[13] + s[23];
gout[n*12+8] = + s[17] - s[25];
gout[n*12+9] = + s[24] - s[8];
gout[n*12+10] = + s[7] - s[15];
gout[n*12+11] = + s[6] + s[16] + s[26];
} else {
gout[n*12+0] += + s[11] - s[19];
gout[n*12+1] += + s[18] - s[2];
gout[n*12+2] += + s[1] - s[9];
gout[n*12+3] += + s[0] + s[10] + s[20];
gout[n*12+4] += + s[14] - s[22];
gout[n*12+5] += + s[21] - s[5];
gout[n*12+6] += + s[4] - s[12];
gout[n*12+7] += + s[3] + s[13] + s[23];
gout[n*12+8] += + s[17] - s[25];
gout[n*12+9] += + s[24] - s[8];
gout[n*12+10] += + s[7] - s[15];
gout[n*12+11] += + s[6] + s[16] + s[26];
}}}
void int1e_ipsprinvsp_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipsprinvsp_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipsprinvsp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_ipsprinvsp_cart
CACHE_SIZE_T int1e_ipsprinvsp_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipsprinvsp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_ipsprinvsp_sph
CACHE_SIZE_T int1e_ipsprinvsp_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 4, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipsprinvsp;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_si_1e, 1);
} // int1e_ipsprinvsp_spinor
ALL_CINT1E(int1e_ipsprinvsp)
ALL_CINT1E_FORTRAN_(int1e_ipsprinvsp)
/* <P* NABLA i|NUC DOT P |j> */
void CINTgout1e_int1e_ippnucp(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+2, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*3+0] = + s[0] + s[4] + s[8];
gout[n*3+1] = + s[9] + s[13] + s[17];
gout[n*3+2] = + s[18] + s[22] + s[26];
} else {
gout[n*3+0] += + s[0] + s[4] + s[8];
gout[n*3+1] += + s[9] + s[13] + s[17];
gout[n*3+2] += + s[18] + s[22] + s[26];
}}}
void int1e_ippnucp_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ippnucp_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ippnucp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 2);
} // int1e_ippnucp_cart
CACHE_SIZE_T int1e_ippnucp_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ippnucp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 2);
} // int1e_ippnucp_sph
CACHE_SIZE_T int1e_ippnucp_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ippnucp;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 2);
} // int1e_ippnucp_spinor
ALL_CINT1E(int1e_ippnucp)
ALL_CINT1E_FORTRAN_(int1e_ippnucp)
/* <P* NABLA i|RINV DOT P |j> */
void CINTgout1e_int1e_ipprinvp(double *gout, double *g, FINT *idx, CINTEnvVars *envs, FINT gout_empty) {
FINT nf = envs->nf;
FINT nrys_roots = envs->nrys_roots;
FINT ix, iy, iz, n, i;
double *g0 = g;
double *g1 = g0 + envs->g_size * 3;
double *g2 = g1 + envs->g_size * 3;
double *g3 = g2 + envs->g_size * 3;
double *g4 = g3 + envs->g_size * 3;
double *g5 = g4 + envs->g_size * 3;
double *g6 = g5 + envs->g_size * 3;
double *g7 = g6 + envs->g_size * 3;
G2E_D_J(g1, g0, envs->i_l+2, envs->j_l+0, 0, 0);
G2E_D_I(g2, g0, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g3, g1, envs->i_l+1, envs->j_l, 0, 0);
G2E_D_I(g4, g0, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g5, g1, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g6, g2, envs->i_l+0, envs->j_l, 0, 0);
G2E_D_I(g7, g3, envs->i_l+0, envs->j_l, 0, 0);
double s[27];
for (n = 0; n < nf; n++) {
ix = idx[0+n*3];
iy = idx[1+n*3];
iz = idx[2+n*3];
for (i = 0; i < 27; i++) { s[i] = 0; }
for (i = 0; i < nrys_roots; i++) {
s[0] += g7[ix+i] * g0[iy+i] * g0[iz+i];
s[1] += g6[ix+i] * g1[iy+i] * g0[iz+i];
s[2] += g6[ix+i] * g0[iy+i] * g1[iz+i];
s[3] += g5[ix+i] * g2[iy+i] * g0[iz+i];
s[4] += g4[ix+i] * g3[iy+i] * g0[iz+i];
s[5] += g4[ix+i] * g2[iy+i] * g1[iz+i];
s[6] += g5[ix+i] * g0[iy+i] * g2[iz+i];
s[7] += g4[ix+i] * g1[iy+i] * g2[iz+i];
s[8] += g4[ix+i] * g0[iy+i] * g3[iz+i];
s[9] += g3[ix+i] * g4[iy+i] * g0[iz+i];
s[10] += g2[ix+i] * g5[iy+i] * g0[iz+i];
s[11] += g2[ix+i] * g4[iy+i] * g1[iz+i];
s[12] += g1[ix+i] * g6[iy+i] * g0[iz+i];
s[13] += g0[ix+i] * g7[iy+i] * g0[iz+i];
s[14] += g0[ix+i] * g6[iy+i] * g1[iz+i];
s[15] += g1[ix+i] * g4[iy+i] * g2[iz+i];
s[16] += g0[ix+i] * g5[iy+i] * g2[iz+i];
s[17] += g0[ix+i] * g4[iy+i] * g3[iz+i];
s[18] += g3[ix+i] * g0[iy+i] * g4[iz+i];
s[19] += g2[ix+i] * g1[iy+i] * g4[iz+i];
s[20] += g2[ix+i] * g0[iy+i] * g5[iz+i];
s[21] += g1[ix+i] * g2[iy+i] * g4[iz+i];
s[22] += g0[ix+i] * g3[iy+i] * g4[iz+i];
s[23] += g0[ix+i] * g2[iy+i] * g5[iz+i];
s[24] += g1[ix+i] * g0[iy+i] * g6[iz+i];
s[25] += g0[ix+i] * g1[iy+i] * g6[iz+i];
s[26] += g0[ix+i] * g0[iy+i] * g7[iz+i];
}
if (gout_empty) {
gout[n*3+0] = + s[0] + s[4] + s[8];
gout[n*3+1] = + s[9] + s[13] + s[17];
gout[n*3+2] = + s[18] + s[22] + s[26];
} else {
gout[n*3+0] += + s[0] + s[4] + s[8];
gout[n*3+1] += + s[9] + s[13] + s[17];
gout[n*3+2] += + s[18] + s[22] + s[26];
}}}
void int1e_ipprinvp_optimizer(CINTOpt **opt, FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTall_1e_optimizer(opt, ng, atm, natm, bas, nbas, env);
}
CACHE_SIZE_T int1e_ipprinvp_cart(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipprinvp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_cart_1e, 1);
} // int1e_ipprinvp_cart
CACHE_SIZE_T int1e_ipprinvp_sph(double *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipprinvp;
return CINT1e_drv(out, dims, &envs, cache, &c2s_sph_1e, 1);
} // int1e_ipprinvp_sph
CACHE_SIZE_T int1e_ipprinvp_spinor(double complex *out, FINT *dims, FINT *shls,
FINT *atm, FINT natm, FINT *bas, FINT nbas, double *env, CINTOpt *opt, double *cache) {
FINT ng[] = {2, 1, 0, 0, 3, 1, 0, 3};
CINTEnvVars envs;
CINTinit_int1e_EnvVars(&envs, ng, shls, atm, natm, bas, nbas, env);
envs.f_gout = &CINTgout1e_int1e_ipprinvp;
return CINT1e_spinor_drv(out, dims, &envs, cache, &c2s_sf_1e, 1);
} // int1e_ipprinvp_spinor
ALL_CINT1E(int1e_ipprinvp)
ALL_CINT1E_FORTRAN_(int1e_ipprinvp)
