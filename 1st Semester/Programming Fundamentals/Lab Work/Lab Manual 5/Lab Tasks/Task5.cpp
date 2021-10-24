#include <iostream>
using namespace std;
int main()
{
    int n, i, j = 1, k,count;
    bool flag;
    cout << "Enter the size of array: ";
    cin >> n;

    int array[n];
    for (i = 0; i < n; i++){
        cout << "Enter array elements " << j << ": ";
        cin >> array[i];
        j++;
    }
    cout << "Elements of array that appear once in an array: ";
    for (i = 0; i < n; i++){
        //flag=0;
        count=0;
        for(k = 0; k < n; k++){
            if(array[k]==array[i]){
                //flag=1;
                count++;
            }
        }
        if(/*flag==1*/ count==1){
            cout << array[i] << " ";
        }
    }
return 0;
}