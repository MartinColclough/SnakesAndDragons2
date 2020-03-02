/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#pragma once
#include <SFML/Graphics.hpp>


using namespace sf;

class Player
{
private:
	const float START_SPEED = 200;
	const float START_HEALTH = 100;
	const int Start_Coin = 0;

	int attack;
	int defence;
	bool key;

	// Where is the player
	Vector2f m_Position;

	// Of course we will need a sprite
	
	// What is the screen resolution
	Vector2f m_Resolution;

	// What size is the current arena
	IntRect m_Arena;

	// How big is each tile of the arena
	int m_TileSize;

	// Which directions is the player currently moving in
	bool m_UpPressed;
	bool m_DownPressed;
	bool m_LeftPressed;
	bool m_RightPressed;

	// How much health has the player got?
	int m_Health;
	// What is the maximum health the player can have
	int m_MaxHealth;

	// When was the player last hit
	Time m_LastHit;

	// Speed in pixels per second
	float m_Speed;

	// variables that incrament everytime a button is pressed then get reset when button is relesed 
	int iUp = 0;
	int iDown = 0;
	int iLeft = 0;
	int iRight = 0;

	int coins;
	// All our public functions will come next


	//String fileName;
	//String fileName2;
	
	float colisionX;
	float colisionY;


	bool wallColision[20][20];
	bool wallColision2[44][20];


	int startingPoint;
	int startingPoint2;

	char counter1[20][20];
	char counter2[44][20];

	bool xoox = false;
public:

	Player();

	//function to spawn the player
	void spawn(IntRect arena, Vector2f resolution, int playerNo);

	// Handle the player getting hit by a zombie
	bool hit(Time timeHit);

	//set the players health
	void setHealth(int health);

	// set the players attack level
	void setAttack(int num);

	//set the players defence level
	void setDefence(int num);

	//set whether the player has a key
	void setKey(bool k);

	// what is the players current attack level?
	int getAttack();

	// what is the players current defence level?
	int getDefence();

	// does the player currently have a key
	bool getKey();

	// How long ago was the player last hit
	Time getLastHitTime();

	// Where is the player
	FloatRect getPosition();

	// Where is the center of the player
	Vector2f getCenter();

	// Which angle is the player facing
	float getRotation();

	// Send a copy of the sprite to main
	Sprite getSprite();

	Sprite m_Sprite;
	// And a texture
	// !!Watch this space!!
	Texture m_Texture;

	// How much health has the player currently got?
	int getHealth();

	// The next four functions move the player
	void moveLeft();

	void moveRight();

	void moveUp();

	void moveDown();

	// Stop the player moving in a specific direction
	void stopLeft();

	void stopRight();

	void stopUp();
	 
	void stopDown();

	// We will call this function once every frame
	void update(float elapsedTime, int playerNo);

	// check if player is walking into a wall
	bool playerWallColision(float x, float y, int direction, int playerNo);

	// checks if the space is available to spawn the player in
	bool checkForSpace(float x, float y, int playerNo);

	// creates a 2d array
	void arrayCreation();

	//calculates random position for the player to spawn
	int randomPosition(int playerNo);

	// set the amount of coins the player has
	void setCoins(int coins);

	// gets the value of the player coins
	int getCoins();

	void colisions(int direction, int playerNo);

	int mazeNumb = 2;

	void setMaze(int mazeNo);
	int getMaze();



};

