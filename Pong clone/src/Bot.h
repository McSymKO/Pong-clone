#pragma once

class Bot
{
public:
	Bot(const float speed);

	//Con / des
	const sf::FloatRect getBounds() const;

	void move(const float speed);
	void checkPosition();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	float mSpeed;
};

