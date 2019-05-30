#ifndef _g09_H_
#define _g09_H_

#include <vector>

// Minus g09
void g09(std::vector<double>& pars, std::vector<double>& result);

// modified, no constraints, returns -1e9 if constraint violated
void g09_mod(std::vector<double>& pars, std::vector<double>& result);

double g1(const double *x, size_t N);
double g2(const double *x, size_t N);
double g3(const double *x, size_t N);
double g4(const double *x, size_t N);
#endif