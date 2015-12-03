#include <iostream>
//#include <String>
using namespace std;

int main ()
{
    cout << "How many exercises to input: ";
	int num_o_excercises;
	cin >> num_o_excercises;

		cout.setf(ios::fixed);
		cout.setf(ios::showpoint);
		cout.precision(2);

	if( num_o_excercises < 1 )
		cout << "Input at least one exercise!";
	else
	{
	    double percentage;
		double points = 0;
		double possiblepoints = 0;
		int n = 1;
		do
		{
            double num;
		    double num2;
                cout << "Score received for exercise " << n << ": ";
                    cin >> num;
                cout << "Total points possible for exercise " << n << ": ";
                    cin >> num2;
			points = points + num;
			possiblepoints = possiblepoints + num2;
			num_o_excercises--;
			n++;
		}while(num_o_excercises >= 1);

		percentage = (points / possiblepoints)*100;

		cout << "Your total is " << points << " out of " << possiblepoints << ", or " << percentage << "%.";
	}
	return 0;
}
