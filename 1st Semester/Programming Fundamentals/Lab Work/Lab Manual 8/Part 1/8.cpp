#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
string removeSpaces(string Z, int start, int end)
{
    int len = end - start, lenZ = Z.size();
    bool flag = false;
    char subZ[len];
    for (int i = start; i <= end; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            subZ[j] = Z[i];
            i++;
            flag = true;
        }
        if (flag == true)
        {
            break;
        }
    }
    Z = subZ;
    return Z;
}
int main()
{
    int start, end;
    string Z;
    cout << "Z: ";
    getline(cin, Z);
    cout << "start: ";
    cin >> start;
    cout << "end: ";
    cin >> end;
    cout << removeSpaces(Z, start, end);
    return 0;
}
