/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/


#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Walls
{
private:
	vector<int> vectorRead;
	Vector2f wallCoords;
	int xCoord;
	int yCoord;
	int xTiles;
	int yTiles;

	Vector2f wallCheck;

	bool wallsPresent[20][20];
	bool wallsPresent2[44][20];

public:
	Walls();
	//void createWalls();
	void setWallCoords(int x, int y);
	vector<int> getReadVector();
	Vector2f getWallCoords();
	
	void bolWalls();
	bool bolWalls2();

	int createWalls(VertexArray& rVA, IntRect arena);
	int createWalls2(VertexArray& rVA, IntRect arena);
	bool getWallsPresent(int x, int y);

	int mazeNumb = 2;

	void setMaze(int mazeNo);
	int getMaze();


};
