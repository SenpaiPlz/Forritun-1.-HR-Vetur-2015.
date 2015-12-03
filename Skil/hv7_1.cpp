#include <iostream>
#include <string>
//#include <math.h>
#include <vector>
//#include <stdio.h>
//#include <algorithm>
//#include <cctype>

using namespace std;

//indent fixes***

struct StructurallySound;
int EnterReps();
StructurallySound ReadInput(int num);
void getname(StructurallySound& info);
void getage(StructurallySound& info);
void getrating(StructurallySound& info);
void output(const StructurallySound& info);

struct StructurallySound
{
	vector<string> name;
	vector<int> age;
	vector<int> rating;
};

int main ()
{
	int num = EnterReps();
	StructurallySound info = ReadInput(num);
	output(info);
	return 0;
}

int EnterReps()
{
	cout << "Number of players: ";
	int num;
	cin >> num;
	return num;
}
StructurallySound ReadInput(int num)
{
	cout << "--- Reading players --- \n";
	StructurallySound info;
	for(int i = 0; i < num; i++)
	{
		getname(info);
		getage(info);
		getrating(info);
		cout << "\n";
	}
	return info;

}

void getname(StructurallySound& info)
{
	string str;
	cout << "Name: ";
	cin >> str;
	info.name.push_back(str);
}

void getage(StructurallySound& info)
{
	int num;
	cout << "Year: ";
	cin >> num;
	info.age.push_back(num);
}

void getrating(StructurallySound& info)
{
	int num;
	cout << "Rating: ";
	cin >> num;
	info.rating.push_back(num);
}

void output(const StructurallySound& info)
{
	int index = 0;
	double average = 0;
	cout << "--- Displaying players --- \n";
	for(size_t i = 0; i < info.name.size(); i++)
	{
		cout << "Name: " << info.name[i] << endl;
		cout << "Year: " << info.age[i] << endl;
		cout << "Rating: " << info.rating[i] << "\n\n";
		if(info.rating[i] > info.rating[index])
		{
			index = i;
		}
		average = average + info.rating[i];
	}
	average = average / info.rating.size();
	cout << "Highest rated player: \n"
	 << "\nName: " << info.name[index]
	 << "\nYear: " << info.age[index]
	 << "\nRating: " << info.rating[index] << "\n\n";
	cout << "Average rating: " << average;
}
