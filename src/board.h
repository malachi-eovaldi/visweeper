// board.h

#include<vector>

#include "tile.h"

class Board // Class for storing the game board and all its tiles
{
	public:
		Board(int width=10, int height=10); // Initialize board with blank Tiles
		void generate(int bombs=10); // Place bombs and adjacent numbers
		std::string repr(); // Return visual representation for terminal output
	private:
		std::vector<std::vector<Tile>> board; // Internal data storage
		int width, height; // Width and height of the board
};
