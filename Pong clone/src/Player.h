#pragma once

class Player
{
public:
	Player(const float speed);

	void setPlayer();

	//Getters / Setters
	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getBounds() const;

	void move();
	void checkPosition();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	const float mSpeed;
};

