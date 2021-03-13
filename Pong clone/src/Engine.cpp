#include "pch.h"
#include "Engine.h"
#include "PlayingState.h"
#include "PauseState.h"

 Engine::Engine()
	: gameRunning(true)
{
	mWindow.create(sf::VideoMode(800, 500), "Pong clone", sf::Style::Close);
	std::cout << "[Engine]: Window created" << "\n";
	mWindow.setFramerateLimit(144);

	gameStates.addState(new PauseState);
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
		else if (sf::Event::KeyPressed && ev.key.code == sf::Keyboard::Space)
			gameStates.addState(new PlayingState);
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
	}
}
