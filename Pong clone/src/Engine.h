#pragma once

#include "StateManager.h"

class Engine
{
public:
	Engine();
	~Engine();

	//Functions
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

