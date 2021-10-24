#include <iostream>
#include <string>
#include<cstring>
using namespace std;
int main()
{
    //cheaper logic.//
    /*int input;

    cout << "Enter string: ";
    cin >> input;
    if (!cin)
    {
        cout << "User enter string";
    }
    else
    {
        cout << "User Enter integer";
    }

    return 0;*/

    int i, x, l;
    char array[100];
    bool flag = 0;

    cout << "Enter the string: ";
    cin >> array;
    l=strlen(array);

    for (i = 0; i < l; i++)
    {
        if (array[i] >= 48 && array[i]<= 57)
        {
            //cout << int (array[i]);
            flag = 1;
        }
        else{
            flag=0;
            break; //If any alphabet is detected.//
        }
    }
    if (flag == 1)
    {
        cout << "User enter integer";
    }
    else if (flag == 0)
    {
        cout << "User enter string";
    }
    return 0; 
}