class Coordinate
{
	public:
		Coordinate(int x, int y); // Contruct a coordinate with given x and y
		int getx(); // Return the x value
		int gety(); // Return the y value
		void setx(int x); // Set the x value
		void sety(int y); // Set the y value
	private:
		int x, y; // Internal storage of x and y
};
// TODO: add getter functions that take in a which char and return the proper
// offset x and/or y values
