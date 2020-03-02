/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include "PickupObjects.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;

Texture textur1;
Texture textur2;

PickupObjects::PickupObjects(int type)
{
	// Store the type of this pickup
	m_Type = type;


	// Associate the texture with the sprite
	if (m_Type == 1)
	{
		coin.loadFromFile("graphics/GoldCoinSprite.png");
		m_Sprite.setTexture(coin);
	}

	else if (m_Type == 2)
	{
		dragon.loadFromFile("graphics/dragonPickup.png");
		m_Sprite.setTexture(dragon);
	}

	else if (m_Type == 3)
	{
		snake.loadFromFile("graphics/snakePickup.png");
		m_Sprite.setTexture(snake);
	}
	else if (m_Type == 4)
	{
		zoom.loadFromFile("graphics/Zoom.png");
		m_Sprite.setTexture(zoom);
	}
	else if (m_Type == 5)
	{
		inkAttack.loadFromFile("graphics/inkPickup.png");
		m_Sprite.setTexture(inkAttack);
	}

	else if (m_Type == 6)
	{
		rotate.loadFromFile("graphics/rotate.png");
		m_Sprite.setTexture(rotate);
	}

	else if (m_Type == 7)
	{
		door.loadFromFile("graphics/door.png");
		m_Sprite.setTexture(door);
	}

	else if (m_Type == 8)
	{
		slow.loadFromFile("graphics/slow.png");
		m_Sprite.setTexture(slow);
	}

	else if (m_Type == 9)
	{
		slowAttack.loadFromFile("graphics/slowAttack.png");
		m_Sprite.setTexture(slowAttack);
	}

	else if (m_Type == 10)
	{
		shop.loadFromFile("graphics/shop.png");
		m_Sprite.setTexture(shop);
	}
	
	else if (m_Type == 11)
	{
		trap.loadFromFile("graphics/trap.png");
		m_Sprite.setTexture(trap);
	}

	else if (m_Type == 12)
	{
		trapAttack.loadFromFile("graphics/trapAttack.png");
		m_Sprite.setTexture(trapAttack);
	}

	else if (m_Type == 13)
	{
		moneyBag.loadFromFile("graphics/moneyBag.png");
		m_Sprite.setTexture(moneyBag);
	}

	else if (m_Type == 14)
	{
		moveWall.loadFromFile("graphics/moveWalls.png");
		m_Sprite.setTexture(moveWall);
	}
}

void PickupObjects::setArena(IntRect arena)
{
	// Copy the details of the arena to the pickup's m_Arena
	m_Arena.left = arena.left + 50;
	m_Arena.width = arena.width - 50;
	m_Arena.top = arena.top + 50;
	m_Arena.height = arena.height - 50;

	spawn();
}

void PickupObjects::spawn()
{

	arrayCreation();
	int x = 0, y = 0;

	while (objectPosition == false)
	{
		 x = rand() % 1000;
		while (x % 50 != 0 && x != 0)
			x = rand() % 900 + 50;// +50;

		 y = rand() % 1000;
		  
		while (y % 50 != 0 && y != 0)
			y = rand() % 900 + 50;// +50;

		cout << " CHECKING IF OBJECT IS ON A WALL: " <<  x  << " "<< y << endl;

		objectPosition = checkForEmptySpace(x, y, 1);
	}
	m_Spawned = true;

	objectPosition = false;

m_Sprite.setPosition(x, y);
}

void PickupObjects::spawn2()
{
	arrayCreation();
	int x = 0, y = 0;

	while (objectPosition == false)
	{
		x = rand() % 1000;
		while (x % 50 != 0 && x != 0)
		{
			x = rand() % 900 + 50;// +50;
		}

		y = rand() % 1000;

		while (y % 50 != 0 && y != 0)
		{
			y = rand() % 900 + 50;// +50;
		}
			x = x + 1200;
			cout << " CHECKING IF OBJECT IS ON A WALL: " <<  x  << " "<< y  << " pickUps"<< endl;

		objectPosition = checkForEmptySpace(x, y, 2);
	}
	m_Spawned = true;

	objectPosition = false;

	m_Sprite.setPosition(x, y);
	
}

Sprite PickupObjects::getSprite()
{
	return m_Sprite;
}

bool PickupObjects::isSpawned()
{
	return m_Spawned;
}

FloatRect PickupObjects::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

int PickupObjects::gotIt()
{
	m_Spawned = false;
	return 1;
}

void PickupObjects::update(float elapsedTime)
{

}

