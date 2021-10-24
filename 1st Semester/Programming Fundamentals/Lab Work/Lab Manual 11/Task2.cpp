#include <iostream>
using namespace std;
int main()
{
    system("cls");
    int n;
    short int i, j = 1;
    int sum = 0, product = 1;
    cout << "Enter the size of array: ";
    cin >> n;
    int *ptr = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter Number " << j << ": ";
        cin >> *ptr;
        sum = sum + *ptr;
        product = product * *ptr;
        j++;
        ptr++;
    }
    delete[] ptr;
    cout << "Sum of all elements is: " << sum << endl
         << "Product of all elements is: " << product << endl;
    return 0;
}