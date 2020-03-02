/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include <SFML/Graphics.hpp>
#include "CameraView.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
using namespace std;
using namespace sf;

Player player1;
View ww;

CameraView::CameraView()
{
	
}

Vector2f CameraView::controlPlayerCamera(Vector2f cam, IntRect arena)
{

	playerCenter.x = cam.x;
	playerCenter.y = cam.y;

	if ((playerCenter.x >= 1430 && playerCenter.x <= 1980))
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = playerCenter.y; 
	}

	if((playerCenter.y >= 230 && playerCenter.y <= 780))
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = playerCenter.y;
	}

	// one side 
	if (playerCenter.x <= 1380)
	{
		cameraCenter.x = 1380;
		cameraCenter.y = playerCenter.y;
	}
	if (playerCenter.x >= 2030)
	{
		cameraCenter.x = 2030;
		cameraCenter.y = playerCenter.y;
	}
	if (playerCenter.y <= 230)
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = 230;
	}
	if (playerCenter.y >= 830)
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = 780;
	}

	// corners of the game
	if (playerCenter.x >= 2030 && playerCenter.y >= 780)
	{
		cameraCenter.x = 2030;
		cameraCenter.y = 780;
	}
	if (playerCenter.x >= 2030 && playerCenter.y <= 230)
	{
		cameraCenter.x = 2030;
		cameraCenter.y = 230;
	}
	if (playerCenter.x <= 1380 && playerCenter.y <= 230)
	{
		cameraCenter.x = 1380;
		cameraCenter.y = 230;
	}

	if (playerCenter.x <= 1380 && playerCenter.y >= 780)
	{
		cameraCenter.x = 1380;
		cameraCenter.y = 780;
	}
	return cameraCenter;
}

Vector2f CameraView::controlPlayerCamera2(Vector2f cam, IntRect arena)
{


	playerCenter.x = cam.x;
	playerCenter.y = cam.y;

	if ((playerCenter.x >= 230 && playerCenter.x <= 780))
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = playerCenter.y;
	}

	if ((playerCenter.y >= 230 && playerCenter.y <= 780))
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = playerCenter.y;
	}

	// one side 
	if (playerCenter.x <= 180)
	{
		cameraCenter.x = 180;
		cameraCenter.y = playerCenter.y;
	}
	if (playerCenter.x >= 830)
	{
		cameraCenter.x = 830;
		cameraCenter.y = playerCenter.y;
	}
	if (playerCenter.y <= 230)
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = 230;
	}
	if (playerCenter.y >= 830)
	{
		cameraCenter.x = playerCenter.x;
		cameraCenter.y = 780;
	}

	// corners of the game
	if (playerCenter.x >= 830 && playerCenter.y >= 780)
	{
		cameraCenter.x = 830;
		cameraCenter.y = 780;
	}
	if (playerCenter.x >= 830 && playerCenter.y <= 230)
	{
		cameraCenter.x = 830;
		cameraCenter.y = 230;
	}
	if (playerCenter.x <= 180 && playerCenter.y <= 230)
	{
		cameraCenter.x = 180;
		cameraCenter.y = 230;
	}

	if (playerCenter.x <= 180 && playerCenter.y >= 780)
	{
		cameraCenter.x = 180;
		cameraCenter.y = 780;
	}
	return cameraCenter;
}


