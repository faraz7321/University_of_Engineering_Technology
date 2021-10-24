#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
string replace(string X, string Y, string Z)
{
    int lenX = X.size();
    int lenY = Y.size();
    int res=lenX-lenY+Z.size();
    for (int i = 0; i < lenY; i++)
    {
        for (int k = 0; k < lenX; k++)
        {
            if (X[k] == Y[i])
            {
                X[k] = Z[i];
            }
        }
    }
    return X;
}
int main()
{
    string X, y, z;
    cout << "X: ";
    getline(cin, X);
    cout << "Y: ";
    getline(cin, y);
    cout << "Z: ";
    getline(cin, z);
    cout << replace(X, y, z);
}