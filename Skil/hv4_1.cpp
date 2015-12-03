//forcing the number of functions made me sad ;__; and I kinda lost my mind
//So to cheer myself up I named all the functions after deities from the Cthulu Mythos.
//With the comments I made while raving mad, you shouldn't get too confused I hope.
#include <iostream>
#include <string>
using namespace std;

bool Xirdneth_Continue();
	//Xirdneth == Maker of Illusions, Lord of Unreality == Continue boolean;

int Sthanee_ReadShares();
	//Sthanee == The Lost One == Reads in the number of shares;

void Hastur_ReadInput(int& cash, int& numerator, int& denominator);
	//Hastur == The Unspeakable, He Who is Not to be Named, Lord of Interstellar Spaces, The King in Yellow.
	//Asks users for an input. Changes the value of cash, numerator and denominator.

double Sedmelluq_Calculate(int shares, int cash, int numerator, int denominator);
	//Sedmelluq == The Great Manipulator, Ishmagon == Manipulates the numbers and calculates the outcome;

void Uvhash_Output(double newcash,int shares,int cash,int numerator,int denominator);
	//Uvhash == The Blood_Mad God of the Void == Takes in all the variables and cout's everything.

int main ()
{
	bool Continue = true;
	int cash, numerator, denominator;

	do
	{
		int shares = Sthanee_ReadShares();
		Hastur_ReadInput(cash, numerator, denominator);
		double newcash = Sedmelluq_Calculate(shares, cash, numerator, denominator);
		Uvhash_Output(newcash, shares, cash, numerator, denominator);
		Continue = Xirdneth_Continue();
	}while(Continue == true);

	return 0;
}

bool Xirdneth_Continue()
{
	char cont;
	cout << "Continue: ";
	cin >> cont;

	if (cont == 'y' || cont == 'Y')
		return true;

	return false;
}

int Sthanee_ReadShares()
{
	int shares;
	cout << "Enter number of shares: ";
	cin >> shares;

	return shares;
}

void Hastur_ReadInput(int& cash, int& numerator, int& denominator)
{
	cout << "Enter price (dollars, numerator, denominator): ";
	cin >> cash >> numerator >> denominator;
}

double Sedmelluq_Calculate(int shares, int cash, int numerator, int denominator)
{
	double dubnum = numerator;  //Ensures us that the outcome will be double.
	double newcash = (cash + (dubnum / denominator)) * shares;

	return newcash;
}

void Uvhash_Output(double newcash,int shares,int cash,int numerator,int denominator)
{
	cout.setf(ios::fixed);
	cout.precision(2);
		cout << shares << " shares with market price " << cash << " ";
		cout << numerator << "/" << denominator;
		cout << " have value $" << newcash << endl;
}
