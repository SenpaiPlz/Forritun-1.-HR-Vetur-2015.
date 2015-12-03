#include <iostream>
using namespace std;

int main ()
{	
	char waifu_name = 'a';
	int age = 0;
	cout << "Initial: ";
	cin >> waifu_name;
	cout << "Age: ";
	cin >> age;
	age = age + 10;
	cout << "Hello " << waifu_name << ", in 10 years you will be " << age << " years old!" << endl;
	return 0;
}