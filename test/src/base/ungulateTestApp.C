//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "ungulateTestApp.h"
#include "ungulateApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
ungulateTestApp::validParams()
{
  InputParameters params = ungulateApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  params.set<bool>("use_legacy_initial_residual_evaluation_behavior") = false;
  return params;
}

ungulateTestApp::ungulateTestApp(InputParameters parameters) : MooseApp(parameters)
{
  ungulateTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

ungulateTestApp::~ungulateTestApp() {}

void
ungulateTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  ungulateApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"ungulateTestApp"});
    Registry::registerActionsTo(af, {"ungulateTestApp"});
  }
}

void
ungulateTestApp::registerApps()
{
  registerApp(ungulateApp);
  registerApp(ungulateTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
ungulateTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ungulateTestApp::registerAll(f, af, s);
}
extern "C" void
ungulateTestApp__registerApps()
{
  ungulateTestApp::registerApps();
}
