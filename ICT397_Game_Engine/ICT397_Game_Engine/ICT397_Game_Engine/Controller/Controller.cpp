#include "Controller.h"

Controller::Controller()
{
	hasHit=false;//for debug purposes
	m_model.SetView(&m_view);
}

void Controller::ModelTest()
{
	m_model.ObjectTypeTest();
}