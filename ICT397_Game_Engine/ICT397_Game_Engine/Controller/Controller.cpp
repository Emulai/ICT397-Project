#include "Controller.h"

Controller::Controller()
{
	m_model.SetView(&m_view);
}

void Controller::ModelTest()
{
	m_model.ObjectTypeTest();
}