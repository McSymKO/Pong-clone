#pragma once

class GameState
{
public:
	virtual void init() {};
	virtual void update() = 0;
	virtual void render(sf::RenderTarget& target) = 0;
};

