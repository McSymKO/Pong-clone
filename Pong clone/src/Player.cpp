#include "pch.h"
#include "Player.h"

Player::Player(const float speed)
	: mSpeed(speed)
{
	mShape.setSize(sf::Vector2f(15.f, 100.f));
	setPlayer();
}

void Player::setPlayer()
{
	mShape.setPosition(760.f, 210.f);
}

const sf::Vector2f& Player::getPosition() const
{
	return mShape.getPosition();
}

const sf::FloatRect Player::getBounds() const
{
	return mShape.getGlobalBounds();
}

void Player::move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		mShape.move(0.f, -1.f * mSpeed);
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		mShape.move(0.f, 1.f * mSpeed);
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
	move();
	checkPosition();
}

void Player::render(sf::RenderTarget& target)
{
	target.draw(mShape);
}
