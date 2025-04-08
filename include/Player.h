#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Game;

class Player
{
	Game& playing;
	int lives;
	std::unique_ptr<sf::Shape> shape; // momentan folosim o forma geometrica
									  // pentru ca sa reprezentam
									  // grafic player-ul pentru simplitate
									  	void update();
	void draw();
	friend class Game;

public:
	Player(Game& playing);
};
