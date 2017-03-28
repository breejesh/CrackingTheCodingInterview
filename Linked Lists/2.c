#include "header/node.c"

int findKth(node *start,int k)
{
    node *n=start;
    node *p;
    while(k-- && n)
    {
        n=n->next;
    }
    if(n==0)
    {
        printf("List is not long enough!");
        exit(0);
    }
    p=start;
    while(n)
    {
        n=n->next;
        p=p->next;
    }
    return p->val;
}

int main()
{
    int n,k,val,kVal;
    node *start=0;
    printf("How many inputs? ");
    scanf("%d",&n);
    printf("Enter values: ");
    while(n--)
    {
        scanf("%d",&val);
        appendToTail(&start,val);
    }
    printf("Enter 'k': ");
    scanf("%d",&k);
    kVal=findKth(start,k);
    printf("%d th/nd/rd element from end is: %d",k,kVal);
    return 0;
}
