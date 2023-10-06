//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "practice1TestApp.h"
#include "practice1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"

InputParameters
practice1TestApp::validParams()
{
  InputParameters params = practice1App::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

practice1TestApp::practice1TestApp(InputParameters parameters) : MooseApp(parameters)
{
  practice1TestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

practice1TestApp::~practice1TestApp() {}

void
practice1TestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  practice1App::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"practice1TestApp"});
    Registry::registerActionsTo(af, {"practice1TestApp"});
  }
}

void
practice1TestApp::registerApps()
{
  registerApp(practice1App);
  registerApp(practice1TestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
practice1TestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  practice1TestApp::registerAll(f, af, s);
}
extern "C" void
practice1TestApp__registerApps()
{
  practice1TestApp::registerApps();
}
