#pragma once

#include <sstream>

#include "GameState.h"
#include "StateManager.h"
#include "Engine.h"
#include "Player.h"
#include "Ball.h"
#include "Bot.h"

//Global function
bool checkVictory();
char getWinner();

class PlayingState : public GameState
{
public:
	PlayingState();

	//Functions
	void resetPositions();
	void resetBotPosition();
	void resumeGame();
	void checkWin();

	void updateBallMovement();
	void updateBotMovement();
	void updateText();
	void update();

	void render(sf::RenderTarget& target);

private:
	StateManager gameStates;

	bool pause;
	bool resume;
	bool ballReflected;
	bool resetBot;

	//Game's elements
	Player mPlayer;
	Bot mBot;
	Ball mBall;
	sf::RectangleShape mLine;

	//Direction
	Ball_Directions::DIRECTION_MOVEMENT mDirection;

	//GUI
	sf::Font mFont;
	sf::Text scoreLeft;
	sf::Text scoreRight;

	//Timer
	sf::Clock mClock;
	float timer;
	float delay;
};

