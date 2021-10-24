#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
char *removeSpaces(char Z[])
{

    int count = 0, len = Z.size();
    for (int i = 0; Z[i]; i++)
    {
        if (Z[i] != ' ')
        {
            Z[count++] = Z[i];
        }
    }
    Z[count] = '\0';
    return Z;
}

int main()
{
    string Z;
    cout << "Z: ";
    getline(cin, Z);
    cout << removeSpaces(Z);
}