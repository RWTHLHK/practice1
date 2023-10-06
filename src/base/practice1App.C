#include "practice1App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
practice1App::validParams()
{
  InputParameters params = MooseApp::validParams();
  params.set<bool>("use_legacy_material_output") = false;
  return params;
}

practice1App::practice1App(InputParameters parameters) : MooseApp(parameters)
{
  practice1App::registerAll(_factory, _action_factory, _syntax);
}

practice1App::~practice1App() {}

void 
practice1App::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAllObjects<practice1App>(f, af, s);
  Registry::registerObjectsTo(f, {"practice1App"});
  Registry::registerActionsTo(af, {"practice1App"});

  /* register custom execute flags, action syntax, etc. here */
}

void
practice1App::registerApps()
{
  registerApp(practice1App);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
practice1App__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  practice1App::registerAll(f, af, s);
}
extern "C" void
practice1App__registerApps()
{
  practice1App::registerApps();
}
