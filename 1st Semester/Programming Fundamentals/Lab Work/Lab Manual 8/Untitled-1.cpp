#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <cctype>
using namespace std;
string toLowerCase(string x)
{
    int len = x.size();
    string ret[len] = {0};
    for (int i = 0; i < len; i++)
    {
        if (x[i] >= 'A' && x[i] <= 'Z')
        {
            x[i] = x[i] + 32;
            ret[i] = x[i];
            return ret[i];
        }
        else
        {
            ret[i] = x[i];
            return ret[i];
        }
    }
}
int main()
{
    string x;
    cout << "X: ";
    getline(cin, x);
    cout << "Lowercase string: ";
    //for (int i = 0; i < len; i++)
    //{
    cout << toLowerCase(x);
    // }
    return 0;
}