#include <stdio.h>
#include <stdlib.h>

typedef
struct node
{
    struct node *next;
    int val;
}node;

node* newNode(int val)
{
    node *n;
    n=(node*)malloc(sizeof(node*));
    n->val=val;
    return n;
}

void deleteNode(node **follower,node **current)
{
    (*follower)->next = (*current)->next;
    free(*current);
}

void appendToTail(node **start,int val)
{

    node *n = *start;
    if(n!=0)
    {
        while(n->next!=0)
        {
            n=n->next;
        }
        n->next = newNode(val);
        n = n->next;
        n->next = 0;
    }
    else
    {
        n=newNode(val);
        n->next=0;
        *start=n;
    }
}
void printList(node *start)
{
    node *n=start;
    while(n!=0)
    {
        printf("%d ",n->val);
        n=n->next;
    }
    printf("\n");
}
