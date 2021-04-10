#pragma once

//Global bot directions
namespace Bot_Directions
{
	enum class Directions
	{
		IDLE,
		UP,
		DOWN
	};
}

class Bot
{
public:
	//Con / des
	Bot(const float speed);

	//Getters / setters
	void setBot();

	const sf::FloatRect getBounds() const;
	const sf::Vector2f& getPosition() const;
	const unsigned& getBotPoints() const;
	void setMovement(Bot_Directions::Directions direction);

	//Functions
	void scoreBotPoint();
	void move();
	void checkPosition();

	void update();
	void render(sf::RenderTarget& target);

private:
	sf::RectangleShape mShape;
	float mSpeed;
	Bot_Directions::Directions mDir;
	unsigned mPoints;
};

