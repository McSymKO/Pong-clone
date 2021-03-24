#include "pch.h"
#include "PauseState.h"

PauseState::PauseState()
	: mPlayer(5.f), mBot(5.f), mBall(5.f)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));
}

void PauseState::update()
{
}

void PauseState::render(sf::RenderTarget& target)
{
	mPlayer.render(target);
	mBot.render(target);
	mBall.render(target);
	target.draw(mLine);
}