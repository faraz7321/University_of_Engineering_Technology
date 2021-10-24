#include<iostream>
using namespace std;
int main()

{
	//Lab manual 3. Display even numbers upto n.
	int n;
	int x=1;
	
	cout << "Enter integer: ";
	cin >> n;
	while(x<=n){//while loop starts here.
        if (x%2==0){
			cout << x ;
			if(x!=n){
			cout<< ", ";     //need to do format corrections
		}
		}
		
		// if (x==n&& x%2==0){
		// 	cout << x;
		// }
		// else if (x%2==0){
		// 	cout << x << ", ";
		// }
		
		x=x+1;
	}//while loop ends here.
	return 0;
}
