#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
#define BUFFER 1024
char toLowerCase(char *x_ptr)
{
    if (isupper(*x_ptr) == true)
    {
        *x_ptr = *x_ptr + 32;
    }
    else
    {
        *x_ptr = *x_ptr;
    }
    return *x_ptr;
}
int main()
{
    char X[BUFFER];
    char res[BUFFER];
    char *ptr = NULL;
    cout << "X: ";
    fgets(X, BUFFER, stdin);
    ptr = X;
    cout << "Lowercase: ";
    for (int i = 0; i <= strlen(X); i++)
    {
        res[i] = toLowerCase(ptr + i);
        cout << res[i];
    }
}