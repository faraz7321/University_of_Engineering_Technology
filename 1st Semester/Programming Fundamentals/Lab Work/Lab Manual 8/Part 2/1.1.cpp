#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#define BUFFER 1024
using namespace std;
bool startsWith(char Y[], char Z[]){
    bool flag = false;
    for (int i = 0; i < strlen(Y) + 1; i++)
    {
        if (Y[i] == Z[i])
        {
            flag = true;
        }
        else {
            flag = false;
        }
    }
    return flag;
}
int main()
{
    char y[BUFFER] = { 0 };
    char z[BUFFER] = { 0 };
    cout << "Y: ";
    //cin >> y;
    fgets(y, BUFFER, stdin);
    cout << "Z: ";
    fgets(z, BUFFER, stdin);

    startsWith(y, z); //a

    if (startsWith(y, z) == true)
    {
        cout << "True\n";
    }
    else if (startsWith(y, z) == false)
    {
        cout << "False\n";
    }
    return 1;
}