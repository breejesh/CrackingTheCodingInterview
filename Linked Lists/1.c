#include "Header/node.c"

void deleteDuplicates(node *start)
{
    node *n,*p,*q;
    int temp;
    n=start;
    while(n!=0)
    {
        temp=n->val;
        p=n->next;
        q=n;
        while(p!=0)
        {
            if(p->val==temp)
            {
                deleteNode(&q,&p);
                p=q->next;
            }
            else
            {
                q=p;
                p=p->next;
            }
        }
        n=n->next;
    }
}

void main()
{
    int n,val;
    node *start=0;
    printf("How many inputs? ");
    scanf("%d",&n);
    printf("Enter values: ");
    while(n--)
    {
        scanf("%d",&val);
        appendToTail(&start,val);
    }
    printf("Original List: ");
    printList(start);
    deleteDuplicates(start);
    printf("New List: ");
    printList(start);
}


