#ifndef Pxvb_block_hpp
#define Pxvb_block_hpp

#include "RcppArmadillo.h"
#include <iostream>

using namespace Rcpp;
using namespace arma;
using namespace std;

List PXvbfunM1_block(arma::field<mat> F4Rblock, arma::umat block_inf, uword nblocks,
                     arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2,
                     arma::vec mu, double& sgga2, double beta0, 
                     const int&constr, const double &epsStopLogLik, const int& maxIter);
					 
List PXvbfunM2_block(arma::field<mat> F4Rblock, arma::umat block_inf, uword nblocks,
                     arma::vec bh1, arma::vec bh2, arma::vec se1, arma::vec se2,
                     arma::vec mu, arma::vec muA, double& sgga2, double& sgal2, double beta0, 
                     const int&constr, const double &epsStopLogLik, const int& maxIter);

#endif /* Pxvb_block_hpp */