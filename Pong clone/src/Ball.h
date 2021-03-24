#pragma once

namespace Directions
{
	enum class DIRECTION_MOVEMENT
	{
		IDLE,
		LEFT,
		UP_LEFT,
		DOWN_LEFT,
		RIGHT,
		UP_RIGHT,
		DOWN_RIGHT
	};
}

class Ball
{
public:
	Ball(const float speed);

	void setBall();

	//Getters / Setters
	const sf::Vector2f& getPosition() const;
	const sf::FloatRect getBounds() const;
	void setMovement(Directions::DIRECTION_MOVEMENT movement);
	
	void move();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	float mSpeed;
	Directions::DIRECTION_MOVEMENT mDirection;
};

