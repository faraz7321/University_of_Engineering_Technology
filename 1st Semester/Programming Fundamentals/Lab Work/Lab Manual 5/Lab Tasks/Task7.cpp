#include <iostream>
using namespace std;
int main()
{
   const int n=10;
    int i, j = 1, x, k;
    cout << "Enter the size of array: ";


    int array[n];
    for (i = 0; i < n; i++){
        cout << "Enter array element " << j << ": ";
        cin >> array[i];
        j++;
    }
    for (i = 0; i < n; i++){
        for (k = i + 1; k < n; k++){
            if (array[i] > array[k]){
                x = array[i];
                array[i] = array[k];
                array[k] = x;
            }
        }
    }
    cout << "Sorted array is\n";
    for (i = 0; i < n; i++){
        cout << array[i] << " ";
    }
    return 0;
}