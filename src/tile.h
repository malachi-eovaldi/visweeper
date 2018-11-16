// tile.h
#pragma once

#include<string>

class Tile
{
	public:
		Tile();
		int get_adj();
		void set_adj(int adj);
		bool is_bomb();
		void set_bomb(bool b);
		bool is_flagged();
		void set_flagged(bool b);
		bool is_hidden();
		void set_hidden(bool b);
		std::string repr();
		std::string debug();

	private:
		int adj;
		bool bomb, flagged, hidden;
};