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

int count(struct Node *p){
    int l{0};
    while(p){
        l++;
        p = p->next;
    }
    return l;
}

bool isSorted(struct Node *p){
    int x{INT_MIN};
    while(p){
        if(p->data < x){
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

int main()
{
    int A[] =  {10,20,30,40,50};
    create(A,5);
    if(isSorted(first)){
        cout << "Sorted" << endl;
    }
    else{
        cout << "Not Sorted" << endl;
    }
    return 0;
}