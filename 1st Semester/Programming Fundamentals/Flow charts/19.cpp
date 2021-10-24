#include <iostream>
#include <string>

using namespace std;
int main()
{
   string raptor_prompt_variable_zzyz;
   ?? x;
   ?? y;
   ?? lcm;

   raptor_prompt_variable_zzyz ="input x";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> x;
   raptor_prompt_variable_zzyz ="input y";
   cout << raptor_prompt_variable_zzyz << endl;
   cin >> y;
   if (x>y)
   {
      lcm =x;
   }
   else
   {
      lcm =y;
   }
   while (!(lcm % x==0 && lcm % y==0))
   {
      lcm =lcm+1;
   }
   cout << "LCM of "+x+" and "+y+" is= "+lcm << endl;
   return 0;
}
