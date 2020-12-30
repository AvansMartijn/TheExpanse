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
	void setTarget(ThreeDObject object);
	void updateTarget(ThreeDObject object);
	const ThreeDObject& getTarget();
	void moveObjects();
	void checkCollisions();
private:
	int playerShipIndex;
	int targetIndex;
};

