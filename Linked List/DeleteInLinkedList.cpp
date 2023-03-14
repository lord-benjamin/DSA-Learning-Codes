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

int Delete(struct Node *p,int index){
    struct Node *q;
    int x{-1};
    if(index < 1 || index > count(p)){
        return -1;
    }
    if(index == 1){
        q = first;
        first = first->next;
        x = q->data;
        delete q;
        return x;
    }
    else{
        p = first;
        q = NULL;
        for(int i{0}; i<index-1; ++i){
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
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
    struct Node *temp;
    int A[] =  {10,20,30,40,50};
    create(A,5);
    display(first);
    cout << endl;
    cout << "Deleted element: " << Delete(first,3) << endl;
    display(first);
    return 0;
}