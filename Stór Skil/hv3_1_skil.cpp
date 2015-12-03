#include <iostream>
#include <string>
using namespace std;

int main ()
{
	//setur aukastafi == 2
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	cout << "Input the cost of the item in $: ";
	//constant afborganir
	const int payments = 50;
	//counter
	int Count;
	//       lán   vextir   total vextir      vaxtar prosenta
	double Loan, interest, alldemgolds = 0, interesetpercentage;
		cin >> Loan;
    cout << endl;
	// lán er minna en 2500 hætta.
	if ( Loan >= 2500 )
		return 0;
	// setur vaxtar prosentu
	if ( Loan > 1000)
		interesetpercentage = 0.02;
	else
		interesetpercentage = 0.015;
	//for loopa sem reiknar og skrifar út helstu upplýsingar
	for( Count = 1; Loan > 0; Count++)
	{
		interest = Loan * interesetpercentage;
		Loan = Loan - ( payments - interest );
		alldemgolds = interest + alldemgolds;
		cout << "Month: " << Count << ", Interest paid: " << interest << ", Remaining debt: " << Loan << endl;
	}
	//skifar út heild og fjölda mánuða.
	cout << endl << "Number of months: " << Count-1 << endl;
	cout << "Total interest paid: " << alldemgolds << endl;
	return 0;
}
