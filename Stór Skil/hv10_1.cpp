#include <iostream>
#include <iomanip>

using namespace std;

//Mooshak really loves to ruin indentation. It's as if it takes tab as /doublequad/ instead of normal /quad/

class Time
{
	public:
		Time();
		Time(const int& hr,const int& min,const int& sec);
		friend istream& operator >> (istream& in, Time& t);
		friend ostream& operator << (ostream& out, Time t);
			//We use call by value so that the case cout << S1 + Time(x,x,x); will output correcly.
		friend Time operator + (const Time& t1, const Time& t2);
		friend Time operator - (const Time& t1, const Time& t2);
		friend bool operator < (const Time& t1, const Time& t2);

	private:
		void normalize();
		int seconds;
		int minutes;
		int hours;
};

Time::Time()
{
	seconds = 0;
	minutes = 0;
	hours = 0;
}

Time::Time(const int& hr,const int& min,const int& sec)
{
	hours = hr;
	minutes = min;
	seconds = sec;
	normalize();
}

istream& operator >> (istream& in, Time& t)
{
	in >> t.hours >> t.minutes >> t.seconds;
	t.normalize();

	return in;
}

ostream& operator << (ostream& out, Time t)
{
		//Everything is stored normalized, so we can just output without normalizing.
	out << setw(2) << setfill('0') << t.hours << ":"
	<< setw(2) << setfill('0') <<  t.minutes << ":"
	<< setw(2) << setfill('0') << t.seconds << "\n";

	return out;
}

Time operator + (const Time& t1, const Time& t2)
{
	Time result(t1.hours + t2.hours, t1.minutes + t2.minutes, t1.seconds + t2.seconds);
	//Edge Case: Makes sure that it normalizes if you add 1 second to something at xx:59:59 it will output correctly.
	if(result.seconds >= 60)
	{
		result.seconds -= 60;
		result.minutes++;
	}
	if(result.minutes >= 60)
	{
		result.minutes -= 60;
		result.hours++;
	}
	result.normalize();

	return result;
}

Time operator - (const Time& t1, const Time& t2)
{
	Time result(t1.hours - t2.hours, t1.minutes - t2.minutes, t1.seconds - t2.seconds);
	result.normalize();

	return result;
}

bool operator < (const Time& t1,const Time& t2)
{
	int temp1 = t1.hours*3600 + t1.minutes*60 + t1.seconds;
	int temp2 = t2.hours*3600 + t2.minutes*60 + t2.seconds;
	if(temp1 < temp2)
		return true;

	return false;
}

void Time::normalize()
{
	int s = seconds;
	int m = minutes;
	int h = hours;

	while(s < 0)
	{
		s += 60;
		m--;
	}

	while(m < 0)
	{
		m += 60;
		h--;
	}

	while(h < 0)
	{
		h = h + 24;
	}

	seconds = s % 60;
	minutes = (m + s/60) % 60;
	hours = (h + m/60 + s/3600) % 24;
}


int main()
{
	Time t1, t2, t3, t4;
	cin >> t1;
	cin >> t2;
	cin >> t3;

	cout << "Time1: " << t1;
	cout << "Time2: " << t2;
	cout << "Time3: " << t3;

	t4 = t1 + t2;
	cout << "Time4: " << t4;

	t1 = t3 - t4;
	cout << "Time1: " << t1;

	if (t1 < t3)
		cout << "Time1 < Time3" << endl;
	else
	cout << "Time3 >= Time1" << endl;

	Time t5 = t2 + Time(0,0,1);
	if (t5 < t2)
		cout << "Time5 < Time2" << endl;
	else
		cout << "Time5 >= Time2" << endl;


	cout << "Almost midnight: " << Time(0,0,0) - Time(0,0,1) << endl;

	return 0;
}
