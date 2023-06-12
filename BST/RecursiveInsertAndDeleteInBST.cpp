#include<iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void Insert(int key){
    struct Node *t{root};
    struct Node *r,*p;
    if(!root){
        p = (struct Node*)malloc(sizeof(struct Node));
        p->data = key;
        p->lchild = p->rchild = NULL;
        root = p;
        return;
    }
    while(t){
        r = t;
        if(key < t->data){
            t = t->lchild;
        }
        else if(key > t->data){
            t = t->rchild;
        }
        else{
            return;
        }
    }
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = key;
    p->lchild = p->rchild = NULL;
    if(key < r->data){
        r->lchild = p;
    }
    else{
        r->rchild = p;
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

struct Node* Search(int key){
    struct Node *t{root};
    while(t){
        if(key < t->data){
            t = t->lchild;
        }
        else if(key > t->data){
            t = t->rchild;
        }
        else{
            return t;
        }
    }
    return NULL;
}

struct Node *RInsert(struct Node *p,int key){
    struct Node *t{NULL};
    if(!p){
        t = (struct Node*)malloc(sizeof(struct Node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data){
        p->lchild = RInsert(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = RInsert(p->rchild,key);
    }
    return p;
}

int Height(struct Node *p){
    if(!p){
        return 0;
    }
    int x,y;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return max(x,y)+1;
}

struct Node *InPre(struct Node *p){
    while(p && p->rchild){
        p = p->rchild;
    }
    return p;
}

struct Node *InSucc(struct Node *p){
    while(p && p->lchild){
        p = p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node *p,int key){
    struct Node *q;
    if(!p){
        return NULL;
    }
    if(!p->lchild && !p->rchild){
        if(p == root){
            root = NULL;
        }
        free(p);
        return NULL;
    }
    if(key < p->data){
        p->lchild = Delete(p->lchild,key);
    }
    else if(key > p->data){
        p->rchild = Delete(p->rchild,key);
    }
    else{
        if(Height(p->lchild) > Height(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild,q->data);
        }
        else{
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild,q->data);
        }
    }
    return p;
}

int main()
{
    struct Node *temp;
    root = RInsert(root,10);
    RInsert(root,5);
    RInsert(root,20);
    RInsert(root,8);
    RInsert(root,30);

    Delete(root,20);

    Inorder(root);
    cout << endl;
    temp = Search(20);
    if(temp){
        cout << "Element is found: " << temp->data;
    }
    else{
        cout << "Element is not found";
    }
    cout << endl;
    return 0;
}
