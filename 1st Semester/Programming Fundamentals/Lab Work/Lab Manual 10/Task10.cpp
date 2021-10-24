#include <iostream>
#include <iomanip>
using std::setiosflags;
using namespace std;
int main()
{
	system("CLS");
	const int MAX_SALES_PERSONS = 5, MAX_PRODUCTS = 6;
	double sales[MAX_SALES_PERSONS][MAX_PRODUCTS] = {0.0}, product_sales[MAX_PRODUCTS] = {0.0};
	double x, total_sales;
	int sales_person, product, terminate;

	while (terminate != -1)
	{
		cout << "Enter the sales person from 1 to 4: ";
		cin >> sales_person;
		cout << "Enter Product number from 1 to 5: ";
		cin >> product;
		cout << "Enter Total Sales: ";
		cin >> x;
		cout << endl;
		sales[sales_person][product] = sales[sales_person][product] + x;
		cout<< "Enter any number to continue or enter '-1' to show results.\n";
		cin >> terminate;
	} //Loop ends after terminating input (-1).//
	cout << endl
		 << setw(37) << "Product 1" << setw(20) << "Product 2" << setw(20) << "Product 3" << setw(20) << "Product 4" << setw(20) << "Product 5" << setw(16) << "Total\n"
		 << setiosflags(ios::fixed | ios::showpoint);

	for (int i = 1; i < MAX_SALES_PERSONS; ++i)
	{
		total_sales = 0.0; //Double.//
		cout << "Sales Person " << i;
		for (int j = 1; j < MAX_PRODUCTS; ++j) //Calculation for Total Sales.//
		{
			total_sales = total_sales + sales[i][j];
			cout << setw(20) << setprecision(2) << sales[i][j];
			product_sales[j] = product_sales[j] + sales[i][j];
		}
		cout << setw(18) << setprecision(2) << total_sales << '\n';
	}
	cout << "\nTotal" << setw(29) << setprecision(2) << product_sales[1];
	for (int j = 2; j < MAX_PRODUCTS; ++j)
	{
		cout << setw(20) << setprecision(2) << product_sales[j];
	}
	cout << endl;
	return 0;
}