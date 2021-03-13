#include "pch.h"
#include "Bot.h"

Bot::Bot(const float speed)
	: mSpeed(speed)
{
	mShape.setSize(sf::Vector2f(15.f, 100.f));
	mShape.setPosition(25.f, 210.f);
}

void Bot::move(const float speed)
{
	
}

void Bot::update()
{
	move(mSpeed);
}

void Bot::render(sf::RenderTarget& target)
{
	target.draw(mShape);
}
