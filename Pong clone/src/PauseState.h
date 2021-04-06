#pragma once

#include "GameState.h"
#include "PlayingState.h"
#include "Player.h"
#include "Bot.h"
#include "Ball.h"

class PauseState : public GameState
{
public:
	PauseState();

	void update();
	void render(sf::RenderTarget& target);

private:
	Player mPlayer;
	Bot mBot;
	Ball mBall;
	sf::RectangleShape mLine;

	//GUI
	sf::Font mFont;
	sf::Text scoreLeft;
	sf::Text scoreRight;
};

