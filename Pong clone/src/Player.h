#pragma once

class Player
{
public:
	Player(const float speed);

	void move();
	void checkPosition();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	const float mSpeed;
};

