#pragma once

class Bot
{
public:
	Bot(const float speed);

	void setBot();

	//Con / des
	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPosition() const;

	void move(const float speed);
	void checkPosition();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	float mSpeed;
};

