#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

using namespace std;

class Sales
{
public:
    Sales(vector<double> d) {D4t4 = d;}
    double getAverage();
    void addSales(double d);
private:
    vector<double> D4t4;
    double average;
};

void readSales(vector<double>& data);

int main()
{
    vector<double> data;
    readSales(data);
    Sales sales(data);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Average sales: " << sales.getAverage() << endl;
    sales.addSales(78.5);
    cout << "Average sales: " << sales.getAverage() << endl;

    return 0;
}

void readSales(vector<double>& data)
{
    ifstream file;
    double d;
    file.open("sales.dat", ios::app);
    if(file.fail())
    {
        exit(1);
    }
    while( file >> d)
    {
        data.push_back(d);
    }
    file.close();
}

double Sales::getAverage()
{
    average = 0;
    for(unsigned int i = 0; i < D4t4.size(); i++)
    {
        average = average + D4t4[i];
    }
    average = average/D4t4.size();
    return average;
}

void Sales::addSales(double d)
{
    D4t4.push_back(d);
}
