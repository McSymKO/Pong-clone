#include "pch.h"
#include "PlayingState.h"
#include "PauseState.h"

PlayingState::PlayingState()
	: mPlayer(5.f), mBot(5.f), mBall(10.f), mDirection(Directions::DIRECTION_MOVEMENT::IDLE), pause(true)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));

	//Ball's starting direction
	mDirection = Directions::DIRECTION_MOVEMENT::RIGHT;
	pause = false;
}

void PlayingState::reset()
{
	mBall.setBall();
	mPlayer.setPlayer();
	mBot.setBot();
}

void PlayingState::updateBallMovement()
{
	if (mBall.getBounds().intersects(mPlayer.getBounds()))
	{	
		if (mBall.getPosition().y < mPlayer.getPosition().y + 30.f)
			mDirection = Directions::DIRECTION_MOVEMENT::UP_LEFT;
		else if (mBall.getPosition().y > mPlayer.getPosition().y + 30.f && mBall.getPosition().y < mPlayer.getPosition().y + 70.f)
			mDirection = Directions::DIRECTION_MOVEMENT::LEFT;
		else if (mBall.getPosition().y > mPlayer.getPosition().y + 70.f && mBall.getPosition().y < mPlayer.getPosition().y + 100.f)
			mDirection = Directions::DIRECTION_MOVEMENT::DOWN_LEFT;
	}
	else if (mBall.getBounds().intersects(mBot.getBounds()))
	{
		if (mBall.getPosition().y < mBot.getPosition().y + 30.f)
			mDirection = Directions::DIRECTION_MOVEMENT::UP_RIGHT;
		else if (mBall.getPosition().y > mBot.getPosition().y + 30.f && mBall.getPosition().y < mBot.getPosition().y + 70.f)
			mDirection = Directions::DIRECTION_MOVEMENT::RIGHT;
		else if (mBall.getPosition().y > mBot.getPosition().y + 70.f && mBall.getPosition().y < mBot.getPosition().y + 100.f)
			mDirection = Directions::DIRECTION_MOVEMENT::DOWN_RIGHT;
	}

	//Ball hits top side
	else if (mBall.getBounds().top < 0.f)
	{
		if (mDirection == Directions::DIRECTION_MOVEMENT::UP_RIGHT)
			mDirection = Directions::DIRECTION_MOVEMENT::DOWN_RIGHT;
		else if (mDirection == Directions::DIRECTION_MOVEMENT::UP_LEFT)
			mDirection = Directions::DIRECTION_MOVEMENT::DOWN_LEFT;
	}

	//Ball hits bottom side
	else if (mBall.getBounds().top + mBall.getBounds().height > 500.f)
	{
		if (mDirection == Directions::DIRECTION_MOVEMENT::DOWN_RIGHT)
			mDirection = Directions::DIRECTION_MOVEMENT::UP_RIGHT;
		else if (mDirection == Directions::DIRECTION_MOVEMENT::DOWN_LEFT)
			mDirection = Directions::DIRECTION_MOVEMENT::UP_LEFT;
	}

	//Ball hits right side
	else if (mBall.getPosition().x > 800.f)
	{
		gameStates.addState(new PauseState);
		pause = true;
		reset();
	}

	//Ball hits left side
	else if (mBall.getPosition().x < 0.f)
	{
		gameStates.addState(new PauseState);
		pause = true;
		reset();
	}

	mBall.setMovement(mDirection);
}

void PlayingState::update()
{
	if (!pause)
	{
		mPlayer.update();
		mBot.update();
		updateBallMovement();
		mBall.update();
	}
}

void PlayingState::render(sf::RenderTarget& target)
{
	target.draw(mLine);
	mPlayer.render(target);
	mBot.render(target);
	mBall.render(target);
}
