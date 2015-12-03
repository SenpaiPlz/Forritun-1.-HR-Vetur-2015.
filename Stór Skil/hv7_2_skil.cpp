#include <iostream>
#include <string>
//#include <math.h>
//#include <vector>
//#include <stdio.h>
//#include <algorithm>
//#include <cctype>
//#include <stdlib.h>

const int boardsize = 9;
	//Probably unnecessary, but looks prettier than hard coding. 

using namespace std;

void displayboard(char arr[]);
	//Displays the board.

void LetsPlayAGame(char arr[]);
	//Initiates the game.

void LetsTryNotToUseSwitches(char arr[],const char player);
	//Reads input from user and determines the move.

char DeterminePlayer(const int Count);
	//Checks which player is playing.

bool DetermineWinner(const char arr[],const int NumberOfTurns,const char player);
	//Checks win conditions

int main ()
{
		//I decided against using a 3x3 array, unnecessarily complicates the code.
		
	char arr[boardsize] = {'1','2','3','4','5','6','7','8','9'};
	displayboard(arr);
	LetsPlayAGame(arr);
	return 0;
}

void displayboard(char arr[])
{
		//Thanks to using a 1d board, this has no for loops.
	
	cout << arr[0] << " " << arr[1] << " " << arr[2] << " \n";
	cout << arr[3] << " " << arr[4] << " " << arr[5] << " \n";
	cout << arr[6] << " " << arr[7] << " " << arr[8] << " \n";
}

void LetsPlayAGame(char arr[])
{
	char player;
	bool Continue = true;
	int NumberOfTurns = 0;
	do
	{
		player = DeterminePlayer(NumberOfTurns);
		LetsTryNotToUseSwitches(arr,player);
		displayboard(arr);
		NumberOfTurns++;
		Continue = DetermineWinner(arr, NumberOfTurns, player);
	}while(Continue == true);
}

void LetsTryNotToUseSwitches(char arr[],const char player)
{
	cout << player << " position: ";
	char Move;
	
	while(!(cin >> Move) | (Move < '1') | (Move > '9') | (Move != arr[Move-'0'-1]))
	{
		cout << "Illegal move!\n";
		cout << player << " position: ";
	}
	
	int input = Move-'0'-1;
	arr[input] = player;
}

char DeterminePlayer(int Count)
{
	char player = 'O';
	if (Count % 2 == 0)
	{
		player = 'X';
	}
	
	return player;
}

bool DetermineWinner(const char arr[],const int NumberOfTurns,const char player)
{
	for(int i = 0; i < 3; i++)
	{
			//Checks each row for winning condition.
		
		if((arr[i] == arr[(i+3)]) && (arr[(i+3)] == arr[(i+6)]))
		{
			cout << "Winner is: " << player;
			return false;
		}
		
			//Checks each column for winning condition.
		
		if((arr[3*i] == arr[(3*i)+1]) && (arr[(3*i)+1] == arr[(3*i)+2]))
		{
			cout << "Winner is: " << player;
			return false;
		}
	}
	if((arr[0] == arr[4]) && (arr[4] == arr[8]))
	{
		cout << "Winner is: " << player;
		return false;
	}
	if((arr[2] == arr[4]) && (arr[4] == arr[6]))
	{
		cout << "Winner is: " << player;
		return false;
	}
	if(NumberOfTurns == 9)
	{
		cout << "Draw!";
		return false;
	}
	return true;
}
