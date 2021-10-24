#include <iostream>
using namespace std;

int main() 
{
	double n, c;
	double y=0;
	
	while(!(n==-1)){
			cout << "Enter number: ";
			cin >> n;
			cout << endl;
		
		if(n>=y){
			c=y;
			y=n;
			
		}

	}
	
	cout << "Greatest number of them is: "<< c;
  return 0;
}
