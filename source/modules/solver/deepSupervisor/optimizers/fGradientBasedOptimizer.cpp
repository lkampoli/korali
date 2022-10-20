#include "modules/solver/deepSupervisor/optimizers/fGradientBasedOptimizer.hpp"

namespace korali
{
;

void fGradientBasedOptimizer::initialize()
{
  _currentValue.resize(_nVars, 0.0f);
};

void fGradientBasedOptimizer::preProcessResult(std::vector<float> &gradient)
{
  if (gradient.size() != _nVars)
    KORALI_LOG_ERROR("Number of gradient values (%ld) is different from the number of parameters (%ld)", gradient.size(), _nVars);

  for (const float v : gradient)
    if (!std::isfinite(v))
      KORALI_LOG_ERROR("\nOptimizer recieved non-finite gradient");
};

void fGradientBasedOptimizer::postProcessResult(std::vector<float> &parameters)
{
  for (const float v : parameters)
    if (!std::isfinite(v))
      KORALI_LOG_ERROR("Optimizer calculated non-finite hyperparameters");
};

void fGradientBasedOptimizer::setConfiguration(knlohmann::json& js) 
{
 if (isDefined(js, "Results"))  eraseValue(js, "Results");

 if (isDefined(js, "N Vars"))
 {
 try { _nVars = js["N Vars"].get<size_t>();
} catch (const std::exception& e)
 { KORALI_LOG_ERROR(" + Object: [ optimizers ] \n + Key:    ['N Vars']\n%s", e.what()); } 
   eraseValue(js, "N Vars");
 }
  else   KORALI_LOG_ERROR(" + No value provided for mandatory setting: ['N Vars'] required by optimizers.\n"); 

 if (isDefined(js, "Eta"))
 {
 try { _eta = js["Eta"].get<float>();
} catch (const std::exception& e)
 { KORALI_LOG_ERROR(" + Object: [ optimizers ] \n + Key:    ['Eta']\n%s", e.what()); } 
   eraseValue(js, "Eta");
 }
  else   KORALI_LOG_ERROR(" + No value provided for mandatory setting: ['Eta'] required by optimizers.\n"); 

 Module::setConfiguration(js);
 _type = "deepSupervisor/optimizers";
 if(isDefined(js, "Type")) eraseValue(js, "Type");
 if(isEmpty(js) == false) KORALI_LOG_ERROR(" + Unrecognized settings for Korali module: optimizers: \n%s\n", js.dump(2).c_str());
} 

void fGradientBasedOptimizer::getConfiguration(knlohmann::json& js) 
{

 js["Type"] = _type;
   js["N Vars"] = _nVars;
   js["Eta"] = _eta;
 Module::getConfiguration(js);
} 

void fGradientBasedOptimizer::applyModuleDefaults(knlohmann::json& js) 
{

 std::string defaultString = "{\"N Vars\": 0, \"Eta\": 0.0001}";
 knlohmann::json defaultJs = knlohmann::json::parse(defaultString);
 mergeJson(js, defaultJs); 
 Module::applyModuleDefaults(js);
} 

void fGradientBasedOptimizer::applyVariableDefaults() 
{

 Module::applyVariableDefaults();
} 

;

} //korali
;
