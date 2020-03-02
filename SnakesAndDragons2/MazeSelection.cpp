/*
Name: Martin Colclough				K-Number: K00227787
Name: Brayden O'Neill			    K-Number: K00224576
Name: Sylwester Szwed				K-Number: K00231357
Snakes and Dragons 2
*/

#include "MazeSelection.h"
#include <iostream>
#include <sstream>
#include <fstream>


using namespace std;

String MazeSelection::createMazeForPlayer1()
{


	int random = rand() % 5 + 1;

	if (random == 1)
	{
		 filename = "Walls/wall1.txt";
	}
	else if (random == 2)
	{
		 filename = "Walls/wall2.txt";
	}
	else if (random == 3)
	{
		 filename = "Walls/wall3.txt";
	}
	else if (random == 4)
	{
		 filename = "Walls/wall4.txt";
	}
	else if (random == 5)
	{
		 filename = "Walls/wall5.txt";
	}
	
	return filename;

}
String MazeSelection::createMazeForPlayer2()
{


	int random = rand() % 5 + 1;

	if (random == 1)
	{
		filename2 = "Walls/wall1.txt";
	}
	else if (random == 2)
	{
		filename2 = "Walls/wall2.txt";
	}
	else if (random == 3)
	{
		filename2 = "Walls/wall3.txt";
	}
	else if (random == 4)
	{
		filename2 = "Walls/wall4.txt";
	}
	else if (random == 5)
	{
		filename2 = "Walls/wall5.txt";
	}
	//  cout << filename2 << " this is string " << endl ;
	return filename2;
}
