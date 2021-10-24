#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
string *tokenizer(string X, char Y)
{
    int len=X.size(), counter=0;
    for (int i = 0; i < len; i++)
    {
        if (X[i]==Y)
        {
            counter++;
        }
    }
}
int main()
{
    string X;
    char Y;
    cout << "X: ";
    cin >> X;
    cout << "Y: ";
    cin >> Y;
    tokenizer(X, Y);
    cout << "Return string array of size" << /*number of element*/ << " with the following elements " <<;

