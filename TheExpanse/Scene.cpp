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
	ExpanseHelper helper;
	//loop through all objects
	for (auto it = objectList.begin(); it != objectList.end(); /* NOTHING */)
	{
		//at least velocity on 1 axis is not 0
		if (it->velocity.x != 0 || it->velocity.y != 0 || it->velocity.z != 0) {
			//if it reached max moves delete it (mostly for bullets)
			if (it->moveCounter > 20)
				it = objectList.erase(it);
			else {
				//move object
				ExpanseHelper helper;
				*it = helper.translateMatrix(*it, it->velocity.x, it->velocity.y, it->velocity.z);
				it->moveCounter++;
				++it;
			}
		}
		else {
			++it;
		}
	}
}

void Scene::checkCollisions()
{


	ExpanseHelper helper;
	for (auto i = objectList.begin(); i != objectList.end(); /* NOTHING */)
	{
		bool deleted = false;
	
		for (auto j = objectList.begin(); j != objectList.end(); /* NOTHING */)
		{
			if (i == j) {
				j++;
				continue;
			}
			if (helper.intersects(i->AABB, j->AABB)) {
				bool dec_i = false;

				if (i->centerPoint == getPlayerShip().centerPoint || j->centerPoint == getPlayerShip().centerPoint) {
					gameOver = true;
					return;
				}

				if (i < j) {
					j = objectList.erase(j);
					i = objectList.erase(i);
				}
				else {
					i = objectList.erase(i);
					j = objectList.erase(j);
				}
			
				deleted = true;
				break;
			}
			else {
				++j;
			}
			
			
		}
		if (!deleted) {
			++i;
		}
	}

	
}

void Scene::pulseObjects()
{
	ExpanseHelper helper;
	for (int i = 0; i < objectList.size(); i++) {
		objectList[i] = helper.pulseObject(objectList[i]);
		//*it = helper.pulseObject(*it);
	}
}
