#include "Model.h"

Model::Model()
{
	m_tested = false;

	m_test.x = 89;
	m_test.y = 400;
	m_test.z = 672.77f;

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

void Model::CreateGameObject(const string t_description, int t_index, float t_transformX, float t_transformY, float t_transformZ, float t_rotationX, float t_rotationY, float t_rotationZ, string t_modelPath, string t_aiPath, int t_health, bool t_hostility, bool t_staticity)
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
	m_goArray[t_index]->Index(t_index);
	
	m_goArray[t_index]->IsHostile(t_hostility);
	m_goArray[t_index]->Staticity(t_staticity);
	
}

void Model::ObjectTypeTest()
{
	if (!m_tested){

		SetGOSize(5);
		CreateGameObject("player", 0, 1, 2, 3, 4, 5, 6, "tree", "hugger", 50, true, false);
		CreateGameObject("player", 1, 1, 2, 3, 4, 5, 6, "tree", "hugger", 60, true, false);
		CreateGameObject("player", 2, 1, 2, 3, 4, 5, 6, "tree", "hugger", 70, true, false);
		cout << m_goArray[0]->Health() << endl;
		m_tested = true;
	}

	m_view->Render();
}

void Model::LoadModels(string mPath, int iNdex)
{
	/* i = 0; i < m_objectCount; i++)
		{

			m_view->LoadModel(m_goArray[i]->ModelPath(), m_goArray[i]->Index());

		}*/
	m_view->SetModelNum(50);
	m_view->LoadModel(mPath, iNdex);
}

void Model::SendToView()
{

	/*m_view->Render(m_player.ModelReference());

	for (int count = 0; count < m_npcCount; count++)
	{
		
		m_view->Render(m_npc[count].ModelReference());

	}
	
	for (int count = 0; count < m_sOCount; count++)
	{

		m_view->Render(m_sObject[count].ModelReference());

	}*/

}

///////
///PRIVATE FUNCTIONS
///////

/*
void SetWithLUA()
{

	m_player.Transform( SET WITH LUA );
	m_player.Rotation( SET WITH LUA );
	m_player.ModelReference( SET WITH LUA );					//Will need to run through modelLoader
																//modelLoader must return integer reference
																//to model

	m_player.Health( SET WITH LUA );


	for (count = 0; count < GET NPC COUNT; count++)
	{

		m_npc[count].Transform( SET WITH LUA );
		m_npc[count].Rotation( SET WITH LUA );
		m_npc[count].ModelReference( SET WITH LUA );			//Will need to run through modelLoader
																//modelLoader must return integer reference
																//to model

		m_npc[count].Hostility( SET WITH LUA );
		m_npc[count].Health( SET WITH LUA );

	}


	for (count = 0; count < GET SCENE OBJECT COUNT; count++)
	{
	
		m_sObject[count].Transform( SET WITH LUA );
		m_sObject[count].Rotation( SET WITH LUA );
		m_sObject[count].ModelReference( SET WITH LUA );		//Will need to run through modelLoader
																//modelLoader must return integer reference
																//to model

		m_sObject[count].Staticity( SET WITH LUA );

	}

}

*/

