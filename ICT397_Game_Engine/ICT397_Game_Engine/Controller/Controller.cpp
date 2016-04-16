#include "Controller.h"

Controller::Controller()
{
	m_model.SetView(&m_view);
	m_model.LuaSettings();
}

void Controller::ModelTest()
{
	m_model.ObjectTypeTest();
}