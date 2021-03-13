#pragma once

class Player
{
public:
	Player(float speed);

	void move(const float speed);
	void checkPosition();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	const float mSpeed;
};

