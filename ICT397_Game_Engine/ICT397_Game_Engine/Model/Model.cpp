#include "Model.h"

//#include <luabind/luabind.hpp>

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

void Model::ObjectTypeTest()
{
	if (!m_tested){

		

		m_tested = true;
	}

	m_view->Render();
}

void Model::LoadModels(string mPath, int iNdex)
{
	/* for (int i = 0; i < m_objectCount; i++)
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
int multiply(int a, int b)
{
  return a*b;
}

int cpp_Multiply(lua_State* luaVM)
{ 
	//determine number of params on the stack
    int numParams=lua_gettop(luaVM);
    if(numParams!=2) {
	   cout<<"not enough params"<<endl;
	   return 0;
    }
    if(!lua_isnumber(luaVM,1)||!lua_isnumber(luaVM,2)){
	  cout<<"bad params"<<endl;
	  return 0;
	}

    //pull params off stack
   int num1=(int)lua_tonumber(luaVM,1);
   int num2=(int)lua_tonumber(luaVM,2);
   //call the real function
   int result=multiply(num1,num2);
   //push result onto the stack
   lua_pushnumber(luaVM,result);
   return 1;  //return the number of values returned
}*/

void Model::LuaSettings()
{  /*
	//create lua state
    lua_State* L = lua_open();
    if (L==NULL){
       cout<<"Error Initializing lua"<<endl;;
      // return -1;
    }

	// reister the wrapper function
    lua_register(L,"cpp_Multiply",cpp_Multiply);

    // load standard lua library functions
    luaL_openlibs(L);

	// load and run Lua script
    if (luaL_dofile(L, "script4.lua" )){
		cout<<"error opening file\n";
	
	   // getchar(); return 1;
	}

    lua_close(L);
    //getchar();
	//return 0;
	
	
	
	
	*/
	
	
	
	
	
	
	
	
	
	
	
	
	/*
		//create lua state
    lua_State* L = lua_open();
    if (L==NULL){
       cout << "Error Initializing lua"<<endl;;
       
    }

    // load standard lua library functions
    luaL_openlibs(L);

	// load and run Lua script
    if (luaL_dofile(L, "GameLuaScript.lua" )){
		cout <<"error opening file\n";
	    
	}

    // Do stuff with lua code.
    lua_settop(L,0);
	lua_getglobal(L,"pVecX");
    lua_getglobal(L,"pVecY");
    lua_getglobal(L,"pVecZ");
	lua_getglobal(L,"pRotX");
    lua_getglobal(L,"pRotY");
    lua_getglobal(L,"pRotZ");
	lua_getglobal(L,"phealth");
	lua_getglobal(L,"pmodelRef");
	lua_getglobal(L,"paiPath");
	lua_getglobal(L,"phostile");
	lua_getglobal(L,"pstatic");
    

	lua_getglobal(L,"n1VecX");
    lua_getglobal(L,"n1VecY");
    lua_getglobal(L,"n1VecZ");
	lua_getglobal(L,"n1RotX");
    lua_getglobal(L,"n1RotY");
    lua_getglobal(L,"n1RotZ");
	lua_getglobal(L,"n1health");
	lua_getglobal(L,"n1modelRef");
	lua_getglobal(L,"n1aiPath");
	lua_getglobal(L,"n1hostile");
	lua_getglobal(L,"n1static");


	lua_getglobal(L,"n2VecX");
    lua_getglobal(L,"n2VecY");
    lua_getglobal(L,"n2VecZ");
	lua_getglobal(L,"n2RotX");
    lua_getglobal(L,"n2RotY");
    lua_getglobal(L,"n2RotZ");
	lua_getglobal(L,"n2health");
	lua_getglobal(L,"n2modelRef");
	lua_getglobal(L,"n2aiPath");
	lua_getglobal(L,"n2hostile");
	lua_getglobal(L,"n2static");


	lua_getglobal(L,"n3VecX");
    lua_getglobal(L,"n3VecY");
    lua_getglobal(L,"n3VecZ");
	lua_getglobal(L,"n3RotX");
    lua_getglobal(L,"n3RotY");
    lua_getglobal(L,"n3RotZ");
	lua_getglobal(L,"n3health");
	lua_getglobal(L,"n3modelRef");
	lua_getglobal(L,"n3aiPath");
	lua_getglobal(L,"n3hostile");
	lua_getglobal(L,"n3static");
	lua_close(L);

			//create lua state
    lua_State* L2 = lua_open();
    if (L==NULL){
       cout << "Error Initializing lua"<<endl;;
       
    }

    // load standard lua library functions
    luaL_openlibs(L);

	// load and run Lua script
    if (luaL_dofile(L, "n4GameLuaScript.lua" )){
		cout <<"error opening file\n";
	    
	}
	lua_getglobal(L,"n4VecX");
    lua_getglobal(L,"n4VecY");
    lua_getglobal(L,"n4VecZ");
	lua_getglobal(L,"n4RotX");
    lua_getglobal(L,"n4RotY");
    lua_getglobal(L,"n4RotZ");
	lua_getglobal(L,"n4health");
	lua_getglobal(L,"n4modelRef");
	lua_getglobal(L,"n4aiPath");
	lua_getglobal(L,"n4hostile");
	lua_getglobal(L,"n4static");

	lua_getglobal(L,"n5VecX");
    lua_getglobal(L,"n5VecY");
    lua_getglobal(L,"n5VecZ");
	lua_getglobal(L,"n5RotX");
    lua_getglobal(L,"n5RotY");
    lua_getglobal(L,"n5RotZ");
	lua_getglobal(L,"n5health");
	lua_getglobal(L,"n5modelRef");
	lua_getglobal(L,"n5aiPath");
	lua_getglobal(L,"n5hostile");
	lua_getglobal(L,"n5static");

	lua_getglobal(L,"n6VecX");
    lua_getglobal(L,"n6VecY");
    lua_getglobal(L,"n6VecZ");
	lua_getglobal(L,"n6RotX");
    lua_getglobal(L,"n6RotY");
    lua_getglobal(L,"n6RotZ");
	lua_getglobal(L,"n6health");
	lua_getglobal(L,"n6modelRef");
	lua_getglobal(L,"n6aiPath");
	lua_getglobal(L,"n6hostile");
	lua_getglobal(L,"n6static");
	
	lua_getglobal(L,"n6VecX");
    lua_getglobal(L,"n6VecY");
    lua_getglobal(L,"n6VecZ");
	lua_getglobal(L,"n6RotX");
    lua_getglobal(L,"n6RotY");
    lua_getglobal(L,"n6RotZ");
	lua_getglobal(L,"n6health");
	lua_getglobal(L,"n6modelRef");
	lua_getglobal(L,"n6aiPath");
	lua_getglobal(L,"n6hostile");
	lua_getglobal(L,"n6static");

	lua_getglobal(L,"n7VecX");
    lua_getglobal(L,"n7VecY");
    lua_getglobal(L,"n7VecZ");
	lua_getglobal(L,"n7RotX");
    lua_getglobal(L,"n7RotY");
    lua_getglobal(L,"n7RotZ");
	lua_getglobal(L,"n7health");
	lua_getglobal(L,"n7modelRef");
	lua_getglobal(L,"n7aiPath");
	lua_getglobal(L,"n7hostile");
	lua_getglobal(L,"n7static");

	lua_getglobal(L,"n8VecX");
    lua_getglobal(L,"n8VecY");
    lua_getglobal(L,"n8VecZ");
	lua_getglobal(L,"n8RotX");
    lua_getglobal(L,"n8RotY");
    lua_getglobal(L,"n8RotZ");
	lua_getglobal(L,"n8health");
	lua_getglobal(L,"n8modelRef");
	lua_getglobal(L,"n8aiPath");
	lua_getglobal(L,"n8hostile");
	lua_getglobal(L,"n8static");

	lua_getglobal(L,"n9VecX");
    lua_getglobal(L,"n9VecY");
    lua_getglobal(L,"n9VecZ");
	lua_getglobal(L,"n9RotX");
    lua_getglobal(L,"n9RotY");
    lua_getglobal(L,"n9RotZ");
	lua_getglobal(L,"n9health");
	lua_getglobal(L,"n9modelRef");
	lua_getglobal(L,"n9aiPath");
	lua_getglobal(L,"n9hostile");
	lua_getglobal(L,"n9static");

	lua_getglobal(L,"n10VecX");
    lua_getglobal(L,"n10VecY");
    lua_getglobal(L,"n10VecZ");
	lua_getglobal(L,"n10RotX");
    lua_getglobal(L,"n10RotY");
    lua_getglobal(L,"n10RotZ");
	lua_getglobal(L,"n10health");
	lua_getglobal(L,"n10modelRef");
	lua_getglobal(L,"n10aiPath");
	lua_getglobal(L,"n10hostile");
	lua_getglobal(L,"n10static");

	lua_getglobal(L,"n11VecX");
    lua_getglobal(L,"n11VecY");
    lua_getglobal(L,"n11VecZ");
	lua_getglobal(L,"n11RotX");
    lua_getglobal(L,"n11RotY");
    lua_getglobal(L,"n11RotZ");
	lua_getglobal(L,"n11health");
	lua_getglobal(L,"n11modelRef");
	lua_getglobal(L,"n11aiPath");
	lua_getglobal(L,"n11hostile");
	lua_getglobal(L,"n11static");

	lua_getglobal(L,"n12VecX");
    lua_getglobal(L,"n12VecY");
    lua_getglobal(L,"n12VecZ");
	lua_getglobal(L,"n12RotX");
    lua_getglobal(L,"n12RotY");
    lua_getglobal(L,"n12RotZ");
	lua_getglobal(L,"n12health");
	lua_getglobal(L,"n12modelRef");
	lua_getglobal(L,"n12aiPath");
	lua_getglobal(L,"n12hostile");
	lua_getglobal(L,"n12static");

	lua_getglobal(L,"n13VecX");
    lua_getglobal(L,"n13VecY");
    lua_getglobal(L,"n13VecZ");
	lua_getglobal(L,"n13otX");
    lua_getglobal(L,"n13RotY");
    lua_getglobal(L,"n13RotZ");
	lua_getglobal(L,"n13health");
	lua_getglobal(L,"n13modelRef");
	lua_getglobal(L,"n13aiPath");
	lua_getglobal(L,"n13hostile");
	lua_getglobal(L,"n13static");

	lua_getglobal(L,"n14VecX");
    lua_getglobal(L,"n14VecY");
    lua_getglobal(L,"n14VecZ");
	lua_getglobal(L,"n14RotX");
    lua_getglobal(L,"n14RotY");
    lua_getglobal(L,"n14RotZ");
	lua_getglobal(L,"n14health");
	lua_getglobal(L,"n14modelRef");
	lua_getglobal(L,"n14aiPath");
	lua_getglobal(L,"n14hostile");
	lua_getglobal(L,"n14static");

	lua_getglobal(L,"n15VecX");
    lua_getglobal(L,"n15VecY");
    lua_getglobal(L,"n15VecZ");
	lua_getglobal(L,"n15RotX");
    lua_getglobal(L,"n15RotY");
    lua_getglobal(L,"n15RotZ");
	lua_getglobal(L,"n15health");
	lua_getglobal(L,"n15modelRef");
	lua_getglobal(L,"n15aiPath");
	lua_getglobal(L,"n15hostile");
	lua_getglobal(L,"n15static");
	
	if(!lua_isnumber(L,1)||!lua_isnumber(L,2)||!lua_isnumber(L,3)||!lua_isnumber(L,4)||!lua_isnumber(L,5)||!lua_isnumber(L,6)||!lua_isnumber(L,7)||!lua_isstring(L,8)||!lua_isstring(L,9)||!lua_isboolean(L,10)||!lua_isboolean(L,11)
	  ||!lua_isnumber(L,12)||!lua_isnumber(L,13)||!lua_isnumber(L,14)||!lua_isnumber(L,15)||!lua_isnumber(L,16)||!lua_isnumber(L,17)||!lua_isnumber(L,18)||!lua_isstring(L,19)||!lua_isstring(L,20)||!lua_isboolean(L,21)||!lua_isboolean(L,22)
	  ||!lua_isnumber(L,23)||!lua_isnumber(L,24)||!lua_isnumber(L,25)||!lua_isnumber(L,26)||!lua_isnumber(L,27)||!lua_isnumber(L,28)||!lua_isnumber(L,29)||!lua_isstring(L,30)||!lua_isstring(L,31)||!lua_isboolean(L,32)||!lua_isboolean(L,33))
	  //||!lua_isnumber(L,34)||!lua_isnumber(L,35)||!lua_isnumber(L,36)||!lua_isnumber(L,37)||!lua_isnumber(L,38)||!lua_isnumber(L,39)||!lua_isnumber(L,40)||!lua_isstring(L,41)||!lua_isstring(L,42)||!lua_isboolean(L,43)||!lua_isboolean(L,44)
	  //||!lua_isnumber(L,45)||!lua_isnumber(L,46)||!lua_isnumber(L,47)||!lua_isnumber(L,48)||!lua_isnumber(L,49)||!lua_isnumber(L,50)||!lua_isnumber(L,51)||!lua_isstring(L,52)||!lua_isstring(L,53)||!lua_isboolean(L,54)||!lua_isboolean(L,55)
	 // ||!lua_isnumber(L,56)||!lua_isnumber(L,57)||!lua_isnumber(L,58)||!lua_isnumber(L,59)||!lua_isnumber(L,60)||!lua_isnumber(L,61)||!lua_isnumber(L,62)||!lua_isstring(L,63)||!lua_isstring(L,64)||!lua_isboolean(L,65)||!lua_isboolean(L,66)
	 // ||!lua_isnumber(L,67)||!lua_isnumber(L,68)||!lua_isnumber(L,69)||!lua_isnumber(L,70)||!lua_isnumber(L,71)||!lua_isnumber(L,72)||!lua_isnumber(L,73)||!lua_isstring(L,74)||!lua_isstring(L,75)||!lua_isboolean(L,76)||!lua_isboolean(L,77)
	 // ||!lua_isnumber(L,78)||!lua_isnumber(L,79)||!lua_isnumber(L,80)||!lua_isnumber(L,81)||!lua_isnumber(L,82)||!lua_isnumber(L,83)||!lua_isnumber(L,84)||!lua_isstring(L,85)||!lua_isstring(L,86)||!lua_isboolean(L,87)||!lua_isboolean(L,88)
	 // ||!lua_isnumber(L,89)||!lua_isnumber(L,90)||!lua_isnumber(L,91)||!lua_isnumber(L,92)||!lua_isnumber(L,93)||!lua_isnumber(L,94)||!lua_isnumber(L,95)||!lua_isstring(L,96)||!lua_isstring(L,97)||!lua_isboolean(L,98)||!lua_isboolean(L,99)
	 // ||!lua_isnumber(L,100)||!lua_isnumber(L,101)||!lua_isnumber(L,102)||!lua_isnumber(L,103)||!lua_isnumber(L,104)||!lua_isnumber(L,105)||!lua_isnumber(L,106)||!lua_isstring(L,107)||!lua_isstring(L,108)||!lua_isboolean(L,109)||!lua_isboolean(L,110)
	//  ||!lua_isnumber(L,112)||!lua_isnumber(L,79)||!lua_isnumber(L,80)||!lua_isnumber(L,81)||!lua_isnumber(L,82)||!lua_isnumber(L,83)||!lua_isnumber(L,84)||!lua_isstring(L,85)||!lua_isstring(L,86)||!lua_isboolean(L,87)||!lua_isboolean(L,88)
	//  ||!lua_isnumber(L,78)||!lua_isnumber(L,79)||!lua_isnumber(L,80)||!lua_isnumber(L,81)||!lua_isnumber(L,82)||!lua_isnumber(L,83)||!lua_isnumber(L,84)||!lua_isstring(L,85)||!lua_isstring(L,86)||!lua_isboolean(L,87)||!lua_isboolean(L,88))
	{
		cout <<"error checking numbers\n";
        
	}
    float l_pVecX=(float)lua_tonumber(L,1);
	float l_pVecY=(int)lua_tonumber(L,2);
    float l_pVecZ=(float)lua_tonumber(L,3);
	float l_pRotX=(float)lua_tonumber(L,4);
	float l_pRotY=(float)lua_tonumber(L,5);
    float l_pRotZ=(float)lua_tonumber(L,6);
	int l_phealth=(int)lua_tonumber(L,7);
	const char* l_pmodelRef=(const char*)lua_tostring(L,8);
	const char* l_paiPath=(const char*)lua_tostring(L,9);
	bool l_phostile=(int)lua_toboolean(L,10);
	bool l_pstatic=(int)lua_toboolean(L,11);

    float l_n1VecX=(float)lua_tonumber(L,12);
	float l_n1VecY=(int)lua_tonumber(L,13);
    float l_n1VecZ=(float)lua_tonumber(L,14);
	float l_n1RotX=(float)lua_tonumber(L,15);
	float l_n1RotY=(float)lua_tonumber(L,16);
    float l_n1RotZ=(float)lua_tonumber(L,17);
	int l_n1health=(int)lua_tonumber(L,18);
	const char* l_n1modelRef=(const char*)lua_tostring(L,19);
	const char* l_n1aiPath=(const char*)lua_tostring(L,20);
	bool l_n1hostile=(int)lua_toboolean(L,21);
	bool l_n1static=(int)lua_toboolean(L,22);

    float l_n2VecX=(float)lua_tonumber(L,23);
	float l_n2VecY=(int)lua_tonumber(L,24);
    float l_n2VecZ=(float)lua_tonumber(L,25);
	float l_n2RotX=(float)lua_tonumber(L,26);
	float l_n2RotY=(float)lua_tonumber(L,27);
    float l_n2RotZ=(float)lua_tonumber(L,28);
	int l_n2health=(int)lua_tonumber(L,29);
	const char* l_n2modelRef=(const char*)lua_tostring(L,30);
	const char* l_n2aiPath=(const char*)lua_tostring(L,31);
	bool l_n2hostile=(int)lua_toboolean(L,32);
	bool l_n2static=(int)lua_toboolean(L,33);

    float l_n3VecX=(float)lua_tonumber(L,34);
	float l_n3VecY=(int)lua_tonumber(L,35);
    float l_n3VecZ=(float)lua_tonumber(L,36);
	float l_n3RotX=(float)lua_tonumber(L,37);
	float l_n3RotY=(float)lua_tonumber(L,38);
    float l_n3RotZ=(float)lua_tonumber(L,39);
	int l_n3health=(int)lua_tonumber(L,40);
	const char* l_n3modelRef=(const char*)lua_tostring(L,41);
	const char* l_n3aiPath=(const char*)lua_tostring(L,42);
	bool l_n3hostile=(int)lua_toboolean(L,43);
	bool l_n3static=(int)lua_toboolean(L,44);

    float l_n4VecX=(float)lua_tonumber(L,45);
	float l_n4VecY=(int)lua_tonumber(L,46);
    float l_n4VecZ=(float)lua_tonumber(L,47);
	float l_n4RotX=(float)lua_tonumber(L,48);
	float l_n4RotY=(float)lua_tonumber(L,49);
    float l_n4RotZ=(float)lua_tonumber(L,50);
	int l_n4health=(int)lua_tonumber(L,51);
	const char* l_n4modelRef=(const char*)lua_tostring(L,52);
	const char* l_n4aiPath=(const char*)lua_tostring(L,53);
	bool l_n4hostile=(int)lua_toboolean(L,54);
	bool l_n4static=(int)lua_toboolean(L,55);

    float l_n5VecX=(float)lua_tonumber(L,56);
	float l_n5VecY=(int)lua_tonumber(L,57);
    float l_n5VecZ=(float)lua_tonumber(L,58);
	float l_n5RotX=(float)lua_tonumber(L,59);
	float l_n5RotY=(float)lua_tonumber(L,60);
    float l_n5RotZ=(float)lua_tonumber(L,61);
	int l_n5health=(int)lua_tonumber(L,62);
	const char* l_n5modelRef=(const char*)lua_tostring(L,63);
	const char* l_n5aiPath=(const char*)lua_tostring(L,64);
	bool l_n5hostile=(int)lua_toboolean(L,65);
	bool l_n5static=(int)lua_toboolean(L,66);

    float l_n6VecX=(float)lua_tonumber(L,67);
	float l_n6VecY=(int)lua_tonumber(L,68);
    float l_n6VecZ=(float)lua_tonumber(L,69);
	float l_n6RotX=(float)lua_tonumber(L,70);
	float l_n6RotY=(float)lua_tonumber(L,71);
    float l_n6RotZ=(float)lua_tonumber(L,72);
	int l_n6health=(int)lua_tonumber(L,73);
	const char* l_n6modelRef=(const char*)lua_tostring(L,74);
	const char* l_n6aiPath=(const char*)lua_tostring(L,75);
	bool l_n6hostile=(int)lua_toboolean(L,76);
	bool l_n6static=(int)lua_toboolean(L,77);

    float l_n7VecX=(float)lua_tonumber(L,78);
	float l_n7VecY=(int)lua_tonumber(L,79);
    float l_n7VecZ=(float)lua_tonumber(L,80);
	float l_n7RotX=(float)lua_tonumber(L,81);
	float l_n7RotY=(float)lua_tonumber(L,82);
    float l_n7RotZ=(float)lua_tonumber(L,83);
	int l_n7health=(int)lua_tonumber(L,84);
	const char* l_n7modelRef=(const char*)lua_tostring(L,85);
	const char* l_n7aiPath=(const char*)lua_tostring(L,86);
	bool l_n7hostile=(int)lua_toboolean(L,87);
	bool l_n7static=(int)lua_toboolean(L,88);

    float l_n8VecX=(float)lua_tonumber(L,89);
	float l_n8VecY=(int)lua_tonumber(L,90);
    float l_n8VecZ=(float)lua_tonumber(L,91);
	float l_n8RotX=(float)lua_tonumber(L,92);
	float l_n8RotY=(float)lua_tonumber(L,93);
    float l_n8RotZ=(float)lua_tonumber(L,94);
	int l_n8health=(int)lua_tonumber(L,95);
	const char* l_n8modelRef=(const char*)lua_tostring(L,96);
	const char* l_n8aiPath=(const char*)lua_tostring(L,97);
	bool l_n8hostile=(int)lua_toboolean(L,98);
	bool l_n8static=(int)lua_toboolean(L,99);

    float l_n9VecX=(float)lua_tonumber(L,100);
	float l_n9VecY=(int)lua_tonumber(L,101);
    float l_n9VecZ=(float)lua_tonumber(L,102);
	float l_n9RotX=(float)lua_tonumber(L,103);
	float l_n9RotY=(float)lua_tonumber(L,104);
    float l_n9RotZ=(float)lua_tonumber(L,105);
	int l_n9health=(int)lua_tonumber(L,106);
	const char* l_n9modelRef=(const char*)lua_tostring(L,107);
	const char* l_n9aiPath=(const char*)lua_tostring(L,108);
	bool l_n9hostile=(int)lua_toboolean(L,109);
	bool l_n9static=(int)lua_toboolean(L,110);

    float l_n10VecX=(float)lua_tonumber(L,111);
	float l_n10VecY=(int)lua_tonumber(L,112);
    float l_n10VecZ=(float)lua_tonumber(L,113);
	float l_n10RotX=(float)lua_tonumber(L,114);
	float l_n10RotY=(float)lua_tonumber(L,115);
    float l_n10RotZ=(float)lua_tonumber(L,116);
	int l_n10health=(int)lua_tonumber(L,117);
	const char* l_n10modelRef=(const char*)lua_tostring(L,118);
	const char* l_n10aiPath=(const char*)lua_tostring(L,119);
	bool l_n10hostile=(int)lua_toboolean(L,120);
	bool l_n10static=(int)lua_toboolean(L,121);

    float l_n11VecX=(float)lua_tonumber(L,122);
	float l_n11VecY=(int)lua_tonumber(L,123);
    float l_n11VecZ=(float)lua_tonumber(L,124);
	float l_n11RotX=(float)lua_tonumber(L,125);
	float l_n11RotY=(float)lua_tonumber(L,126);
    float l_n11RotZ=(float)lua_tonumber(L,127);
	int l_n11health=(int)lua_tonumber(L,128);
	const char* l_n11modelRef=(const char*)lua_tostring(L,129);
	const char* l_n11aiPath=(const char*)lua_tostring(L,130);
	bool l_n11hostile=(int)lua_toboolean(L,131);
	bool l_n11static=(int)lua_toboolean(L,132);

    float l_n12VecX=(float)lua_tonumber(L,133);
	float l_n12VecY=(int)lua_tonumber(L,134);
    float l_n12VecZ=(float)lua_tonumber(L,135);
	float l_n12RotX=(float)lua_tonumber(L,136);
	float l_n12RotY=(float)lua_tonumber(L,137);
    float l_n12RotZ=(float)lua_tonumber(L,138);
	int l_n12health=(int)lua_tonumber(L,139);
	const char* l_n12modelRef=(const char*)lua_tostring(L,140);
	const char* l_n12aiPath=(const char*)lua_tostring(L,141);
	bool l_n12hostile=(int)lua_toboolean(L,142);
	bool l_n12static=(int)lua_toboolean(L,143);

    float l_n13VecX=(float)lua_tonumber(L,144);
	float l_n13VecY=(int)lua_tonumber(L,145);
    float l_n13VecZ=(float)lua_tonumber(L,146);
	float l_n13RotX=(float)lua_tonumber(L,147);
	float l_n13RotY=(float)lua_tonumber(L,148);
    float l_n13RotZ=(float)lua_tonumber(L,149);
	int l_n13health=(int)lua_tonumber(L,150);
	const char* l_n13modelRef=(const char*)lua_tostring(L,151);
	const char* l_n13aiPath=(const char*)lua_tostring(L,152);
	bool l_n13hostile=(int)lua_toboolean(L,153);
	bool l_n13static=(int)lua_toboolean(L,154);
    
    float l_n14VecX=(float)lua_tonumber(L,155);
	float l_n14VecY=(int)lua_tonumber(L,156);
    float l_n14VecZ=(float)lua_tonumber(L,157);
	float l_n14RotX=(float)lua_tonumber(L,158);
	float l_n14RotY=(float)lua_tonumber(L,159);
    float l_n14RotZ=(float)lua_tonumber(L,160);
	int l_n14health=(int)lua_tonumber(L,161);
	const char* l_n14modelRef=(const char*)lua_tostring(L,162);
	const char* l_n14aiPath=(const char*)lua_tostring(L,163);
	bool l_n14hostile=(int)lua_toboolean(L,164);
	bool l_n14static=(int)lua_toboolean(L,1);

	float l_n15VecX=(float)lua_tonumber(L,100);
	float l_n15VecY=(int)lua_tonumber(L,101);
    float l_n15VecZ=(float)lua_tonumber(L,102);
	float l_n15RotX=(float)lua_tonumber(L,103);
	float l_n15RotY=(float)lua_tonumber(L,104);
    float l_n15RotZ=(float)lua_tonumber(L,105);
	int l_n15health=(int)lua_tonumber(L,106);
	const char* l_n15modelRef=(const char*)lua_tostring(L,107);
	const char* l_n15aiPath=(const char*)lua_tostring(L,108);
	bool l_n15hostile=(int)lua_toboolean(L,109);
	bool l_n15static=(int)lua_toboolean(L,110);

	
	//setModelRef
	cout << "Player Transform >> " << l_pVecX << " " << l_pVecY << " " << l_pVecZ << endl;
	cout << "Player Rotation >> " << l_pRotX << " " << l_pRotY << " " << l_pRotZ << endl;
	cout << "Player Health >> " << l_phealth << " <<" << endl;
	cout << "Model Reference >> " << l_pmodelRef << endl;
	cout << "aiPath >> " << l_paiPath << endl;
	cout << "hostile >> " << l_phostile << endl;
	cout << "staticplayer >> " << l_pstatic << endl;
    lua_close(L);
 */ 

}

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

