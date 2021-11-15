/*
	This is the check if gitfetch works
*/


#include "Renderer.h"
#include "Game.h"
#include <iostream>

int main()
{
	bool gameOver = false;

	Renderer renderer;
	sf::Event event;
	Game game(renderer);
	while (!gameOver) 
	{
		while (renderer.pollEvents(event)) {
			if (event.type == sf::Event::Closed) {
				return 0;
			}
			if (event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2i locationOnGrid = renderer.getMousePostion();
				if (game.select(locationOnGrid.x, locationOnGrid.y)) {
					renderer.select(locationOnGrid);
				}
				else {
					renderer.select(sf::Vector2i(-1, -1));
				}
			}
		}
		renderer.update(game.board);
	}
}


/*
TODO
	
	=> Impliment the rules

=>PAWNS
=>KING
=>ROOKS
=>BISHOP
=>KNIGHT
=>QUEEN

*/