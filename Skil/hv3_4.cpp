#include <iostream>
#include <string>
using namespace std;

double Afhverjuthurfidiadverasvonabitrirbandarikjakarla(double num)
{
	num = (num*1.8) + 32;
	return num;
}

int main ()
{
	int Fahrenheitsuckar;
	cout << "Input maximum celsius: ";
	cin >> Fahrenheitsuckar;
	if(Fahrenheitsuckar < 0)
    {
        return 0;
    }
	for(int i = 0; i <= Fahrenheitsuckar; i++)
	{
		double num = i;
		cout << i << " ";
		cout << Afhverjuthurfidiadverasvonabitrirbandarikjakarla(num) << endl;
	}
	return 0;
}
