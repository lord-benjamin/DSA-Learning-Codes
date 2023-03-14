#include<iostream>
using namespace std;

class Node{
public:
    int data;
    struct Node *next;   
};

struct Node *first{NULL},*second{NULL},*third{NULL};

void create1(int A[],int n){
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
void create2(int A[],int n){
    int i;
    struct Node *t,*last;
    second = (struct Node*)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;
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

void concat(struct Node *p,struct Node *q){
    third = p;
    while(p->next){
        p = p->next;
    }
    p->next = q;
}

void merge(struct Node *p,struct Node *q){
    struct Node *last{NULL};
    if(p->data < q->data){
        third = p;
        last = p;
        p = p->next;
        last->next = NULL;
    }
    else{
        third = q;
        last = q;
        q = q->next;
        last->next = NULL;
    }
    while(p && q){
        if(p->data < q->data){
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else{
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if(p){
        last->next = p;
    }
    else{
        last->next = q;
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
    int B[] =  {5,15,25,35,45};
    create1(A,5);
    create2(B,5);
    display(first);
    cout << endl;
    display(second);
    cout << endl;
    merge(first,second);
    display(third);
    return 0;
}