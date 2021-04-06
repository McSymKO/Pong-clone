#pragma once

#include "StateManager.h"

class Engine
{
public:
	Engine();
	~Engine();

	bool isGameRunning();

	void pollEvents();
	void update();
	void render();

	void run();

private:
	sf::RenderWindow mWindow;
	bool gameRunning;
	bool pressedSpace;

	StateManager gameStates;
};

