#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st){
    cout << "Enter size of stack: ";
    cin >> st->size;
    st->top = -1;
    st->S = (int*)malloc(sizeof(st->size*sizeof(int)));
}

void Display(struct Stack st){
    for(int i{st.top}; i>=0; --i){
        cout << st.S[i] << " ";
    }
    cout << endl;
}

void push(struct Stack *st,int x){
    if(st->top == st->size-1){
        cout << "Stack overflow" << endl;
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(struct Stack *st){
    int x{-1};
    if(st->top == -1){
        cout << "Stack underflow" << endl;
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int peek(struct Stack st,int index){
    int x{-1};
    if(st.top-index+1 < 0){
        cout << "Invalid index" << endl;
    }
    else{
        x = st.S[st.top-index+1];
    }
    return x;
}

bool isEmpty(struct Stack st){
    return st.top == -1;
}

bool isFull(struct Stack st){
    return st.top = st.size-1;
}

int stackTop(struct Stack st){
    if(!isEmpty(st)){
        return st.S[st.top];
    }
    return -1;
}

int main()
{
    struct Stack st;
    create(&st);
    
    push(&st,10);
    push(&st,20);
    push(&st,30);
    push(&st,40);

    cout << peek(st,2) << endl;

    Display(st);
    return 0;
}