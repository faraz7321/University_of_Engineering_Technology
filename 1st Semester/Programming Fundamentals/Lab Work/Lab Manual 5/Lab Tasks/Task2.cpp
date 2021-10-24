#include <iostream>
using namespace std;
int main()
{
    int i,j=1, sum = 0, pro = 1, array[5];
    int *ptr=&array[0];
    for (i = 0; i < 5; i++)
    {
        cout << "Enter Number " << j << ": ";
        cin >> *ptr;
        sum = sum + *ptr;
        pro = pro * *ptr;
        j++;
        ptr++;
    }
    cout << "sum of all elements is: " << sum << endl
         << "Product of all elements is: " << pro << endl;
}