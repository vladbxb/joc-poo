#include "Game.h"
#include <SFML/Graphics.hpp>
#include <exception>
#include <iostream>

int main()
{
	try
	{
		Game game;
		game.run();
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception:\n" << e.what() << '\n';
		return 1;
	}
	return 0;
}

