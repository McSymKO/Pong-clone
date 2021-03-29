#pragma once

#include "GameState.h"
#include "StateManager.h"
#include "Player.h"
#include "Bot.h"
#include "Ball.h"

class PlayingState : public GameState
{
public:
	PlayingState();

	void resetPositions();

	void resetBotPosition();

	void updateBallMovement();
	void updateBotMovement();
	void update();
	void render(sf::RenderTarget& target);

private:
	StateManager gameStates;
	bool pause;
	bool ballReflected;
	bool resetBot;

	//Game's elements
	Player mPlayer;
	Bot mBot;
	Ball mBall;
	sf::RectangleShape mLine;

	Ball_Directions::DIRECTION_MOVEMENT mDirection;

	//GUI
	sf::Text scoreLeft;
	sf::Text scoreRight;
	sf::Font mFont;
};

