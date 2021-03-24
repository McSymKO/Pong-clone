#include "pch.h"
#include "Bot.h"

Bot::Bot(const float speed)
	: mSpeed(speed)
{
	mShape.setSize(sf::Vector2f(15.f, 100.f));
	setBot();
}

void Bot::setBot()
{
	mShape.setPosition(25.f, 210.f);
}

const sf::FloatRect Bot::getBounds() const
{
	return mShape.getGlobalBounds();
}

const sf::Vector2f& Bot::getPosition() const
{
	return mShape.getPosition();
}

void Bot::move(const float speed)
{
	
}

void Bot::checkPosition()
{
	if (mShape.getGlobalBounds().top < 0.f)
		mShape.setPosition(mShape.getGlobalBounds().left, 0.f);
	else if (mShape.getGlobalBounds().top + mShape.getGlobalBounds().height > 500.f)
		mShape.setPosition(mShape.getGlobalBounds().left, 500.f - mShape.getGlobalBounds().height);
}

void Bot::update()
{
	checkPosition();
	move(mSpeed);
}

void Bot::render(sf::RenderTarget& target)
{
	target.draw(mShape);
}
