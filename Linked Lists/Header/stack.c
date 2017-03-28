#include <conio.h>
#include <stdio.h>

#define MAX 100

typedef
struct stack {
    int arr[MAX];
    int top;
}stack;

initStack(stack *s)
{
    s->top=-1;
}
void push(stack *s,int ele)
{
    (s->top)++;
    s->arr[s->top]=ele;
}

int pop(stack *s)
{
    int x=s->arr[s->top];
    s->top -= 1;
    return x;
}

int peek(stack s)
{
    return s.arr[s.top];
}

short isEmpty(stack s)
{
    if(s.top==-1)
        return 1;
    return 0;
}

short isFull(stack s)
{
    if(s.top==MAX-1)
        return 1;
    return 0;
}

void displayStack(stack s)
{
    int i;
    for(i=s.top;i>=0;i--)
        printf("%d\n",s.arr[i]);
}
