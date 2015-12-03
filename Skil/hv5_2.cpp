#include <iostream>

using namespace std;

const string units[19] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
const string tens[8] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int ReadInput();
void WriteOutput(int choice);

int main ()
{
	bool Continue = true;
	do
	{
		int choice = ReadInput();
		if (choice <= 0 || choice > 99)
		{
			Continue = false;
		}
		else
		{
			WriteOutput(choice);
		}
	}while(Continue == true);
	return 0;
}

int ReadInput()
{
	cout << "Input number: ";
	int a;
	cin >> a;

	return a;
}

void WriteOutput(int choice)
{
	if(choice / 20 == 0)
	{
		cout << units[choice-1] << endl;
	}
	else
	{
		int temp = choice / 10;
		cout << tens[temp-2];
		//temp-2 because, if choice == 20. then temp == 2. But twenty is in tens[0] and temp-2 == 0;
		choice = choice % (temp*10);
		if(choice != 0)
		{
			cout << "-" << units[choice-1] << endl;
		}
	}
}

/* Im sad to say I didnt have enough time to have make silly names or comments this week, perhaps next week*/