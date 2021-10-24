#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
bool contains(string Y, string Z)
{
    int lenY = Y.size(), lenZ = Z.size(), count = 0;
    bool flag = false;
    for (int i = 0; Y[i] != '\0'; i++)
    {
        if (count == lenZ)
        {
            break;
        }
        else if (Y[i] == Z[count] && Z[count] != '\0' && Y[i] != ' ')
        {
            count++;
        }
        else
        {
            count = 0;// counter reset.
        }
    }
    if (count == lenZ)
    {
        flag = true;
    }
    else
    {
        flag = false;
    }
    return flag;
}
int main()
{
    string y, z;
    cout << "Y: ";
    getline(cin, y);
    cout << "Z: ";
    cin >> z;
    if (contains(y, z) == true)
    {
        cout << "True";
    }
    else if (contains(y, z) == false)
    {
        cout << "Flase";
    }
}
