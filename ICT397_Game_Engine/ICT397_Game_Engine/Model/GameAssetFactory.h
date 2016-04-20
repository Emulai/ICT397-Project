#ifndef GAMEASSETFACTORY_H
#define GAMEASSETFACTORY_H

#include "Player.h"
#include "NonPlayerCharacter.h"
#include "SceneObject.h"

class GameAssetFactory
{
public:

	/**
        * @brief Returns View
        *
        * Returns a pointer to either a Player, NPC or Scene GameObject
        *
		* @param const string t_description - GameObject type
        * @return GameObject* - A pointer to a GameObject instance
        */
	static GameObject *NewGameObject(const string &t_description);

};

#endif