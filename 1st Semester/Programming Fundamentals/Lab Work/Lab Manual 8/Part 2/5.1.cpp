#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
char *replace(char X[], char Y[], char Z[])
{
    int *lenX;
    *lenX = X.size();
    int *lenY;
    *lenY = Y.size();
    char arr1[lenX];
    char *parr1 = arr1;

    for (int i = 0; i < lenX; i++)
    {
        parr1++ = X++; //check iteration upon build.
    }
    for (int i = 0; i < lenX; i++)
    {
        for (int k = 0; k < lenY; i++)
        {
            if (arr1[k] == Y[i])
            {
                arr1[k] = Z[i];
            }
            else
            {
                arr1[k] = X[i];
            }
        }
    }
    X = arr1;
    return X;
}
int main()
{
    string x, y, z;
    cout << "X: ";
    getline(cin, x);
    cout << "Y: ";
    getline(cin, x);
    cout << "Z: ";
    getline(cin, x);
    cout << replace(x, y, z);
}