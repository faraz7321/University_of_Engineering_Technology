#include<iostream>
using namespace std;
int main()

{
	//Lab manual 3. Salary
	char n;
	
	cout << "Enter your status" << endl
	     << "Enter 's' or 'S' for senior person's salary" << endl
         << "Enter 'j' or 'J' for junior person's salary" << endl;
         
         cin >> n;
         
         if(n=='j' || n=='J'){
         	cout << "Your salary is RS.275 per week";
		 }
         
         else if(n=='s' || n=='S'){
		 
         	cout << "Your salary is RS.400 per week";
         }
         else{
         	cout << "Invalid selection!";
		 }
  return 0;
}
