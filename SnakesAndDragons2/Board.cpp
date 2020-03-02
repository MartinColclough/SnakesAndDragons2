/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

//make a new pickup called moveWalls and in the .intersects() forLoops
//state = State::LEVEL_LOADING;

#include <SFML/Graphics.hpp>
#include "CameraView.h"
#include "Board.h"
#include <sstream>
#include "Player.h"
#include "Dice.h"
#include "PickupObjects.h"
#include "Walls.h"
#include "HUD.h"
#include "TextureANDSprites.h"
#include <Windows.h>
#include "MazeSelection.h"
#include <iostream>
#include <SFML/Audio.hpp>

using namespace sf;
using namespace std;
int main()
{
	srand(time(NULL));
	// The game will always be in one of four states
	enum class State { PAUSED, LEVEL_LOADING, LEVEL_LOADING2, GAME_OVER, PLAYING, START_UP, DRAGON, SNAKE, READY_UP, MENU, RULES, DRAGONATTACK, SNAKEATTACK, SHOP, INK };
	
	// Start with the GAME_OVER state
	State state = State::START_UP;
	State state2 = State::START_UP;

	// Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	// Create a an SFML View for the main action
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Snakes and Dragons 2", Style::Fullscreen);
	CameraView camView;

	// creating view for player 1 and player 2 
	sf::View view(sf::FloatRect(0, 0, resolution.x / 2, resolution.y));
	sf::View view1(sf::FloatRect(0, 0, resolution.x / 2, resolution.y));

	//setting the size and position for player one
	view.setViewport(sf::FloatRect(0.02f, 0.02f, 0.46f, 0.7f));
	view.setSize(resolution.x / 2, resolution.y);


	//setting the size and position for player two
	view1.setViewport(sf::FloatRect(0.52f, 0.02f, 0.46f, 0.7f));
	view1.setSize(resolution.x / 2, resolution.y);

	//sf::Vector2f position(0,0);
	//zoom for the for views
	view.zoom(0.4f);
	view1.zoom(0.4f);

	//creating the mazeCreation Object
	MazeSelection mazeCreation;

	sf::View viewHUD(sf::FloatRect(0, 0, resolution.x, resolution.y));


	// Here is our clock for timing everything
	Clock clock;
	// How long has the PLAYING state been active
	Time gameTimeTotal;

	// Create an instance of the Player class
	Player player;
	Player player2;

	mazeCreation.createMazeForPlayer1();
	mazeCreation.createMazeForPlayer2();

	//Creating the dice Object
	Dice dice;
	Dice dice2;

	//add new pickupObjects to place on the board, the number in the brackets decide what sprite will go onto them
	PickupObjects coin(1);
	PickupObjects dragon(2);
	PickupObjects snake(3);
	PickupObjects zoom(4);
	PickupObjects inkAttack(5);
	PickupObjects rotate(6);
	PickupObjects door(7);
	PickupObjects slow(8);
	PickupObjects slowAttack(9);
	PickupObjects shop(10);
	PickupObjects trap(11);
	PickupObjects trapAttack(12);
	PickupObjects moneyBag(13);
	PickupObjects moveWall(14);

	//add new vectors to hold these PickupObjects so you can have multiple of each on the board at one time
	vector<PickupObjects> coins;
	vector<PickupObjects> dragons;
	vector<PickupObjects> snakes;
	vector<PickupObjects> zooms;
	vector<PickupObjects> inkAttacks;
	vector<PickupObjects> rotates;
	vector<PickupObjects> doors;
	vector<PickupObjects> slows;
	vector<PickupObjects> slowAttacks;
	vector<PickupObjects> shops;
	vector<PickupObjects> traps;
	vector<PickupObjects> trapAttacks;
	vector<PickupObjects> moneyBags;
	vector<PickupObjects> moveWalls;

	//set the price of the items in the shop
	int keyPrice = 100;
	int healthPotionPrice = 10;
	int attackLevelPrice = 15;
	int defenceLevelPrice = 15;

	//These values will decide how many of each objects the boards will contain. However many of each object you want, double it so they are on both boards
	int numCoins = 20;
	int numDragons = 6;
	int numSnakes = 6;
	int numZooms = 2;
	int numInkAttacks = 2;
	int numRotates = 2;
	int numDoors = 2;
	int numSlows = 2;
	int numSlowAttacks = 2;
	int numShops = 2;
	int numTraps = 0;
	int numTrapAttacks = 2;
	int numMoneyBags = 2;
	int numMoveWalls = 2;

	int totalDamage = 0;	//decide the total damage dealt, this will be calculated later while taking the players attack & defence levels aswell as the monster strength into account
	int dragonDamage = 12;	//decide the strength of the dragon, this will be its max hit
	int snakeDamage = 5;	//decide the strength of the snake, this will be its max hit
	int healthPotionStrength = 15;	//decide how much health the health potion will heal	

	int dragonReward = 5;	//decide how much gold the dragon will award the player
	int snakeReward = 3;	//decide how much gold the snake will award the player
	int moneyBagReward = 5;	//decide how much gold the moneyBag will award the player

	int randomMovement = rand() % 4 + 1;	//decide which direction the title in the start screen will move

	//set all the of the directions to fault so that only one is chosen at any given time after the switch statement
	bool downLeft = false;	
	bool downRight = false;
	bool upRight = false;
	bool upLeft = false;

	//here use the randomMovement variable to decide which direction the title will move to begin with
	switch (randomMovement)
	{
	case 1: downLeft = true; break;
	case 2: downRight = true; break;
	case 3: upRight = true; break;
	case 4: upLeft = true; break;
	}

	//int damageTaken = ((dragonDamage - (rand() % player2.getDefence() + 1)) * 10);
	//int damageTaken2 = ((snakeDamage - (rand() % player.getDefence() + 1)) * 10);

	Walls walls;
	Walls walls2;

	HUD gameHUD;

	gameHUD.ViewOutline();
	gameHUD.GameText(resolution);

	//place the coins into their appropriate vector
	for (int i = 0; i < numCoins; i++)
	{
		coins.push_back(coin);
	}

	//place the dragon into their appropriate vector
	for (int i = 0; i < numDragons; i++)
	{
		dragons.push_back(dragon);
	}

	//place the snakes into their appropriate vector
	for (int i = 0; i < numSnakes; i++)
	{
		snakes.push_back(snake);
	}
	
	//place the zooms into their appropriate vector
	for (int i = 0; i < numZooms; i++)
	{
		zooms.push_back(zoom);
	}

	//place the InkAttacks into their appropriate vector
	for (int i = 0; i < numInkAttacks; i++)
	{
		inkAttacks.push_back(inkAttack);
	}

	//place the rotates into their appropriate vector
	for (int i = 0; i < numRotates; i++)
	{
		rotates.push_back(rotate);
	}

	//place the doors into their appropriate vector
	for (int i = 0; i < numDoors; i++)
	{
		doors.push_back(door);
	}

	//place the slows into their appropriate vector
	for (int i = 0; i < numSlows; i++)
	{
		slows.push_back(slow);
	}

	//place the slowAttacks into their appropriate vector
	for (int i = 0; i < numSlowAttacks; i++)
	{
		slowAttacks.push_back(slowAttack);
	}

	//place the shops into their appropriate vector
	for (int i = 0; i < numShops; i++)
	{
		shops.push_back(shop);
	}

	//place the traps into their appropriate vector
	for (int i = 0; i < numTrapAttacks; i++)
	{
		trapAttacks.push_back(trapAttack);
	}

	//place the moneyBags into their appropriate vector
	for (int i = 0; i < numMoneyBags; i++)
	{
		moneyBags.push_back(moneyBag);
	}

	//place the moveWalls into their appropriate vector
	for (int i = 0; i < numMoveWalls; i++)
	{
		moveWalls.push_back(moveWall);
	}

	//initialise the variables which decide the length of the events such as zooms, rotates, slows, etc
	int zoomTimer = 0;
	int zoomTimer2 = 0;
	int rotateTimer = 0;
	int rotateTimer2 = 0;
	int slowTimer = 0;
	int slowTimer2 = 0;
	int inkTimer = 0;
	int inkTimer2 = 0;

	//initialise the variables which decide whether or not the events such as zooms, rotates, slows, etc are currently in effect
	bool zoomBool = false;
	bool zoomBool2 = false;
	bool rotateBool = false;
	bool rotateBool2 = false;
	bool slowBool = false;
	bool slowBool2 = false;
	bool inkBool = false;
	bool inkBool2 = false;
	bool exit1 = false;
	bool exit2 = false;

	// The boundaries of the arena
	IntRect arena;
	IntRect arena2;

	//creating the Texture and Sprites Object
	TextureANDSprites TandS;
	TandS.CreateTExturesAndSprites(resolution);

	// loading texture from file
	TandS.textur1.loadFromFile("graphics/player1.png");
	TandS.textur2.loadFromFile("graphics/player2.png");
	//TandS.textur2.loadFromFile("graphics/player2Walk.png");
	TandS.textur1Flip.loadFromFile("graphics/player1Flip.png");
	TandS.textur2Flip.loadFromFile("graphics/player2Flip.png");
	TandS.textur1Back.loadFromFile("graphics/player1Back.png");
	TandS.textur2Back.loadFromFile("graphics/player2Back.png");

	//assigning texture to the players 
	player.m_Sprite.setTexture(TandS.textur1);
	player2.m_Sprite.setTexture(TandS.textur2);

	//Sound Buffers
	//coin
	SoundBuffer coinBuffer;
	coinBuffer.loadFromFile("sound/pickupCoin.wav");
	Sound coinPickup;
	coinPickup.setBuffer(coinBuffer);
	coinPickup.setVolume(10.0f);

	//move
	SoundBuffer moveBuffer;
	moveBuffer.loadFromFile("sound/move.wav");
	Sound move;
	move.setBuffer(moveBuffer);
	move.setVolume(.2f);

	//money bag buffer
	SoundBuffer mbBuffer;
	mbBuffer.loadFromFile("sound/mbSound.wav");
	Sound mb;
	mb.setBuffer(mbBuffer);
	mb.setVolume(1000.0f);

	//snake buffer
	SoundBuffer snakeBuffer;
	snakeBuffer.loadFromFile("sound/snakeHiss.wav");
	Sound snakeHiss;
	snakeHiss.setBuffer(snakeBuffer);
	snakeHiss.setVolume(10.0f);

	//dragon buffer
	SoundBuffer dragonBuffer;
	dragonBuffer.loadFromFile("sound/dragon.wav");
	Sound dragonRoar;
	dragonRoar.setBuffer(dragonBuffer);
	dragonRoar.setVolume(40.0f);

	//gameOver buffer
	SoundBuffer gameOverBuffer;
	gameOverBuffer.loadFromFile("sound/gameOver.wav");
	Sound gameOver;
	gameOver.setBuffer(gameOverBuffer);
	gameOver.setVolume(10.0f);

	//Prepare the background music
	Music music;
	if (!music.openFromFile("sound/backgroundMusic.wav"))
	{
		return -1;
	}

	music.setPitch(1.0f);
	music.setVolume(1.0f);
	music.setLoop(true);
	////play background music while the game is open
	music.play();
	int direction = 0;
	// The main game loop
	while (window.isOpen())
	{
		//Handle events
		Event event;
		while (window.pollEvent(event))
		{
			//Allow for user input, depending on the current state
			if (event.type == Event::KeyPressed || event.type == Event::JoystickButtonPressed)
			{
				//Restart the game at any time if the players press either 'Enter' or 'Backup'
				if ((event.key.code == Keyboard::Return || Joystick::isButtonPressed(0, 6) || Joystick::isButtonPressed(1, 6)))
				{
					state = State::START_UP;
					state2 = State::START_UP;
				}

				//Check if the game is currently in the game_over state
				else if (state == State::GAME_OVER && state2 == State::GAME_OVER)
				{
					//reset all of the players stats
					player.setHealth(100);
					player2.setHealth(100);
					player.setCoins(0);
					player2.setCoins(0);
					player.setKey(0);
					player2.setKey(0);

					//clear all of the vector holding the objects on the board, preparing them for the next game
					coins.clear();
					dragons.clear();
					snakes.clear();
					zooms.clear();
					//inkAttacks.clear();
					rotates.clear();
					doors.clear();
					slows.clear();
					slowAttacks.clear();
					shops.clear();
					traps.clear();
					trapAttacks.clear();
					moneyBags.clear();
					moveWalls.clear();

					//place the coins into their appropriate vector
					for (int i = 0; i < numCoins; i++)
					{
						coins.push_back(coin);
					}
					
					//place the dragons into their appropriate vector
					for (int i = 0; i < numDragons; i++)
					{
						dragons.push_back(dragon);
					}
					
					//place the snakes into their appropriate vector
					for (int i = 0; i < numSnakes; i++)
					{
						snakes.push_back(snake);
					}
					
					//place the zooms into their appropriate vector
					for (int i = 0; i < numZooms; i++)
					{
						zooms.push_back(zoom);
					}

					//place the inkAttacks into their appropriate vector
					for (int i = 0; i < numInkAttacks; i++)
					{
						inkAttacks.push_back(inkAttack);
					}

					//place the rotates into their appropriate vector
					for (int i = 0; i < numRotates; i++)
					{
						rotates.push_back(rotate);
					}

					//place the doors into their appropriate vector
					for (int i = 0; i < numDoors; i++)
					{
						doors.push_back(door);
					}

					//place the slows into their appropriate vector
					for (int i = 0; i < numSlows; i++)
					{
						slows.push_back(slow);
					}

					//place the slowAttacks into their appropriate vector
					for (int i = 0; i < numSlowAttacks; i++)
					{
						slowAttacks.push_back(slowAttack);
					}

					//place the shops into their appropriate vector
					for (int i = 0; i < numShops; i++)
					{
						shops.push_back(shop);
					}

					//place the trapAttacks into their appropriate vector
					for (int i = 0; i < numTrapAttacks; i++)
					{
						trapAttacks.push_back(trapAttack);
					}

					//place the moneyBags into their appropriate vector
					for (int i = 0; i < numMoneyBags; i++)
					{
						moneyBags.push_back(moneyBag);
					}

					for (int i = 0; i < numMoveWalls; i++)
					{
						moveWalls.push_back(moveWall);
					}

					//if the game is over and the user is prompted with input, if the they press '1' or 'A' then play the game again
					if (event.key.code == Keyboard::Num1 || event.key.code == Keyboard::Numpad1  || Joystick::isButtonPressed(0, 0) || Joystick::isButtonPressed(1, 0)) {
						//needs to be startup
						state = State::LEVEL_LOADING;
						state2 = State::LEVEL_LOADING;
					}

					//if the game is over and the user is prompted with input, if the they press '2' or 'X' then return to the menu
					if (event.key.code == Keyboard::Num2 || event.key.code == Keyboard::Numpad2 || Joystick::isButtonPressed(0, 2) || Joystick::isButtonPressed(1, 2)) {
						//needs to be startup
						state = State::MENU;
						state2 = State::MENU;
					}
				}

				//if the current state is START_UP, if the they press 'Enter' or 'A' then go to menu
				if ((event.key.code == Keyboard::Return || Joystick::isButtonPressed(0, 0) || Joystick::isButtonPressed(1, 0)) && state == State::START_UP && state2 == State::START_UP)
				{
					Sleep(200);
					state = State::MENU;
					state2 = State::MENU;
				}
				
				//if the current state is MENU, if player1 presses '1' or 'A' then start the game
				else if ((event.key.code == Keyboard::Num1 || Joystick::isButtonPressed(0, 0) || Joystick::isButtonPressed(1, 0)) && state == State::MENU)
				{
					state = State::LEVEL_LOADING;
					state2 = State::LEVEL_LOADING;
				}

				//if the current state is RULES, if player1 presses '2' or 'X' then return to menu
				if ((event.key.code == Keyboard::Num2 || Joystick::isButtonPressed(0, 2) || Joystick::isButtonPressed(1, 2)) && state == State::MENU)
				{
					state = State::RULES;
				}

				//if the current state is RULES, if player1 presses '2' or 'X' then return to menu
				else if ((event.key.code == Keyboard::Num2 || Joystick::isButtonPressed(0, 2) || Joystick::isButtonPressed(1, 2)) && state == State::RULES)
				{
					state = State::MENU;
				}

				//if the current state is RULES, if player1 presses '1' or 'A' then start the game
				if ((event.key.code == Keyboard::Num1 || Joystick::isButtonPressed(0, 0) || Joystick::isButtonPressed(1, 0)) && state == State::RULES)
				{
					state = State::LEVEL_LOADING;
					state2 = State::LEVEL_LOADING;
				}

				//if the current state is LEVEL_LOADING, if the they press 'Enter' or 'Backup' then start the game
				if ((event.key.code == Keyboard::Return || Joystick::isButtonPressed(0, 10) || Joystick::isButtonPressed(1, 10)) && state == State::LEVEL_LOADING && state2 == State::LEVEL_LOADING)
				{
					state = State::PLAYING;
					state2 = State::PLAYING;
				}
				
				//if the current state is SNAKE, if player1 presses '1' or 'A' then go to SNAKEATTACK
				if ((event.key.code == Keyboard::Num1 || Joystick::isButtonPressed(0, 0)) && state == State::SNAKE) {
					state = State::SNAKEATTACK;
				}

				//if the current state is SNAKE, if player1 presses '2' or 'X' then send the snake to player2 and player1 returns to the board
				if ((event.key.code == Keyboard::Num2 || Joystick::isButtonPressed(0, 2)) && state == State::SNAKE) {
					state = State::PLAYING;
					state2 = State::SNAKEATTACK;
				}

				//if the current state is SNAKE, if player1 presses '3' or 'B' then return to the board
				if ((event.key.code == Keyboard::Num3 || Joystick::isButtonPressed(0, 1)) && state == State::SNAKE) {
					state = State::PLAYING;
				}

				//if the current state is SNAKEATTACK, if player1 presses 'Space' or 'A' fight the snake and set players health / reward coins
				if ((event.key.code == Keyboard::Space || Joystick::isButtonPressed(0, 0)) && state == State::SNAKEATTACK) {
					totalDamage = (((rand() % snakeDamage + 1) + ((rand() % player.getDefence()) - rand() % player2.getAttack())) * (rand() & 5 + 1));
					if (totalDamage < 0)
						totalDamage = 0;
					player.setHealth(player.getHealth() - totalDamage);
					player.setCoins(player.getCoins() + rand() % snakeReward + 1);
					state = State::PLAYING;
				}
				
				//if the current state is SNAKE, if player2 presses '1' or 'A' then go to SNAKEATTACK
				if ((event.key.code == Keyboard::Numpad1 || Joystick::isButtonPressed(1, 0)) && state2 == State::SNAKE) {
					state2 = State::SNAKEATTACK;
				}

				//if the current state is SNAKE, if player2 presses '2' or 'X' then send the snake to player1 and player2 returns to the board
				if ((event.key.code == Keyboard::Numpad2 || Joystick::isButtonPressed(1, 2)) && state2 == State::SNAKE) {
					state = State::SNAKEATTACK;
					state2 = State::PLAYING;
				}

				//if the current state is SNAKE, if player2 presses '3' or 'B' then return to the board
				if ((event.key.code == Keyboard::Numpad3 || Joystick::isButtonPressed(1, 1)) && state2 == State::SNAKE) {
					state2 = State::PLAYING;
				}

				//if the current state is SNAKEATTACK, if player2 presses 'Space' or 'A' fight the snake and set players health / reward coins
				if ((event.key.code == Keyboard::Space || Joystick::isButtonPressed(1, 0)) && state2 == State::SNAKEATTACK) {
					totalDamage = (((rand() % snakeDamage + 1) + ((rand() % player2.getDefence()) - rand() % player.getAttack())) * (rand() & 5 + 1));
					if (totalDamage < 0)
						totalDamage = 0;
					player2.setHealth(player2.getHealth() - totalDamage);
					player.setCoins(player.getCoins() + rand() % snakeReward + 1);
					state2 = State::PLAYING;
				}

				//if the current state is DRAGON, if player1 presses '1' or 'A' then go to DRAGONATTACK
				if ((event.key.code == Keyboard::Num1 || Joystick::isButtonPressed(0, 0)) && state == State::DRAGON) {
					state = State::DRAGONATTACK;
				}

				//if the current state is DRAGON, if player1 presses '2' or 'B' then return to board
				if ((event.key.code == Keyboard::Num2 || Joystick::isButtonPressed(0, 1)) && state == State::DRAGON) {
					state = State::PLAYING;
				}

				//if the current state is DRAGONATTACK, if player1 presses 'Space' or 'A' fight the Dragon and set players health / reward coins
				if ((event.key.code == Keyboard::Space || Joystick::isButtonPressed(0, 0)) && state == State::DRAGONATTACK) {
					totalDamage = (((rand() % dragonDamage + 1) + ((rand() % player.getDefence()) - rand() % player2.getAttack())) * (rand() & 5 + 1));
					if (totalDamage < 0)
						totalDamage = 0;
					player.setHealth(player.getHealth() - totalDamage);
					player.setCoins(player.getCoins() + rand() % dragonReward + 1);
					state = State::PLAYING;
				}

				//if the current state is DRAGON, if player2 presses '1' or 'A' then go to DRAGONATTACK
				if ((event.key.code == Keyboard::Numpad1 || Joystick::isButtonPressed(1, 0)) && state2 == State::DRAGON) {
					state2 = State::DRAGONATTACK;
				}

				//if the current state is DRAGON, if player2 presses '2' or 'B' then return to board
				if ((event.key.code == Keyboard::Numpad2 || Joystick::isButtonPressed(1, 1)) && state2 == State::DRAGON) {
					state2 = State::PLAYING;
				}

				//if the current state is DRAGONATTACK, if player2 presses 'Space' or 'A' fight the Dragon and set players health / reward coins
				if ((event.key.code == Keyboard::Space || Joystick::isButtonPressed(1, 0)) && state2 == State::DRAGONATTACK) {
					totalDamage = (((rand() % dragonDamage + 1) + ((rand() % player2.getDefence()) - rand() % player.getAttack())) * (rand() & 5 + 1));
					if (totalDamage < 0)
						totalDamage = 0;
					player2.setHealth(player2.getHealth() - totalDamage);
					player2.setCoins(player2.getCoins() + rand() % dragonReward + 1);
					state2 = State::PLAYING;
				}

				//if the current state is SHOP, if player1 presses '1' or 'Y' purchase a key
				if ((event.key.code == Keyboard::Num1 || Joystick::isButtonPressed(0, 3)) && state == State::SHOP && player.getCoins() >= keyPrice) {
					player.setKey(true);
					player.setCoins(player.getCoins() - keyPrice);
				}

				//if the current state is SHOP, if player1 presses '4' or 'A' purchase a healthPotion, the player cant go above 100 health
				if ((event.key.code == Keyboard::Num3 || Joystick::isButtonPressed(0, 0)) && state == State::SHOP && player.getCoins() >= healthPotionPrice && player.getHealth() < 100) {
					player.setHealth(player.getHealth() + healthPotionStrength);
					if (player.getHealth() > 100)
						player.setHealth(100);
					player.setCoins(player.getCoins() - healthPotionPrice);
				}

				//if the current state is SHOP, if player1 presses '2' or 'B' purchase an Attack Level, the player cant go above 4 Attack
				if ((event.key.code == Keyboard::Num2 || Joystick::isButtonPressed(0, 1)) && state == State::SHOP && player.getCoins() >= attackLevelPrice && player.getAttack() < 4) {
					player.setAttack(player.getAttack() + 1);
					player.setCoins(player.getCoins() - attackLevelPrice);
				}

				//if the current state is SHOP, if player1 presses '3' or 'X' purchase a Defence Level, the player cant go above 4 Defence
				if ((event.key.code == Keyboard::Num4 || Joystick::isButtonPressed(0, 2)) && state == State::SHOP && player.getCoins() >= defenceLevelPrice && player.getDefence() < 4) {
					player.setDefence(player.getDefence() + 1);
					player.setCoins(player.getCoins() - defenceLevelPrice);
				}

				//if the current state is SHOP, if player2 presses '1' or 'Y' purchase a key
				if ((event.key.code == Keyboard::Numpad1 || Joystick::isButtonPressed(1, 3)) && state2 == State::SHOP && player2.getCoins() >= keyPrice) {
					player2.setKey(true);
					player2.setCoins(player2.getCoins() - keyPrice);
				}

				//if the current state is SHOP, if player2 presses '4' or 'A' purchase a healthPotion, the player cant go above 100 health
				if ((event.key.code == Keyboard::Numpad3 || Joystick::isButtonPressed(1, 0)) && state2 == State::SHOP && player2.getCoins() >= healthPotionPrice && player2.getHealth() < 100) {
					player2.setHealth(player2.getHealth() + healthPotionStrength);
					if (player2.getHealth() > 100)
						player2.setHealth(100);
					player2.setCoins(player2.getCoins() - healthPotionPrice);
				}

				//if the current state is SHOP, if player2 presses '3' or 'X' purchase a Defence Level, the player cant go above 4 Defence
				if ((event.key.code == Keyboard::Numpad2 || Joystick::isButtonPressed(1, 1)) && state2 == State::SHOP && player2.getCoins() >= attackLevelPrice && player2.getAttack() < 4) {
					player2.setAttack(player2.getAttack() + 1);
					player2.setCoins(player2.getCoins() - attackLevelPrice);
				}

				//if the current state is SHOP, if player12presses '3' or 'X' purchase a Defence Level, the player cant go above 4 Defence
				if ((event.key.code == Keyboard::Numpad4 || Joystick::isButtonPressed(1, 2)) && state2 == State::SHOP && player2.getCoins() >= defenceLevelPrice && player2.getDefence() < 4) {
					player2.setDefence(player2.getDefence() + 1);
					player2.setCoins(player2.getCoins() - defenceLevelPrice);
				}
			}
		}// End event polling

		 //If the player presses 'Escape' or 'Start' then close the game
		if (Keyboard::isKeyPressed(Keyboard::Escape) || Joystick::isButtonPressed(0, 7) || Joystick::isButtonPressed(1, 7))
		{
			window.close();
		}

		//add some variables to deal with the dpad of the controller, used for input
		unsigned int controller = event.joystickMove.joystickId;	//if controller is 0, its player1.. if its 1 then its player2
		Joystick::Axis controllerDPadId = event.joystickMove.axis;	//if the id is 6 then its either left or right, if its 7 its either up or down
		float controllerDPadAxis = event.joystickMove.position;		//if the axis is positive then its either up or right, if its negative then its either left or down

		//print details of button pressed in the console, made it easier to find the values that needed to be used
		if (controllerDPadId > 5 && controllerDPadId < 8)
		{
			cout << controller << "\t" << controllerDPadId << "\t" << controllerDPadAxis << " \t player 1" << endl;
		}

		// Handle controls while playing
		if (state == State::PLAYING)
		{
			
			//If player presses 'W' or 'DPadUp' then go up and change texture
			if ((Keyboard::isKeyPressed(Keyboard::W) || (controllerDPadId == 7 && controllerDPadAxis > 50) && controller == 0) && slowBool == false)
			{
				player.m_Sprite.setTexture(TandS.textur1Back);
				player.moveUp();
				move.play();
				
			}
			else
			{
				player.stopUp();
			}
			
			//If player presses 'S' or 'DPadDown' then go down and change texture
			if ((Keyboard::isKeyPressed(Keyboard::S) || (controllerDPadId == 7 && controllerDPadAxis < -50) && controller == 0) && slowBool == false)
			{
				player.moveDown();
				move.play();
				player.m_Sprite.setTexture(TandS.textur1);
			}
			else
			{
				player.stopDown();
			}

			//If player presses 'A' or 'DPadLeft' then go left and change texture
			if ((Keyboard::isKeyPressed(Keyboard::A) || (controllerDPadId == 6 && controllerDPadAxis < -50) && controller == 0) && slowBool == false)
			{
				player.m_Sprite.setTexture(TandS.textur1WalkFlip);
				player.moveLeft();
				move.play();	
				direction = 1;
			}
			else
			{		
				player.stopLeft();
				if (direction == 1)
				{
					
					player.m_Sprite.setTexture(TandS.textur1Flip);
				}
				else
				{
					player.m_Sprite.setTexture(TandS.textur1);
				}
			}

			//If player presses 'D' or 'DPadRight' then go right and change texture
			if ((Keyboard::isKeyPressed(Keyboard::D) || (controllerDPadId == 6 && controllerDPadAxis > 50) && controller == 0) && slowBool == false)
			{
				player.m_Sprite.setTexture(TandS.textur1Walk);
				player.moveRight();
				move.play();	
				direction = 2;
			}
			else
			{	
				player.stopRight();		
				if (direction == 2)
				{
					player.m_Sprite.setTexture(TandS.textur1);
				}
				else
				{
					player.m_Sprite.setTexture(TandS.textur1Flip);
				}
			}
			
			cout << direction << endl;

		}
		if (state2 == State::PLAYING)
		{
			//If player presses 'upArrow' or 'DPadUp' then go up and change texture
			if ((Keyboard::isKeyPressed(Keyboard::Up) || (controllerDPadId == 7 && controllerDPadAxis > 50) && controller == 1) && slowBool2 == false)
			{
				player2.moveUp();
				move.play();
				player2.m_Sprite.setTexture(TandS.textur2Back);
			}
			else
			{
				player2.stopUp();
			}

			//If player presses 'downArrow' or 'DPadDown' then go down and change texture
			if ((Keyboard::isKeyPressed(Keyboard::Down) || (controllerDPadId == 7 && controllerDPadAxis < -50) && controller == 1) && slowBool2 == false)
			{
				player2.moveDown();
				move.play();
				player2.m_Sprite.setTexture(TandS.textur2);
			}
			else
			{
				player2.stopDown();
			}

			//If player presses 'leftArrow' or 'DPadLeft' then go Left and change texture
			if ((Keyboard::isKeyPressed(Keyboard::Left) || (controllerDPadId == 6 && controllerDPadAxis < -50) && controller == 1) && slowBool2 == false)
			{
				player2.moveLeft();
				move.play();
				player2.m_Sprite.setTexture(TandS.textur2Flip);
			}
			else
			{
				player2.stopLeft();
			}

			//If player presses 'rightArrow' or 'DPadRight' then go right and change texture
			if ((Keyboard::isKeyPressed(Keyboard::Right) || (controllerDPadId == 6 && controllerDPadAxis > 50) && controller == 1) && slowBool2 == false)
			{
				player2.moveRight();
				move.play();
				player2.m_Sprite.setTexture(TandS.textur2);
			}
			else
			{
				player2.stopRight();
			}
		}// End WASD while playing

		//load the game
		if (state == State::LEVEL_LOADING || state2 == State::LEVEL_LOADING)
		{
			//this variable will be used to choose from a random wall file
			int RandMaze = rand() % 5 + 1;
			
			//players must have the same random map or collisions will not work properly 
			player.setMaze(RandMaze);
			player2.setMaze(RandMaze);
			walls.setMaze(RandMaze);

			/* DO NOT CHANGE THE SIZE OF THE MAP OR IT WILL BREAK THE CAMERA*/
			arena.width = 1000;
			arena.height = 1000;
			arena.left = 0;
			arena.top = 0;

			arena2.width = 1000;
			arena2.height = 1000;
			arena2.left = 1200;
			arena2.top = 0;

			// Pass the vertex array by reference 
			// to the createBackground function
			int tileSize = createBackground(TandS.background, arena);
			int tileSize2 = createBackground(TandS.background2, arena2);

			walls.bolWalls();
			walls.createWalls(TandS.vertexWalls, arena);

			walls.bolWalls2();
			walls.createWalls2(TandS.vertexWalls2, arena2);

			//spawn the coins for player1
			for (int i = 0; i < numCoins / 2; i++)
			{
				coins[i].setMaze(RandMaze);
				coins[i].setArena(arena);

			}

			//spawn the dragons for player1
			for (int i = 0; i < numDragons / 2; i++)
			{
				dragons[i].setMaze(RandMaze);
				dragons[i].setArena(arena);
				;
			}

			//spawn the snakes for player1
			for (int i = 0; i < numSnakes / 2; i++)
			{
				snakes[i].setMaze(RandMaze);
				snakes[i].setArena(arena);
			}

			//spawn the zooms for player1
			for (int i = 0; i < numZooms / 2; i++)
			{
				//snakes[i].setArena(arena);
				zooms[i].setMaze(RandMaze);
				zooms[i].setArena(arena);
			}

			//spawn the inkAttacks for player1
			for (int i = 0; i < numInkAttacks/2; i++)
			{
				inkAttacks[i].setMaze(RandMaze);
				inkAttacks[i].setArena(arena);
			}

			//spawn the rotates for player1
			for (int i = 0; i < numRotates / 2; i++)
			{
				rotates[i].setMaze(RandMaze);
				rotates[i].setArena(arena);
			}

			//spawn the doors for player1
			for (int i = 0; i < numDoors / 2; i++)
			{
				doors[i].setMaze(RandMaze);
				doors[i].setArena(arena);
			}

			//spawn the slows for player1
			for (int i = 0; i < numSlows / 2; i++)
			{
				slows[i].setMaze(RandMaze);
				slows[i].setArena(arena);
			}

			//spawn the slowAttacks for player1
			for (int i = 0; i < numSlowAttacks / 2; i++)
			{
				slowAttacks[i].setMaze(RandMaze);
				slowAttacks[i].setArena(arena);
			}

			//spawn the shops for player1
			for (int i = 0; i < numShops / 2; i++)
			{
				shops[i].setMaze(RandMaze);
				shops[i].setArena(arena);
			}

			//spawn the trapAttacks for player1
			for (int i = 0; i < numTrapAttacks / 2; i++)
			{
				trapAttacks[i].setMaze(RandMaze);
				trapAttacks[i].setArena(arena);
			}

			//spawn the moneyBags for player1
			for (int i = 0; i < numMoneyBags / 2; i++)
			{
				moneyBags[i].setMaze(RandMaze);
				moneyBags[i].setArena(arena);
			}

			//spawn the moveWalls for player1
			for (int i = 0; i < numMoveWalls / 2; i++)
			{
				moveWalls[i].setMaze(RandMaze);
				moveWalls[i].setArena(arena);
			}

			//spawn the coins for player2
			for (int i = numCoins / 2; i < numCoins; i++)
			{
				coins[i].setMaze(RandMaze);
				coins[i].spawn2();
			}

			//spawn the dragons for player2
			for (int i = numDragons / 2; i < numDragons; i++)
			{
				dragons[i].setMaze(RandMaze);
				dragons[i].spawn2();
			}

			//spawn the snakes for player2
			for (int i = numSnakes / 2; i < numSnakes; i++)
			{
				snakes[i].setMaze(RandMaze);
				snakes[i].spawn2();
			}

			//spawn the zooms for player2
			for (int i = numZooms / 2; i < numZooms; i++)
			{
				snakes[i].setMaze(RandMaze);
				zooms[i].spawn2();
			}

			//spawn the inkAttacks for player2
			for (int i = numInkAttacks/2; i < numInkAttacks; i++)
			{
				inkAttacks[i].setMaze(RandMaze);
				inkAttacks[i].spawn2();
			}

			//spawn the rotates for player2
			for (int i = numRotates / 2; i < numRotates; i++)
			{
				rotates[i].setMaze(RandMaze);
				rotates[i].spawn2();
			}
			
			//spawn the doors for player2
			for (int i = numDoors / 2; i < numDoors; i++)
			{
				doors[i].setMaze(RandMaze);
				doors[i].spawn2();
			}

			//spawn the slows for player2
			for (int i = numSlows / 2; i < numSlows; i++)
			{
				slows[i].setMaze(RandMaze);
				slows[i].spawn2();
			}

			//spawn the slowAttacks for player2
			for (int i = numSlowAttacks / 2; i < numSlowAttacks; i++)
			{
				slowAttacks[i].setMaze(RandMaze);
				slowAttacks[i].spawn2();
			}

			//spawn the shops for player2
			for (int i = numShops / 2; i < numShops; i++)
			{
				shops[i].setMaze(RandMaze);
				shops[i].spawn2();
			}
			
			//spawn the trapAttacks for player2
			for (int i = 0; i < numTrapAttacks / 2; i++)
			{
				trapAttacks[i].setMaze(RandMaze);
				trapAttacks[i].spawn2();
			}

			//spawn the moneyBags for player2
			for (int i = numMoneyBags / 2; i < numMoneyBags; i++)
			{
				moneyBags[i].setMaze(RandMaze);
				moneyBags[i].spawn2();
			}

			//spawn the moveWalls for player2
			for (int i = numMoveWalls / 2; i < numMoveWalls; i++)
			{
				moveWalls[i].setMaze(RandMaze);
				moveWalls[i].spawn2();
			}

			//spawn the players on the map
			player.spawn(arena, resolution, 1);
			player2.spawn(arena2, resolution, 2);

			//once everything has been loaded, start the game
			state = State::PLAYING;
			state2 = State::PLAYING;
		}// End load level
		 /*
		 ****************
		 UPDATE THE FRAME
		 ****************
		 */
		if (state == State::PLAYING)
		{
			// Update the delta time
			Time dt = clock.restart();
			// Update the total game time
			gameTimeTotal += dt;
			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();



			// Update the player
			player.update(dtAsSeconds, 1);

			Vector2f playerPosition(player.getCenter());

			view.setCenter(camView.controlPlayerCamera2(player.getCenter(), arena));
			//view1.setCenter(camView.controlPlayerCamera(player2.getCenter(),arena));

			//if player1 lands on a coin 
			for (int i = 0; i < numCoins / 2; i++)
			{
				if (player.getPosition().intersects(coins[i].getPosition()) && coins[i].isSpawned())
				{

					coins[i].gotIt();
					player.setCoins(player.getCoins() + 1);
					coinPickup.play();
					coins[i].spawn();
				}
			}

			//if player1 lands on a dragon
			for (int i = 0; i < numDragons / 2; i++)
			{
				if (player.getPosition().intersects(dragons[i].getPosition()) && dragons[i].isSpawned() /*&& player.getCoins() >= 5*/)
				{
					cout << player.getCoins() << endl;
					dragons[i].gotIt();
					//state = State::MENU;
					state = State::DRAGON;
					//state2 = State::PLAYING;
					dragonRoar.play();
					dragons[i].spawn();
				}
			}

			//if player1 lands on a snake
			for (int i = 0; i < numSnakes / 2; i++)
			{
				if (player.getPosition().intersects(snakes[i].getPosition()) && snakes[i].isSpawned())
				{
					snakes[i].gotIt();
					state = State::SNAKE;
					snakeHiss.play();
					snakes[i].spawn();
				}
			}

			//if player1 lands on a zoom
			for (int i = 0; i < numZooms / 2; i++)
			{
				if (player.getPosition().intersects(zooms[i].getPosition()) && zooms[i].isSpawned() && zoomBool == false)
				{
					zooms[i].gotIt();
					view.zoom(1.5f);
					zoomBool = true;
				}
			}

			//if they land on a zoom, start a counter
			if (zoomBool == true)
			{
				zoomTimer++;
			}

			//when the counter reaches a certain point, stop zooming
			if (zoomTimer >= 1000 + ((player.getAttack() - player2.getDefence()) * 300))
			{
				zoomBool = false;
				zoomTimer = 0;
				view.zoom(0.65f);
			}

			//if player1 lands on a inkAttack
			for (int i = 0; i < numInkAttacks / 2; i++)
			{
				if (player.getPosition().intersects(inkAttacks[i].getPosition()) && inkAttacks[i].isSpawned() && inkBool2 == false)
				{
					inkAttacks[i].gotIt();
					inkBool2 = true;
				}
			}

			//if they land on a inkAttack, start a counter
			if (inkBool2 == true)
			{
				inkTimer2++;
			}

			//when the counter reaches a certain point, stop the inkAttack
			if (inkTimer2 >= 500 + ((player.getAttack() - player2.getDefence()) * 300))
			{
				inkBool2 = false;
				inkTimer2 = 0;
				inkAttacks[0].spawn();
			}

			//if player1 lands on a rotate
			for (int i = 0; i < numRotates / 2; i++)
			{
				if (player.getPosition().intersects(rotates[i].getPosition()) && rotates[i].isSpawned() && rotateBool == false)
				{
					rotates[i].gotIt();
					view1.zoom(-1.0f);
					rotateBool = true;
				}
			}

			//if they land on a rotate, start a counter
			if (rotateBool == true)
			{
				rotateTimer++;
			}

			//when the counter reaches a certain point, stop rotating
			if (rotateTimer >= 1000 + ((player2.getAttack() - player.getDefence()) * 300))
			{
				rotateBool = false;
				rotateTimer = 0;
				view1.zoom(-1.0f);
				rotates[0].spawn();
			}

			//if player1 lands on a door
			for (int i = 0; i < numDoors / 2; i++)
			{
				if (player.getPosition().intersects(doors[i].getPosition()) && doors[i].isSpawned() && player.getKey() == true)
				{
					exit1 = true;
					state = State::GAME_OVER;
					state2 = State::GAME_OVER;
				}
			}

			//if player1 lands on a slow
			for (int i = 0; i < numSlows / 2; i++)
			{
				if (player.getPosition().intersects(slows[i].getPosition()) && slows[i].isSpawned())
				{
					slows[i].gotIt();
					slowBool = true;
					slows[i].spawn();
				}
			}

			//if they land on a slow, start a counter
			if (slowBool == true)
			{
				slowTimer++;
			}

			//when the counter reaches a certain point, stop slow
			if (slowTimer >= 1000 + ((player2.getAttack() - player.getDefence()) * 300))
			{
				slowBool = false;
				slowTimer = 0;
			}

			//if player1 lands on a slowAttack
			for (int i = 0; i < numSlowAttacks / 2; i++)
			{
				if (player.getPosition().intersects(slowAttacks[i].getPosition()) && slowAttacks[i].isSpawned())
				{
					/*int minusCoins = rand() % 10 + 1;*/

					slowAttacks[i].gotIt();
					slowBool2 = true;

					/*if (player2.getCoins() > 0)
					{
						player2.setCoins(player2.getCoins() - minusCoins);
						if (player2.getCoins() < 0)
							player.setCoins(0);
					}*/

					slowAttacks[i].spawn();
				}
			}

			//if they land on a slow, start a counter
			if (slowBool2 == true)
			{
				slowTimer2++;
			}

			//when the counter reaches a certain point, stop slow
			if (slowTimer2 >= 1000 + ((player.getAttack() - player2.getDefence()) * 300))
			{
				slowBool2 = false;
				slowTimer = 0;
			}

			//if player1 lands on a shop
			for (int i = 0; i < numShops / 2; i++)
			{
				if (player.getPosition().intersects(shops[i].getPosition()) && shops[i].isSpawned())
				{
					//shops[i].gotIt();
					state = State::SHOP;
				}
			}

			//if player1 lands on a trapAttack
			for (int i = 0; i < numTrapAttacks / 2; i++)
			{
				if (player.getPosition().intersects(trapAttacks[i].getPosition()) && trapAttacks[i].isSpawned())
				{
					trapAttacks[i].gotIt();
					//numTraps++;
					traps.push_back(trap);
				}
			}

			//if player1 lands on a moneyBag
			for (int i = 0; i < numMoneyBags / 2; i++)
			{
				if (player.getPosition().intersects(moneyBags[i].getPosition()) && moneyBags[i].isSpawned())
				{
					moneyBags[i].gotIt();
					player.setCoins(player.getCoins() + moneyBagReward);
					mb.play();
					moneyBags[i].spawn();
				}
			}

			//if player1 lands on a moveWall
			for (int i = 0; i < numMoveWalls / 2; i++)
			{
				if (player.getPosition().intersects(moveWalls[i].getPosition()) && moveWalls[i].isSpawned())
				{
					moveWalls[i].gotIt();
					state = State::LEVEL_LOADING;
					//mb.play();
					moveWalls[i].spawn();
				}
			}

			//cout << player.getPositionX() << " " << player.getPositionY() << endl;
		}// End updating the scene

		if (state2 == State::PLAYING)
		{
			// Update the delta time
			Time dt = clock.restart();
			// Update the total game time
			gameTimeTotal += dt;
			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = dt.asSeconds();

			player2.update(dtAsSeconds, 2);

			Vector2f playerPosition2(player2.getCenter());

			//view.setCenter(camView.controlPlayerCamera2(player.getCenter(), arena));
			view1.setCenter(camView.controlPlayerCamera(player2.getCenter(), arena));

			//if player2 lands on a coin
			for (int i = numCoins / 2; i < numCoins; i++)
			{
				if (player2.getPosition().intersects(coins[i].getPosition()) && coins[i].isSpawned())
				{
					coins[i].gotIt();
					player2.setCoins(player2.getCoins() + 1);
					coinPickup.play();
					coins[i].spawn2();

				}
			}

			//if player2 lands on a dragon
			for (int i = numDragons / 2; i < numDragons; i++)
			{
				if (player2.getPosition().intersects(dragons[i].getPosition()) && dragons[i].isSpawned() /*&& player2.getCoins() >= 5*/)
				{
					dragons[i].gotIt();
					state2 = State::DRAGON;
					//state = State::PLAYING;
					dragonRoar.play();
					dragons[i].spawn2();
				}
			}

			//if player2 lands on a snake
			for (int i = numSnakes / 2; i < numSnakes; i++)
			{
				if (player2.getPosition().intersects(snakes[i].getPosition()) && snakes[i].isSpawned())
				{
					snakes[i].gotIt();
					state2 = State::SNAKE;
					snakeHiss.play();
					snakes[i].spawn2();
				}
			}

			//if player2 lands on a zoom
			for (int i = numZooms / 2; i < numZooms; i++)
			{
				if (player2.getPosition().intersects(zooms[i].getPosition()) && zooms[i].isSpawned() && zoomBool2 == false)
				{
					zooms[i].gotIt();
					view1.zoom(1.5f);
					zoomBool2 = true;
				}
			}

			//if they land on a zoom, start a counter
			if (zoomBool2 == true)
			{
				zoomTimer2++;
			}

			//when the counter reaches a certain point, stop zoom
			if (zoomTimer2 >= 1000 + ((player2.getAttack() - player.getDefence()) * 300))
			{
				zoomBool2 = false;
				zoomTimer2 = 0;
				view1.zoom(0.65f);
				zooms[1].spawn2();
			}


			//if player2 lands on an inkAttack
			for (int i = numInkAttacks / 2; i < numInkAttacks; i++)
			{
				if (player2.getPosition().intersects(inkAttacks[i].getPosition()) && inkAttacks[i].isSpawned() && inkBool == false)
				{
					inkAttacks[i].gotIt();
					inkBool = true;
				}
			}

			//if they land on a inkAttack, start a counter
			if (inkBool == true)
			{
				inkTimer++;
			}

			//when the counter reaches a certain point, stop inkAttack
			if (inkTimer >= 500 + ((player2.getAttack() - player.getDefence()) * 300))
			{
				inkBool = false;
				inkTimer = 0;
				inkAttacks[1].spawn2();
			}

			//if player2 lands on a rotate
			for (int i = numRotates / 2; i < numRotates; i++)
			{
				if (player2.getPosition().intersects(rotates[i].getPosition()) && rotates[i].isSpawned() && rotateBool2 == false)
				{
					rotates[i].gotIt();
					view.zoom(-1.00f);
					rotateBool2 = true;
				}
			}

			//if they land on a rotate, start a counter
			if (rotateBool2 == true)
			{
				rotateTimer2++;
			}

			//when the counter reaches a certain point, stop rotate
			if (rotateTimer2 >= 1000 + ((player.getAttack() - player2.getDefence()) * 300))
			{
				rotateBool2 = false;
				rotateTimer2 = 0;
				view.zoom(-1.0f);
				rotates[1].spawn2();
			}
			//cout << player.getPositionX() << " " << player.getPositionY() << endl;

			//if player2 lands on a doors
			for (int i = numDoors / 2; i < numDoors; i++)
			{
				if (player2.getPosition().intersects(doors[i].getPosition()) && doors[i].isSpawned() && player2.getKey() == true)
				{
					exit2 = true;
					state = State::GAME_OVER;
					state2 = State::GAME_OVER;
				}
			}

			//if player2 lands on a slows
			for (int i = numSlows / 2; i < numSlows; i++)
			{
				if (player2.getPosition().intersects(slows[i].getPosition()) && slows[i].isSpawned())
				{
					slows[i].gotIt();
					slowBool2 = true;
					slows[1].spawn2();
				}
			}

			//if they land on a slow, start a counter
			if (slowBool2 == true)
			{
				slowTimer2++;
			}

			//when the counter reaches a certain point, stop slow
			if (slowTimer2 >= 1000 + ((player.getAttack() - player2.getDefence()) * 300))
			{
				slowBool2 = false;
				slowTimer2 = 0;
			}


			//if player2 lands on a slowAttack
			for (int i = numSlowAttacks / 2; i < numSlowAttacks; i++)
			{
				if (player2.getPosition().intersects(slowAttacks[i].getPosition()) && slowAttacks[i].isSpawned())
				{
					//int minusCoins = rand() % 10 + 1;

					slowAttacks[i].gotIt();
					slowBool = true;

					/*if (player.getCoins() > 0)
					{
						player.setCoins(player.getCoins() - minusCoins);
						if (player.getCoins() < 0)
							player.setCoins(0);
					}*/

					slowAttacks[i].spawn2();
				}
			}

			//if they land on a slowAttack, start a counter
			if (slowBool == true)
			{
				slowTimer++;
			}

			//when the counter reaches a certain point, stop slow
			if (slowTimer >= 1000 + ((player2.getAttack() - player.getDefence()) * 300))
			{
				slowBool = false;
				slowTimer = 0;
			}

			//if player2 lands on shop
			for (int i = numShops / 2; i < numShops; i++)
			{
				if (player2.getPosition().intersects(shops[i].getPosition()) && shops[i].isSpawned())
				{
					//shops[i].gotIt();
					state2 = State::SHOP;
				}
			}

			//if player2 lands on a moneyBag
			for (int i = numMoneyBags / 2; i < numMoneyBags; i++)
			{
				if (player2.getPosition().intersects(moneyBags[i].getPosition()) && moneyBags[i].isSpawned())
				{
					moneyBags[i].gotIt();
					player2.setCoins(player2.getCoins() + moneyBagReward);
					mb.play();
					moneyBags[i].spawn2();

				}
			}

			//if player1 lands on a moneyBag
			for (int i = numMoveWalls / 2; i < numMoveWalls; i++)
			{
				if (player2.getPosition().intersects(moveWalls[i].getPosition()) && moveWalls[i].isSpawned())
				{
					moveWalls[i].gotIt();
					state = State::LEVEL_LOADING;
					//mb.play();
					moveWalls[i].spawn();
				}
			}
		}// End updating the scene

		//if in snake state, draw snake encounter
		if (state == State::SNAKE)
		{
			window.draw(gameHUD.snakeScreenText);
		}

		//-------win conditions-------
		if (player.getHealth() <= 0)	//if player 1 dies
		{
			state = State::GAME_OVER;
			state2 = State::GAME_OVER;
		}

		else if (player2.getHealth() <= 0)	//if player 2 dies
		{
			state = State::GAME_OVER;
			state2 = State::GAME_OVER;
		}

		else if (player.getCoins() >= 1)	//if player 1 escapes
		{
			state == State::GAME_OVER;
			state2 == State::GAME_OVER;
		}

		else if (player.getCoins() >= 1)	//if player 2 escapes
		{
			state == State::GAME_OVER;
			state2 == State::GAME_OVER;
		}

		/*
		************************************************************
		*DISPLAY THE STATS OF THE PLAYERS UNDERNEATH THE GAME WINDOW
		************************************************************
		*/
		std::stringstream sshealthDisplay;
		sshealthDisplay << "Health: " << player.getHealth();
		gameHUD.text.setString(sshealthDisplay.str());

		std::stringstream ssCoinDisplay;
		ssCoinDisplay << "Coins: " << player.getCoins();
		gameHUD.coinDisplay.setString(ssCoinDisplay.str());

		std::stringstream ssAttackDisplay;
		ssAttackDisplay << "Attack Level: " << player.getAttack();
		gameHUD.attackDisplay.setString(ssAttackDisplay.str());

		std::stringstream ssDefenceDisplay;
		ssDefenceDisplay << "Defence Level: " << player.getDefence();
		gameHUD.defenceDisplay.setString(ssDefenceDisplay.str());

		std::stringstream ssKeyDisplay;
		ssKeyDisplay << "Key: " << player.getKey();
		gameHUD.keyDisplay.setString(ssKeyDisplay.str());

		std::stringstream ssCoinDisplay2;
		ssCoinDisplay2 << "Coins: " << player2.getCoins();
		gameHUD.coinDisplay2.setString(ssCoinDisplay2.str());

		std::stringstream sshealthDisplay2;
		sshealthDisplay2 << "Health: " << player2.getHealth();
		gameHUD.text2.setString(sshealthDisplay2.str());

		std::stringstream ssAttackDisplay2;
		ssAttackDisplay2 << "Attack Level: " << player2.getAttack();
		gameHUD.attackDisplay2.setString(ssAttackDisplay2.str());

		std::stringstream ssDefenceDisplay2;
		ssDefenceDisplay2 << "Defence Level: " << player2.getDefence();
		gameHUD.defenceDisplay2.setString(ssDefenceDisplay2.str());

		std::stringstream ssKeyDisplay2;
		ssKeyDisplay2 << "Key: " << player2.getKey();
		gameHUD.keyDisplay2.setString(ssKeyDisplay2.str());

		std::stringstream ssZoom;
		ssZoom << "INCREASED VISION!!! ";
		gameHUD.zoom.setString(ssZoom.str());

		std::stringstream ssZoom2;
		ssZoom2 << "INCREASED VISION!!! ";
		gameHUD.zoom2.setString(ssZoom2.str());

		std::stringstream ssRotate;
		ssRotate << "UPSIDE DOWN!!!";
		gameHUD.rotate.setString(ssRotate.str());

		std::stringstream ssRotate2;
		ssRotate2 << "UPSIDE DOWN!! ";
		gameHUD.rotate2.setString(ssRotate2.str());

		std::stringstream ssSlow;
		ssSlow << "STUNNED!!!";
		gameHUD.slow.setString(ssSlow.str());

		std::stringstream ssSlow2;
		ssSlow2 << "STUNNED!!!";
		gameHUD.slow2.setString(ssSlow2.str());

		/*
		**************
		Draw the scene
		**************
		*/
		if (state == State::PLAYING)
		{
			/*
			*********
			*PLAYER 1
			*********
			*/
			//window.clear(sf::Color(0,0,0));
			window.setView(viewHUD);
			window.draw(TandS.mainScreen);
			window.draw(gameHUD.getRectangle());
			window.draw(gameHUD.getRectangle2());

			// set the mainView to be displayed in the window
			// And draw everything related to it
			window.setView(view);
			// Draw the background
			window.draw(TandS.background, &TandS.textureBackground);
			window.draw(TandS.background2, &TandS.textureBackground2);
			window.draw(TandS.vertexWalls, &TandS.textureWalls);
			window.draw(TandS.vertexWalls2, &TandS.textureWalls2);

			for (int i = 0; i < numCoins; i++)
			{
				//draw the coins
				if (coins[i].isSpawned())
				{
					window.draw(coins[i].getSprite());
				}
			}

			for (int i = 0; i < numDragons; i++)
			{
				//draw the dragons
				if (dragons[i].isSpawned())
				{
					window.draw(dragons[i].getSprite());
				}
			}

			for (int i = 0; i < numSnakes; i++)
			{
				//draw the snakes
				if (snakes[i].isSpawned())
				{
					window.draw(snakes[i].getSprite());
				}
			}

			for (int i = 0; i < numZooms; i++)
			{
				//draw the zooms
				if (zooms[i].isSpawned())
				{
					window.draw(zooms[i].getSprite());
				}
			}

			for (int i = 0; i < numInkAttacks; i++)
			{
				//draw the inkAttacks
				if (inkAttacks[i].isSpawned())
				{
					window.draw(inkAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numRotates; i++)
			{
				//draw the rotates
				if (rotates[i].isSpawned())
				{
					window.draw(rotates[i].getSprite());
				}
			}

			for (int i = 0; i < numDoors; i++)
			{
				//draw the exits
				if (doors[i].isSpawned())
				{
					window.draw(doors[i].getSprite());
				}
			}

			for (int i = 0; i < numSlows; i++)
			{
				//draw the slows
				if (slows[i].isSpawned())
				{
					window.draw(slows[i].getSprite());
				}
			}

			for (int i = 0; i < numSlowAttacks; i++)
			{
				//draw the slowAttacks
				if (slowAttacks[i].isSpawned())
				{
					window.draw(slowAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numShops; i++)
			{
				//draw the shops
				if (shops[i].isSpawned())
				{
					window.draw(shops[i].getSprite());
				}
			}

			for (int i = 0; i < numMoneyBags; i++)
			{
				//draw the moneyBags
				if (moneyBags[i].isSpawned())
				{
					window.draw(moneyBags[i].getSprite());
				}
			}

			for (int i = 0; i < numMoveWalls; i++)
			{
				//draw the moveWalls
				if (moveWalls[i].isSpawned())
				{
					window.draw(moveWalls[i].getSprite());
				}
			}

			// Draw the players
			window.draw(player.getSprite());
			window.draw(player2.getSprite());

			//draw the board
			window.setView(view1);
			window.draw(TandS.background, &TandS.textureBackground);
			window.draw(TandS.background2, &TandS.textureBackground2);
			window.draw(TandS.vertexWalls, &TandS.textureWalls);
			window.draw(TandS.vertexWalls2, &TandS.textureWalls2);

			/*
			*********
			*PLAYER 2
			*********
			*/
			for (int i = 0; i < numCoins; i++)
			{
				//draw the coins
				if (coins[i].isSpawned())
				{
					window.draw(coins[i].getSprite());
				}
			}

			for (int i = 0; i < numDragons; i++)
			{
				//draw the coin
				if (dragons[i].isSpawned())
				{
					window.draw(dragons[i].getSprite());
				}
			}

			for (int i = 0; i < numSnakes; i++)
			{
				//draw the coin
				if (snakes[i].isSpawned())
				{
					window.draw(snakes[i].getSprite());
				}
			}
			for (int i = 0; i < numZooms; i++)
			{
				//draw the coin
				if (zooms[i].isSpawned())
				{
					window.draw(zooms[i].getSprite());
				}
			}

			for (int i = 0; i < numInkAttacks; i++)
			{
				//draw the inkAttack
				if (inkAttacks[i].isSpawned())
				{
					window.draw(inkAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numRotates; i++)
			{
				if (rotates[i].isSpawned())
				{
					window.draw(rotates[i].getSprite());
				}
			}

			for (int i = 0; i < numDoors; i++)
			{
				if (doors[i].isSpawned())
				{
					window.draw(doors[i].getSprite());
				}
			}

			for (int i = 0; i < numSlows; i++)
			{
				if (slows[i].isSpawned())
				{
					window.draw(slows[i].getSprite());
				}
			}

			for (int i = 0; i < numSlowAttacks; i++)
			{
				if (slowAttacks[i].isSpawned())
				{
					window.draw(slowAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numShops; i++)
			{
				if (shops[i].isSpawned())
				{
					window.draw(shops[i].getSprite());
				}
			}

			for (int i = 0; i < numMoveWalls; i++)
			{
				//draw the moveWall
				if (moveWalls[i].isSpawned())
				{
					window.draw(moveWalls[i].getSprite());
				}
			}



			// Draw the players for player 1
			window.draw(player.getSprite());
			window.draw(player2.getSprite());

			// Draw the players for player 2
			window.draw(player2.getSprite());
			window.draw(player.getSprite());

			//draw the stats window for each player
			window.setView(viewHUD);
			window.draw(gameHUD.playerStatsGui());
			window.draw(gameHUD.playerStatsGui2());

			/*
			************************************
			*DISPLAY ALL THE STATS OF THE PLAYER
			************************************
			*/
			window.draw(gameHUD.getText());
			window.draw(gameHUD.getText2());
			window.draw(gameHUD.PlayerOneHeading);
			window.draw(gameHUD.PlayerTwoHeading);
			window.draw(gameHUD.coinDisplay);
			window.draw(gameHUD.coinDisplay2);
			window.draw(gameHUD.attackDisplay);
			window.draw(gameHUD.attackDisplay2);
			window.draw(gameHUD.defenceDisplay);
			window.draw(gameHUD.defenceDisplay2);
			window.draw(gameHUD.keyDisplay);
			window.draw(gameHUD.keyDisplay2);
			//window.draw(gameHUD.dragonScreenText); 
		}

		if (state2 == State::PLAYING)
		{
			//window.clear(sf::Color(0,0,0));
			window.setView(viewHUD);
			window.draw(TandS.mainScreen);
			window.draw(gameHUD.getRectangle());
			window.draw(gameHUD.getRectangle2());

			// set the mainView to be displayed in the window
			// And draw everything related to it
			window.setView(view);
			// Draw the background
			window.draw(TandS.background, &TandS.textureBackground);
			window.draw(TandS.background2, &TandS.textureBackground2);
			window.draw(TandS.vertexWalls, &TandS.textureWalls);
			window.draw(TandS.vertexWalls2, &TandS.textureWalls2);

			for (int i = 0; i < numCoins; i++)
			{
				//draw the coins
				if (coins[i].isSpawned())
				{
					window.draw(coins[i].getSprite());
				}
			}

			for (int i = 0; i < numDragons; i++)
			{
				//draw the dragons
				if (dragons[i].isSpawned())
				{
					window.draw(dragons[i].getSprite());
				}
			}

			for (int i = 0; i < numSnakes; i++)
			{
				//draw the snakes
				if (snakes[i].isSpawned())
				{
					window.draw(snakes[i].getSprite());
				}
			}

			for (int i = 0; i < numZooms; i++)
			{
				//draw the zooms
				if (zooms[i].isSpawned())
				{
					window.draw(zooms[i].getSprite());
				}
			}

			for (int i = 0; i < numInkAttacks; i++)
			{
				//draw the zooms
				if (inkAttacks[i].isSpawned())
				{
					window.draw(inkAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numRotates; i++)
			{
				//draw the rotates
				if (rotates[i].isSpawned())
				{
					window.draw(rotates[i].getSprite());
				}
			}

			for (int i = 0; i < numDoors; i++)
			{
				//draw the exits
				if (doors[i].isSpawned())
				{
					window.draw(doors[i].getSprite());
				}
			}

			for (int i = 0; i < numSlows; i++)
			{
				//draw the slows
				if (slows[i].isSpawned())
				{
					window.draw(slows[i].getSprite());
				}
			}

			for (int i = 0; i < numSlowAttacks; i++)
			{
				//draw the slowAttacks
				if (slowAttacks[i].isSpawned())
				{
					window.draw(slowAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numShops; i++)
			{
				//draw the shops
				if (shops[i].isSpawned())
				{
					window.draw(shops[i].getSprite());
				}
			}

			for (int i = 0; i < numMoneyBags; i++)
			{
				//draw the moneyBags
				if (moneyBags[i].isSpawned())
				{
					window.draw(moneyBags[i].getSprite());
				}
			}


			for (int i = 0; i < numMoveWalls; i++)
			{
				//draw the moneyBags
				if (moveWalls[i].isSpawned())
				{
					window.draw(moveWalls[i].getSprite());
				}
			}

			// Draw the players
			window.draw(player.getSprite());
			window.draw(player2.getSprite());

			//draw the background
			window.setView(view1);
			window.draw(TandS.background, &TandS.textureBackground);
			window.draw(TandS.background2, &TandS.textureBackground2);
			window.draw(TandS.vertexWalls, &TandS.textureWalls);
			window.draw(TandS.vertexWalls2, &TandS.textureWalls2);

			for (int i = 0; i < numCoins; i++)
			{
				//draw the coins
				if (coins[i].isSpawned())
				{
					window.draw(coins[i].getSprite());
				}
			}

			for (int i = 0; i < numDragons; i++)
			{
				//draw the dragons
				if (dragons[i].isSpawned())
				{
					window.draw(dragons[i].getSprite());
				}
			}

			for (int i = 0; i < numSnakes; i++)
			{
				//draw the snakes
				if (snakes[i].isSpawned())
				{
					window.draw(snakes[i].getSprite());
				}
			}

			for (int i = 0; i < numZooms; i++)
			{
				//draw the zooms
				if (zooms[i].isSpawned())
				{
					window.draw(zooms[i].getSprite());
				}
			}

			for (int i = 0; i < numInkAttacks; i++)
			{
				//draw the zooms
				if (inkAttacks[i].isSpawned())
				{
					window.draw(inkAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numRotates; i++)
			{
				//draw the rotates
				if (rotates[i].isSpawned())
				{
					window.draw(rotates[i].getSprite());
				}
			}

			for (int i = 0; i < numDoors; i++)
			{
				//draw the exits
				if (doors[i].isSpawned())
				{
					window.draw(doors[i].getSprite());
				}
			}

			for (int i = 0; i < numSlows; i++)
			{
				//draw the slows
				if (slows[i].isSpawned())
				{
					window.draw(slows[i].getSprite());
				}
			}

			for (int i = 0; i < numSlowAttacks; i++)
			{
				//draw the slowAttacks
				if (slowAttacks[i].isSpawned())
				{
					window.draw(slowAttacks[i].getSprite());
				}
			}

			for (int i = 0; i < numShops; i++)
			{
				//draw the shops
				if (shops[i].isSpawned())
				{
					window.draw(shops[i].getSprite());
				}
			}
			for (int i = 0; i < numMoneyBags; i++)
			{
				//draw the moneyBags
				if (moneyBags[i].isSpawned())
				{
					window.draw(moneyBags[i].getSprite());
				}
			}

			for (int i = 0; i < numMoveWalls; i++)
			{
				//draw the moveWalls
				if (moveWalls[i].isSpawned())
				{
					window.draw(moveWalls[i].getSprite());
				}
			}

			//draw the players
			window.draw(player2.getSprite());
			window.draw(player.getSprite());

			//draw the stats window for the players
			window.setView(viewHUD);
			window.draw(gameHUD.playerStatsGui());
			window.draw(gameHUD.playerStatsGui2());

			//draw the actual stats for the players
			window.draw(gameHUD.getText());
			window.draw(gameHUD.getText2());
			window.draw(gameHUD.PlayerOneHeading);
			window.draw(gameHUD.PlayerTwoHeading);
			window.draw(gameHUD.coinDisplay);
			window.draw(gameHUD.coinDisplay2);
			window.draw(gameHUD.attackDisplay);
			window.draw(gameHUD.attackDisplay2);
			window.draw(gameHUD.defenceDisplay);
			window.draw(gameHUD.defenceDisplay2);
			window.draw(gameHUD.keyDisplay);
			window.draw(gameHUD.keyDisplay2);
			
			//if zoomBool1, draw it
			if (zoomBool == true && zoomTimer < 1500)
			{
				window.draw(gameHUD.zoom);
			}

			//if zoomBool1, draw it
			else if (zoomBool2 == true)
			{
				window.draw(gameHUD.zoom2);
			}

			//if rotateBool, draw it
			if (rotateBool == true)
			{
				window.draw(gameHUD.rotate);
			}

			//if rotateBool2, draw it
			else if (rotateBool2 == true)
			{
				window.draw(gameHUD.rotate2);
			}
			
			//if slowBool, draw it
			if (slowBool == true)
			{
				window.draw(gameHUD.slow2);
			}

			//if slowBool2, draw it
			else if (slowBool2 == true)
			{
				window.draw(gameHUD.slow);
			}

			if (inkBool == true)
			{
				window.draw(TandS.inkedS);
			}

			if (inkBool2 == true)
			{
				window.draw(TandS.inkedS2);
			}



		}

		if (state == State::START_UP)
		{
			//draw the background, title, and text of the startup screen
			window.draw(TandS.mainScreen);
			window.draw(gameHUD.loadingScreenText);
			window.draw(TandS.mainScreenTitle);

			//move up right -> x++, y--
			if (upRight == true) {
				TandS.mainScreenTitle.setPosition(TandS.mainScreenTitle.getPosition().x + 0.4, TandS.mainScreenTitle.getPosition().y - 0.4);
				if (TandS.mainScreenTitle.getPosition().x >= resolution.x - 1125) {
					upRight = false;
					upLeft = true;
				}

				if (TandS.mainScreenTitle.getPosition().y <= 0) {
					upRight = false;
					downRight = true;
				}
			}

			//move down right -> x++, y++
			if (downRight == true) {
				TandS.mainScreenTitle.setPosition(TandS.mainScreenTitle.getPosition().x + 0.4, TandS.mainScreenTitle.getPosition().y + 0.4);
				if (TandS.mainScreenTitle.getPosition().x >= resolution.x - 1125) {
					downRight = false;
					downLeft = true;
				}
				if (TandS.mainScreenTitle.getPosition().y >= resolution.y - 100) {
					downRight = false;
					upRight = true;
				}
			}

			//move up left -> x-- y--
			if (upLeft == true) {
				TandS.mainScreenTitle.setPosition(TandS.mainScreenTitle.getPosition().x - 0.4, TandS.mainScreenTitle.getPosition().y - 0.4);
				if (TandS.mainScreenTitle.getPosition().x <= 0) {
					upLeft = false;
					upRight = true;
				}
				if (TandS.mainScreenTitle.getPosition().y <= 0) {
					upLeft = false;
					downLeft = true;
				}
			}

			//move down left -> x--, y++
			if (downLeft == true) {
				TandS.mainScreenTitle.setPosition(TandS.mainScreenTitle.getPosition().x - 0.4, TandS.mainScreenTitle.getPosition().y + 0.4);
				if (TandS.mainScreenTitle.getPosition().x <= 0) {
					downLeft = false;
					downRight = true;
				}
				if (TandS.mainScreenTitle.getPosition().y >= resolution.y - 100) {
					downLeft = false;
					upLeft = true;
				}
			}
		}

		if (state == State::MENU)
		{
			//make the tile of the game go back to its original position once you go to the menu
			TandS.mainScreenTitle.setPosition(265, 30);

			//draw the menu page, background image, and title
			window.draw(TandS.mainScreen);
			window.draw(TandS.mainScreenTitle);
			window.draw(TandS.menuS);
		}
		if (state == State::RULES)
		{
			//draw the rules page, background image, and title
			window.draw(TandS.mainScreen);
			window.draw(TandS.rulesS);
			window.draw(TandS.mainScreenTitle);
		}

		if (state == State::SNAKE)
			window.draw(TandS.snakeBGS);	//if player1 snake, draw page

		if (state2 == State::SNAKE)
			window.draw(TandS.snakeBGS2);	//if player2 snake, draw page

		if (state == State::SNAKEATTACK)	//if player1 snakeattack, draw page
			window.draw(TandS.snakeFightS);

		if (state2 == State::SNAKEATTACK)	//if player2 snakeattack, draw page
			window.draw(TandS.snakeFightS2);

		if (state == State::DRAGON)			//if player1 dragon, draw page
			window.draw(TandS.dragonBGS);
		 
		if (state2 == State::DRAGON)		//if player2 dragon, draw page
			window.draw(TandS.dragonBGS2);

		if (state == State::DRAGONATTACK)	//if player1 dragonattack, draw page
			window.draw(TandS.dragonFightS);

		if (state2 == State::DRAGONATTACK)	//if player2 dragonattack, draw page
			window.draw(TandS.dragonFightS2);

		if (state == State::SHOP)
		{
			//draw the shop while on the same tile
			window.draw(TandS.shopContentsSprite1);

			//if the player moves while on the shop, then make the shop disappear
			if (Keyboard::isKeyPressed(Keyboard::W) ||
				Keyboard::isKeyPressed(Keyboard::A) ||
				Keyboard::isKeyPressed(Keyboard::S) ||
				Keyboard::isKeyPressed(Keyboard::D) ||
				((controllerDPadId == 7 && controllerDPadAxis > 50) && controller == 0) ||
				((controllerDPadId == 6 && controllerDPadAxis < -50) && controller == 0) ||
				((controllerDPadId == 7 && controllerDPadAxis < -50) && controller == 0) ||
				((controllerDPadId == 6 && controllerDPadAxis > 50) && controller == 0))
			{
				state = State::PLAYING;
			}
		}

		if (state2 == State::SHOP)
		{
			//draw the shop while on the same tile
			window.draw(TandS.shopContentsSprite2);

			//if the player moves while on the shop, then make the shop disappear
			if (Keyboard::isKeyPressed(Keyboard::Up) ||
				Keyboard::isKeyPressed(Keyboard::Down) ||
				Keyboard::isKeyPressed(Keyboard::Left) ||
				Keyboard::isKeyPressed(Keyboard::Right) ||
				((controllerDPadId == 7 && controllerDPadAxis > 50) && controller == 1) ||
				((controllerDPadId == 6 && controllerDPadAxis < -50) && controller == 1) ||
				((controllerDPadId == 7 && controllerDPadAxis < -50) && controller == 1) ||
				((controllerDPadId == 6 && controllerDPadAxis > 50) && controller == 1))
			{
				state2 = State::PLAYING;
			}
		}

		//if in the game over state
		if (state == State::GAME_OVER || state2 == State::GAME_OVER) {
			if (player.getHealth() <= 0) {
				//if player1 dies, draw that option
				window.draw(TandS.mainScreen);
				window.draw(TandS.gameOverS1);
			}

			if (player2.getHealth() <= 0) {
				//if player2 dies, draw that option
				window.draw(TandS.mainScreen);
				window.draw(TandS.gameOverS2);
			}

			if (exit1 == true) {
				//if player1 escapes, draw that option
				window.draw(TandS.mainScreen);
				window.draw(TandS.gameOverS3);
			}

			if (exit2 == true) {
				//if player2 escapes, draw that option
				window.draw(TandS.mainScreen);
				window.draw(TandS.gameOverS4);
			}
		}

		window.display();

	}// End game loop

	return 0;
}