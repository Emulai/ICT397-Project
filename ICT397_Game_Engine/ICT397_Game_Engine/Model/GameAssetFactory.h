#ifndef GAMEASSETFACTORY_H
#define GAMEASSETFACTORY_H

#include "Player.h"
#include "NonPlayerCharacter.h"
#include "SceneObject.h"

class GameAssetFactory
{
public:

	static GameObject *NewGameObject(const string &description);

};

#endif