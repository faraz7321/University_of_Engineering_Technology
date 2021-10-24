#include <iostream>
#include<iomanip>
using namespace std;
int main()

{
    string student[5]; //student and marks are parallel
    int marks[5];      //arrays, notice the same size of both
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter Name of student " << i + 1 << ": ";
        getline(cin, student[i]); //for input of spaces into string data type
        cout << "Enter Marks of student " << i + 1 << ": ";
        cin >> marks[i];
        cout << endl;
        cin.ignore(25, '\n');
    }
    cout <<left<< setw(15) << "Student Name" <<left<<setw(15) << "Marks"<< endl;
    for (int i = 0; i < 5; i++)
    {
        cout << left << setw(15) << student[i] << left << setw(15) << marks[i] << endl;
    }

    return 0;
}