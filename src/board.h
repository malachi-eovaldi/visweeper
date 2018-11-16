// board.h

#include<vector>

#include "tile.h"

class Board
{
	public:
		Board(int width=10, int height=10);
		void generate(int bombs=10);
		std::string repr();
	private:
		std::vector<std::vector<Tile>> board;
		int width, height;
};
