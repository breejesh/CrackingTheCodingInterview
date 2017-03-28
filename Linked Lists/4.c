#include "Header/node.c"

node* stupidPartition(node *start,int x,node *last)
{
    if(last==0)
        return start;
    node *t=(last->next);
    node *n = stupidPartition(start,x,t);
    while(n!=last && n)
    {
        //printf("%d,%d\n",n->val,last->val);
        if((n->val)<x)
        {
            n = n->next;
            //printf("No Swap\n");
        }
        else
        {
            int temp;
            temp = n->val;
            n->val = last->val;
            last->val = temp;
            //printf("Swap\n");
            return n;
        }
    }
    return 0;
}

void betterPartition(node *start,int x)
{
    node *n=start;
    node *p=start;
    while(n)
    {
        if(n->val<x)
        {
            int temp=n->val;
            n->val=p->val;
            p->val=temp;
            p=p->next;
        }
        n=n->next;
    }
}

int main()
{
    int n,val,x;
    node *start=0;
    printf("How many inputs? ");
    scanf("%d",&n);
    printf("Enter values: ");
    while(n--)
    {
        scanf("%d",&val);
        appendToTail(&start,val);
    }
    printf("Enter 'x': ");
    scanf("%d",&x);
    printf("\nOriginal List: ");
    printList(start);
    betterPartition(start,x);
    printf("\nNew List: ");
    printList(start);
    return 0;
}
