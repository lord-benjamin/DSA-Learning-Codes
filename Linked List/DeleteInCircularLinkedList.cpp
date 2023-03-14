#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *Head;

void create(int A[],int n){
    struct Node *t,*last;
    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for(int i{1}; i<n; ++i){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

int Length(struct Node *p){
    int len{0};
    do{
        len++;
        p = p->next;
    }while(p != Head);
    return len;
}

int Delete(struct Node *p,int index){{
    struct Node *q;
    int x;
    if(index<0 || index>Length(Head)){
        return -1;
    }
    if(index==1){
        while(p->next != Head){
            p = p->next;
        }
        x = Head->data;
        if(Head == p){
            delete Head;
            Head = NULL;
        }
        else{
            p->next = Head->next;
            delete Head;
            Head = p->next;
        }
    }
    else{
        for(int i{0}; i<index-2; ++i){
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}

}

void Display(struct Node *h){
    do{
        cout << h->data << " ";
        h = h->next;
    }while(h != Head);
    cout << endl;
}

int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    Display(Head);
    Delete(Head,3);
    Display(Head);
    return 0;
}