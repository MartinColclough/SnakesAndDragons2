/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Walls.h"
#include <sstream>
#include <fstream>
#include "Board.h"
#include <iostream>
#include <map>

using namespace sf;
using namespace std;

Walls::Walls()
{
	//int arrayWalls[20][20];
	vector<int> vectorRead;
	xCoord = 0;
	yCoord = 0;
	xTiles = 20;
	yTiles = 20;
}

void Walls::setWallCoords(int x, int y)
{
	wallCoords.x = x;
	wallCoords.y = y;
}

vector<int> Walls::getReadVector()
{
	return vectorRead;
}

Vector2f Walls::getWallCoords()
{
	return wallCoords;
}

void Walls::bolWalls()
{
	int x;
	int sum = getMaze();
	if (sum == 1)
	{
		string filename = "Walls/wall1.txt";
		ifstream inputFile(filename);

		char asas[20][20];

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent[x][y] = true;
				}
				else
				{
					wallsPresent[x][y] = false;
				}
			}
		}
	}
	if (sum == 2)
	{
		string filename = "Walls/wall2.txt";
		ifstream inputFile(filename);

		char asas[20][20];

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent[x][y] = true;
				}
				else
				{
					wallsPresent[x][y] = false;
				}
			}
		}
	}
	if (sum == 3)
	{
		string filename = "Walls/wall3.txt";
		ifstream inputFile(filename);

		char asas[20][20];

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent[x][y] = true;
				}
				else
				{
					wallsPresent[x][y] = false;
				}
			}
		}
	}
	if (sum == 4)
	{
		string filename = "Walls/wall4.txt";
		ifstream inputFile(filename);

		char asas[20][20];

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent[x][y] = true;
				}
				else
				{
					wallsPresent[x][y] = false;
				}
			}
		}
	}
	if (sum == 5)
	{
		string filename = "Walls/wall5.txt";
		ifstream inputFile(filename);

		char asas[20][20];

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent[x][y] = true;
				}
				else
				{
					wallsPresent[x][y] = false;
				}
			}
		} 
	}

}
bool Walls::bolWalls2()
{
	int x;
	int sum = getMaze();
	if (sum == 1)
	{
		string filename = "Walls/wall1.txt";
		ifstream inputFile(filename);

		char asas[44][20];

		for (int x = 24; x < 44; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent2[x][y] = true;
				}
				else
				{
					wallsPresent2[x][y] = false;
				}
			}
		}
	}
	if (sum == 2)
	{
		string filename = "Walls/wall2.txt";
		ifstream inputFile(filename);

		char asas[44][20];

		for (int x = 24; x < 44; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent2[x][y] = true;
				}
				else
				{
					wallsPresent2[x][y] = false;
				}
			}
		}
	}
	if (sum == 3)
	{
		string filename = "Walls/wall3.txt";
		ifstream inputFile(filename);

		char asas[44][20];

		for (int x = 24; x < 44; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent2[x][y] = true;
				}
				else
				{
					wallsPresent2[x][y] = false;
				}
			}
		}
	}
	if (sum == 4)
	{
		string filename = "Walls/wall4.txt";
		ifstream inputFile(filename);

		char asas[44][20];

		for (int x = 24; x < 44; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent2[x][y] = true;
				}
				else
				{
					wallsPresent2[x][y] = false;
				}
			}
		}
	}
	if (sum == 5)
	{
		string filename = "Walls/wall5.txt";
		ifstream inputFile(filename);

		char asas[44][20];

		for (int x = 24; x < 44; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> asas[x][y];
				//asas[x] >> lol[x];

				if (asas[x][y] == '1')
				{
					wallsPresent2[x][y] = true;
				}
				else
				{
					wallsPresent2[x][y] = false;
				}
			}
		}
	}
	return wallsPresent2;
}
int Walls::createWalls(VertexArray& rVA, IntRect arena)
{
	// Anything we do to rVA we are actually doing to background (in the main function)

	// How big is each tile/texture
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;
	int ya = 0;

	int worldWidth = arena.width / TILE_SIZE;
	int worldHeight = arena.height / TILE_SIZE;
	int worldLeft = arena.left / TILE_SIZE;
	int	worldTop = arena.top / TILE_SIZE;

	int startingPoint = worldWidth + worldLeft;
	int startingPoint2 = worldHeight + worldTop;
	//int ss = startingPoint / TILE_SIZE;
	//int ss2 = startingPoint / TILE_SIZE;

	// What type of primitive are we using?
	rVA.setPrimitiveType(Quads);

	// Set the size of the vertex array
	// Set the size of the vertex array
	rVA.resize(startingPoint * startingPoint2 * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex =0;
	int tileCounter = 0;

	cout << worldWidth << " worldWidth " << endl;
	cout << worldHeight << " worldHeight" << endl;
	cout << worldLeft << " worldLeft " << endl;
	cout << worldTop << " worldTop" << endl;
	cout << startingPoint << " startingPoint " << endl;
	cout << startingPoint2 << " startingPoint2 " << endl;
	//cout << ss << " ss " << endl;
	//cout << ss2 << " ss2 " << endl;

	for (int w = worldLeft; w < startingPoint; w++)
	{
		for (int h = worldTop; h < startingPoint2; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);
			//cout << w << " is counted "<< endl;
			//cout << h << " is counted "<< endl;
			//cout << "  walltexture" << wallsPresent[w][h] << endl;
			// Define the position in the Texture to draw for current quad
			// Either mud, stone, grass or wall
			if(wallsPresent[w][h] == 0)			
			{
				// Use the wall texture
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				//cout << "  walltexture" << tileCounter << endl;
				//cout << "  walltexture" << wallsPresent[w][h] << endl;

			}
			else 
			{
				ya++;
				// Use a random floor texture
				//cout << "  number of coloured tiles :" << ya << endl;

				//	srand((int)time(0) + h * w - h);

				int mOrG = (rand() % TILE_TYPES);

				int verticalOffset = mOrG * TILE_SIZE;

				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

			}
			tileCounter++;
			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;
		}
	}
	cout << " total number of tiles" << tileCounter << endl;
	return TILE_SIZE;
}
int Walls::createWalls2(VertexArray& rVA, IntRect arena)
{
	// Anything we do to rVA we are actually doing to background (in the main function)

	// How big is each tile/texture
	const int TILE_SIZE = 50;
	const int TILE_TYPES = 3;
	const int VERTS_IN_QUAD = 4;
	int ya = 0;

	int worldWidth = arena.width / TILE_SIZE;
	int worldHeight = arena.height / TILE_SIZE;
	int worldLeft = arena.left / TILE_SIZE;
	int	worldTop = arena.top / TILE_SIZE;

	int startingPoint = worldWidth + worldLeft;
	int startingPoint2 = worldHeight + worldTop;
	//int ss = startingPoint / TILE_SIZE;
	//int ss2 = startingPoint / TILE_SIZE;

	// What type of primitive are we using?
	rVA.setPrimitiveType(Quads);

	// Set the size of the vertex array
	// Set the size of the vertex array
	rVA.resize(startingPoint * startingPoint2 * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;
	int tileCounter = 0;

	cout << worldWidth << " worldWidth " << endl;
	cout << worldHeight << " worldHeight" << endl;
	cout << worldLeft << " worldLeft " << endl;
	cout << worldTop << " worldTop" << endl;
	cout << startingPoint << " startingPoint " << endl;
	cout << startingPoint2 << " startingPoint2 " << endl;
	//cout << ss << " ss " << endl;
	//cout << ss2 << " ss2 " << endl;

	for (int w = 24; w < 44; w++)
	{
		for (int h = 0; h < 20; h++)
		{
			// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);
			cout << w << " is counted "<< endl;
			cout << h << " is counted "<< endl;
			cout << "  walltexture: " << wallsPresent[w][h] << endl;
			// Define the position in the Texture to draw for current quad
			// Either mud, stone, grass or wall
			if (wallsPresent2[w][h] == 0)
			{
				// Use the wall texture
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				//cout << "  walltexture" << tileCounter << endl;
				//cout << "  walltexture" << wallsPresent[w][h] << endl;

			}
			else
			{
				ya++;
				// Use a random floor texture
				//cout << "  number of coloured tiles :" << ya << endl;

				//	srand((int)time(0) + h * w - h);

				int mOrG = (rand() % TILE_TYPES);

				int verticalOffset = mOrG * TILE_SIZE;

				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

			}
			tileCounter++;
			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD; 
		}
	}
	cout << " total number of tiles" << tileCounter << endl;
	return TILE_SIZE;
}
bool Walls::getWallsPresent(int x ,int y)
{
		if(wallsPresent[x][y] == 0)
		{
			return false;
		}
		else
		{
			return true;
		}

	// import x and y 
	// check if x and y are false 
	// return  value 

}
void Walls::setMaze(int mazeNo)
{
	mazeNumb = mazeNo;
}

int Walls::getMaze()
{
	return mazeNumb;
}

