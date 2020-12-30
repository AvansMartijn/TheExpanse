#include "Scene.h"
#include "ExpanseHelper.h"

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

void Scene::moveObjects()
{
	for (auto it = objectList.begin(); it != objectList.end(); /* NOTHING */)
	{
		if (it->velocity.x != 0 || it->velocity.y != 0 || it->velocity.z != 0) {
			if (it->moveCounter > 20)
				it = objectList.erase(it);
			else {
				ExpanseHelper helper;
				//Vector v = helper.getForwardVector(*it);
				*it = helper.translateMatrix(*it, it->velocity.x, it->velocity.y,it->velocity.z);
				it->moveCounter++;
				++it;
			}
		}
		else {
			++it;
		}
	}
}
