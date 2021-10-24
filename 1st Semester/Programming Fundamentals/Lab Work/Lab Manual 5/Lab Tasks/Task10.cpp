#include <iostream>
using namespace std;
int main()
{
    //Input of elements.//
    int array[10], i, x, k;
    cout << "Enter array elements "<< ": ";
    for (i = 0; i < 10; i++){
        cin >> array[i];
    }
    //Sorting array in acending order.//
    for (i = 0; i < 10; i++){
        for (k = i + 1; k < 10; k++){
            if (array[i] > array[k]){
                x = array[i];
                array[i] = array[k];
                array[k] = x;
            }
        }
    }
    cout << "Seperated array is: ";
    //Output for even array.//
    for (i = 0; i < 10; i++){
        if(array[i]%2==0)
            cout << array[i] << " ";
    }
    //Output for odd array.//
    for (i = 0; i < 10; i++){
        if(array[i]%2!=0)
            cout << array[i] << " ";
    }
    return 0;
}