#include "Header/node.c"

void delX(node *n)
{
    node *p=n->next;
    n->val=p->val;
    if(n->next!=0)
    {
        deleteNode(&n,&p);
    }
    else
    {
        free(n);
        n=0;
    }
}

int main()
{
    int n,temp,mid,val;
    node *start=0,*p;
    printf("How many inputs? ");
    scanf("%d",&n);
    temp=n;
    printf("Enter values: ");
    while(temp--)
    {
        scanf("%d",&val);
        appendToTail(&start,val);
    }
    mid=n/2;
    printf("Mid: %d\nOriginal List: ",mid);
    printList(start);
    if(mid>0)
    {
        p=start;
        while(mid--)
        {
            p=p->next;
        }
        delX(p);
        printf("New List: ");
        printList(start);
    }
    else
    {
        start=0;
        printf("New List: Empty");
    }
}
