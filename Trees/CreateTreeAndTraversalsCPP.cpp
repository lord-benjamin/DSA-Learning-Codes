#include<iostream>
using namespace std;

class Node{
public: 
    Node *lchild;
    int data;
    Node *rchild;
};

class Queue{
private:
    int front;
    int rear;
    int size;
    Node **Q;
public:
    Queue(){
        front = rear = -1;
        size = 10;
        Q = new Node*[size];
    }
    Queue(int size){
        front = rear = -1;
        this->size = size;
        Q = new Node*[this->size];
    }
    void enqueue(Node* x);
    Node* dequeue();
    int isEmpty(){
        return front == rear;
    }
};

void Queue::enqueue(Node* x){
    if(rear == size - 1){
        cout << "Queue is full" << endl;
    }
    else{
        rear++;
        Q[rear] = x;
    }
}

Node* Queue::dequeue(){
    Node* x{NULL};
    if(front == rear){
        cout << "Queue is empty" << endl;
    }
    else{
        front++;
        x = Q[front];
    }
    return x;
}

class Tree{
private:
    Node *root;
public:
    Tree(){
        root = NULL;
    }
    void CreateTree();
    void Preorder(Node *p);
    void Preorder(){
        Preorder(root);
    }
    void Inorder(Node *p);
    void Inorder(){
        Inorder(root);
    }
    void Postorder(Node *p);
    void Postorder(){
        Postorder(root);
    }
    void Levelorder(Node *p);
    void Levelorder(){
        Levelorder(root);
    }
    int Height(Node *root);
    int Height(){
        return Height(root);
    }
};

void Tree::CreateTree(){
    Node *p,*t;
    int x;
    Queue q(100);
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty()){
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if(x!=-1){
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}

void Tree::Preorder(Node *p){
    if(p){
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(struct Node *p){
    if(p){
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

void Tree::Postorder(struct Node *p){
    if(p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}

void Tree::Levelorder(Node *p){
    Queue q(100);
    cout << root->data;
    q.enqueue(root);
    while(!q.isEmpty()){
        root = q.dequeue();
        if(root->lchild){
            cout << root->lchild->data << " ";
            q.enqueue(root->lchild);
        }
        if(root->rchild){
            cout << root->rchild->data << " ";
            q.enqueue(root->rchild);
        }
    }
}

int Tree::Height(Node *p){
    int x{0},y{0};
    if(root==0){
        return 0;
    }
    x = Height(root->lchild);
    y = Height(root->rchild);
    return max(x,y)+1;
}

int main()
{
    Tree t;
    t.CreateTree();
    cout << "Preorder Traversal: ";
    t.Preorder();
    cout << endl;
    cout << "Inorder Traversal: ";
    t.Inorder();
    cout << endl;
    cout << "Postorder Traversal: ";
    t.Postorder();
    cout << endl;
    return 0;
}