void PickupObjects::arrayCreation()
{
	int randWall = getMaze();

	if (randWall == 1)
	{

		string filename = "Walls/wall1.txt";
		string filename2 = "Walls/wall1.txt";

		ifstream inputFile(filename);
		ifstream inputFile2(filename2);

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> counter1[x][y];

				if (counter1[x][y] == '1')
				{
					counter1[x][y] = '0';
					objectColision[x][y] = true;
				}
				else
				{
					objectColision[x][y] = false;
				}
			}
		}

		for (int a = 24; a < 44; a++)
		{
			for (int b = 0; b < 20; b++)
			{
				inputFile2 >> counter2[a][b];

				if (counter2[a][b] == '1')
				{
					counter2[a][b] = '0';
					objectColision2[a][b] = true;
				}
				else
				{
					objectColision2[a][b] = false;
				}
			}
		}
	}
	if (randWall == 2)
	{
		string filename = "Walls/wall2.txt";
		string filename2 = "Walls/wall2.txt";

		ifstream inputFile(filename);
		ifstream inputFile2(filename2);

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> counter1[x][y];

				if (counter1[x][y] == '1')
				{
					counter1[x][y] = '0';
					objectColision[x][y] = true;
				}
				else
				{
					objectColision[x][y] = false;
				}
			}
		}

		for (int a = 24; a < 44; a++)
		{
			for (int b = 0; b < 20; b++)
			{
				inputFile2 >> counter2[a][b];

				if (counter2[a][b] == '1')
				{
					counter2[a][b] = '0';
					objectColision2[a][b] = true;

				}
				else
				{
					objectColision2[a][b] = false;
				}
			}
		}
	}
	if (randWall == 3)
	{

		string filename = "Walls/wall3.txt";
		string filename2 = "Walls/wall3.txt";

		ifstream inputFile(filename);
		ifstream inputFile2(filename2);

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> counter1[x][y];

				if (counter1[x][y] == '1')
				{
					counter1[x][y] = '0';
					objectColision[x][y] = true;
				}
				else
				{
					objectColision[x][y] = false;
				}
			}
		}

		for (int a = 24; a < 44; a++)
		{
			for (int b = 0; b < 20; b++)
			{
				inputFile2 >> counter2[a][b];

				if (counter2[a][b] == '1')
				{
					counter2[a][b] = '0';
					objectColision2[a][b] = true;

				}
				else
				{
					objectColision2[a][b] = false;
				}
			}
		}
	}
	if (randWall == 4)
	{
		string filename = "Walls/wall4.txt";
		string filename2 = "Walls/wall4.txt";

		ifstream inputFile(filename);
		ifstream inputFile2(filename2);

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> counter1[x][y];

				if (counter1[x][y] == '1')
				{
					counter1[x][y] = '0';
					objectColision[x][y] = true;
				}
				else
				{
					objectColision[x][y] = false;
				}
			}
		}

		for (int a = 24; a < 44; a++)
		{
			for (int b = 0; b < 20; b++)
			{
				inputFile2 >> counter2[a][b];

				if (counter2[a][b] == '1')
				{
					counter2[a][b] = '0';
					objectColision2[a][b] = true;

				}
				else
				{
					objectColision2[a][b] = false;
				}
			}
		}
	}
	if (randWall == 5)
	{
		string filename = "Walls/wall5.txt";
		string filename2 = "Walls/wall5.txt";

		ifstream inputFile(filename);
		ifstream inputFile2(filename2);

		for (int x = 0; x < 20; x++)
		{
			for (int y = 0; y < 20; y++)
			{
				inputFile >> counter1[x][y];

				if (counter1[x][y] == '1')
				{
					counter1[x][y] = '0';
					objectColision[x][y] = true;
				}
				else
				{
					objectColision[x][y] = false;
				}
			}
		}

		for (int a = 24; a < 44; a++)
		{
			for (int b = 0; b < 20; b++)
			{
				inputFile2 >> counter2[a][b];

				if (counter2[a][b] == '1')
				{
					counter2[a][b] = '0';
					objectColision2[a][b] = true;
				}
				else
				{
					objectColision2[a][b] = false;
				}
			}
		}
	}
}

bool PickupObjects::checkForEmptySpace(int x, int y, int OneTwo)
{
	int XObject = x / 50;
	int YObject = y / 50;

	//cout << " VALUE FOR X: " << XObject;
	//cout << " VALUE FOR Y: " << YObject;
	if (OneTwo == 1)
	{
		if (objectColision[XObject][YObject] == 1)
		{
			objectColision2[XObject][YObject] = 0;
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{

		if (objectColision2[XObject][YObject] == 1) 
		{
			cout << " the x and y value: " << objectColision2[XObject][YObject];
			cout << " PickUp IS ON SAFE SPACE" << endl;
			cout << " returning true" << endl;
			objectColision2[XObject][YObject] = 0;
			return true;
		}
		else
		{
			cout << " the x and y value: " << objectColision[XObject][YObject];
			cout << " YO YOU ON A WALL: Pickup 1  " << endl;
			return false;
		}

	}

}
void PickupObjects::setMaze(int mazeNo)
{
	mazeNumb = mazeNo;
}

int PickupObjects::getMaze()
{
	return mazeNumb;
}

