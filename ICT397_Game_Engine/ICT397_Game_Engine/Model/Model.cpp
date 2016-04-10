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

void Model::ObjectTypeTest()
{
	if (!m_tested){

		//GameObject

		m_player.Transform(m_test);
		m_player.Rotation(m_test);

		cout << "Player Transform >> " << m_player.TransformX() << " " << m_player.TransformY() << " " << m_player.TransformZ() << " <<" << endl;
		cout << "Player Rotation >> " << m_player.RotationX() << " " << m_player.RotationY() << " " << m_player.RotationZ() << " <<" << endl;

		m_player.TransformX(50);
		m_player.TransformY(100);
		m_player.TransformZ(70);

		m_player.RotationX(90);
		m_player.RotationY(57);
		m_player.RotationZ(12);

		Vector3 f_tTest = m_player.Transform();
		Vector3 f_rTest = m_player.Rotation();

		cout << "Player Transform >> " << f_tTest.x << " " << f_tTest.y << " " << f_tTest.z << " <<" << endl;
		cout << "Player Rotation >> " << f_rTest.x << " " << f_rTest.y << " " << f_rTest.z << " <<" << endl;

		float f_tX, f_tY, f_tZ, f_rX, f_rY, f_rZ;

		f_tX = m_player.TransformX();
		f_tY = m_player.TransformY();
		f_tZ = m_player.TransformZ();

		f_rX = m_player.RotationX();
		f_rY = m_player.RotationY();
		f_rZ = m_player.RotationZ();

		cout << "Player Transform >> " << f_tX << " " << f_tY << " " << f_tZ << " <<" << endl;
		cout << "Player Rotation >> " << f_rX << " " << f_rY << " " << f_rZ << " <<" << endl;

		m_player.ModelReference(7);

		cout << "Model Path Here >> " << m_player.ModelReference() << " <<" << endl;

		//Player

		m_player.Health(289);

		cout << "Player Health >> " << m_player.Health() << " <<" << endl;

		//NPC

		m_npc = new NonPlayerCharacter[m_npcCount];

		m_npc[10].Health(6);
		m_npc[5].IsHostile(true);
		m_npc[1].AIPath("Banana");

		cout << "NPC Health >> " << m_npc[10].Health() << " <<" << endl; 
		cout << "NPC Hostility >> " << m_npc[5].IsHostile() << " <<" << endl; 
		cout << "NPC AI Path >> " << m_npc[1].AIPath() << " <<" << endl;

		//Scene Object
		
		m_sObject = new SceneObject[m_sOCount];

		m_sObject[2].Staticity(false);

		cout << "Scene Object Staticity >> " << m_sObject[2].Staticity() << " <<" << endl;

		m_tested = true;

		//obj.Load("tris.md2", "skin.pcx");
	}

	//obj.Draw();
}

void Model::SendToView()
{

	m_view->Render(m_player.ModelReference());

	for (int count = 0; count < m_npcCount; count++)
	{
		
		m_view->Render(m_npc[count].ModelReference());

	}
	
	for (int count = 0; count < m_sOCount; count++)
	{

		m_view->Render(m_sObject[count].ModelReference());

	}

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

