#include "pch.h"
#include "PlayingState.h"
#include "Common.h"

static bool g_victory;

PlayingState::PlayingState()
	: mPlayer(5.f), mBot(1.f), mBall(12.f), mDirection(Ball_Directions::DIRECTION_MOVEMENT::IDLE)
	,pause(false), ballReflected(false), resetBot(false), resume(false), timer(), delay(4.0f)
{

	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));

	//Ball's starting direction
	mDirection = Ball_Directions::DIRECTION_MOVEMENT::RIGHT;

	//Points
	std::string pointsLeft = std::to_string(mBot.getBotPoints());
	std::string pointsRight = std::to_string(mPlayer.getPlayerPoints());

	//Initializing texts and font
	mFont.loadFromFile("Fonts/OpenSans-Regular.ttf");

	scoreLeft.setFont(mFont);
	scoreLeft.setCharacterSize(44);
	scoreLeft.setPosition(sf::Vector2f(170.f, 20.f));
	scoreLeft.setString(pointsLeft);

	scoreRight.setFont(mFont);
	scoreRight.setCharacterSize(44);
	scoreRight.setPosition(sf::Vector2f(610.f, 20.f));
	scoreRight.setString(pointsRight);
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

void PlayingState::resumeGame()
{
	float time = mClock.getElapsedTime().asSeconds();
	mClock.restart();
	timer += time;
	if (timer > delay)
	{
		timer = 0;
		pause = false;
		resume = false;
	}
}

void PlayingState::checkWin()
{
	if (mBot.getBotPoints() == 5 || mPlayer.getPlayerPoints() == 5)
	{
		g_victory = true;
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
		resetPositions();
		pause = true;
		resume = true;

		//+1 Point to bot
		mBot.scoreBotPoint();
	}

	//Ball hits left side
	else if (mBall.getPosition().x < 0.f)
	{
		resetPositions();
		pause = true;
		resume = true;

		//+1 Point to player
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
		}
		//bot moving DOWN
		else if (mBot.getPosition().y < mBall.getPosition().y)
		{
			mBot.setMovement(Bot_Directions::Directions::DOWN);
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

void PlayingState::updateText()
{
	std::stringstream ss;

	ss << mBot.getBotPoints();

	scoreLeft.setString(ss.str());
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
		updateText();
		checkWin();
	}
	else if (pause && resume)
	{
		resumeGame();
	}
}

void PlayingState::render(sf::RenderTarget& target)
{
	target.draw(mLine);
	mPlayer.render(target);
	mBot.render(target);
	mBall.render(target);
	target.draw(scoreLeft);
	target.draw(scoreRight);
}

bool checkVictory()
{
	return g_victory;
}
