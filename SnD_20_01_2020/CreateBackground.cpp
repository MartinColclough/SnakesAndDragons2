/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include <SFML/Graphics.hpp>
#include "Board.h"
#include <iostream>
using namespace std;

int createBackground(VertexArray& rVA, IntRect arena)
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
	int ss = startingPoint / TILE_SIZE;
	int ss2 = startingPoint / TILE_SIZE;

	// What type of primitive are we using?
	rVA.setPrimitiveType(Quads);
	 
	// Set the size of the vertex array
	// Set the size of the vertex array
	rVA.resize(startingPoint * startingPoint2 * VERTS_IN_QUAD);

	// Start at the beginning of the vertex array
	int currentVertex = 0;
	int tileCounter = 0;


	for (int w = worldLeft; w < startingPoint; w++)
	{
		for (int h = worldTop; h < startingPoint2; h++)
		{
			/*
				// Position each vertex in the current quad
			rVA[currentVertex + 0].position = Vector2f(w * TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 1].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, h * TILE_SIZE);
			rVA[currentVertex + 2].position = Vector2f((w * TILE_SIZE) + TILE_SIZE, (h * TILE_SIZE) + TILE_SIZE);
			rVA[currentVertex + 3].position = Vector2f((w * TILE_SIZE), (h * TILE_SIZE) + TILE_SIZE);
			//cout << w << " is counted "<< endl;
			//cout << h << " is counted "<< endl;

			// Define the position in the Texture to draw for current quad
			// Either mud, stone, grass or wall
			if (h == 0 || h == worldHeight - 1  || w == 43  || w == 24|| w == 0 || w == worldWidth - 1 )
			{
				// Use the wall texture
				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
			//	cout << "  number of black tiles" << tileCounter << endl;
			}
			else
			{
				ya++;
				// Use a random floor texture
				cout << "  number of coloured tiles :" << ya << endl;
				
			//	srand((int)time(0) + h * w - h);

				int mOrG = (rand() % TILE_TYPES);


				int verticalOffset = mOrG * TILE_SIZE;

				rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + verticalOffset);
				rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + verticalOffset);
				rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + verticalOffset);
				rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + verticalOffset);

				if (ya  == 15)
				{
					// Use the wall texture
					rVA[currentVertex + 0].texCoords = Vector2f(0, 0 + TILE_TYPES * TILE_SIZE);
					rVA[currentVertex + 1].texCoords = Vector2f(TILE_SIZE, 0 + TILE_TYPES * TILE_SIZE);
					rVA[currentVertex + 2].texCoords = Vector2f(TILE_SIZE, TILE_SIZE + TILE_TYPES * TILE_SIZE);
					rVA[currentVertex + 3].texCoords = Vector2f(0, TILE_SIZE + TILE_TYPES * TILE_SIZE);
					//cout << "  number of black tiles" << tileCounter << endl;
				}
			}
			tileCounter++;
			// Position ready for the next for vertices
			currentVertex = currentVertex + VERTS_IN_QUAD;

			*/
		}
	}
	cout << " total number of tiles" << tileCounter << endl;
	return TILE_SIZE;
}