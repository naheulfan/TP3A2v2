#pragma once
#include <vector>
#include "Observer.h"
class Observed
{
public:
	Observed();
	~Observed();
	void NotifyAllObservers();
private:
///	std::vector<Observer*> observers;

};

