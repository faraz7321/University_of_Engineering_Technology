#include <iostream>
using namespace std;
int main()
{
    int array[7];

    //input into array
    for (int i = 0; i < 7; i++)
    {
        cout << "Enter a number: ";
        cin >> array[i];
    }
    //output of the array
    for (int i = 0; i < 7; i++)
    {
        cout << array[i] << endl;
    }
    return 0;
}