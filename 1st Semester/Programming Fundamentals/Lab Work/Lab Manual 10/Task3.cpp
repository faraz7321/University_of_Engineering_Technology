#include <iostream>
#include <cstring>
#define BUFFER 1024
using namespace std;
int main()
{
    int array[BUFFER] = {NULL};
    for (int i = 0; i < BUFFER; i++)
    {
        cout << "Input: ";
        cin >> array[i];
        cout << "Output: {";
        for (int i = 0; i < BUFFER; i++)
        {
            if (array[i])
            {
                cout << array[i] << ",";
            }
        }
        cout << "}"<< endl;
    }
}