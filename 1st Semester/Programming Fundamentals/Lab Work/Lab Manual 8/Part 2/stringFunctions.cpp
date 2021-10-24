#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
#define BUFFER 1024
using namespace std;
bool startsWith(string Y, string Z);
bool endsWith(string Y, string Z);
string toLowerCase(string X);
string *tokenizer(string X, char Y);
string replace(string X, string Y, string Z);
bool contains(string Y, string Z);
string removeSpaces(string Z);
string removeSpaces(string Z, int start, int end);
//Part 2.//
bool startsWith(char Y[], char Z[]);
bool endsWith(char Y[], char Z[]);
char toLowerCase(char *x_ptr);
char *tokenizer(char X[], char Y);
char *replace(char X[], char Y[], char Z[]);
bool contains(char Y[], char Z[]);
char *removeSpaces(char Z[]);
char *removeSpaces(char Z[], int start, int end);
int main()
{
    {
        //Lab Task 1 (startsWith() function).//
        string y, z;
        cout << "Y: ";
        getline(cin, y);
        cout << "Z: ";
        getline(cin, z);
        startsWith(y, z);
        if (startsWith(y, z) == true)
        {
            cout << "True\n";
        }
        else if (startsWith(y, z) == false)
        {
            cout << "False\n";
        }
    }
    //Lab Task 2 (endsWith() function).//
    {
        string y, z;
        cout << "Y: ";
        getline(cin, y);
        cout << "Z: ";
        getline(cin, z);
        endsWith(y, z);
        if (endsWith(y, z) == true)
        {
            cout << "True\n";
        }
        else if (endsWith(y, z) == false)
        {
            cout << "False\n";
        }
    }
    //Lab Task 3 (toLowerCase() function).//
    {
        string X;
        cout << "X: ";
        getline(cin, X);
        cout << "Lowercase string: " << toLowerCase(X);
    }
    //Lab Task 4 string* tokenizer(string X, char Y) function).//

    //Lab Task 5 string replace(string X, string Y, string Z) function).//
    {
        string x, y, z;
        cout << "X: ";
        getline(cin, x);
        cout << "Y: ";
        getline(cin, y);
        cout << "Z: ";
        getline(cin, z);
        cout << replace(x, y, z);
    }
    //Lab Task 6 bool contains(string Y, string Z) function).//
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
    //Lab Task 7 string removeSpaces(string Z).//
    {
        string Z;
        cout << "Z: ";
        getline(cin, Z);
        cout << removeSpaces(Z);
    }
    //Lab Task 8 string removeSpaces(string Z, int start, int end).//
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
    }
    //Lab Task 1.1 bool startsWith(char Y[], char Z[]) .//
    {
        /* code */
    }

    //Lab Task 2.1  bool endsWith(char Y[], char Z[]).//
    {
        /* code */
    }

    //Lab Task 3.1  char* toLowerCase(char X[]).//
    {

        char X[BUFFER];
        char res[BUFFER];
        char *ptrD = NULL;
        cout << "X: ";
        fgets(X, BUFFER, stdin);
        ptrD = X;
        for (int i = 0; i <= strlen(X); i++)
        {
            res[i] = toLowerCase(ptrD + i);
        }
        cout << "Lowercase: ";
        for (int i = 0; i <= strlen(X); i++)
        {
            cout << res[i];
        }
    }

    //Lab Task 4.1  char* *tokenizer(char X[], char Y).//
    {
        /* code */
    }

    //Lab Task 5.1  char* replace(char X[], char Y[], char Z[]).//
    {
        /* code */
    }

    //Lab Task 6.1  bool contains(char Y[], char Z[]).//
    {
        /* code */
    }

    //Lab Task 7.1 char* removeSpaces(char Z[]).//
    {
        /* code */
    }

    //Lab Task 8.1 char* removeSpaces(char Z[], int start, int end).//
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

    return 0;
}
bool startsWith(string Y, string Z)
{
    bool flag = false;
    int zlen = Z.length();
    for (int i = 0; i < zlen; i++)
    {
        if (Y[i] == Z[i])
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}
bool endsWith(string Y, string Z)
{
    bool flag = false;
    int zlen = Z.size();
    int ylen = Y.size();
    int x = ylen - zlen;
    for (int i = 0; i < zlen; i++)
    {
        if (Y[x + i] == Z[i])
        {
            flag = true;
        }
        else
        {
            flag = false;
        }
    }
    return flag;
}
string toLowerCase(string X)
{
    int len = X.size();
    //string ret;
    for (int i = 0; i < len; i++)
    {
        if (isupper(X[i]) == true)
        {
            X[i] = X[i] + 32;
        }
        else
        {
            X[i] = X[i];
        }
    }
    return X;
}
string *tokenizer(string X, char Y)
{
    /* code */
}
string replace(string X, string Y, string Z)
{
    int lenX = X.size();
    int lenY = Y.size();
    for (int i = 0; i < lenY; i++)
    {
        for (int k = 0; k < lenX; k++)
        {
            if (X[k] == Y[i])
            {
                X[k] = Z[i];
            }
        }
    }
    return X;
}
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
            count = 0;
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
string removeSpaces(string Z)
{
    int count = 0;
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
//Part 2.//
bool startsWith(char Y[], char Z[])
{
    /* code */
}
bool endsWith(char Y[], char Z[])
{
    /* code */
}
char toLowerCase(char *x_ptr)
{
return tolower(*x_ptr);
}
char *tokenizer(char X[], char Y)
{
    /* code */
}
char *replace(char X[], char Y[], char Z[])
{
    /* code */
}
bool contains(char Y[], char Z[])
{
    /* code */
}
char *removeSpaces(char Z[])
{
    /* code */
}
char *removeSpaces(char Z[], int start, int end)
{
    //int lenZ = Z.size();  to be fixed
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