#include "pch.h"
#include "StateManager.h"

void StateManager::addState(GameState* state)
{
	states.push(state);
	/*states.top()->init();*/
}

void StateManager::update()
{
	states.top()->update();
}

void StateManager::render(sf::RenderTarget& target)
{
	states.top()->render(target);
}
