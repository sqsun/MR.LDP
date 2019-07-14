#ifndef data_loader_hpp
#define data_loader_hpp

#include <RcppArmadillo.h>
#include <Rcpp.h>
#include "time.h"
#include <iostream>
#include "ReadGeneFile.hpp"

using namespace Rcpp;
using namespace arma;
using namespace std;

Rcpp::List ReadSNPinfo(std::string stringname, IntegerVector A1, IntegerVector A2, CharacterVector rsname,
                       IntegerVector chr, IntegerVector bp, NumericVector morgan, int N);
Rcpp::List Read_summarystat(std::string stringname, IntegerVector SA1, IntegerVector SA2, CharacterVector rsname,
                            NumericVector betah, NumericVector s2, NumericVector pvalue, IntegerVector chr, IntegerVector bp, int N);

Rcpp::List matchscreen(std::string screenname, std::string stringname1, std::string stringname2, std::string stringname3, double pva_cutoff);
#endif /* data_loader_hpp */