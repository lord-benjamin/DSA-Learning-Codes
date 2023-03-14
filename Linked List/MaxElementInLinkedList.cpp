#include<iostream>
using namespace std;

class Node{
public:
    int data;
    struct Node *next;   
};

struct Node *first;

void create(int A[],int n){
    int i;
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;
    for(int i{1}; i<n; ++i){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

int Max(struct Node *p){
    int max{INT_MIN};
    while(p){
        if(p->data > max){
            max = p->data;
        }
        p = p->next;
    }
    return max;
}

int Rmax(struct Node *p){
    int x{0};
    if(!p){
        return INT_MIN;
    }
    x = Rmax(p->next);
    if(x > p->data){
        return x;
    }
    else{
        return p->data;
    }
}

int main()
{
    int A[] =  {3,5,7,10,15};
    create(A,5);
    cout << "Max is " << Rmax(first) << endl;
    return 0;
}