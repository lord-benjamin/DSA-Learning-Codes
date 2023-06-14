#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *first{NULL};

void SortedInsert(struct Node **H,int x){
    struct Node *t,*q{NULL},*p{*H};
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if(*H == NULL){
        *H = t;
    }
    else{
        while(p && p->data<x){
            q = p;
            p = p->next;
        }
        if(p == first){
            t->next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search(struct Node *p,int key){
    while(p){
        if(key == p->data){
            return p;
        }
        p = p->next;
    }
    return NULL;
}


int Hash(int key){
    return key%10;
}

void Insert(struct Node *H[],int key){
    int index{Hash(key)};
    SortedInsert(&H[index],key);
}

int main()
{
    struct Node *HT[10];
    struct Node *temp;
    for(int i{0}; i<10; ++i){
        HT[i] = NULL;
    }
    Insert(HT,12);
    Insert(HT,22);
    Insert(HT,42);

    temp = Search(HT[Hash(22)],22);
    cout << temp->data << endl;
    return 0;
}