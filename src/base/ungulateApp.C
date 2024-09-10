#include "ungulateApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
ungulateApp::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

ungulateApp::ungulateApp(InputParameters parameters) : MooseApp(parameters)
{
  ungulateApp::registerAll(_factory, _action_factory, _syntax);
}

ungulateApp::~ungulateApp() {}

void
ungulateApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<ungulateApp>(f, af, s);
  Registry::registerObjectsTo(f, {"ungulateApp"});
  Registry::registerActionsTo(af, {"ungulateApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
ungulateApp::registerApps()
{
  registerApp(ungulateApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
ungulateApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ungulateApp::registerAll(f, af, s);
}
extern "C" void
ungulateApp__registerApps()
{
  ungulateApp::registerApps();
}
