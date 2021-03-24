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

	void reset();

	void updateBallMovement();
	void update();
	void render(sf::RenderTarget& target);

private:
	StateManager gameStates;
	bool pause;

	//Game's elements
	Player mPlayer;
	Bot mBot;
	Ball mBall;
	sf::RectangleShape mLine;

	Directions::DIRECTION_MOVEMENT mDirection;

	//GUI
	sf::Text scoreLeft;
	sf::Text scoreRight;
	sf::Font mFont;
};

