#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
char *removeSpaces(char Z[], int start, int end)
{
    int lenZ = Z.size();
    int len = end - start;
    bool flag = false;
    char subZ[len];
    for (int i = start; i <= end; i++)
    {
        for (int j = 0; j <= len; j++)
        {
            subZ[j] = *(Z++);
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
    char *Z;
    cout << "Z: ";
    cin >> Z;
    cout << "start: ";
    cin >> start;
    cout << "end: ";
    cin >> end;
    cout << removeSpaces(Z, start, end);
}