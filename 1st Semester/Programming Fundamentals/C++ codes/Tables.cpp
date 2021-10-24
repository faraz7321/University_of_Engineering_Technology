#include<iostream>
using namespace std;
int main()

{
	//Lab manual 3. Tables
	int x;
	int n=1;
	
	cout << "Enter integer: ";
	cin >> x;
	
	while(n<=10){//while loop starts here.
	cout << x << " * " <<n<<" = "<< x*n <<endl;
	n=n+1;
	}//while loop ends here.

return 0;
}
