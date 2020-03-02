/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include "Dice.h"
#include <Windows.h>
#include <iostream>
#include <cstdlib>

using namespace sf;

Dice::Dice(int diceRoll) 
{
	diceRoll = 0;

}

void Dice::rDice()
{
	
	diceRoll = (rand() % 6) + 1;
	//std::cout << diceRoll;
}

void Dice::setDice()
{
	diceRoll--;
}
	
int Dice::getDice()
{
	return diceRoll;
}

void Dice::RollDice()
{
	m_DicePressed = true;
}

void Dice::StopDice()
{
	m_DicePressed = false;
}

void Dice::updateDice()
{

	if (m_DicePressed == true && iDice < 1)
	{
		diceRoll = (rand() % 6) + 1;
		iDice++;
	    //std::cout << getDice();
	}

	if (m_DicePressed == false && iDice == 1)
	{
		iDice = 0;
	}
}