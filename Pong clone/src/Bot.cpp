#include "pch.h"
#include "Bot.h"

Bot::Bot(const float speed)
	: mSpeed(speed), mDir(Bot_Directions::Directions::IDLE)
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

void Bot::setMovement(Bot_Directions::Directions direction)
{
	mDir = direction;
}

void Bot::move()
{
	if (mDir == Bot_Directions::Directions::IDLE)
		mShape.move(0.f, 0.f);
	else if (mDir == Bot_Directions::Directions::UP)
		mShape.move(0.f, -1.f * mSpeed);
	else if (mDir == Bot_Directions::Directions::DOWN)
		mShape.move(0.f, 1.f * mSpeed);
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
	move();
}

void Bot::render(sf::RenderTarget& target)
{
	target.draw(mShape);
}
