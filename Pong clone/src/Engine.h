#pragma once

#include "StateManager.h"

class Engine
{
public:
	Engine();

	bool isGameRunning();

	void pollEvents();
	void update();
	void render();

	void run();

private:
	sf::RenderWindow mWindow;
	bool gameRunning;

	StateManager gameStates;
};

