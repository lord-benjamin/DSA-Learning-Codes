#include<iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Stack{
    int size;
    int top;
    struct Node **S;
};

void Stackcreate(struct Stack *st,int size){
    st->size = size;
    st->top = -1;
    st->S = (struct Node**)malloc(sizeof(st->size*sizeof(struct Node*)));
}

void push(struct Stack *st,struct Node* x){
    if(st->top == st->size-1){
        cout << "Stack overflow" << endl;
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

struct Node* pop(struct Stack *st){
    struct Node* x{NULL};
    if(st->top == -1){
        cout << "Stack underflow" << endl;
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

bool isEmpty(struct Stack st){
    return st.top == -1;
}

bool isFull(struct Stack st){
    return st.top = st.size-1;
}

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

void IPreorder(struct Node *p){
    struct Stack stk;
    Stackcreate(&stk,100);
    while(p || !isEmpty(stk)){
        if(p){
            cout << p->data << " ";
            push(&stk,p);
            p = p->lchild;
        }
        else{
            p = pop(&stk);
            p = p->rchild;
        }
    }
}

void IInorder(struct Node *p){
    struct Stack stk;
    Stackcreate(&stk,100);
    while(p || !isEmpty(stk)){
        if(p){
            push(&stk,p);
            p = p->lchild;
        }
        else{
            p = pop(&stk);
            cout << p->data << " ";
            p = p->rchild;
        }
    }
}

int main()
{
    createTree();
    cout << "Preorder Traversal: ";
    IPreorder(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    IInorder(root);
    cout << endl;
    // cout << "Postorder Traversal: ";
    // postorder(root);
    // cout << endl;
    return 0;
}