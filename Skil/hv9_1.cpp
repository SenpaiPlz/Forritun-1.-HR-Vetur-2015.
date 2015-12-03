#include <iostream>
//#include <string>
//#include <math.h>
//#include <vector>
//#include <stdio.h>
//#include <algorithm>
//#include <cctype>
//#include <cstdlib>
//#include <sstream>
//#include <fstream>

using namespace std;

class Circle
{
	public:
		double getRadius() const {return Radius;}
		
		double perimeter() const {return 2*pi*Radius;}
		
		double area() const {return pi*Radius*Radius;}
		
		void setRadius(double radius) {Radius = radius;}
		
		Circle(double radius) {Radius = radius;}
		
		/*Seeing this program is so simple I decided to implement the functions above as I declared them*/
		
	private:
		static const double pi = 3.14159;
		double Radius;
};


void circleInfo(Circle& circle)
{
	cout << "Area: " << circle.area() << endl;
	cout << "Perimeter: " << circle.perimeter() << endl;
}


int main ()
{
	double radius;
	cout << "Radius of circle: ";
	cin >> radius;
	Circle circle(radius);
	circleInfo(circle);
	circle.setRadius(circle.getRadius() + 1.0);
	circleInfo(circle);
	return 0;
}
