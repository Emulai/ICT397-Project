#ifndef GAMEASSETFACTORY_H
#define GAMEASSETFACTORY_H

#include "ObjectType.h"

class GameAssetFactory
{
public:

	static GameObject *NewGameObject(const string &description);

};

#endif