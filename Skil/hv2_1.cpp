#include <iostream>
//#include <String>
using namespace std;

int main ()
{
	int num;
	cout << "Input n: ";
	cin >> num;
	if(num > 0)
    {
        while( num != 0 )
        {
            if( num % 2 == 0 )
                cout << num << " is even" << endl;
            else
                cout << num << " is odd" << endl;
            num--;
        }
	}
	return 0;
}
