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

void RemoveDuplicate(struct Node *p){
    struct Node *q = p->next;
    while(q){
        if(p->data != q->data){
            p = q;
            q = q->next;
        }
        else{
            p->next = q->next;
            delete q;
            q = p->next;
        }
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
    int A[] =  {10,20,20,20,30,40,50};
    create(A,7);
    display(first);
    cout << endl;
    RemoveDuplicate(first);
    display(first);
    return 0;
}