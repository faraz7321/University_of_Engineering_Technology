#include <iostream>
using namespace std;
int main()
{
    system("cls");
    short int i;
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int *ptr = new int[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter array element " << i + 1 << ": ";
        cin >> ptr[i];
    }
    cout << "Output array is " << endl
         << *ptr * *(ptr + 1) << " "; //First product
    for (i = 1; i < n - 1; i++)
    {
        cout << *(ptr + i + 1) * *(ptr + i - 1) << " ";
    }
    cout << *(ptr + n - 1) * *(ptr + n - 2); //Last Product
    delete[] ptr;
    return 0;
}