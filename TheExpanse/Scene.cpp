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
	for (auto it = objectList.begin(); it != objectList.end(); /* NOTHING */)
	{
		
		if (it->velocity.x != 0 || it->velocity.y != 0 || it->velocity.z != 0) {
			if (it->moveCounter > 20)
				it = objectList.erase(it);
			else {
				ExpanseHelper helper;
				//Vector v = helper.getForwardVector(*it);
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

	/*std::vector<ThreeDObject> newObjectList;
	for (int i = 0; i < objectList.size(); i++) {
		for (int j = 0; j < objectList.size(); j++) {
			if (i == j) {
				continue;
			}
			if (helper.intersects(objectList[i].AABB, objectList[j].AABB)) {
				if (i == playerShipIndex) {
					newObjectList.push_back(objectList[i]);
				}
				
			}
			else {
				newObjectList.push_back(objectList[i]);
			}
		}
	}*/

	//objectList = newObjectList;
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
				//collision
				//delete both

				bool dec_i = false;

				/*if (i < j) { 
					--j;
				}
				else {
					dec_i = true;
				}*/
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

				/*if (dec_i) { 
					--i; 
				}*/
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
