#include <iostream>
using namespace std;
int main ()

{
	//Lab Manual 3, prime numbers.//
	int n;
	
	cout << "Enter number: ";
	cin >> n;
	
	if(n==2){
	cout << "prime";
	}
	else if(n==1){
		cout <<"Not prime";
	}	
	else if(n%2!=0){
	
	cout << "Prime";
}
	else{
		cout <<"Not prime";
	}

return 0;
}
