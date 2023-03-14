#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x){
    struct Node *t;
    t = (struct Node*)malloc(sizeof(struct Node));
    if(t==NULL){
        cout << "Stack is full" << endl;
    }
    else{
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(){
    struct Node *t;
    int x{-1};
    if(top == NULL){
        cout << "Stack is empty" << endl;
    }
    else{
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display(){
    struct Node *p;
    p = top;
    while(p){
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    return 1;
}

int Eval(char *postfix){
    int x1,x2,r{0};
    for(int i{0}; postfix[i]!='\0'; ++i){
        if(isOperand(postfix[i])){
            push(postfix[i]-'0');
        }
        else{
            x2 = pop();
            x1 = pop();
            switch(postfix[i]){
                case '+':
                    r = x1+x2;
                    break;
                case '-':
                    r = x1-x2;
                    break;
                case '*':
                    r = x1*x2;
                    break;
                case '/':
                    r = x1/x2;
                    break;
            }
            push(r);
        }
    }
    return top->data;
}

int main()
{
    char *postfix = "234*+82/-";
    cout << "Result is " << Eval(postfix) << endl;
    return 0;
}