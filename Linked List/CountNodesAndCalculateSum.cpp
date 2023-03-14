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

int Rcount(struct Node *p){
    if(p){
        return Rcount(p->next)+1;
    }
    else{
        return 0;
    }
}

int sum(struct Node *p){
    int s{0};
    while(p){
        s += (p->data);
        p = p->next;
    }
    return s;
}

int Rsum(struct Node *p){
    if(!p){
        return 0;
    }
    else{
        return Rsum(p->next)+p->data;
    }
}

int main()
{
    int A[] =  {3,5,7,10,15};
    create(A,5);
    cout << "Length is " << Rcount(first) << endl;
    cout << "Sum is " << Rsum(first) << endl;
    return 0;
}