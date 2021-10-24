#include<iostream>
using namespace std;
int main()

{
	//Lab manual 3. Factorial.
	char q='y';;
	int N;
	while (q=='y' || q=='Y'){     //while loop starts here.
	
	//factorial loop starts here.
	
    cout << "Enter factorial of number: ";
    cin >> N;
    int x=1;
    int fact=1;
    while(x<=N){
        fact=fact*x;
        x=x+1;

    }
    cout << "Computed factorial is:  " << fact << endl;
    //Factorial loop ends here.
    
    cout << "Do you want to calculate again (Y/N)?" <<endl;
    cin >> q;
    
}//while loop ends here.
return 0;
}

