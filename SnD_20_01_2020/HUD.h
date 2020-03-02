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

class HUD
{
private:



public:

	// rectangleShape variables for the game 
	sf::RectangleShape rectangle;
	sf::RectangleShape rectangle2;
	sf::RectangleShape GuiDisplay;
	sf::RectangleShape GuiDisplay2;

	// text variables for the game 
	Text dragonScreenText;
	Text snakeScreenText;
	Text menuScreenText;
	Text rulesScreenText;
	Text rulesScreenText2;
	Font font;
	Text loadingScreenText;
	Text text;
	Text PlayerOneHeading;
	Text text2;
	Text PlayerTwoHeading;
	Text coinDisplay;
	Text coinDisplay2;
	Text attackDisplay;
	Text attackDisplay2;
	Text defenceDisplay;
	Text defenceDisplay2;
	Text keyDisplay;
	Text keyDisplay2;
	Text zoom;
	Text zoom2;
	Text rotate;
	Text rotate2;
	Text slow;
	Text slow2;

	void ViewOutline();
	void GameText(Vector2f resolution);


	// getters for the ractangle shapes 
	RectangleShape getRectangle();
	RectangleShape getRectangle2();
	RectangleShape playerStatsGui();
	RectangleShape playerStatsGui2();

	// getters for the various texts
	Text getdragonScreenText();
	Text getsnakeScreenText();
	Text getText();
	Text getText2();
	Text getloadingScreenText();
	Text getPlayerOneHeading();
	Text getPlayerTwoHeading();
	Text getcoinDisplay();
	Text getcoinDisplay2();





};

