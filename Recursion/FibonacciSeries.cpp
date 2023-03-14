#include<iostream>
using namespace std;

int fib(int n){
    int t0{0},t1{1},s{0};
    if(n<=1){
        return n;
    }
    for(int i{2}; i<=n; ++i){
        s = t0+t1;
        t0 = t1;
        t1 = s;
    }
    return s;
}

int rfib(int n){
    if(n<=1){
        return n;
    }
    return rfib(n-1)+rfib(n-2);
}

int F[10];

int memofib(int n){
    if(n<=1){
        F[n] = n;
        return n;
    }
    else{
        if(F[n-2] == -1){
            F[n-2] = memofib(n-2);
        }
        if(F[n-1] == -1){
            F[n-1] = memofib(n-1);
        }
        return F[n-1]+F[n-2];
    }
}

int main()
{
    for(int i{0}; i<10; ++i){
        F[i] = -1;
    }
    cout << memofib(10) << endl;
    return 0;
}