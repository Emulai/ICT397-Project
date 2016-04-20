#include "Model.h"

//#include <luabind/luabind.hpp>

Model::Model()
{

}

Model::~Model()
{
	/*if (m_view)
		delete m_view;

	if (m_npc)
		delete m_npc;

	if (m_sObject)
		delete m_sObject;*/
}

void Model::SetView(View *t_view)
{
	m_view = t_view;
}

void Model::SetGOSize(int t_size)
{
	m_goArray = new GameObject *[t_size];
	m_view->SetModelNum(t_size);
	m_objectCount = t_size;
}

void Model::CreateGameObject(const string t_description, int t_index, float t_transformX, float t_transformY, float t_transformZ, float t_rotationX,
							 float t_rotationY, float t_rotationZ, string t_modelPath, string t_aiPath, int t_health, bool t_hostility, bool t_staticity)
{
	m_goArray[t_index] = m_gAF.NewGameObject(t_description);

	m_goArray[t_index]->TransformX(t_transformX);
	m_goArray[t_index]->TransformY(t_transformY);
	m_goArray[t_index]->TransformZ(t_transformZ);

	m_goArray[t_index]->RotationX(t_rotationX);
	m_goArray[t_index]->RotationY(t_rotationY);
	m_goArray[t_index]->RotationZ(t_rotationZ);

	m_goArray[t_index]->ModelPath(t_modelPath);
	m_goArray[t_index]->AIPath(t_aiPath);

	m_goArray[t_index]->Health(t_health);

	m_goArray[t_index]->IsHostile(t_hostility);
	m_goArray[t_index]->Staticity(t_staticity);

}

void Model::LoadModels(string t_modelPath, int t_index)
{
	/* for (int i = 0; i < m_objectCount; i++)
	{
		m_view->LoadModel(m_goArray[i]->ModelPath(), m_goArray[i]->Index());
	}*/

	m_view->SetModelNum(50);
	m_view->LoadModel(t_modelPath, t_index);
}




