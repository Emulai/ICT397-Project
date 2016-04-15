#include "Model.h"

Model::Model()
{
	m_tested = false;

	m_test.x = 89;
	m_test.y = 400;
	m_test.z = 672.77f;

	m_npcCount = 12;
	m_sOCount = 7;
}

Model::~Model()
{
	//////////////////////////CAUSES ASSERTION CRASH IF USED
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

GameObject* Model::CreateGameObject(string t_description)
{
	GameObject *tempGameObject = m_gAF.NewGameObject(t_description);
	return tempGameObject;
}

void Model::ExampleFactoryCall()
{
	if (!m_tested)
	{

		GameObject *newGameObject = CreateGameObject("player");

		newGameObject->IsHostile(true);

		newGameObject = CreateGameObject("npc");

		newGameObject->IsHostile(true);

		newGameObject = CreateGameObject("scene");

		newGameObject->IsHostile(true);

		newGameObject = CreateGameObject("npc");

		newGameObject->Health(100);

		GameObject *newestGameObject = CreateGameObject("npc");

		newestGameObject->Health(50);

		cout << "NPC 1: " << newGameObject->Health() << endl;

		cout << "NPC 2: " << newestGameObject->Health() << endl;

		m_tested = true;

	}

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

