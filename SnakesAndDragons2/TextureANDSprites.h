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

class TextureANDSprites
{

private:



public:

	VertexArray background;
	VertexArray background2;
	VertexArray vertexWalls;
	VertexArray vertexWalls2;

	Texture textureBackground;
	Texture textureBackground2;

	Texture textureWalls;
	Texture textureWalls2;

	Texture gameTitle;
	Texture loadingScreen;
	Texture dragonScreen;
	Texture snakeScreen;
	Texture wallChangeTure;

	Texture dragonBG;
	Texture dragonBG2;
	Texture dragonFight;
	Texture dragonFight2;

	Texture snakeBG;
	Texture snakeBG2;
	Texture snakeFight;
	Texture snakeFight2;

	Texture menu;
	Sprite menuS;

	Texture rules;
	Sprite rulesS; 

	Texture gameOver1;
	Texture gameOver2;
	Texture gameOver3;
	Texture gameOver4;

	Texture gameOver12;
	Texture gameOver22;
	Texture gameOver32;
	Texture gameOver42;

	Sprite gameOverS1;
	Sprite gameOverS2;
	Sprite gameOverS3;
	Sprite gameOverS4;

	Sprite mainScreen;
	Sprite mainScreenTitle;
	Sprite dragonScreenSprite;
	Sprite snakeScreenSprite;
	Sprite shopContentsSprite1;
	Sprite shopContentsSprite2;
	Sprite dragonBGS;
	Sprite dragonBGS2;
	Sprite dragonFightS;
	Sprite dragonFightS2;

	Sprite snakeBGS;
	Sprite snakeBGS2;
	Sprite snakeFightS;
	Sprite snakeFightS2;

	Sprite wallChange;
	
	Texture coinPickup;
	Texture dragonPickup;
	Texture snakePickup;
	Texture rotatePickup;
	Texture doorPickup;
	Texture shopPickup;
	Texture shopContents;

	Texture textur1;
	Texture textur2;
	Texture textur1Flip;
	Texture textur2Flip;
	Texture textur1Back;
	Texture textur2Back;
	Texture textur1Walk;
	Texture textur2Walk;
	Texture textur1WalkFlip;
	Texture textur2WalkFlip;


	Texture inkPickup;
	Sprite inkPickupS;

	Texture inked;
	Texture inked2;
	Sprite inkedS;
	Sprite inkedS2;

	void CreateTExturesAndSprites(Vector2f resolution);
};

