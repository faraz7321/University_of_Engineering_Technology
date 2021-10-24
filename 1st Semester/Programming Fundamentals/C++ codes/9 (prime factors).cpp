#include <iostream>
using namespace std;
int main ()

{
	//Lab Manual 3, prime factors.//
	int in, x;
	
	cout << "Enter number: ";
	cin >> in;
	cout << "Prime factors are: ";
	
	x=2;
	while (x<=in){
		
		while(in%x==0){
			in=in/x;
			cout << x << ", ";
		}
		
		x=x+1;
	}
	
	
}
