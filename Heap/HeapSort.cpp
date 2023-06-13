#include<iostream>
using namespace std;

void Insert(int A[],int n){
    int i=n,temp;
    temp = A[i];
    while(i>1 && temp>A[i/2]){
        A[i] = A[i/2];
        i /= 2;
    }
    A[i] = temp;
}

int Delete(int A[],int n){
    int x{A[n]},temp,val{A[1]};
    A[1] = A[n];
    A[n] = val;
    int i{1},j{i*2};
    while(j<n-1){
        if(A[j+1] > A[j]){
            j++;
        }
        if(A[i] < A[j]){
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i = j;
            j *= 2;
        }
        else{
            break;
        }
    }
    return val;
}

int main()
{
    int H[] = {0,10,20,30,25,5,40,35};
    for(int i{2}; i<=7; ++i){
        Insert(H,i);
    }
    for(int i{7}; i>1; --i){
        Delete(H,i);
    }
    for(int i{1}; i<=7; ++i){
        cout << H[i] << " ";
    }
    cout << endl;

    return 0;
}