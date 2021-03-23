#include "pch.h"
#include "PlayingState.h"

PlayingState::PlayingState()
	: mPlayer(5.f), mBot(5.f), mBall(5.f), mDirection(Directions::DIRECTION_MOVEMENT::IDLE)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));
}

void PlayingState::updateBallMovement()
{
	mBall.setMovement(mDirection);
}

void PlayingState::update()
{
	mPlayer.update();
	mBot.update();
	mBall.update();
	updateBallMovement();
}

void PlayingState::render(sf::RenderTarget& target)
{
	target.draw(mLine);
	mPlayer.render(target);
	mBot.render(target);
	mBall.render(target);
}
