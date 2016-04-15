#include "GameAssetFactory.h"

GameObject *GameAssetFactory::NewGameObject(const string &t_description)
{

	if(t_description == "player")
	{

		cout << "Player returned" << endl;
		return new Player;

	}else if(t_description == "npc")
	{

		cout << "NPC returned " << endl;
		return new NonPlayerCharacter;

	}else if(t_description == "scene")
	{

		cout << "SceneObject returned" << endl;
		return new SceneObject;

	}else
	{

		cout << "Not a valid GameObject" << endl;
		return NULL;

	}

}