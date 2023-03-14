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

void Insert(struct Node *p,int index,int x){
    struct Node *t;
    if(index < 0 || index > count(p)){
        return;
    }
    t = new Node;
    t->data = x;
    if(index == 0){
        t->next = first;
        first = t;
    }
    else{
        p = first;
        for(int i{0}; i<index-1; ++i){
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
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
    Insert(first,0,10);
    Insert(first,1,20);
    Insert(first,2,30);
    Insert(first,0,5);
    display(first);
    return 0;
}