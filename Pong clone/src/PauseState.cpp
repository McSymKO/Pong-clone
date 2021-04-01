#include "pch.h"
#include "PauseState.h"

PauseState::PauseState()
	: mPlayer(5.f), mBot(5.f), mBall(5.f)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));

	//Points
	std::string pointsLeft = std::to_string(mBot.getBotPoints());

	//Texts and font
	mFont.loadFromFile("Fonts/OpenSans-Regular.ttf");

	scoreLeft.setFont(mFont);
	scoreLeft.setCharacterSize(44);
	scoreLeft.setPosition(sf::Vector2f(170.f, 20.f));
	scoreLeft.setString(pointsLeft);
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