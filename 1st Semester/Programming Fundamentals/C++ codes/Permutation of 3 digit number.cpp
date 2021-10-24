#include<iostream>
#include<string>
using namespace std;
int main()

{
	//Lab manual 3. Permutation
    int x, y, z;

    cout << "Enter three digit input: ";
	cin >> x >> y >> z; //Put space after entering each digit and press enter after last digit.//
    

    cout << x << y << z << endl
         << x << z << y << endl
         << y << x << z << endl
         << y << z << y << endl
         << z << x << y << endl
         << z << y << x << endl;


    return 0;
}
