//Patryk Socha
//16.05.2017

#ifndef JMCActionInitialization_h
#define JMCActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

class JMCActionInitialization : public G4VUserActionInitialization
{
	public:
		JMCActionInitialization();
		virtual ~JMCActionInitialization();
		virtual void BuildForMaster() const;
		virtual void Build() const;
};

#endif
