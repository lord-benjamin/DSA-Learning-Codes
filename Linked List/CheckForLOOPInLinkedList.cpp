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

void display(struct Node *p){
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
}

bool hasLoop(struct Node *f){
    struct Node *slow{f},*fast{f};
    do{
        slow = slow->next;
        fast = fast->next;
        if(fast){
            fast = fast->next;
        }
    }while(slow && fast && slow!=fast);
    if(slow == fast){
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    struct Node *t1,*t2;
    int A[] =  {10,20,30,40,50};
    create(A,5);
    t1 = first->next->next;
    t2 = first->next->next->next->next;
    t2->next = t1;
    cout << hasLoop(first);
    return 0;
}