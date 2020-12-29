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

void Scene::setTarget(ThreeDObject object)
{
	objectList.push_back(object);
	targetIndex = objectList.size() - 1;
}

void Scene::updateTarget(ThreeDObject object)
{
	objectList[targetIndex] = object;
}

const ThreeDObject& Scene::getTarget()
{
	return objectList.at(targetIndex);
}
