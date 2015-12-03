#include <iostream>
//#include <string>
//#include <math.h>
#include <vector>
//#include <stdio.h>
//#include <algorithm>
//#include <cctype>
//#include <cstdlib>
//#include <sstream>
//#include <fstream>

using namespace std;

vector<int> ReadInput();
	//Reads the input into a vector, stops reading at first negative integer.
	
vector<int> IndexChecker(const vector<int>& input);
	//Checks where all even integers are located and stores the location in a vector.
	
void inputintoarray(const vector<int>& index,const vector<int>& data,int arr[]);
	//Takes all the even integers and inputs them into a dynamic array, swaps every two integers in the array.
	
void outputdesu(const int arr[],const vector<int>& index);
	//Simply outputs the array.

int main ()
{
	vector<int> data = ReadInput();
	vector<int> index = IndexChecker(data);
	int* arr = new int [index.size()];
	inputintoarray(index,data,arr);
	outputdesu(arr,index);

	delete[] arr;
	return 0;
}

vector<int> ReadInput()
{
	int num;
	vector<int> input;
	do
	{
		cin >> num;
		if(num >= 0)
		{
			input.push_back(num);
		}
	}while(num >= 0);
	
	return input;
}

vector<int> IndexChecker(const vector<int>& input)
{
	vector<int> indexes;
	for(size_t i = 0; i < input.size(); i++)
	{
		if(input[i] % 2 == 0)
		{
			cout << input[i] << " ";
			indexes.push_back(i);
		}
	}
	cout << endl;

	return indexes;
}

void inputintoarray(const vector<int>& index,const vector<int>& data, int arr[])
{
	int count = 1;
	for(size_t i = 0; i < index.size(); i++, count++)
	{
		arr[i] = data[index[i]];
		if(count % 2 == 0 && count-2 >= 0)
		{
			int temp = arr[count-2];
			arr[count-2] = arr[count-1];
			arr[count-1] = temp;
		}
	}
}

void outputdesu(const int arr[],const vector<int>& index)
{
	for(size_t i = 0; i < index.size(); i++)
	{
		cout << arr[i] << " ";
	}
}
