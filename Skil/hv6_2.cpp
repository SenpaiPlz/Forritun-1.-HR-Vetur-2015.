#include <iostream>
#include <string>
//#include <math.h>
//#include <vector>
//#include <stdio.h>
//#include <algorithm>

using namespace std;

const char SEPERATOR = '/';
const char YEARSEP = '.';
//Just in case you'd want to use another kind of standardized format.

string ThrowawayData();
int findindex(const string& str, int index);
void output(const string& str, int firstindex, int secondindex, int thirdindex, int dot);

int main ()
{
	string str = ThrowawayData();
	int firstindex = findindex(str, 0),
	secondindex = findindex(str, firstindex+1),
	thirdindex = findindex(str, secondindex+1);
		/*makes things simple by not having dynamic ammount of indexes (See standardized format)
		Grammar***
		*/
	int dot = str.find(YEARSEP, thirdindex+1);
		//Im not going to put this  into its own function... ;__;

	output(str, firstindex, secondindex, thirdindex, dot);

	return 0;
}

string ThrowawayData()
{
	string str;
	getline(cin, str);

	return str;
}

int findindex(const string& str, int index)
{
	int num = str.find(SEPERATOR, index);

	return num;
}

void output(const string& str, int firstindex, int secondindex, int thirdindex, int dot)
{
	int lengthbetweenindex;
	cout << "Registered_year: " << str.substr(dot+1, str.size()) << endl;
		/*Seeing that the year is always last, I can call an out of bounds size like str.size to make sure
		  that I always catch the ending. This works because of how the std::string::substr function treat out of bound sizes.
		  All this really does is save me a couple of lines of code*/

	lengthbetweenindex = thirdindex - secondindex;
	cout << "Campus: " << str.substr(secondindex+1, lengthbetweenindex-1) << endl;

	lengthbetweenindex = secondindex - firstindex;
	cout << "Course: " << str.substr(firstindex+1, lengthbetweenindex-1) << endl;

	cout << "Faculty: " << str.substr(0, firstindex) << endl;
}