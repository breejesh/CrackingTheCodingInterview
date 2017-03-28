#include "Header/node.c"

node* checkPlain(node *start,node *last)
{
    node* n;
    if(last==0)
        return start;

    n=checkPlain(start,last->next);
    if(n && n->val==last->val)
    {
        if(n->next)
            return n->next;
        else return 1;
    }
    return 0;
}

int main()
{
    node* start=0;
    int n,val;

    printf("How many inputs? ");
    scanf("%d",&n);

    printf("Enter values: ");
    while(n--)
    {
        scanf("%d",&val);
        appendToTail(&start,val);
    }

    printf("\nLinked List: ");
    printList(start);

    if(checkPlain(start,start))
        printf("\nPalindrome!\n");
    else printf("\nNot a Palindrome!\n");

    return 0;
}
