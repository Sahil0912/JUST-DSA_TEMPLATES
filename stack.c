#include <stdio.h>
#define MAX_LEN 1000
#define EMPTY (-1)
#define FULL (MAX_LEN -1)
typedef struct stack
{
    char s[MAX_LEN];
    int top;
}stack;

//push function
void push(char c, stack *stk){
    (*stk).top++;
    (*stk).s[(*stk).top] = c;
}

// pop function
void pop_(stack *stk){
    (*stk).s[(*stk).top] = 0;
    (*stk).top--;
}

// or maybe pop function as:
void pop(stack *stk){
    return(stk->s[(*stk).top--]);
}

int main(){
    // here first we have seen structure and struct pointer , typedef

    // then ADT Stack:
    // see as a stack of book or something : LIFO
    // operations: push, pop, top, empty, full, reset

    // 💫💫

    return 0;
}