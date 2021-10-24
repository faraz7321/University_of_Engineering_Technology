#include <iostream>
using namespace std;
int main()

{
	//Lab Manual 3, 10
	int n=1;
	int x;
	int count;
	
	cout << "Enter number: ";
	cin >> x;
	
	while(n<=x){
	count=1; //reset.//
	
	while(count<=n){
	cout << "*"; 
	count=count+1;
	}
	cout <<endl;
	n=n+1;
}
	return 0;
}
