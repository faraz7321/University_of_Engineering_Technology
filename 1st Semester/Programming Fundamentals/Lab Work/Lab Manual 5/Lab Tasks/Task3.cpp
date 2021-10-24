#include <iostream>
using namespace std;
int main()
{
    int i, array[10];

    for (i = 0; i < 10; i++)
    {
        cin >> array[i];
    }
    cout << "Initial array: \n";
    for (i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << "\n\n";

    cout << "After splitting: \n";
    for (i = 0; i < 5; i++)
    {
        cout << array[i] << "\t";
    }
    cout << endl;
    for (i = 5; i < 10; i++)
    {
        cout << array[i] << "\t";
    }
    return 0;
}