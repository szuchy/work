//Patryk Socha
//16.05.2017

#include "JMCActionInitialization.hh"
#include "JMCPrimaryGeneratorAction.hh"
#include "JMCRunAction.hh"
#include "JMCEventAction.hh"
#include "JMCSteppingAction.hh"

JMCActionInitialization::JMCActionInitialization() : G4VUserActionInitialization() {}

JMCActionInitialization::~JMCActionInitialization() {}

void JMCActionInitialization::BuildForMaster() const
{
	JMCRunAction* runAction = new JMCRunAction;
	SetUserAction(runAction);
}

void JMCActionInitialization::Build() const
{
	SetUserAction(new JMCPrimaryGeneratorAction);

	JMCRunAction* runAction = new JMCRunAction;
	SetUserAction(runAction);

	JMCEventAction* eventAction = new JMCEventAction(runAction);
	SetUserAction(eventAction);

	SetUserAction(new JMCSteppingAction(eventAction));
}
