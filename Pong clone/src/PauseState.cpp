#include "pch.h"
#include "PauseState.h"

PauseState::PauseState()
	: mPlayer(5.f), mBot(5.f), mBall(5.f)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));

	//Texts and font
	mFont.loadFromFile("Fonts/OpenSans-Regular.ttf");

	scoreLeft.setFont(mFont);
	scoreLeft.setCharacterSize(44);
	scoreLeft.setPosition(sf::Vector2f(170.f, 20.f));
	scoreLeft.setString("0");

	scoreRight.setFont(mFont);
	scoreRight.setCharacterSize(44);
	scoreRight.setPosition(sf::Vector2f(610.f, 20.f));
	scoreRight.setString("0");
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
	target.draw(scoreLeft);
	target.draw(scoreRight);
}