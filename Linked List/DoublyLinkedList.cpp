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

int main()
{
    int A[] = {10,20,30,40,50};
    create(A,5);
    cout << "Length is: " << Length(first) << endl;
    Display(first);
    return 0;
}