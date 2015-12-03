#include <iostream>

using namespace std;

const int MaxValue = 20;

int ReadInput();
void Error();
void Input(int arr[], int Size);
void SwapFrontBack(int arr[], int Size);
void OutPut(int arr[], int Size);

int main()
{
	int Size = ReadInput();
	if(Size <= 0 || Size > MaxValue )
	{
		Error();
	}
	else
	{
		int arr[MaxValue];
		Input(arr, Size);
		SwapFrontBack(arr, Size);
		OutPut(arr, Size);
	
	}

	return 0;
}

int ReadInput()
{
	cout << "Input size of array: ";
	int a;
	cin >> a;
	return a;
}

void Error()
{
	cout << "Invalid size! ";
}

void Input(int arr[], int Size)
{
	cout << "Input " << Size  << " elements: ";
	for(int i = 0; i < Size; i++)
	{
		cin >> arr[i];
	}
}

void SwapFrontBack(int arr[], int Size)
{
	int i = 0;
	int temp = arr[i];
	arr[i] = arr[Size-1];
	arr[Size-1] = temp;
}

void OutPut(int arr[], int Size)
{
	for(int i = 0; i < Size; i++)
	{
		cout << arr[i] << " ";
	}
}
//Mooshak really just loves to ruin indentations does it not...
//Whelp should be readable now. 