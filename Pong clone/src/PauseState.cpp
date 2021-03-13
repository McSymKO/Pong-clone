#include "pch.h"
#include "PauseState.h"

PauseState::PauseState()
	: mPlayer(5.f), mBot(5.f)
{
	mLine.setSize(sf::Vector2f(5.f, 500.f));
	mLine.setPosition(sf::Vector2f(390.f, 0.f));

	//GUI texts
	mFont.loadFromFile("Fonts/OpenSans-Regular.ttf");
	pauseText.setFont(mFont);
	pauseText.setCharacterSize(100);
	pauseText.setString("PAUSE");
	
	//Centering Pause Text
	sf::FloatRect textRect = pauseText.getLocalBounds();
	pauseText.setOrigin(textRect.left + textRect.width / 2.0f,
						textRect.top + textRect.height / 2.0f);
	pauseText.setPosition(sf::Vector2f(800.f / 2.f, 500.f / 2.f));
}

void PauseState::update()
{
}

void PauseState::render(sf::RenderTarget& target)
{
	mPlayer.render(target);
	mBot.render(target);
	target.draw(mLine);
	target.draw(pauseText);
}