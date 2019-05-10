// board.h

#include<vector>
#include<iostream>

#include "tile.h"

class Board // Class for storing the game board and all its tiles
{
	public:
		Board(int width=10, int height=10); // Initialize board with blank Tiles
		void generate(int bombs=10); // Place bombs and adjacent numbers
		std::string repr(); // Return visual representation for terminal output
		void open_tile_at(int x, int y); // Set board[x][y] to not hidden
		/* Open the tile at (x,y) then auto expand to open empty tiles around.
		 * This method is preferable to open_tile_at() unless it is explicitly
		 * required to only open the tile at (x,y) */
		void auto_open_at(int x, int y);
		void toggle_flag_at(int x, int y); // Toggle board[x][y] flag state
		/* Return what tiles around (x,y) are valid E.g. if you input (0,0), it
		 * will not return any tiles around the top or left because the (0,0) is
		 * in the top left corner, thus they would be out of the bounds of the
		 * board and trying to use them would give a segfault. */
		char get_valid_tiles_around(int x, int y);
		int get_x_offs(char which); // Get x offset of adjacent
		int get_y_offs(char which); // Get y offset of adjacent

		const static char
				TL_DIAG = 1,		// (1)		Top left diagonal
				TOP = 1 << 1,		// (2)		Directly above
				TR_DIAG = 1 << 2,	// (4)		Top right diagonal
				LEFT = 1 << 3, 		// (8)		Directly left
				RIGHT = 1 << 4, 	// (16)		Directly right
				BL_DIAG = 1 << 5,	// (32)		Bottom left diagonal
				BOTTOM = 1 << 6,	// (64)		Directly below
				BR_DIAG = 1 << 7;	// (128)	Bottom right diagonal
		/* Print out a string representation of a "which" char */
		std::string which_repr(char which);
	private:
		std::vector<std::vector<Tile>> board; // Internal data storage
		int width, height; // Width and height of the board
		/* Increment each of the selected Tiles directly adjacent to the Tile at
		 * board[x][y] with each bit of which corresponding to a specific
		 * location according to the constants defined above */
		void increment_adj(int x, int y, char which);
		/* Returns whether or not to add this to the list of tiles to auto
		 * expand around */
		bool should_expand(int x, int y);
		/* Returns whether or not to auto open this tile.  If this function
		 * returns true for a specific tile, then should_expand should
		 * also return true for that same tile. */
		bool should_auto_open(int x, int y);
};
