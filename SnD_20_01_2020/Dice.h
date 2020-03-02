/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Dice
{
private:
	int diceRoll;

	bool m_DicePressed;

	int iDice = 0;
public:
	Dice(int diceRoll = 0);

	void rDice();
	
	void setDice();

	int getDice();

	void RollDice();

	void StopDice();

	void updateDice();
};
