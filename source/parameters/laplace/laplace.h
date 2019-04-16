#ifndef _KORALI_LAPLACE_H_
#define _KORALI_LAPLACE_H_

#include "parameters/base/base.h"

namespace Korali::Parameter
{

class Laplace : public Korali::Parameter::Base
{
 private:
  double _mean;
  double _width;
  double _aux;

 public:

  Laplace(nlohmann::json& js, int seed = 0);
  Laplace(double mean, double width, size_t seed = 0);
  ~Laplace();

  double getDensity(double x);
  double getDensityLog(double x);
  double getRandomNumber();
  static double logLikelihood(double sigma, int nData, double* x, double* u);

  void printDetails() override;
  void initialize();

  // Serialization Methods
  nlohmann::json getConfiguration();
  void setConfiguration(nlohmann::json& js);
};

} // namespace Korali

#endif // _KORALI_LAPLACE_H_