/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include "player.h"
#include <iostream>
#include <sstream>
#include <fstream>
#include "Walls.h"
using namespace std;


Walls wal;


Player::Player()
{
	m_Speed = START_SPEED;
	m_Health = START_HEALTH;
	m_MaxHealth = START_HEALTH;	
	coins = Start_Coin;

	// Remember how big the tiles are in this arena
	m_TileSize = 50;

	attack = 1;
	defence = 1;

	key = false;

	/* Set the origin of the sprite to the centre, 
	 for smooth rotation*/
	m_Sprite.setOrigin(30, 30);
}

int Player::randomPosition(int playerNo)
{
	//return a random that is a multiple of 50
	//must be lower than 450 so that they don't go outside the map
	int random = rand() % 450; 

	if (playerNo == 1)
	{
		while (random % 50 != 0 && random != 0)
		{
			random = rand() % 450;
		}
	}
	else
	{
		while (random % 50 != 0 && random != 0)
		{
			random = rand() % 450;
		}
	}

	return random;
}

void Player::spawn(IntRect arena, Vector2f resolution, int playerNo)
{

	int x = 0, y = 0;
	

	while (xoox == false)
	{
		if (playerNo == 1)
		{
			x = rand() % 1000;
			while (x % 50 != 0 && x != 0)
			{
				x = rand() % 900;
			}
			y = rand() % 1000;

			while (y % 50 != 0 && y != 0)
			{

				y = rand() % 900;
			}
		}

		if (playerNo == 2)
		{
			x = (rand() % 1000);
			while (x % 50 != 0 && x != 0)
			{
				x = rand() % 900;
			}

			y = rand() % 1000;

			while (y % 50 != 0 && y != 0)
			{
				y = rand() % 900;
			}
			x = x + 1200;
		}
		

		cout << " CHECKING IF OBJECT IS ON A WALL: " << x << " " << y << endl;

		xoox = checkForSpace(x, y, playerNo);
	}

	m_Position.x = x + 30;
	m_Position.y = y + 30;

	cout << m_Position.x << endl;
	cout << m_Position.y << endl;

	xoox = false;

	startingPoint = arena.width + arena.left;
	startingPoint2 = arena.height + arena.top;

	// Copy the details of the arena to the player's m_Arena 
	m_Arena.left = arena.left;
	m_Arena.width = arena.width;
	m_Arena.top = arena.top;
	m_Arena.height = arena.height;

	// Strore the resolution for future use
	m_Resolution.x = resolution.x;
	m_Resolution.y = resolution.y; 
}

void Player::setHealth(int health)
{
	m_Health = health;
}

void Player::setAttack(int num)
{
	attack = num;
}

void Player::setDefence(int num)
{
	defence = num;
}

void Player::setKey(bool k)
{
	key = k;
}

int Player::getAttack()
{
	return attack;
}

int Player::getDefence()
{
	return defence;
}

bool Player::getKey()
{
	return key;
}

FloatRect Player::getPosition()
{
	return m_Sprite.getGlobalBounds();
}

Vector2f Player::getCenter()
{
	return m_Position;
}

float Player::getRotation()
{
	return m_Sprite.getRotation();
}

Sprite Player::getSprite()
{
	return m_Sprite;
}

int Player::getHealth()
{
	return m_Health;
}

void Player::moveLeft()
{
	m_LeftPressed = true;
}

void Player::moveRight()
{
	m_RightPressed = true;
}

void Player::moveUp()
{
	m_UpPressed = true;
}

void Player::moveDown()
{
	m_DownPressed = true;
}

void Player::stopLeft()
{
	m_LeftPressed = false;
}

void Player::stopRight()
{
	m_RightPressed = false;
}

void Player::stopUp()
{
	m_UpPressed = false;
}

void Player::stopDown()
{
	m_DownPressed = false;
}

void Player::update(float elapsedTime, int playerNo)
{
	// Player moving up
	if (m_UpPressed == true && iUp < 1)
	{
		m_Position.y = m_Position.y - m_TileSize;
		iUp++;
		cout << m_Position.y << endl;
		colisions(1, playerNo);
	}

	if (m_UpPressed == false && iUp == 1)
	{
		iUp = 0;
	}
	// Player moving down

	if (m_DownPressed == true && iDown < 1)
	{
		m_Position.y = m_Position.y + m_TileSize;
		iDown++;
		colisions(2, playerNo);
	}
	if (m_DownPressed == false && iDown == 1)
	{
		iDown = 0;
	}
	// Player moving right

	if (m_RightPressed == true && iRight < 1)
	{
		m_Position.x = m_Position.x + m_TileSize;
		iRight++;
		cout << m_Position.x  << endl;
		colisions(3, playerNo);
	}
	if (m_RightPressed == false && iRight == 1)
	{
		iRight = 0;
	}

	//Player Moving left
	if (m_LeftPressed == true && iLeft < 1)
	{
		m_Position.x = m_Position.x - m_TileSize;
		colisions(4, playerNo);

		iLeft++;
	}
	if (m_LeftPressed == false && iLeft == 1)
	{
		iLeft = 0;
	}

	m_Sprite.setPosition(m_Position);

	// Keep the player in the the arena
	 
	if (m_Position.x > startingPoint - m_TileSize)
	{
		m_Position.x = startingPoint - 70;
	}
	if (m_Position.x < m_Arena.left + m_TileSize)
	{
		m_Position.x = m_Arena.left + 80;
	}
	if (m_Position.y > startingPoint2 - m_TileSize)
	{
		m_Position.y = startingPoint2 - 70;
	}
	if (m_Position.y < m_Arena.top + m_TileSize)
	{
		m_Position.y = m_Arena.top + 80;
	}
}

