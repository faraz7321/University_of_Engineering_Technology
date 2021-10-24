#include<iostream>
using namespace std;
int main()

{
	long int x =0, y=1;
    long int z, n, ans;
    int count=0;
    
	cin >> z;
    cout << x << ", " << y << ", ";
        for( n=3; n<=z ; n++){
        	
            ans=x+y;
            cout << ans << ", ";
            //Alternate for counter.
			x=y;
            y=ans;                                    
 
//        if(count==0){
// 	    x=ans;
// 	    count=1;
//        }
// 
//        else {
//      	y=ans;
// 	    count=0;
//        }	


        
}
return 0;
}
