#include <iostream>
using namespace std;
int main()
{ //String length.//
    string X = "Programming";
    int size = X.length();
}

#include <iostream>
using namespace std;
int main()
{ //How to access character of string X.//
    string X = "Programming";
    char y = X[3]; // y now contains g
}

#include <iostream>
using namespace std;
int main()
{ //How to join two string X and string Y.//
    string X = "Samyan";
    string Y = "Wahla";
    string Z = X + Y;
    cout << Z << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{ // How to join string X with char y.//
    string X = "school";
    char Y = 's';
    string Z = X + Y;
    cout << Z << endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{ //What to do if I am unable to declare the array of variable sizes.//
    string array1[12];
    int size;
    cout << "enter size of array: ";
    cin >> size;
    string *array2 = new string[size];
    //declare array of varaible size //we will study this notation in details later return 0;
}