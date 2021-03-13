#pragma once

#include "GameState.h"
#include "Player.h"
#include "Bot.h"

class PlayingState : public GameState
{
public:
	PlayingState();

	void update();
	void render(sf::RenderTarget& target);

private:
	Player mPlayer;
	Bot mBot;
	sf::RectangleShape mLine;

	//GUI
	sf::Text scoreLeft;
	sf::Text scoreRight;
	sf::Font mFont;
};

