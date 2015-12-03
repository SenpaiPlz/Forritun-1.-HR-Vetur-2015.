#include <iostream>
#include <string>
using namespace std;

const int rlimit = 10;
const int llimit = 1;

int left (int i)
{
	if( i == llimit )
		return i;
	else
	{
		i = i - 1;
		return i;
	}
}

int right (int i)
{
	if( i == rlimit )
		return i;
	else
	{
		i = i + 1;
		return i;
	}
}

int switches (char GrandDecision, int i)
{
	switch(GrandDecision)
			{
				case 'l':
				{
					i = left(i);
					cout << "New position is: " << i << endl;
					return i;
					break;
				}
				case 'r':
				{
					i = right(i);
					cout << "New position is: " << i << endl;
					return i;
					break;
				}
				default:
				{
				    cout << "New position is: " << i <<endl;
					i = 0;
					return i;
					break;
				}
			}
}
int main ()
{
	cout << "Input an position between 1 and 10: ";
	int i;
		cin >> i;
	if( i >= llimit && i <= rlimit )
		do
		{
		    cout << "l - for moving left" << endl
                 << "r - for moving right" << endl
                 << "Any other letter for quitting" << endl
                 << "Input your choice: ";
			char GrandDecision;
			cin >> GrandDecision;
			i = switches(GrandDecision, i);

		}while(i != 0);

    return 0;
}
