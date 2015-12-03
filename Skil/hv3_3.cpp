#include <iostream>
#include <string>
using namespace std;

int main ()
{
	int Starsforthespangledbanner;
	cin >> Starsforthespangledbanner;
	for( int i = Starsforthespangledbanner; i > 0; i--)
	{
		for (int j = i; j > 0; j--)
		{
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}
