#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
bool endsWith(string Y, string Z)
{
    bool flag = false;
    int zlen = Z.size();
    int ylen = Y.size();
    int x = ylen - zlen;
    for (int i = 0; i < zlen; i++)
    {
        if (Y[x + i] == Z[i])
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}
int main()
{
    //Lab Task 2 (endsWith() function).//
    string y, z;
    cout << "Y: ";
    getline(cin, y);
    cout << "Z: ";
    getline(cin, z);
    endsWith(y, z);
    if (endsWith(y, z) == true)
    {
        cout << "True\n";
    }
    else if (endsWith(y, z) == false)
    {
        cout << "False\n";
    }
    return 0;
}
