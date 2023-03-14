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

void Reverse1(struct Node *p){
    int *A,i{0};
    A = new int[count(p)];
    struct Node *q{p};
    while(q){
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;
    i--;
    while(q){
        q->data = A[i];
        q = q->next;
        i--;
    }
}

void Reverse2(struct Node *p){
    struct Node *q{NULL},*r{NULL};
    while(p){
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}

void Reverse3(struct Node *q,struct Node *p){
    if(p){
        Reverse3(p,p->next);
        p->next = q;
    }
    else{
        first = q;
    }
}

void display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    int A[] =  {10,20,30,40,50};
    create(A,5);
    display(first);
    cout << endl;
    Reverse3(NULL,first);
    display(first);
    return 0;
}