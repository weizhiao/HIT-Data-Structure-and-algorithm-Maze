#ifndef stack_H
#define stack_H
struct stack
{
    int i;
    int j;
    int v;
    struct stack*next;
};

typedef struct stack* STACK;

STACK MakeNull();
void Push(STACK S,int i,int j,int v);
void Pop(STACK S);
void Top(STACK S);
int IsEmpty(STACK S);
void ReverseStack(STACK S);
void PrintStack(STACK S);

#endif // stack_H
