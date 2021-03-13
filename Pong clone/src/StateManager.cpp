#include "pch.h"
#include "StateManager.h"

void StateManager::addState(GameState* state)
{
	removeState();
	states.push(state);
	states.top()->init();
}

void StateManager::removeState()
{
	if (!states.empty())
		states.pop();
}

void StateManager::update()
{
	states.top()->update();
}

void StateManager::render(sf::RenderTarget& target)
{
	states.top()->render(target);
}
