#include<iostream>
#include<string>
using namespace std;
int main()
{
    string cnic;
    getline(cin, cnic);
    bool flag = false;
    bool check = false;
    if (cnic.length() == 13)
    {
        check = true;
    }
    if (check == true)
    {
        for (int i = 0; i < 13; i++)
        {
            if (cnic[i] >= '0' && cnic[i] <= '9')
            {
                cout << "VALID";
            }
        }
    }
    return 0;
}