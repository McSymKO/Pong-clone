#pragma once

class Player
{
public:
	Player(const float speed);

	//Getters / setters
	void setPlayer();

	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getBounds() const;
	const unsigned& getPlayerPoints() const;

	//Functions
	void scorePlayerPoint();
	void move();
	void checkPosition();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	const float mSpeed;
	unsigned mPoints;
};

