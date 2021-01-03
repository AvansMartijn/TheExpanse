#include "ExpanseController.h"

void ExpanseController::drawStuff()
{
	window.clear();
	for (const ThreeDObject& obj : scene.objectList)
	{
		window.drawObject(obj);
		if (showBoundingBoxes) {
			window.drawAABB(obj);
		}
	}
	window.renderPresent();
}

void ExpanseController::initWorld()
{
	Spaceship theShip;
	Icosahedron target;
	ThreeDObject newTarget = helper.translateMatrix(target, 0, 0, -40);
	newTarget.pulseData.growCounter = 0;
	newTarget.pulseData.growMultiplier = 1.05;
	newTarget.pulseData.isGrowing = true;
	newTarget.pulseData.growTimes = 30;
	scene.setPlayerShip(theShip);
	scene.setTarget(newTarget);
	Cube body1;
	ThreeDObject newBody1 = helper.translateMatrix(body1, -10, 5, -30);
	Cube body2;
	ThreeDObject newBody2 = helper.translateMatrix(body1, 10, 5, -10);
	Cube body3;
	ThreeDObject newBody3 = helper.translateMatrix(body1, 7, 9, -5);
	Cube body4;
	ThreeDObject newBody4 = helper.translateMatrix(body1, -15, 30, -60);
	Cube body5;
	ThreeDObject newBody5 = helper.translateMatrix(body1, 8, -30, -20);
	Cube body6;
	ThreeDObject newBody6 = helper.translateMatrix(body1, 15, -10, -15);


	scene.objectList.push_back(newBody1);
	scene.objectList.push_back(newBody2);
	scene.objectList.push_back(newBody3);
	scene.objectList.push_back(newBody4);
	scene.objectList.push_back(newBody5);
	scene.objectList.push_back(newBody6);
}

void ExpanseController::programLoop()
{
	unsigned int a = SDL_GetTicks();
	unsigned int b = SDL_GetTicks();
	double delta = 0;

	while (true)
	{
		a = SDL_GetTicks();
		delta = a - b;
		if (delta > 1000 / 60) {
			b = a;

			onTick();
			// Get the next event
			SDL_Event event;
			if (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					// Break out of the loop on quit
					break;
				}
				if (event.type == SDL_KEYDOWN) {
					if (event.key.keysym.sym == SDLK_h) {
						if (showBoundingBoxes) {
							showBoundingBoxes = false;
						}
						else {
							showBoundingBoxes = true;
						}
					}
					if (event.key.keysym.sym == SDLK_ESCAPE) {
						reset();
						initWorld();
					}
				}

			}
			drawStuff();
		}
	}
}

void ExpanseController::onTick()
{
	if (!scene.gameOver) {
		handlePlayerControls();
		scene.pulseObjects();
		scene.moveObjects();
		scene.checkCollisions();
	}

}

void ExpanseController::reset()
{
	Scene newScene;
	scene = newScene;
}

void ExpanseController::handlePlayerControls()
{
	const Uint8* keystate = SDL_GetKeyboardState(NULL);
	if (keystate[SDL_SCANCODE_KP_PLUS])
	{
		scene.updatePlayerShip(helper.scaleOnLocation(scene.getPlayerShip(), 2, 2, 2));
	}
	if (keystate[SDL_SCANCODE_KP_MINUS])
	{
		scene.updatePlayerShip(helper.scaleOnLocation(scene.getPlayerShip(), 0.5, 0.5, 0.5));
	}
	//PITCH bACK
	if (keystate[SDL_SCANCODE_S])
	{
		scene.updatePlayerShip(helper.pitch(scene.getPlayerShip(), 3));
	}
	//PITCH forward
	if (keystate[SDL_SCANCODE_W])
	{
		scene.updatePlayerShip(helper.pitch(scene.getPlayerShip(), -3));
	}
	//JAW RIGHT
	if (keystate[SDL_SCANCODE_D])
	{
		scene.updatePlayerShip(helper.jaw(scene.getPlayerShip(), -3));
	}

	//JAW left
	if (keystate[SDL_SCANCODE_A])
	{
		scene.updatePlayerShip(helper.jaw(scene.getPlayerShip(), 3));
	}
	//ROLL RIGHT
	if (keystate[SDL_SCANCODE_E])
	{
		scene.updatePlayerShip(helper.roll(scene.getPlayerShip(), 3));
	}

	//ROLL LEFT
	if (keystate[SDL_SCANCODE_Q])
	{
		scene.updatePlayerShip(helper.roll(scene.getPlayerShip(), -3));
	}
	//CAMERA UP
	if (keystate[SDL_SCANCODE_PAGEUP])
	{
		window.camera.eye = window.camera.eye - window.camera.up;
	}
	//CAMERA DOWN
	if (keystate[SDL_SCANCODE_PAGEDOWN])
	{
		window.camera.eye = window.camera.eye + window.camera.up;
	}
	//camera forward
	if (keystate[SDL_SCANCODE_UP])
	{
		window.camera.eye = window.camera.eye - window.camera.direction;
	}
	//camera backward
	if (keystate[SDL_SCANCODE_DOWN])
	{
		window.camera.eye = window.camera.eye + window.camera.direction;
	}
	//camera left
	if (keystate[SDL_SCANCODE_LEFT])
	{
		window.camera.eye = window.camera.eye - window.camera.right;

	}
	//camera right
	if (keystate[SDL_SCANCODE_RIGHT])
	{
		window.camera.eye = window.camera.eye + window.camera.right;
	}
	if (keystate[SDL_SCANCODE_LSHIFT]) {
		Vector v = helper.getForwardVector(scene.getPlayerShip());
		v = helper.normalize(v);
		scene.updatePlayerShip(helper.translateMatrix(scene.getPlayerShip(), v.x, v.y, v.z));
	}
	if (keystate[SDL_SCANCODE_SPACE]) {
		Icosahedron bullet;
		Vector spaceShipForward = helper.getForwardVector(scene.getPlayerShip());
		spaceShipForward = helper.normalize(spaceShipForward);
		bullet.velocity = spaceShipForward;
		if (keystate[SDL_SCANCODE_LSHIFT]) {
			bullet.velocity.x = bullet.velocity.x + spaceShipForward.x;
			bullet.velocity.y = bullet.velocity.y + spaceShipForward.y;
			bullet.velocity.z = bullet.velocity.z + spaceShipForward.z;
		}
		ThreeDObject newObj = helper.translateMatrix(bullet, -bullet.centerPoint.x, -bullet.centerPoint.y, -bullet.centerPoint.z);
		newObj = helper.scaleOnLocation(newObj, 0.2, 0.2, 0.2);
		newObj = helper.translateMatrix(newObj, scene.getPlayerShip().forward.x, scene.getPlayerShip().forward.y, scene.getPlayerShip().forward.z);
		newObj = helper.translateMatrix(newObj, bullet.velocity.x, bullet.velocity.y, bullet.velocity.z);
		//bullet.
		scene.objectList.push_back(newObj);

	}

}
