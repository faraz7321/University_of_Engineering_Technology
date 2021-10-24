#include <iostream>
#include <string>
#include <cctype>
using namespace std;
char to_lowercase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;

    return c;
}

int main()
{
    string str;
    getline(cin, str);
    for (char &c : str)
    {
        c = to_lowercase(c);
    }
    cout << str;
    return 0;
}
