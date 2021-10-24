#include <iostream>
#include <cmath>
using namespace std;
int main() 

{
	//Lab Manual 3. calculator.//
	
   float x;
   float y;
   float ans;
   int A;
   
    cout << "Enter 1st number: ";
    cin >> x;
      cout << "Operations: " << endl
           << "Press '1' for Multiplication." << endl
           << "Press '2' for Division." << endl
           << "Press '3' for Addition." << endl
           << "Press '4' for Subtraction." << endl
           << "Press '5' to Raise Power by." << endl;
    
   cin >> A;
   
    /*Error message
    
        if(A>5){
    	
    			cout << "Error! Invalid operator selected. Try again :) " << endl;
    		
		}
	
   else{*/
   
   
   
   cout << "Enter 2nd Number: ";
   cout << endl;
   cin >> y;
   
   //Main code.//
   if (A==1){
   	ans=x*y;
   	cout << x << " * " << y << " = " << ans << endl;
   }
   else if(A==2 && y==0){
   	cout << "Error! Division by zero is not allowed";
   }
   else if (A==2){
   	ans=x/y;
   	cout << x << " / " << y << " = " << ans << endl;
   }
   else if (A==3){
   	ans=x+y;
   	cout << x << " + " << y << " = " << ans << endl;
   }
   else if (A==4){
   	ans=x-y;
   	cout << x << " - " << y << " = " << ans << endl;
   }
   else if (A==5){
   	ans=pow(x, y);
   	cout << x << " ^ " << y << " = " << ans << endl;
   }
   
   	return 0;
   	
}
