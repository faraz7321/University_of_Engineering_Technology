#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <cctype>
using namespace std;
string toLowerCase(string X)
{
    int len = X.size();
    //string ret;
    for (int i = 0; i < len; i++)
    {
        if (isupper(X[i]) == true)
        {
            X[i] = X[i] + 32;
        }
        else
        {
            X[i] = X[i];
        }
    }
    return X;
}
int main()
{
    string X;
    cout << "X: ";
    getline(cin, X);

    cout << "Lowercase string: " << toLowerCase(X);

    return 0;
}
//damn ni// yupppp