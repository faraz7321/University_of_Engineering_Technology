#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
bool startsWith(string Y, string Z)
{
    bool flag = false;
    int zlen = Z.length();
    for (int i = 0; i < zlen; i++)
    {
        if (Y[i] == Z[i])
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
    string y, z;
    cout << "Y: ";
    getline(cin, y);
    cout << "Z: ";
    getline(cin, z);
    startsWith(y, z);
    if (startsWith(y, z) == true)
    {
        cout << "True\n";
    }
    else if (startsWith(y, z) == false)
    {
        cout << "False\n";
    }
    return 0;
}