void Player::colisions(int direction, int playerNo)
{
	colisionX = m_Position.x / 50;
	colisionY = m_Position.y / 50;
	playerWallColision(colisionX, colisionY, direction, playerNo);
}

bool Player::playerWallColision(float x, float y, int direction, int playerNo)
{
	int xx = x;
	int xy = y;

	if (playerNo == 1)
	{
		if (wallColision[xx][xy] == 0 && direction == 1)
		{
			m_Position.y = m_Position.y + m_TileSize;
		}
		if (wallColision[xx][xy] == 0 && direction == 2)
		{
			m_Position.y = m_Position.y - m_TileSize;
		}
		if (wallColision[xx][xy] == 0 && direction == 3)
		{
			m_Position.x = m_Position.x - m_TileSize;
		}
		if (wallColision[xx][xy] == 0 && direction == 4)
		{
			m_Position.x = m_Position.x + m_TileSize;
		}
		else if (wallColision[xx][xy] == 1)
		{

		}
	}
	if (playerNo == 2)
	{
		if (wallColision2[xx][xy] == 0 && direction == 1)
		{
			m_Position.y = m_Position.y + m_TileSize;	
		}
		if (wallColision2[xx][xy] == 0 && direction == 2)
		{
			m_Position.y = m_Position.y - m_TileSize;
		}
		if (wallColision2[xx][xy] == 0 && direction == 3)
		{
			m_Position.x = m_Position.x - m_TileSize;	
		}
		if (wallColision2[xx][xy] == 0 && direction == 4)
		{
			m_Position.x = m_Position.x + m_TileSize;
		}
		else if(wallColision2[xx][xy] == 1)
		{
			
		}
	}
	return true; 
}

bool Player::checkForSpace(float x, float y, int playerNo)
{
	int xxy = x / 50;
	int yxy = y / 50;

	arrayCreation();

	cout << " MADE IT TO HERE" << endl;

	if (playerNo == 1)
	{ 
		if (wallColision[xxy][yxy] == 1)
		{
			cout << " the x and y value: " << wallColision[xxy][yxy];
			cout << " PLAYER 1 IS ON SAFE SPACE" << endl;
			cout << " there is no wall here" << endl;
			return true;
		}
		else
		{
			cout << " the x and y value: " << wallColision[xxy][yxy];
			//wallColision[xxy][yxy];
			cout << " YO YOU ON A WALL: PLAYER 1 " << endl;
			cout << " returning false" << endl;
			return false;
		}
	}

	if (playerNo == 2)
	{
		if (wallColision2[xxy][yxy] == 1)
		{
			cout << " the x and y value: " << wallColision2[xxy][yxy];
			cout << " PLAYER 2 IS ON SAFE SPACE" << endl;
			cout << " returning true" << endl;
			return true;
		}
		else
		{
			cout << " the x and y value: " << wallColision2[xxy][yxy];
			cout << " YO YOU ON A WALL: PLAYER 2 " << endl;
			return false;
		}
	} 
}

void Player::arrayCreation( )
{
	int xxo = getMaze();
	if (xxo == 1)
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
					wallColision[x][y] = true;
				}
				else
				{
					wallColision[x][y] = false;
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
					wallColision2[a][b] = true;
				}
				else
				{
					wallColision2[a][b] = false;
				}
			}
		}
	}

	if (xxo == 2)
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
					wallColision[x][y] = true;
				}
				else
				{
					wallColision[x][y] = false;
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
					wallColision2[a][b] = true;
				}
				else
				{
					wallColision2[a][b] = false;
				}
			}
		}
	}
	if (xxo == 3)
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
					wallColision[x][y] = true;
				}
				else
				{
					wallColision[x][y] = false;
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
					wallColision2[a][b] = true;
				}
				else
				{
					wallColision2[a][b] = false;
				}
			}
		}
	}
	if (xxo == 4)
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
					wallColision[x][y] = true;
				}
				else
				{
					wallColision[x][y] = false;
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
					wallColision2[a][b] = true;
				}
				else
				{
					wallColision2[a][b] = false;
				}
			}
		}
	}
	if (xxo == 5)
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
					wallColision[x][y] = true;
				}
				else
				{
					wallColision[x][y] = false;
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
					wallColision2[a][b] = true;
				}
				else
				{
					wallColision2[a][b] = false;
				}
			}
		}
	}
}

void Player::setMaze(int mazeNo)
{
	mazeNumb = mazeNo;
}

int Player::getMaze()
{
	return mazeNumb;
}
void Player::setCoins(int coin)
{
	coins = coin;
}

int Player::getCoins()
{
	return coins;
}