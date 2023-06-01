#include<iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    Node **Q;
};

void create (struct Queue *q,int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (Node **)malloc(q->size*sizeof(Node*));
}

void enqueue(struct Queue *q,Node *x){
    if(q->rear == q->size - 1){
        cout << "Queue is full" << endl;
    }
    else{
        q->rear++;
        q->Q[q->rear] = x;
    }
}

Node* dequeue(struct Queue *q){
    Node* x{NULL};
    if(q->front == q->rear){
        cout << "Queue is empty" << endl;
    }
    else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front == q.rear;
}

struct Node *root{NULL};

void createTree(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    cout << "Enter root value: ";
    cin >> x;
    root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q,root);
    while (!isEmpty(q)){
        p = dequeue(&q);
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q,t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = (struct Node*)malloc(sizeof(struct Node));
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p){
    if(p){
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p){
    if(p){
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout << p->data << " ";
    }
}

int count(struct Node *root){
    if(root){
        return count(root->lchild)+count(root->rchild)+1;
    }
    return 0;
}

int height(struct Node *root){
    int x{0},y{0};
    if(!root){
        return 0;
    }
    x = height(root->lchild);
    y = height(root->rchild);
    return max(x,y)+1;
}

int main()
{
    createTree();
    cout << "Count: " << count(root) << endl;
    cout << "Height: " << height(root) << endl; 
    return 0;
}