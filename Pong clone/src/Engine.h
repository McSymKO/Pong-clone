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

	void renderEndGameText();
	void render();

	void run();

private:
	void initEndGameText();

private:
	sf::RenderWindow mWindow;
	bool gameRunning;
	bool pressedSpace;

	StateManager gameStates;

	//Endgame text
	sf::Text mText;
	sf::Font mFont;

	//Timer
	sf::Clock mClock;
	float timer;
	float delay;
};

