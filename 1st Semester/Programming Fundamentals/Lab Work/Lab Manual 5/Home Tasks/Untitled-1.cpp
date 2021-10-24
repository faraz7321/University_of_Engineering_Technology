#include<iostream>
using namespace std;
int main (){
    int array[10];
    int check = 0;
    int checki = 0;
    for (int i=0;i<10;i++)
    {
        cout<<"Enter Array Elements: ";
        cin>>array[i];
    }
    for (int i=0;i<10;i++)
    {
        if (array[i] >array[i+1])
        {
            check = check + 1;
        }
        if (array[i] < array [i+1])
        {
            checki = checki + 1;
        }
        
    }
    if (checki == 9)
    {
        cout<<"Array is increasing "<<endl;
    }
    if (check == 9)
    {
        cout<<"Array is decreasing "<<endl;
    }
    else if (check == 0 && checki == 0)
    {
        cout<<"Array is constant "<<endl;
    }
    else if (check > 0 && check < 9)
    {
        cout<<"Array is increasing and decreasing"<<endl;
    }
    return 0;
}