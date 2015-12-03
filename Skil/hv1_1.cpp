#include <iostream>
using namespace std;

int main ()
{	
	int num_of_waifu = 0;
	double num_that_will_ruin_laifu = 0.0;
	
	cout << "Enter the cost of an item: ";
	cin >> num_of_waifu;
	num_that_will_ruin_laifu = num_of_waifu * 1.24;
	cout << "The total cost including VAT is: " << num_that_will_ruin_laifu << endl;
	return 0;
}