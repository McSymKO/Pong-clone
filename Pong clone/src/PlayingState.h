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
};

