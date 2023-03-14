#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *front=NULL,*rear=NULL;

void enqueue(int x){
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(!t){
        cout << "Queue is full" << endl;
    }
    else{
        t->data = x;
        t->next = NULL;
        if(!front){
            front=rear=t;
        }
        else{
            rear->next = t;
            rear = t;
        }
    }
}

int dequeue(){
    int x{-1};
    struct Node *t;
    if(!front){
        cout << "Queue is empty" << endl;
    }
    else{
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void Display(){
    struct Node *p=front;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    Display();
    dequeue();
    Display();
    return 0;
}