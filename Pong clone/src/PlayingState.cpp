#include "pch.h"
#include "PlayingState.h"
#include "PauseState.h"

PlayingState::PlayingState()
	: mPlayer(5.f), mBot(1.f), mBall(12.f), mDirection(Ball_Directions::DIRECTION_MOVEMENT::IDLE)
	,pause(true), ballReflected(false), resetBot(false)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));

	//Ball's starting direction
	mDirection = Ball_Directions::DIRECTION_MOVEMENT::RIGHT;
	pause = false;
}

void PlayingState::resetPositions()
{
	mBall.setBall();
	mPlayer.setPlayer();
	mBot.setBot();
}

void PlayingState::resetBotPosition()
{
	//Return on its start position, depending on where bot currently is
	if (mBot.getPosition().y > 210.f)
	{
		mBot.setMovement(Bot_Directions::Directions::UP);
		resetBot = true;
	}
	else if (mBot.getPosition().y < 210.f)
	{
		mBot.setMovement(Bot_Directions::Directions::DOWN);
		resetBot = true;
	}
}

void PlayingState::updateBallMovement()
{
	//Intersects player
	if (mBall.getBounds().intersects(mPlayer.getBounds()))
	{	
		if (mBall.getPosition().y + 7.5f <= mPlayer.getPosition().y + 30.f)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::UP_LEFT;
		else if (mBall.getPosition().y + 7.5f > mPlayer.getPosition().y + 30.f && mBall.getPosition().y + 7.5f <= mPlayer.getPosition().y + 70.f)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::LEFT;
		else if (mBall.getPosition().y + 7.5f > mPlayer.getPosition().y + 70.f && mBall.getPosition().y + 7.5f <= mPlayer.getPosition().y + 100.f)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::DOWN_LEFT;
	}

	//Intersects bot
	else if (mBall.getBounds().intersects(mBot.getBounds()))
	{
		//Ball hits bot on 3 sides
		if (mBall.getPosition().y + 7.5f <= mBot.getPosition().y + 30.f)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::UP_RIGHT;
		else if (mBall.getPosition().y + 7.5f > mBot.getPosition().y + 30.f && mBall.getPosition().y + 7.5f <= mBot.getPosition().y + 70.f)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::RIGHT;
		else if (mBall.getPosition().y + 7.5f > mBot.getPosition().y + 70.f && mBall.getPosition().y + 7.5f <= mBot.getPosition().y + 100.f)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::DOWN_RIGHT;
		
		//Resetting bot
		resetBotPosition();
	}

	//Ball hits top side
	else if (mBall.getBounds().top < 0.f)
	{
		if (mDirection == Ball_Directions::DIRECTION_MOVEMENT::UP_RIGHT)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::DOWN_RIGHT;
		else if (mDirection == Ball_Directions::DIRECTION_MOVEMENT::UP_LEFT)
		{
			ballReflected = true;
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::DOWN_LEFT;
		}
	}

	//Ball hits bottom side
	else if (mBall.getBounds().top + mBall.getBounds().height > 500.f)
	{
		if (mDirection == Ball_Directions::DIRECTION_MOVEMENT::DOWN_RIGHT)
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::UP_RIGHT;
		else if (mDirection == Ball_Directions::DIRECTION_MOVEMENT::DOWN_LEFT)
		{
			ballReflected = true;
			mDirection = Ball_Directions::DIRECTION_MOVEMENT::UP_LEFT;
		}
	}

	//Ball hits right side
	else if (mBall.getPosition().x > 800.f)
	{
		gameStates.addState(new PauseState);
		pause = true;
		resetPositions();
	}

	//Ball hits left side
	else if (mBall.getPosition().x < 0.f)
	{
		gameStates.addState(new PauseState);
		pause = true;
		resetPositions();
	}

	mBall.setMovement(mDirection);
}

void PlayingState::updateBotMovement()
{
	//LEFT direction
	if (mDirection == Ball_Directions::DIRECTION_MOVEMENT::LEFT)
	{
		//bot moving UP
		if (mBot.getPosition().y > mBall.getPosition().y)
		{
			mBot.setMovement(Bot_Directions::Directions::UP);

			if (mBot.getPosition().y <= mBall.getPosition().y)
				mBot.setMovement(Bot_Directions::Directions::IDLE);
		}
		//bot moving DOWN
		else if (mBot.getPosition().y < mBall.getPosition().y)
		{
			mBot.setMovement(Bot_Directions::Directions::DOWN);

			if (mBot.getPosition().y >= mBall.getPosition().y)
				mBot.setMovement(Bot_Directions::Directions::IDLE);
		}
	}
	//UP LEFT
	else if (mBall.getDirection() == Ball_Directions::DIRECTION_MOVEMENT::UP_LEFT && ballReflected)
	{
		mBot.setMovement(Bot_Directions::Directions::UP);
	}
	//DOWN LEFT
	else if (mBall.getDirection() == Ball_Directions::DIRECTION_MOVEMENT::DOWN_LEFT && ballReflected)
	{
		mBot.setMovement(Bot_Directions::Directions::DOWN);
	}
	//Don't move bot if it returned on its start position
	else if (mBot.getPosition().y == 210.f && resetBot)
	{
		mBot.setMovement(Bot_Directions::Directions::IDLE);
	}
}

void PlayingState::update()
{
	if (!pause)
	{
		mPlayer.update();
		updateBotMovement();
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
