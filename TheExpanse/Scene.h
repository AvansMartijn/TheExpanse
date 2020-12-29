#pragma once
#include <vector>
#include "ThreeDObject.h"
#include "Spaceship.h"
#include "Cube.h"

class Scene
{
public:
	std::vector<ThreeDObject> objectList;

	void setPlayerShip(Spaceship playership);
	void updatePlayerShip(ThreeDObject spaceship);
	const ThreeDObject& getPlayerShip();
private:
	int playerShipIndex;
};

