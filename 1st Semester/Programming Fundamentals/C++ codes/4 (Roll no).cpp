#include <iostream>
#include <string>
using namespace std;
int main ()

{
	int year;
	int roll;
	string x;
	
	cout << "Enter your registration number: ";
	cin >> year >> x >> roll;
	if (year>=2017 && year<=2020){
		if (x=="-CS-" || x=="-CD-CS-"){
			if (roll>=1 && roll<=260){
				cout << year << x << roll << " is valid registration number" ;
			}
		}
	}
	

	
	
return 0;
}
