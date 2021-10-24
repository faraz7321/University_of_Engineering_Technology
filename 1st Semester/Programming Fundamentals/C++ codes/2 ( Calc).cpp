#include <iostream>
#include <cmath>
using namespace std;
int main() 

{
	//Lab Manual 3. Calculator 2
   int x;
   int y;
   float ans;
   char A;
   
   cout << "Welcome to calculator" << endl
        << "Enter operator(+, -, /, *,% ,&& ,|| ,>> ,<< ,<= ,>= ,!=):  ";
    cin >> A;
    
   cout << "Enter 1st number: ";
   cin >>x;
   
    /*Error message
    
        //if(A>5){
    	
    			cout << "Error! Invalid operator selected. Try again :) " << endl;
    		
		}*/
	
   cout << "Enter 2nd Number: ";
   cin >> y;
   
   if (A=='*'){
   	ans=x*y;
   }
   if (A=='/'){
   	ans=x/y;
   }
   if (A=='+'){
   	ans=x+y;
   }
   if (A=='-'){
   	ans=x-y;
   }
   
   cout << "Calculated value: " << ans;



   	return 0;
   	
}
