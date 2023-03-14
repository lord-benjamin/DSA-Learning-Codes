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

void Display(struct Node *h){
    do{
        cout << h->data << " ";
        h = h->next;
    }while(h != Head);
    cout << endl;
}

void RDisplay(struct Node *h){
    static bool flag{false};
    if(h!=Head || flag==false){
        flag = true;
        cout << h->data << " ";
        RDisplay(h->next);
    }
    flag = false;
}

int main()
{
    int A[] = {2,3,4,5,6};
    create(A,5);
    RDisplay(Head);
    return 0;
}