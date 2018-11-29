// board.h

#include<vector>

#include "tile.h"

class Board // Class for storing the game board and all its tiles
{
	public:
		Board(int width=10, int height=10); // Initialize board with blank Tiles
		void generate(int bombs=10); // Place bombs and adjacent numbers
		std::string repr(); // Return visual representation for terminal output
		void open_tile_at(int x, int y); // Set board[x][y] to not hidden

		const static char
				TL_DIAG = 1,		// Top left diagonal
				TOP = 1 << 1,		// Directly above
				TR_DIAG = 1 << 2,	// Top right diagonal
				LEFT = 1 << 3, 		// Directly left
				RIGHT = 1 << 4, 	// Directly right
				BL_DIAG = 1 << 5,	// Bottom left diagonal
				BOTTOM = 1 << 6,	// Directly below
				BR_DIAG = 1 << 7;	// Bottom right diagonal
	private:
		std::vector<std::vector<Tile>> board; // Internal data storage
		int width, height; // Width and height of the board
		void increment_adj(int x, int y, char which);
		/* Increment each of the selected Tiles directly adjacent to the Tile at
		 * board[x][y] with each bit of which corresponding to a specific
		 * location according to the constants defined above */
};
