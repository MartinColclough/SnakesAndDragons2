/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include "HUD.h"

// Get the screen resolution and create an SFML window
int resolutionX = VideoMode::getDesktopMode().width;
int resolutionY = VideoMode::getDesktopMode().height;

void HUD::ViewOutline()
{
	//ractangle to make the outline for player one 
	rectangle.setSize(sf::Vector2f(800, 760));
	rectangle.setPosition(20, 10);
	rectangle.setFillColor(sf::Color::Red);

	//ractangle to make the outline for player two
	rectangle2.setSize(sf::Vector2f(800, 760));
	rectangle2.setFillColor(sf::Color::Blue);
	rectangle2.setPosition(resolutionX - 820, 10);

	//rectangle with red outline for player stats 
	GuiDisplay.setSize(sf::Vector2f(780, 200));
	GuiDisplay.setPosition(30, 800);
	GuiDisplay.setFillColor(sf::Color::Black);
	GuiDisplay.setOutlineColor(sf::Color::Red);
	GuiDisplay.setOutlineThickness(10);

	//rectangle with blue outline for player stats 
	GuiDisplay2.setSize(sf::Vector2f(780, 200));
	GuiDisplay2.setPosition(resolutionX - 820, 800);
	GuiDisplay2.setFillColor(sf::Color::Black);
	GuiDisplay2.setOutlineColor(sf::Color::Blue);
	GuiDisplay2.setOutlineThickness(10);

}

void HUD::GameText(Vector2f resolution)
{
	//font for the game 
	font.loadFromFile("fonts/FIRESTARTER.ttf");

	//text for dragon screen 
	dragonScreenText.setFont(font);
	dragonScreenText.setCharacterSize(50);
	dragonScreenText.setPosition(50,50);
	dragonScreenText.setString("A Dragon has appreared! \n 1 - Attack \n 2- Send to Enemy (15 gold) \n 3 - Leave");


	// text for snake screen
	snakeScreenText.setFont(font);
	snakeScreenText.setCharacterSize(50);
	snakeScreenText.setPosition(50, 50);
	snakeScreenText.setString("A Snake has appeared! \n 1 - Attack \n 2 - Send to Enemy (10 gold cost) \n 3 - Leave");

	// main text for the menu Screen
	//menuScreenText.setFont(font);
	//menuScreenText.setCharacterSize(50);
	//menuScreenText.setPosition(400, 250);
	//menuScreenText.setString("			- MENU -  \n  \n	Press [1] / [A] to Play the Game\n     \n	Press [2] / [X] to View the Rules \n  \n	Press [Escape] / [Start] to exit game");

	//main text for the rules Screen
	rulesScreenText.setFont(font);
	rulesScreenText.setCharacterSize(50);
	rulesScreenText.setPosition(270, 125);
	rulesScreenText.setString("				- RULES - \n \n-- MOVEMENT -- \nPlayer 1 - Use WASD to move \nPlayer 2 - Use Arrow Keys to move \n \n-- PICKUPS -- \nCoin - Add Gold \nSnake - Attack your opponent \nDragon - Attack to earn gold or attack \nyour opponent\n \n-- HOW TO WIN -- \nEarn enough gold to use the exit \nOpponent reaches 0 health");

	//bottom text for rules Screen
	rulesScreenText2.setFont(font);
	rulesScreenText2.setCharacterSize(50);
	rulesScreenText2.setPosition(100, resolution.y - 125);
	rulesScreenText2.setString("Press [1] / [A] to Play Game		Press [2] / [X] to Return to Menu");

	// start of game instructions
	loadingScreenText.setFont(font);
	loadingScreenText.setCharacterSize(50);
	loadingScreenText.setPosition(resolution.x / 3.5, resolution.y / 1.08);
	loadingScreenText.setString("Press [Enter] / [A] to load Game");

	// text for display dice (only will be needed when in battle)
	text.setFont(font);
	text.setPosition(50, 810);

	// text for display dice (only will be needed when in battle)
	text2.setFont(font);
	text2.setPosition(890, 810);

	// text to display players current amount of coin
	coinDisplay.setFont(font);
	coinDisplay.setPosition(50, 845);
	
	// text to display players current amount of coin
	coinDisplay2.setFont(font);
	coinDisplay2.setPosition(890, 845);

	// text for display dice (only will be needed when in battle) 
	attackDisplay.setFont(font);
	attackDisplay.setPosition(50, 880);

	// text for display dice (only will be needed when in battle)
	attackDisplay2.setFont(font);
	attackDisplay2.setPosition(890, 880);

	// text for display dice (only will be needed when in battle)
	defenceDisplay.setFont(font);
	defenceDisplay.setPosition(50, 915);

	// text for display dice (only will be needed when in battle)
	defenceDisplay2.setFont(font);
	defenceDisplay2.setPosition(890, 915);

	// text for display dice (only will be needed when in battle)
	keyDisplay.setFont(font);
	keyDisplay.setPosition(50, 950);

	// text for display dice (only will be needed when in battle)
	keyDisplay2.setFont(font);
	keyDisplay2.setPosition(890, 950);

	// text for display dice (only will be needed when in battle)
	zoom.setFont(font);
	zoom.setPosition(450, 950);

	zoom2.setFont(font);
	zoom2.setPosition(1300, 950);

	rotate.setFont(font);
	rotate.setPosition(1300, 850);

	rotate2.setFont(font);
	rotate2.setPosition(450, 850);

	slow.setFont(font);
	slow.setPosition(1300, 900);

	slow2.setFont(font);
	slow2.setPosition(450, 900);

}

// getters for the variables
Text HUD::getText()
{
	return text;
}
Text HUD::getText2()
{
	return text2;
}
Text HUD::getloadingScreenText()
{
	return loadingScreenText;
}
Text HUD::getPlayerOneHeading()
{
	return PlayerOneHeading;
}
Text HUD::getPlayerTwoHeading()
{
	return PlayerTwoHeading;
}
Text HUD::getcoinDisplay()
{
	return coinDisplay;
}
Text HUD::getcoinDisplay2()
{
	return coinDisplay2;
}
RectangleShape HUD::getRectangle()
{
	return rectangle;
}
RectangleShape HUD::getRectangle2()
{
	return rectangle2;
}
RectangleShape HUD::playerStatsGui()
{
	return GuiDisplay;
}
RectangleShape HUD::playerStatsGui2()
{
	return GuiDisplay2;
}