#include "pch.h"
#include "Engine.h"
#include "PlayingState.h"
#include "PauseState.h"

 Engine::Engine()
	: gameRunning(true), pressedSpace(false)
{
	mWindow.create(sf::VideoMode(800, 500), "Pong clone", sf::Style::Close);
	std::cout << "[Engine]: Window created" << "\n";
	mWindow.setFramerateLimit(144);

	gameStates.addState(new PauseState);
}

 Engine::~Engine()
 {
	std::cout << "[Engine]: Game is Over!" << "\n";
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

void Engine::render()
{
	mWindow.clear(sf::Color::Black);

	gameStates.render(mWindow);
	mWindow.display();
}

void Engine::run()
{
	while (isGameRunning())
	{
		pollEvents();
		update();
		render();

		//When someone scores 5 points = Game Over
		if (checkVictory())
			gameRunning = false;
	}
}
