#include<iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node *first = NULL;

void create(int A[],int n){
    struct Node *t,*last;
    first = (struct Node*)malloc(sizeof(struct Node));
    first->data = A[0];
    first->prev = first->next = NULL;
    last = first;
    for(int i{1}; i<n; ++i){
         t = (struct Node*)malloc(sizeof(struct Node));
         t->data = A[i];
         t->next = last->next;
         t->prev = last;
         last->next = t;
         last = t;
    }
}

void Display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int Length(struct Node *p){
    int len{0};
    while(p){
        len++;
        p = p->next;
    }
    return len;
}

void Insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index < 0 || index > Length(p)){
        return;
    }
    if(index == 0){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else{
        for(int i{0}; i<index-1; ++i){
            p = p->next;
        }
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next){
            p->next->prev = t;
        }
        p->next = t;
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    Insert(first,2,25);
    Display(first);
    return 0;
}