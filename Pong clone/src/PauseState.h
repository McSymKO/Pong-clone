#pragma once

#include "GameState.h"
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
	sf::Text pauseText;
	sf::Text scoreLeft;
	sf::Text scoreRight;
	sf::Font mFont;
};

