#include <RcppArmadillo.h>
#include <Rcpp.h>
#include <stdio.h>
#include <bitset>
#include <math.h>
#include <boost/algorithm/string.hpp>
#include <boost/range.hpp>
#include <boost/range/algorithm.hpp>
#include "time.h"
#include <iostream>
#include <thread>
#include <vector>
#include "pdsoft.hpp"
#include "Pxvb.hpp"
#include "Gibbspar.hpp"
#include "ReadGeneFile.hpp"
#include "CalCorr.hpp"
#include "data_loader.hpp"
#include "Model1_Par_pxvb.hpp"
#include "Model2_Par_pxvb.hpp"

using namespace Rcpp;
using namespace arma;
using namespace std;
using namespace boost;

// [[Rcpp::depends(RcppArmadillo)]]
// [[Rcpp::depends(BH)]]


// load_block_file
vector<umat> load_block_file(string block_file);
RcppExport SEXP _MR_LDP_load_block_file(SEXP block_fileSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< string >::type block_file(block_fileSEXP);
    rcpp_result_gen = Rcpp::wrap(load_block_file(block_file));
    return rcpp_result_gen;
END_RCPP
}
// test_blocks
List test_blocks(arma::ivec bp, arma::ivec chr, std::string block_file);
RcppExport SEXP _MR_LDP_test_blocks(SEXP bpSEXP, SEXP chrSEXP, SEXP block_fileSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    rcpp_result_gen = Rcpp::wrap(test_blocks(bp, chr, block_file));
    return rcpp_result_gen;
END_RCPP
}
// Cal_blockR
List Cal_blockR(arma::ivec bp, arma::ivec chr, arma::uvec avbIndex, std::string block_file, std::string stringname3, int coreNum, double lam);
RcppExport SEXP _MR_LDP_Cal_blockR(SEXP bpSEXP, SEXP chrSEXP, SEXP avbIndexSEXP, SEXP block_fileSEXP, SEXP stringname3SEXP, SEXP coreNumSEXP, SEXP lamSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type avbIndex(avbIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< double >::type lam(lamSEXP);
    rcpp_result_gen = Rcpp::wrap(Cal_blockR(bp, chr, avbIndex, block_file, stringname3, coreNum, lam));
    return rcpp_result_gen;
END_RCPP
}
// gibbs2_update_gamma
void gibbs2_update_gamma(arma::vec gammah, arma::vec Gammah, arma::vec sg2, arma::vec sG2, arma::mat R, arma::vec& mu, arma::vec& muA, double& beta0, double& sgga2, double& sgal2, double agm, double bgm, arma::vec& GinvsG2, arma::mat& insGRinsG);
RcppExport SEXP _MR_LDP_gibbs2_update_gamma(SEXP gammahSEXP, SEXP GammahSEXP, SEXP sg2SEXP, SEXP sG2SEXP, SEXP RSEXP, SEXP muSEXP, SEXP muASEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP agmSEXP, SEXP bgmSEXP, SEXP GinvsG2SEXP, SEXP insGRinsGSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type gammah(gammahSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type Gammah(GammahSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sg2(sg2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sG2(sG2SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type mu(muSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type muA(muASEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< double >::type agm(agmSEXP);
    Rcpp::traits::input_parameter< double >::type bgm(bgmSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type GinvsG2(GinvsG2SEXP);
    Rcpp::traits::input_parameter< arma::mat& >::type insGRinsG(insGRinsGSEXP);
    gibbs2_update_gamma(gammah, Gammah, sg2, sG2, R, mu, muA, beta0, sgga2, sgal2, agm, bgm, GinvsG2, insGRinsG);
    return R_NilValue;
END_RCPP
}
// gibbs2_update_alpha
void gibbs2_update_alpha(arma::vec gammah, arma::vec Gammah, arma::vec sg2, arma::vec sG2, arma::mat R, arma::vec mu, arma::vec& muA, double beta0, double sgal2, arma::vec GinvsG2);
RcppExport SEXP _MR_LDP_gibbs2_update_alpha(SEXP gammahSEXP, SEXP GammahSEXP, SEXP sg2SEXP, SEXP sG2SEXP, SEXP RSEXP, SEXP muSEXP, SEXP muASEXP, SEXP beta0SEXP, SEXP sgal2SEXP, SEXP GinvsG2SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type gammah(gammahSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type Gammah(GammahSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sg2(sg2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sG2(sG2SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type muA(muASEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type GinvsG2(GinvsG2SEXP);
    gibbs2_update_alpha(gammah, Gammah, sg2, sG2, R, mu, muA, beta0, sgal2, GinvsG2);
    return R_NilValue;
END_RCPP
}
// Para_Gibbs1
void Para_Gibbs1(arma::field<mat> F4Rblock, arma::umat block_inf, uword nblocks, arma::vec bh1, arma::vec bh2, arma::vec s12, arma::vec s22, arma::vec& gamma, double& beta0, double& sgga2, int coreNum);
RcppExport SEXP _MR_LDP_Para_Gibbs1(SEXP F4RblockSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP s12SEXP, SEXP s22SEXP, SEXP gammaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP coreNumSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<mat> >::type F4Rblock(F4RblockSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s12(s12SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s22(s22SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Para_Gibbs1(F4Rblock, block_inf, nblocks, bh1, bh2, s12, s22, gamma, beta0, sgga2, coreNum);
    return R_NilValue;
END_RCPP
}
// Para_Gibbs2
void Para_Gibbs2(arma::field<mat> F4Rblock, arma::umat block_inf, uword nblocks, arma::vec bh1, arma::vec bh2, arma::vec s12, arma::vec s22, arma::vec& gamma, arma::vec& alpha, double& beta0, double& sgga2, double& sgal2, int coreNum);
RcppExport SEXP _MR_LDP_Para_Gibbs2(SEXP F4RblockSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP s12SEXP, SEXP s22SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<mat> >::type F4Rblock(F4RblockSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s12(s12SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s22(s22SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Para_Gibbs2(F4Rblock, block_inf, nblocks, bh1, bh2, s12, s22, gamma, alpha, beta0, sgga2, sgal2, coreNum);
    return R_NilValue;
END_RCPP
}
// gibbsres1
Rcpp::List gibbsres1(arma::field<mat> F4Rblock, arma::umat block_inf, uword nblocks, arma::vec bh1, arma::vec bh2, arma::vec s12, arma::vec s22, arma::vec& gamma, double& beta0, double& sgga2, int coreNum, int IterMax);
RcppExport SEXP _MR_LDP_gibbsres1(SEXP F4RblockSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP s12SEXP, SEXP s22SEXP, SEXP gammaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP coreNumSEXP, SEXP IterMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<mat> >::type F4Rblock(F4RblockSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s12(s12SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s22(s22SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< int >::type IterMax(IterMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(gibbsres1(F4Rblock, block_inf, nblocks, bh1, bh2, s12, s22, gamma, beta0, sgga2, coreNum, IterMax));
    return rcpp_result_gen;
END_RCPP
}
// gibbsres2
Rcpp::List gibbsres2(arma::field<mat> F4Rblock, arma::umat block_inf, uword nblocks, arma::vec bh1, arma::vec bh2, arma::vec s12, arma::vec s22, arma::vec& gamma, arma::vec& alpha, double& beta0, double& sgga2, double& sgal2, int coreNum, int IterMax);
RcppExport SEXP _MR_LDP_gibbsres2(SEXP F4RblockSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP s12SEXP, SEXP s22SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP IterMaxSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::field<mat> >::type F4Rblock(F4RblockSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s12(s12SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type s22(s22SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< int >::type IterMax(IterMaxSEXP);
    rcpp_result_gen = Rcpp::wrap(gibbsres2(F4Rblock, block_inf, nblocks, bh1, bh2, s12, s22, gamma, alpha, beta0, sgga2, sgal2, coreNum, IterMax));
    return rcpp_result_gen;
END_RCPP
}
// Varres
void Varres(field<mat>& F4H2a, arma::mat R, arma::umat block_inf, uword nblocks, arma::vec bh2, arma::vec se2, arma::ivec N2);
RcppExport SEXP _MR_LDP_Varres(SEXP F4H2aSEXP, SEXP RSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh2SEXP, SEXP se2SEXP, SEXP N2SEXP) {
BEGIN_RCPP
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< field<mat>& >::type F4H2a(F4H2aSEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type N2(N2SEXP);
    Varres(F4H2a, R, block_inf, nblocks, bh2, se2, N2);
    return R_NilValue;
END_RCPP
}
// Herit_iMax
arma::vec Herit_iMax(arma::mat R, arma::umat block_inf, uword nblocks, arma::vec bh2, arma::vec se2, arma::ivec N2, arma::mat ALres);
RcppExport SEXP _MR_LDP_Herit_iMax(SEXP RSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh2SEXP, SEXP se2SEXP, SEXP N2SEXP, SEXP ALresSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type N2(N2SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type ALres(ALresSEXP);
    rcpp_result_gen = Rcpp::wrap(Herit_iMax(R, block_inf, nblocks, bh2, se2, N2, ALres));
    return rcpp_result_gen;
END_RCPP
}
// heritability
double heritability(field<mat> F4H2a, arma::umat block_inf, uword nblocks, arma::vec alpha);
RcppExport SEXP _MR_LDP_heritability(SEXP F4H2aSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP alphaSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< field<mat> >::type F4H2a(F4H2aSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type alpha(alphaSEXP);
    rcpp_result_gen = Rcpp::wrap(heritability(F4H2a, block_inf, nblocks, alpha));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_SimVb
Rcpp::List MRLDP_SimVb(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec gamma, arma::vec alpha, double beta0, double& sgga2, double& sgal2, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter, const int& model);
RcppExport SEXP _MR_LDP_MRLDP_SimVb(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< const int& >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_SimVb(bh1, bh2, se1, se2, gamma, alpha, beta0, sgga2, sgal2, R, constr, epsStopLogLik, maxIter, model));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_SimPXvb
Rcpp::List MRLDP_SimPXvb(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec gamma, arma::vec alpha, double beta0, double& sgga2, double& sgal2, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter, const int& model);
RcppExport SEXP _MR_LDP_MRLDP_SimPXvb(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< const int& >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_SimPXvb(bh1, bh2, se1, se2, gamma, alpha, beta0, sgga2, sgal2, R, constr, epsStopLogLik, maxIter, model));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_SimVBMg
Rcpp::List MRLDP_SimVBMg(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec gamma, double sgga2, double sgal2, double beta0, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_MRLDP_SimVBMg(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_SimVBMg(bh1, bh2, se1, se2, gamma, sgga2, sgal2, beta0, R, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_SimMggibbs
Rcpp::List MRLDP_SimMggibbs(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec gamma, double& sgga2, double sgal2, double beta0, arma::mat R, int maxIter, int agm, double bgm);
RcppExport SEXP _MR_LDP_MRLDP_SimMggibbs(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP maxIterSEXP, SEXP agmSEXP, SEXP bgmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< int >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< int >::type agm(agmSEXP);
    Rcpp::traits::input_parameter< double >::type bgm(bgmSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_SimMggibbs(bh1, bh2, se1, se2, gamma, sgga2, sgal2, beta0, R, maxIter, agm, bgm));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_SimGibbspar
Rcpp::List MRLDP_SimGibbspar(arma::mat R, arma::umat block_inf, uword nblocks, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& gamma, arma::vec& alpha, double& beta0, double& sgga2, double& sgal2, int coreNum, int IterMax, arma::ivec N2, int model);
RcppExport SEXP _MR_LDP_MRLDP_SimGibbspar(SEXP RSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP IterMaxSEXP, SEXP N2SEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< int >::type IterMax(IterMaxSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type N2(N2SEXP);
    Rcpp::traits::input_parameter< int >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_SimGibbspar(R, block_inf, nblocks, bh1, bh2, se1, se2, gamma, alpha, beta0, sgga2, sgal2, coreNum, IterMax, N2, model));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_RealVb
Rcpp::List MRLDP_RealVb(arma::ivec bp, arma::ivec chr, arma::uvec avbIndex, std::string block_file, std::string stringname3, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& gamma, arma::vec& alpha, double& beta0, double& sgga2, double& sgal2, int coreNum, double lam, const int& constr, const double& epsStopLogLik, const int& maxIter, const int& model);
RcppExport SEXP _MR_LDP_MRLDP_RealVb(SEXP bpSEXP, SEXP chrSEXP, SEXP avbIndexSEXP, SEXP block_fileSEXP, SEXP stringname3SEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP lamSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type avbIndex(avbIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< double >::type lam(lamSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< const int& >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_RealVb(bp, chr, avbIndex, block_file, stringname3, bh1, bh2, se1, se2, gamma, alpha, beta0, sgga2, sgal2, coreNum, lam, constr, epsStopLogLik, maxIter, model));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_RealPXvb
Rcpp::List MRLDP_RealPXvb(arma::ivec bp, arma::ivec chr, arma::uvec avbIndex, std::string block_file, std::string stringname3, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& gamma, arma::vec& alpha, double& beta0, double& sgga2, double& sgal2, int coreNum, double lam, const int& constr, const double& epsStopLogLik, const int& maxIter, const int& model);
RcppExport SEXP _MR_LDP_MRLDP_RealPXvb(SEXP bpSEXP, SEXP chrSEXP, SEXP avbIndexSEXP, SEXP block_fileSEXP, SEXP stringname3SEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP lamSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type avbIndex(avbIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< double >::type lam(lamSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< const int& >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_RealPXvb(bp, chr, avbIndex, block_file, stringname3, bh1, bh2, se1, se2, gamma, alpha, beta0, sgga2, sgal2, coreNum, lam, constr, epsStopLogLik, maxIter, model));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_RealParPXvb
Rcpp::List MRLDP_RealParPXvb(arma::ivec bp, arma::ivec chr, arma::uvec avbIndex, std::string block_file, std::string stringname3, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& gamma, arma::vec& alpha, double& beta0, double& sgga2, double& sgal2, int coreNum, double lam, const int& constr, const double& epsStopLogLik, const int& maxIter, const int& model);
RcppExport SEXP _MR_LDP_MRLDP_RealParPXvb(SEXP bpSEXP, SEXP chrSEXP, SEXP avbIndexSEXP, SEXP block_fileSEXP, SEXP stringname3SEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP lamSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type avbIndex(avbIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< double >::type lam(lamSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< const int& >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_RealParPXvb(bp, chr, avbIndex, block_file, stringname3, bh1, bh2, se1, se2, gamma, alpha, beta0, sgga2, sgal2, coreNum, lam, constr, epsStopLogLik, maxIter, model));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_RealVBMg
Rcpp::List MRLDP_RealVBMg(arma::ivec bp, arma::ivec chr, arma::uvec avbIndex, std::string block_file, std::string stringname3, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& gamma, double& beta0, double& sgga2, double sgal2, int coreNum, double lam, const int& constr, const double& epsStopLogLik, const int& maxIter, const int& model);
RcppExport SEXP _MR_LDP_MRLDP_RealVBMg(SEXP bpSEXP, SEXP chrSEXP, SEXP avbIndexSEXP, SEXP block_fileSEXP, SEXP stringname3SEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP lamSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type avbIndex(avbIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< double >::type lam(lamSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< const int& >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_RealVBMg(bp, chr, avbIndex, block_file, stringname3, bh1, bh2, se1, se2, gamma, beta0, sgga2, sgal2, coreNum, lam, constr, epsStopLogLik, maxIter, model));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_RealMggibbs
Rcpp::List MRLDP_RealMggibbs(arma::ivec bp, arma::ivec chr, arma::uvec avbIndex, std::string block_file, std::string stringname3, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& gamma, double& beta0, double& sgga2, double sgal2, int coreNum, double lam, int maxIter, int agm, double bgm);
RcppExport SEXP _MR_LDP_MRLDP_RealMggibbs(SEXP bpSEXP, SEXP chrSEXP, SEXP avbIndexSEXP, SEXP block_fileSEXP, SEXP stringname3SEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP lamSEXP, SEXP maxIterSEXP, SEXP agmSEXP, SEXP bgmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type avbIndex(avbIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< double >::type lam(lamSEXP);
    Rcpp::traits::input_parameter< int >::type maxIter(maxIterSEXP);
    Rcpp::traits::input_parameter< int >::type agm(agmSEXP);
    Rcpp::traits::input_parameter< double >::type bgm(bgmSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_RealMggibbs(bp, chr, avbIndex, block_file, stringname3, bh1, bh2, se1, se2, gamma, beta0, sgga2, sgal2, coreNum, lam, maxIter, agm, bgm));
    return rcpp_result_gen;
END_RCPP
}
// MRLDP_RealGibbspar
Rcpp::List MRLDP_RealGibbspar(arma::ivec bp, arma::ivec chr, arma::uvec avbIndex, std::string block_file, std::string stringname3, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& gamma, arma::vec& alpha, double& beta0, double& sgga2, double& sgal2, int coreNum, double lam, int IterMax, arma::ivec N2, int model);
RcppExport SEXP _MR_LDP_MRLDP_RealGibbspar(SEXP bpSEXP, SEXP chrSEXP, SEXP avbIndexSEXP, SEXP block_fileSEXP, SEXP stringname3SEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP gammaSEXP, SEXP alphaSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP lamSEXP, SEXP IterMaxSEXP, SEXP N2SEXP, SEXP modelSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::ivec >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type avbIndex(avbIndexSEXP);
    Rcpp::traits::input_parameter< std::string >::type block_file(block_fileSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type gamma(gammaSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type alpha(alphaSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< double >::type lam(lamSEXP);
    Rcpp::traits::input_parameter< int >::type IterMax(IterMaxSEXP);
    Rcpp::traits::input_parameter< arma::ivec >::type N2(N2SEXP);
    Rcpp::traits::input_parameter< int >::type model(modelSEXP);
    rcpp_result_gen = Rcpp::wrap(MRLDP_RealGibbspar(bp, chr, avbIndex, block_file, stringname3, bh1, bh2, se1, se2, gamma, alpha, beta0, sgga2, sgal2, coreNum, lam, IterMax, N2, model));
    return rcpp_result_gen;
END_RCPP
}
// Para_PXVb1
Rcpp::List Para_PXVb1(arma::mat R, arma::umat block_inf, uword nblocks, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& mu, double& beta0, double& sgga2, int coreNum, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_Para_PXVb1(SEXP RSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP muSEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP coreNumSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type mu(muSEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(Para_PXVb1(R, block_inf, nblocks, bh1, bh2, se1, se2, mu, beta0, sgga2, coreNum, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// Para_PXVb2
Rcpp::List Para_PXVb2(arma::mat R, arma::umat block_inf, uword nblocks, arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec& mu, arma::vec& muA, double& beta0, double& sgga2, double& sgal2, int coreNum, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_Para_PXVb2(SEXP RSEXP, SEXP block_infSEXP, SEXP nblocksSEXP, SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP muSEXP, SEXP muASEXP, SEXP beta0SEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP coreNumSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< arma::umat >::type block_inf(block_infSEXP);
    Rcpp::traits::input_parameter< uword >::type nblocks(nblocksSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type mu(muSEXP);
    Rcpp::traits::input_parameter< arma::vec& >::type muA(muASEXP);
    Rcpp::traits::input_parameter< double& >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< int >::type coreNum(coreNumSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(Para_PXVb2(R, block_inf, nblocks, bh1, bh2, se1, se2, mu, muA, beta0, sgga2, sgal2, coreNum, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// vbfunM1
List vbfunM1(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec mu, double& sgga2, double beta0, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_vbfunM1(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP muSEXP, SEXP sgga2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(vbfunM1(bh1, bh2, se1, se2, mu, sgga2, beta0, R, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// PXvbfunM1
List PXvbfunM1(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec mu, double& sgga2, double beta0, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_PXvbfunM1(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP muSEXP, SEXP sgga2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(PXvbfunM1(bh1, bh2, se1, se2, mu, sgga2, beta0, R, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// vbfunM2
List vbfunM2(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec mu, arma::vec muA, double& sgga2, double& sgal2, double beta0, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_vbfunM2(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP muSEXP, SEXP muASEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type muA(muASEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(vbfunM2(bh1, bh2, se1, se2, mu, muA, sgga2, sgal2, beta0, R, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// PXvbfunM2
List PXvbfunM2(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec mu, arma::vec muA, double& sgga2, double& sgal2, double beta0, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_PXvbfunM2(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP muSEXP, SEXP muASEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type muA(muASEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double& >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(PXvbfunM2(bh1, bh2, se1, se2, mu, muA, sgga2, sgal2, beta0, R, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// VBMgM2
List VBMgM2(arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2, arma::vec mu, double& sgga2, double sgal2, double beta0, arma::mat R, const int& constr, const double& epsStopLogLik, const int& maxIter);
RcppExport SEXP _MR_LDP_VBMgM2(SEXP bh1SEXP, SEXP bh2SEXP, SEXP se1SEXP, SEXP se2SEXP, SEXP muSEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP constrSEXP, SEXP epsStopLogLikSEXP, SEXP maxIterSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type bh1(bh1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type bh2(bh2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se1(se1SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type se2(se2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< const int& >::type constr(constrSEXP);
    Rcpp::traits::input_parameter< const double& >::type epsStopLogLik(epsStopLogLikSEXP);
    Rcpp::traits::input_parameter< const int& >::type maxIter(maxIterSEXP);
    rcpp_result_gen = Rcpp::wrap(VBMgM2(bh1, bh2, se1, se2, mu, sgga2, sgal2, beta0, R, constr, epsStopLogLik, maxIter));
    return rcpp_result_gen;
END_RCPP
}
// MgMgib2
List MgMgib2(arma::vec gammah, arma::vec Gammah, arma::vec sg2, arma::vec sG2, arma::vec mu, double& sgga2, double sgal2, double beta0, arma::mat R, int IterMax, int agm, double bgm);
RcppExport SEXP _MR_LDP_MgMgib2(SEXP gammahSEXP, SEXP GammahSEXP, SEXP sg2SEXP, SEXP sG2SEXP, SEXP muSEXP, SEXP sgga2SEXP, SEXP sgal2SEXP, SEXP beta0SEXP, SEXP RSEXP, SEXP IterMaxSEXP, SEXP agmSEXP, SEXP bgmSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::vec >::type gammah(gammahSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type Gammah(GammahSEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sg2(sg2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type sG2(sG2SEXP);
    Rcpp::traits::input_parameter< arma::vec >::type mu(muSEXP);
    Rcpp::traits::input_parameter< double& >::type sgga2(sgga2SEXP);
    Rcpp::traits::input_parameter< double >::type sgal2(sgal2SEXP);
    Rcpp::traits::input_parameter< double >::type beta0(beta0SEXP);
    Rcpp::traits::input_parameter< arma::mat >::type R(RSEXP);
    Rcpp::traits::input_parameter< int >::type IterMax(IterMaxSEXP);
    Rcpp::traits::input_parameter< int >::type agm(agmSEXP);
    Rcpp::traits::input_parameter< double >::type bgm(bgmSEXP);
    rcpp_result_gen = Rcpp::wrap(MgMgib2(gammah, Gammah, sg2, sG2, mu, sgga2, sgal2, beta0, R, IterMax, agm, bgm));
    return rcpp_result_gen;
END_RCPP
}
// getLineNum
int getLineNum(std::string filename);
RcppExport SEXP _MR_LDP_getLineNum(SEXP filenameSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type filename(filenameSEXP);
    rcpp_result_gen = Rcpp::wrap(getLineNum(filename));
    return rcpp_result_gen;
END_RCPP
}
// ReadSNPinfo
Rcpp::List ReadSNPinfo(std::string stringname, IntegerVector A1, IntegerVector A2, CharacterVector rsname, IntegerVector chr, IntegerVector bp, NumericVector morgan, int N);
RcppExport SEXP _MR_LDP_ReadSNPinfo(SEXP stringnameSEXP, SEXP A1SEXP, SEXP A2SEXP, SEXP rsnameSEXP, SEXP chrSEXP, SEXP bpSEXP, SEXP morganSEXP, SEXP NSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type stringname(stringnameSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type A1(A1SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type A2(A2SEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type rsname(rsnameSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type morgan(morganSEXP);
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    rcpp_result_gen = Rcpp::wrap(ReadSNPinfo(stringname, A1, A2, rsname, chr, bp, morgan, N));
    return rcpp_result_gen;
END_RCPP
}
// Read_summarystat
Rcpp::List Read_summarystat(std::string stringname, IntegerVector SA1, IntegerVector SA2, CharacterVector rsname, NumericVector betah, NumericVector s2, NumericVector pvalue, IntegerVector chr, IntegerVector bp, int N);
RcppExport SEXP _MR_LDP_Read_summarystat(SEXP stringnameSEXP, SEXP SA1SEXP, SEXP SA2SEXP, SEXP rsnameSEXP, SEXP betahSEXP, SEXP s2SEXP, SEXP pvalueSEXP, SEXP chrSEXP, SEXP bpSEXP, SEXP NSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type stringname(stringnameSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type SA1(SA1SEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type SA2(SA2SEXP);
    Rcpp::traits::input_parameter< CharacterVector >::type rsname(rsnameSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type betah(betahSEXP);
    Rcpp::traits::input_parameter< NumericVector >::type s2(s2SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type pvalue(pvalueSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type chr(chrSEXP);
    Rcpp::traits::input_parameter< IntegerVector >::type bp(bpSEXP);
    Rcpp::traits::input_parameter< int >::type N(NSEXP);
    rcpp_result_gen = Rcpp::wrap(Read_summarystat(stringname, SA1, SA2, rsname, betah, s2, pvalue, chr, bp, N));
    return rcpp_result_gen;
END_RCPP
}
// select
CharacterVector select(CharacterVector vec_, NumericVector idx_);
RcppExport SEXP _MR_LDP_select(SEXP vec_SEXP, SEXP idx_SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< CharacterVector >::type vec_(vec_SEXP);
    Rcpp::traits::input_parameter< NumericVector >::type idx_(idx_SEXP);
    rcpp_result_gen = Rcpp::wrap(select(vec_, idx_));
    return rcpp_result_gen;
END_RCPP
}
// matchscreen
Rcpp::List matchscreen(std::string screenname, std::string stringname1, std::string stringname2, std::string stringname3, double pva_cutoff);
RcppExport SEXP _MR_LDP_matchscreen(SEXP screennameSEXP, SEXP stringname1SEXP, SEXP stringname2SEXP, SEXP stringname3SEXP, SEXP pva_cutoffSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type screenname(screennameSEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname1(stringname1SEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname2(stringname2SEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    Rcpp::traits::input_parameter< double >::type pva_cutoff(pva_cutoffSEXP);
    rcpp_result_gen = Rcpp::wrap(matchscreen(screenname, stringname1, stringname2, stringname3, pva_cutoff));
    return rcpp_result_gen;
END_RCPP
}
// matchsnp
Rcpp::List matchsnp(std::string stringname1, std::string stringname2, std::string stringname3);
RcppExport SEXP _MR_LDP_matchsnp(SEXP stringname1SEXP, SEXP stringname2SEXP, SEXP stringname3SEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< std::string >::type stringname1(stringname1SEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname2(stringname2SEXP);
    Rcpp::traits::input_parameter< std::string >::type stringname3(stringname3SEXP);
    rcpp_result_gen = Rcpp::wrap(matchsnp(stringname1, stringname2, stringname3));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_MR_LDP_load_block_file", (DL_FUNC) &_MR_LDP_load_block_file, 1},
    {"_MR_LDP_test_blocks", (DL_FUNC) &_MR_LDP_test_blocks, 3},
    {"_MR_LDP_Cal_blockR", (DL_FUNC) &_MR_LDP_Cal_blockR, 7},
    {"_MR_LDP_gibbs2_update_gamma", (DL_FUNC) &_MR_LDP_gibbs2_update_gamma, 14},
    {"_MR_LDP_gibbs2_update_alpha", (DL_FUNC) &_MR_LDP_gibbs2_update_alpha, 10},
    {"_MR_LDP_Para_Gibbs1", (DL_FUNC) &_MR_LDP_Para_Gibbs1, 11},
    {"_MR_LDP_Para_Gibbs2", (DL_FUNC) &_MR_LDP_Para_Gibbs2, 13},
    {"_MR_LDP_gibbsres1", (DL_FUNC) &_MR_LDP_gibbsres1, 12},
    {"_MR_LDP_gibbsres2", (DL_FUNC) &_MR_LDP_gibbsres2, 14},
    {"_MR_LDP_Varres", (DL_FUNC) &_MR_LDP_Varres, 7},
    {"_MR_LDP_Herit_iMax", (DL_FUNC) &_MR_LDP_Herit_iMax, 7},
    {"_MR_LDP_heritability", (DL_FUNC) &_MR_LDP_heritability, 4},
    {"_MR_LDP_MRLDP_SimVb", (DL_FUNC) &_MR_LDP_MRLDP_SimVb, 14},
    {"_MR_LDP_MRLDP_SimPXvb", (DL_FUNC) &_MR_LDP_MRLDP_SimPXvb, 14},
    {"_MR_LDP_MRLDP_SimVBMg", (DL_FUNC) &_MR_LDP_MRLDP_SimVBMg, 12},
    {"_MR_LDP_MRLDP_SimMggibbs", (DL_FUNC) &_MR_LDP_MRLDP_SimMggibbs, 12},
    {"_MR_LDP_MRLDP_SimGibbspar", (DL_FUNC) &_MR_LDP_MRLDP_SimGibbspar, 16},
    {"_MR_LDP_MRLDP_RealVb", (DL_FUNC) &_MR_LDP_MRLDP_RealVb, 20},
    {"_MR_LDP_MRLDP_RealPXvb", (DL_FUNC) &_MR_LDP_MRLDP_RealPXvb, 20},
    {"_MR_LDP_MRLDP_RealParPXvb", (DL_FUNC) &_MR_LDP_MRLDP_RealParPXvb, 20},
    {"_MR_LDP_MRLDP_RealVBMg", (DL_FUNC) &_MR_LDP_MRLDP_RealVBMg, 19},
    {"_MR_LDP_MRLDP_RealMggibbs", (DL_FUNC) &_MR_LDP_MRLDP_RealMggibbs, 18},
    {"_MR_LDP_MRLDP_RealGibbspar", (DL_FUNC) &_MR_LDP_MRLDP_RealGibbspar, 19},
    {"_MR_LDP_Para_PXVb1", (DL_FUNC) &_MR_LDP_Para_PXVb1, 14},
    {"_MR_LDP_Para_PXVb2", (DL_FUNC) &_MR_LDP_Para_PXVb2, 16},
    {"_MR_LDP_vbfunM1", (DL_FUNC) &_MR_LDP_vbfunM1, 11},
    {"_MR_LDP_PXvbfunM1", (DL_FUNC) &_MR_LDP_PXvbfunM1, 11},
    {"_MR_LDP_vbfunM2", (DL_FUNC) &_MR_LDP_vbfunM2, 13},
    {"_MR_LDP_PXvbfunM2", (DL_FUNC) &_MR_LDP_PXvbfunM2, 13},
    {"_MR_LDP_VBMgM2", (DL_FUNC) &_MR_LDP_VBMgM2, 12},
    {"_MR_LDP_MgMgib2", (DL_FUNC) &_MR_LDP_MgMgib2, 12},
    {"_MR_LDP_getLineNum", (DL_FUNC) &_MR_LDP_getLineNum, 1},
    {"_MR_LDP_ReadSNPinfo", (DL_FUNC) &_MR_LDP_ReadSNPinfo, 8},
    {"_MR_LDP_Read_summarystat", (DL_FUNC) &_MR_LDP_Read_summarystat, 10},
    {"_MR_LDP_select", (DL_FUNC) &_MR_LDP_select, 2},
    {"_MR_LDP_matchscreen", (DL_FUNC) &_MR_LDP_matchscreen, 5},
    {"_MR_LDP_matchsnp", (DL_FUNC) &_MR_LDP_matchsnp, 3},
    {NULL, NULL, 0}
};

RcppExport void R_init_MR_LDP(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
