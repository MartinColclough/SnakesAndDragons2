/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class CameraView
{
private:


	int startingPoint;
	int startingPoint2;


public:


	CameraView();


	Vector2f controlPlayerCamera(Vector2f cam, IntRect arena);
	Vector2f controlPlayerCamera2(Vector2f cam, IntRect arena);
	Vector2f playerCenter;
	Vector2f cameraCenter;
	Vector2f arenaSize;
	View view;

};

