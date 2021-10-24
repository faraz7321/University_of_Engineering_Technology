#include <iostream>
using namespace std;
int main()
{
    char array[20];
    cout << "Enter a string:";
    cin.get(array, 13);
    cout << "Entered string is " << array << endl;
    return 0;
}