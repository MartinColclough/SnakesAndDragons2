/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PickupObjects
{

private:

	// The sprite that represents this pickup
	Sprite m_Sprite;

	// type of pick of pick up it is 
	int m_Type;

	//is it spawned 
	bool m_Spawned;

	// The arena it exists in
	IntRect m_Arena;

	int seconds_to_spawn = 5;

	Texture coin;
	Texture dragon;
	Texture snake;
	Texture zoom;
	Texture inkAttack;
	Texture rotate;
	Texture door;
	Texture slow;
	Texture slowAttack;
	Texture shop;
	Texture trap;
	Texture trapAttack;
	Texture moneyBag;
	Texture moveWall;

	bool objectColision[20][20];
	bool objectColision2[44][20];


	int startingPoint;
	int startingPoint2;

	char counter1[20][20];
	char counter2[44][20];

	bool objectPosition = false;

	int cc = 0;
public:

	PickupObjects(int type);

	//void Pickup(int type);

	// Prepare a new pickup
	void setArena(IntRect arena);

	void spawn();
	void spawn2();

	// Check the position of a pickup
	FloatRect getPosition();

	// Get the sprite for drawing
	Sprite getSprite();

	// Let the pickup update itself each frame
	void update(float elapsedTime);

	// Is this pickup currently spawned?
	bool isSpawned();

	// Get the goodness from the pickup
	int gotIt();

	void arrayCreation();

	// check if the coins are spawning on the wall or not
	bool checkForEmptySpace(int x, int y, int OneTwo);

	bool checkObject();

	int mazeNumb = 2;

	void setMaze(int mazeNo);
	int getMaze();

};

