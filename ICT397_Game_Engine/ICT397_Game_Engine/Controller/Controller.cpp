#include "Controller.h"

Controller::Controller()
{
	m_model.SetView(&m_view);
	m_modelsLoaded = false;
}

void Controller::ModelTest(string mPath, int iNdex)
{
	if(!m_modelsLoaded) 
	{
		m_model.LoadModels(mPath, iNdex);
		m_modelsLoaded = true;
	}
	m_model.ObjectTypeTest();
}