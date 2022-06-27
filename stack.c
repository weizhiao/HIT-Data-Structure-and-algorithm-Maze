#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

STACK MakeNull()
{
    STACK S=malloc(sizeof(struct stack));
    S->next=NULL;
    return S;
}

void Push(STACK S,int i,int j,int v)
{
    STACK temp=malloc(sizeof(struct stack));
    temp->next=S->next;
    temp->i=i;
    temp->j=j;
    temp->v=v;
    S->next=temp;
}

void Pop(STACK S)
{
    STACK temp=S->next;
    S->next=temp->next;
    free(temp);
}

void Top(STACK S)
{
    printf("(%d,%d)",S->next->i,S->next->j);
}

int IsEmpty(STACK S)
{
    if(S->next==NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ReverseStack(STACK S)
{
    STACK temp=MakeNull();
    while(S->next!=NULL)
    {
        Push(temp,S->next->i,S->next->j,S->next->v);
        Pop(S);
    }
    S->next=temp->next;
}

void PrintStack(STACK S)
{
    while(S->next!=NULL)
    {
        Top(S);
        printf("\n");
        Pop(S);
    }
}
