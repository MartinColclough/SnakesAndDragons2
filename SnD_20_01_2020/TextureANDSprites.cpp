/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include "TextureANDSprites.h"
#include <iostream>
#include <sstream>
void TextureANDSprites::CreateTExturesAndSprites(Vector2f resolution)
{

/*
	COMMENTS COMING SOON !!!!!!!!!!!!!!!!!!!!!!!!!!

*/
	// Load the texture for our background vertex array

	textureBackground.loadFromFile("graphics/background_sheet.png");
	textureBackground2.loadFromFile("graphics/background_sheet.png");


	textureWalls.loadFromFile("graphics/background_sheet.png");;
	textureWalls2.loadFromFile("graphics/background_sheet.png");


	gameTitle.loadFromFile("graphics/gameTitle.png");


	loadingScreen.loadFromFile("graphics/SnakeAndDragonsLoadScreen.jpg");
	dragonScreen.loadFromFile("graphics/DragonScreen.png");
	snakeScreen.loadFromFile("graphics/SnakeScreen.png");

	dragonBG.loadFromFile("graphics/DragonBG1.png"); 
	dragonBG2.loadFromFile("graphics/DragonBG1.png");
	dragonFight.loadFromFile("graphics/DragonBG2.png");

	snakeBG.loadFromFile("graphics/SnakeBG1.png");
	snakeBG2.loadFromFile("graphics/SnakeBG2.png");
	snakeFight.loadFromFile("graphics/SnakeBG2.png");

	mainScreen.setTexture(loadingScreen);

	rules.loadFromFile("graphics/rules.png");
	rulesS.setTexture(rules);
	rulesS.setPosition(150,175);

	mainScreenTitle.setTexture(gameTitle);
	mainScreenTitle.setPosition(265, 30);  //265,30


	dragonScreenSprite.setTexture(dragonScreen);
	snakeScreenSprite.setTexture(snakeScreen);


	coinPickup.loadFromFile("graphics/GoldCoinSprite.png");
	dragonPickup.loadFromFile("graphics/dragonPickup.png");
	snakePickup.loadFromFile("graphics/snakePickup.png");
	rotatePickup.loadFromFile("graphics/rotate.png");
	shopPickup.loadFromFile("graphics/shop.png");
	//add inked pickup

	shopContents.loadFromFile("graphics/shopContents.png");

	shopContentsSprite1.setTexture(shopContents);
	shopContentsSprite1.setPosition(44, 31);
	shopContentsSprite2.setTexture(shopContents);
	shopContentsSprite2.setPosition(884, 31);

	wallChangeTure.loadFromFile("graphics/wallChange.png");

	menu.loadFromFile("graphics/menu.png");

	gameOver1.loadFromFile("graphics/gameOver1.png");
	gameOver2.loadFromFile("graphics/gameOver2.png");
	gameOver3.loadFromFile("graphics/gameOver3.png");
	gameOver4.loadFromFile("graphics/gameOver4.png");

	inked.loadFromFile("graphics/inkAttack.png");
	inked2.loadFromFile("graphics/inkAttack.png");

	wallChange.setTexture(wallChangeTure);

	dragonBGS.setTexture(dragonBG);
	dragonBGS.setPosition(20, 10);

	dragonBGS2.setTexture(dragonBG);
	dragonBGS2.setPosition(860, 10);

	dragonFightS.setTexture(dragonFight);
	dragonFightS.setPosition(20, 10);

	dragonFightS2.setTexture(dragonFight);
	dragonFightS2.setPosition(860, 10);

	snakeBGS.setTexture(snakeBG);
	snakeBGS.setPosition(20, 10);

	snakeBGS2.setTexture(snakeBG);
	snakeBGS2.setPosition(860, 10);

	snakeFightS.setTexture(snakeFight);
	snakeFightS.setPosition(20, 10);

	snakeFightS2.setTexture(snakeFight);
	snakeFightS2.setPosition(860, 10);

	menuS.setTexture(menu);
	menuS.setPosition(560,350);

	gameOverS1.setTexture(gameOver1);
	gameOverS1.setPosition(150, 175);

	gameOverS2.setTexture(gameOver2);
	gameOverS2.setPosition(150, 175);

	gameOverS3.setTexture(gameOver3);
	gameOverS3.setPosition(150, 175);

	gameOverS4.setTexture(gameOver4);
	gameOverS4.setPosition(150, 175);

	inkedS.setTexture(inked);
	inkedS.setPosition(20, 10);

	inkedS2.setTexture(inked2);
	inkedS2.setPosition(860, 10);
	 
	// loading texture from file
	textur1.loadFromFile("graphics/player1.png");
	textur2.loadFromFile("graphics/player2.png");

	textur1Walk.loadFromFile("graphics/player1Walk.png");
	textur1WalkFlip.loadFromFile("graphics/player1WalkFlip.png");

	textur2Walk.loadFromFile("graphics/player2Walk.png");



}

