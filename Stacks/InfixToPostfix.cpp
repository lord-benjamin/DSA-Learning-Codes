#include<iostream>
#include<cstring>
using namespace std;

struct Node{
    char data;
    struct Node *next;
};

struct Node *top = NULL;

void push(char x){
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

char pop(){
    struct Node *t;
    char x{-1};
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

int pre(char x){
    if(x == '+' || x == '-'){
        return 1;
    }
    else if(x == '*' || x == '/'){
        return 2;
    }
    return 0;
}

int isOperand(char x){
    if(x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    return 1;
}

char* convert(char *infix){
    char *postfix = new char[strlen(infix)+1];
    int i{0},j{0};
    while(infix[i] != '\0'){
        if(isOperand(infix[i])){
            postfix[j++] = infix[i++];
        }
        else{
            if(pre(infix[i]) > pre(top->data)){
                push(infix[i++]);
            }
            else{
                postfix[j++] = pop();
            }
        }
    }
    while(top){
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char *infix = "a+b*c-d/e";
    push('#');
    char *postfix = convert(infix);
    cout << postfix << endl;
    return 0;
}