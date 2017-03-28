#include "Header/node.c"

void createLoop(node* start,int n)
{
    srand(time(NULL));
    int random = 1 + rand()%(n-1);
    node *end=start;
    node *x=start;
    while(end->next)
    {
        end=end->next;
    }
    while(random--)
        x=x->next;
    end->next=x;
}

void findLoop(node* start)
{
    node *fast,*slow,*looper;
    int loopSize=1,temp;

    fast=start->next;
    slow=start;
    looper=start;

    while(fast!=slow)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    slow=slow->next;

    while(slow!=fast)
    {
        loopSize++;
        slow=slow->next;
    }
    printf("\nLoop size: %d\n",loopSize);

    while(looper!=slow)
    {
        temp=loopSize-1;
        slow=fast;
        while(temp!=0 && looper!=slow)
        {
            slow=slow->next;
            temp--;
        }
        if(temp==0)
            looper=looper->next;
        else break;
    }
    printf("\nBeginning of loop: %d\n",looper->val);

    //Printing
    slow=start;
    temp=2;
    printf("\nCircular List: ");
    while(temp)
    {
        if(slow==looper)
            temp--;
        printf("%d ",slow->val);
        slow=slow->next;
    }


}
int main()
{
    int n,val;
    node *start=0;
    printf("How many inputs? ");
    scanf("%d",&n);
    printf("\nEnter values: ");
    while(n--)
    {
        scanf("%d",&val);
        appendToTail(&start,val);
    }
    printf("\nOriginal List: ");
    printList(start);
    createLoop(start,n);
    findLoop(start);
    printf("\n");
    return 0;
}
