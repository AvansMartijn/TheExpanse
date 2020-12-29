#include "Scene.h"

void Scene::setPlayerShip(Spaceship spaceship)
{
	objectList.push_back(spaceship);
	playerShipIndex = objectList.size() - 1;
}

void Scene::updatePlayerShip(ThreeDObject spaceship)
{
	objectList[playerShipIndex] = spaceship;
}

const ThreeDObject& Scene::getPlayerShip()
{
	return objectList.at(playerShipIndex);
}
