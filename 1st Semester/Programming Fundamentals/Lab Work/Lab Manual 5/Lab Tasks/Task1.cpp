#include <iostream>
using namespace std;
int main ()
{

    string a[3];
    string y[3] ,reg[3];

    for (int i = 0; i < 3; i++)
    {
        cout << "dept?: ";
    cin>> a[i];
    cout << "year?: ";
    cin >> y[i];
    cout << "reg no: ";
    cin >>reg[i];
    }
    
    
    for (int i = 0; i < 3; i++)
    {
        cout <<endl <<y<<"-"<<a<<"-"<<reg;
    }
    

    return 0;
}
