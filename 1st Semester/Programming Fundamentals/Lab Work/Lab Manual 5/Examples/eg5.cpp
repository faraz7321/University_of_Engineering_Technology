#include <iostream>
#include <cstring> //give the functions for the character array(See the details in book)
using namespace std;
int main()
{
    char array1[20];
    char array2[20];
    cout << "Enter a string:";
    cin >> array1;
    int arraySize = strlen(array1); //strlen return the length of string entered by users
    cout << "Size of the array: " << arraySize << endl;
    for (int i = 0; i < arraySize; i++)
    {
        array2[i] = array1[i];
    }
    array2[arraySize] = '\0'; //remove this line the write down the effect on output
    cout << "Entered string is " << array1 << endl;
    cout << "Copied string is " << array2 << endl;

    return 0;
}