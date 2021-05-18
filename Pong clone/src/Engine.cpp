#include "pch.h"
#include "Engine.h"
#include "PlayingState.h"
#include "PauseState.h"

 Engine::Engine()
	: gameRunning(true), pressedSpace(false), delay(25.f)
{
	mWindow.create(sf::VideoMode(800, 500), "Pong clone", sf::Style::Close);
	std::cout << "[Engine]: Window created" << "\n";
	mWindow.setFramerateLimit(120);

	gameStates.addState(new PauseState);

	initEndGameText();
}

 Engine::~Engine()
 {
	std::cout << "[Engine]: Game is Over!" << "\n";
 }

 void Engine::initEndGameText()
 {
	 //Init end game text
	 mFont.loadFromFile("Fonts/OpenSans-Regular.ttf");

	 mText.setFont(mFont);
	 mText.setFillColor(sf::Color::Black);
	 mText.setCharacterSize(50);
 }

bool Engine::isGameRunning()
{
	return gameRunning;
}

void Engine::pollEvents()
{
	sf::Event ev;

	while (mWindow.pollEvent(ev))
	{
		if (ev.type == sf::Event::Closed)
			gameRunning = false;
		else if (ev.type == sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Escape)
			gameRunning = false;
		else if (sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space && !pressedSpace)
		{
			gameStates.addState(new PlayingState);
			pressedSpace = true;
		}
	}
}

void Engine::update()
{
	gameStates.update();
}

void Engine::renderEndGameText()
{
	if (getWinner() == 'B')
	{
		mWindow.clear(sf::Color::White);
		mText.setString("The winner is - Bot");
		mText.setPosition(sf::Vector2f(200.f, 200.f));
		mWindow.draw(mText);
	}
	else if (getWinner() == 'P')
	{
		mWindow.clear(sf::Color::White);
		mText.setString("The winner is - Player");
		mText.setPosition(sf::Vector2f(200.f, 200.f));
		mWindow.draw(mText);
	}
}

void Engine::render()
{
	mWindow.clear(sf::Color::Black);

	gameStates.render(mWindow);

	if (checkVictory())
	{
		renderEndGameText();

		float time = mClock.getElapsedTime().asSeconds();
		mClock.restart();
		timer += time;
		if (timer > delay)
		{
			timer = 0;
			gameRunning = false;
		}
	}
	mWindow.display();
}

void Engine::run()
{
	while (isGameRunning())
	{
		pollEvents();
		update();
		render();
	}
}
