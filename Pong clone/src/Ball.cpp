 #include "pch.h"
#include "Ball.h"

Ball::Ball(const float speed)
	:mSpeed(speed), mDirection(Directions::DIRECTION_MOVEMENT::IDLE)
{
	mShape.setSize(sf::Vector2f(15.f, 15.f));
	mShape.setPosition(sf::Vector2f(386.f, 240.f));
}

const sf::Vector2f& Ball::getPosition() const
{
	return mShape.getPosition();
}

void Ball::setMovement(Directions::DIRECTION_MOVEMENT movement)
{
	mDirection = movement;
}

void Ball::move()
{
	if (mDirection == Directions::DIRECTION_MOVEMENT::RIGHT)
		mShape.move(0.1f * mSpeed, 0.f);
	else if (mDirection == Directions::DIRECTION_MOVEMENT::UP_RIGHT)
		mShape.move(0.1f * mSpeed, -0.1f * mSpeed);
	else if (mDirection == Directions::DIRECTION_MOVEMENT::DOWN_RIGHT)
		mShape.move(0.1f * mSpeed, 0.1f * mSpeed);
	else if (mDirection == Directions::DIRECTION_MOVEMENT::LEFT)
		mShape.move(-0.1f * mSpeed, 0.f);
	else if (mDirection == Directions::DIRECTION_MOVEMENT::UP_LEFT)
		mShape.move(-0.1f * mSpeed, -0.1f * mSpeed);
	else if (mDirection == Directions::DIRECTION_MOVEMENT::DOWN_LEFT)
		mShape.move(-0.1f * mSpeed, 0.1f * mSpeed);
}

void Ball::update()
{
	move();
}

void Ball::render(sf::RenderTarget& target)
{
	target.draw(mShape);
}
