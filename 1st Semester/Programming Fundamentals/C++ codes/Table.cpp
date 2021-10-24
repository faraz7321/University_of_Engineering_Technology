#include <iostream>

using namespace std;
int main()

{
   
   int x, n, ans;

   cout << "number: ";
   cin >> n;
   x =0;
   while (1)
   {
      x =x+1;
      if (x>9) break;
      if (x<=10){
      
         ans =x*n;
         cout << ans << endl;      
        }
   }
   ans =x*n;
   cout << ans << endl;
   return 0;
}
