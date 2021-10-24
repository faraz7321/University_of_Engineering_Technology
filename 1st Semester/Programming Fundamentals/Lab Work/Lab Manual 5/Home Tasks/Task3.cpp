#include<iostream>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int main()

{
	char e[40];
	int l,i;
	bool check=false;
	cout << "Enter Email Address: "<< endl;
	cin >> e;
	l=strlen(e);
	for (i=0;i<l;i++){
		if (e[i]=='@' && e[0]!='@'){
			check=true;
		}
	}
	//.com checker
	//[l-1]=='m' [l-2]=='o' [l-3]=='c' [l-4]=='.'
	//if(check==true){
		//if ()

	//}
	if(check==false){
		cout << "Invalid Email address";
	}

	return 0;
}
