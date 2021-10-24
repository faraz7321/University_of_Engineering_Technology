#include <iostream>
#include <conio.h>
#include <iomanip>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

int main()
{
    char item[20];
    int quan, code, b, s;

    // ofstream outfile;
    // outfile.open("test.txt");

    // cin.getline(item, 20);
    // //cin.ignore();
    

    // outfile << item << endl;


    //outfile.close();

    ifstream infile;
    infile.open("test.txt");

    infile>>item;
    cout<<"Item: "<< item<<endl;

    infile>> quan;
    cout<<"Quantity: "<< quan;









}