#include<iostream>
using namespace std;

int main()
{
    int arr1[5]{1,3,5,7,9};
    int arr2[5]{2,4,6,8,10};
    int arr[10];
    int i{0},j{0},k{0};
    while(i<5 && j<5){
        if(arr1[i] < arr2[j]){
            arr[k++] = arr1[i++];
        }
        else{
            arr[k++] = arr2[j++];
        }
    }
    for(;i<5; ++i){
        arr[k++] = arr1[i];
    }
    for(;j<5; ++j){
        arr[k++] = arr2[j];
    }
    for(int i{0}; i<10; ++i){
        cout << arr[i] << " ";
    }
    
    return 0;
}