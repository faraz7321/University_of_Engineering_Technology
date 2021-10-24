#include <iostream>
using namespace std;
int main()
{
    system("cls");
    short int i;
    int n;
    cout << "Enter even size of array: ";
    cin >> n;
    int *ptr = new int[n];
    for (i = 0; i < n; i++)
    {
        cin >> ptr[i];
    }
    cout << "Initial array: \n";
    for (i = 0; i < n; i++)
    {
        cout << ptr[i] << "   ";
    }
    cout << "\n\n";

    cout << "After splitting: \n";
    for (i = 0; i < n/2; i++)
    {
        cout << *(ptr + i) << "\t";
        //ptr++;
    }
    cout << endl;
    for (i = n/2; i < n; i++)
    {
        cout << *(ptr + i) << "\t";
    }
    delete [] ptr;
    return 0;
}