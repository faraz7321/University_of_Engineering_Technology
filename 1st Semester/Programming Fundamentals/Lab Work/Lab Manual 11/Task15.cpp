#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	system("cls");
	int n;
	short int j = 1, i;
	cout << "Enter Number of Customer: ";
	cin >> n;
	cout << endl;
	int *mangoes = new int[n], *oranges = new int[n], *banana = new int[n], *bill = new int[n];
	for (i = 0; i < n; i++)
	{
		cout << "Customer" << j << ": \n";
		cout << "Enter Number of Mangoes: ";
		cin >> *(mangoes + i);
		cout << "Enter Number of Oranges: ";
		cin >> *(oranges + i);
		cout << "Enter Number of Banana: ";
		cin >> *(banana + i);
		j++;
		//bill.//
		*(bill + i) = *(mangoes + i) * 20 + *(oranges + i) * 10 + *(banana + i) * 5;
	}
	cout << "************************************************************************\n"
		 << left << setw(15) << "Customer No." << left << setw(15) << "Mangoes" << left << setw(15) << "Oranges"
		 << left << setw(15) << "Bananas" << left << setw(15) << "Total Bill\n"
		 << "************************************************************************\n";
	j = 1;
	for (i = 0; i < n; i++)
	{
		cout << left << setw(15) << j << left << setw(15) << *(mangoes + i) << left << setw(15) << *(oranges + i)
			 << left << setw(15) << *(banana + i) << "Rs. " << left << setw(15) << *(bill + i) << endl;
		j++;
	}
	delete[] mangoes;
	delete[] oranges;
	delete[] banana;
	delete[] bill;
	return 0;
}