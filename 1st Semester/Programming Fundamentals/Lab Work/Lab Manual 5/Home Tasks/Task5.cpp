#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()

{
	int n;

	cout << "Enter Number of Customer: ";
	cin >> n;
	cout << endl;
	int cus[n], m[n], o[n], b[n], bill[n], j = 1, i;

	for (i = 0; i < n; i++)
	{
		cout << "Customer" << j << ": " << endl;
		cout << "Enter Number of Mangoes: ";
		cin >> m[i];
		cout << "Enter Number of Oranges: ";
		cin >> o[i];
		cout << "Enter Number of Banana: ";
		cin >> b[i];
		j++;
		//bill.//
		bill[i] = m[i] * 20 + o[i] * 10 + b[i] * 5;
	}
	cout << "************************************************************************" << endl
		 << left << setw(15) << "Customer No." << left << setw(15) << "Mangoes" << left << setw(15) << "Oranges"
		 << left << setw(15) << "Bananas" << left << setw(15) << "Total Bill" << endl
		 << "************************************************************************" << endl;
	j = 1;
	for (i = 0; i < n; i++)
	{
		cout << left << setw(15) << j << left << setw(15) << m[i] << left << setw(15) << o[i]
			 << left << setw(15) << b[i] << "Rs. "<< left << setw(15) << bill[i] << endl;
		j++;
	}
	return 0;
}