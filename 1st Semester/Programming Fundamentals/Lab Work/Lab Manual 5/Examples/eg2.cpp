#include <iostream>
using namespace std;
int main()
{
    int array1[5];
    int array2[5];
    //input into array1
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter a number: ";
        cin >> array1[i];
    }
    //copy of the array1 into array2
    for (int i = 0; i < 5; i++)
    {
        array2[i] = array1[i];
    }
    //output of the array2
    for (int i = 0; i < 5; i++)
    {
        cout << array2[i] << endl;
    }
    return 0;
}