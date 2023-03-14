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

struct Node* LSearch(struct Node *p,int key){
    struct Node *q{NULL};
    while(p){
        if(key == p->data){
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}

struct Node* RSearch(struct Node *p,int key){
    if(!p){
        return NULL;
    }
    if(key == p->data){
        return p;
    }
    return RSearch(p->next,key);
}

int main()
{
    struct Node *temp;
    int A[] =  {3,5,7,10,15};
    create(A,5);
    temp = LSearch(first,15);
    if(temp){
        cout << "Key is found " << temp->data << endl;
    }
    else{
        cout << "Key is not found" << endl;
    }
    return 0;
}