#include "pch.h"
#include "Player.h"

Player::Player(float speed)
	: mSpeed(speed)
{
	mShape.setSize(sf::Vector2f(15.f, 100.f));
	mShape.setPosition(760.f, 210.f);
}

void Player::move(const float speed)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		mShape.move(0.f, -1.f * speed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		mShape.move(0.f, 1.f * speed);
}

void Player::checkPosition()
{
	if (mShape.getGlobalBounds().top < 0.f)
		mShape.setPosition(mShape.getGlobalBounds().left, 0.f);
	else if (mShape.getGlobalBounds().top + mShape.getGlobalBounds().height > 500.f)
		mShape.setPosition(mShape.getGlobalBounds().left, 500.f - mShape.getGlobalBounds().height);
}

void Player::update()
{
	move(mSpeed);
	checkPosition();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(mShape);
}