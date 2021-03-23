#include "pch.h"
#include "PlayingState.h"

PlayingState::PlayingState()
	: mPlayer(5.f), mBot(5.f), mBall(10.f), mDirection(Directions::DIRECTION_MOVEMENT::IDLE)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));

	//Ball's starting direction
	mDirection = Directions::DIRECTION_MOVEMENT::RIGHT;
}

void PlayingState::updateBallMovement()
{
	if (mBall.getBounds().intersects(mPlayer.getBounds()))
	{
		sf::Vector2f playerPos = mPlayer.getPosition();
		sf::Vector2f ballPos = mBall.getPosition();

		//TO DO ---> BALL REFLECTIONS
	}
	else if (mBall.getBounds().intersects(mBot.getBounds()))
	{
		mDirection = Directions::DIRECTION_MOVEMENT::RIGHT;
	}
	mBall.setMovement(mDirection);
}

void PlayingState::update()
{
	mPlayer.update();
	mBot.update();
	updateBallMovement();
	mBall.update();
}

void PlayingState::render(sf::RenderTarget& target)
{
	target.draw(mLine);
	mPlayer.render(target);
	mBot.render(target);
	mBall.render(target);
}
