#include <iostream>
using namespace std;

const int MAX_SIZE = 20;

void fillArray(int a[], int size, int& numberUsed);
void sort(int a[], int numberUsed);
void swapValues(int& v1, int& v2);
void displayArray(const int a[], int numberUsed);

int main( )
{
	int sampleArray[MAX_SIZE], numberUsed;

	fillArray(sampleArray, MAX_SIZE, numberUsed);
	sort(sampleArray, numberUsed);

	cout << "In sorted order the numbers are:\n";
	displayArray(sampleArray, numberUsed);

	return 0;
}

void fillArray(int a[], int size, int& numberUsed)
{
	cout << "Enter up to " << size << " nonnegative whole numbers.\n"
	<< "Mark the end of the list with a negative number.\n";
	int next, index = 0;
	cin >> next;
	while ((next >= 0) && (index < size))
	{
		a[index] = next;
		index++;
		cin >> next;
	}
	numberUsed = index;
}

void sort(int a[], int numberUsed)
{
	for(int i = 1; i < numberUsed; i++)
	{
		int j = i;
		while(j > 0 && a[j-1] > a[j])
		{
			swapValues(a[j],a[j-1]);
			j--;
		}
		displayArray(a, numberUsed);
	}
}


void swapValues(int& v1, int& v2)
{
	int temp;
	temp = v1;
	v1 = v2;
	v2 = temp;
}


void displayArray(const int a[], int numberUsed)
{
	for (int index = 0; index < numberUsed; index++)
	cout << a[index] << " ";
	cout << endl;
}
