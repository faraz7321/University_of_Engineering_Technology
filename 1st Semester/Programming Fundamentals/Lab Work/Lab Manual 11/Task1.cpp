#include <iostream>
using namespace std;
int main()
{
    system("cls");
    int *ptr = new int[10];
    short int i, j = 1;
    //Taking input From the User//
    for (i = 0; i < 10; i++)
    {
        cout << "Enter Number " << j << ": ";
        cin >> *ptr;
        j++;
        ptr++;
    }
    //Prints number in reverse order
    for (i = 9; i >= 0; i--)
    {
        cout << *(ptr - 1) << endl;
        ptr--;
    }
    delete[] ptr;
    return 0;
}