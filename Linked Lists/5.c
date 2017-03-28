#include "Header/node.c"
#include "Header/stack.c"

void addRev(node *num1,node *num2,node **sum)
{
    int carry=0,res;
    node *n=newNode(0),*p;
    *sum=n;
    while(num1 && num2)
    {
        res = (num1->val + num2->val) + carry;
        n->val=res%10;
        carry = res/10;
        p=newNode(0);
        n->next=p;
        n=p;
        num1=num1->next;
        num2=num2->next;
    }
    while(num1)
    {
        res = num1->val + carry;
        n->val=res%10;
        carry = res/10;
        p=newNode(0);
        n->next=p;
        n=p;
        num1=num1->next;
    }
    while(num2)
    {
        res = num2->val + carry;
        n->val=res%10;
        carry = res/10;
        p=newNode(0);
        n->next=p;
        n=p;
        num2=num2->next;
    }
    if(carry!=0)
    {
        n->val=carry;
        n->next=0;
    }
    else n=0;
}

void addFor(node *num1,node *num2,node **sum)
{
    int res,carry=0;
    stack s1,s2,s3;
    node *n=newNode(0),*p;

    *sum=n;
    initStack(&s1);
    initStack(&s2);
    initStack(&s3);

    while(num1 && num2)
    {
        push(&s1,num1->val);
        num1=num1->next;
        push(&s2,num2->val);
        num2=num2->next;
    }

    while(num1)
    {
        push(&s1,num1->val);
        num1=num1->next;
        push(&s2,-1);
    }

    while(num2)
    {
        push(&s2,num2->val);
        num2=num2->next;
        push(&s1,-1);
    }

    //printf("\nStack S1\n");
    //displayStack(s1);

    //printf("\nStack S2\n");
    //displayStack(s2);

    while(peek(s1)==-1)
    {
        pop(&s1);
    }

    while(peek(s2)==-1)
    {
        pop(&s2);
    }

    while(!isEmpty(s1) && !isEmpty(s2))
    {
        res = pop(&s1) + pop(&s2) + carry;
        carry=res/10;
        res%=10;
        push(&s3,res);
    }

    while(!isEmpty(s1))
    {
        res = pop(&s1) + carry;
        carry=res/10;
        res%=10;
        push(&s3,res);
    }

    while(!isEmpty(s2))
    {
        res = pop(&s2) + carry;
        carry=res/10;
        res%=10;
        push(&s3,res);
    }

    if(carry!=0)
        push(&s3,carry);

    //printf("\nStack S3\n");
    //displayStack(s3);

    while(!isEmpty(s3))
    {
        n->val=pop(&s3);
        if(isEmpty(s3))
            n->next=0;
        else
        {
            p=newNode(0);
            n->next=p;
            n=n->next;
        }
    }
}

int main()
{
    node *num1=0,*num2=0,*sum=0;
    int n1,n2,val;

    printf("Number 1 digits: ");
    scanf("%d",&n1);

    printf("Enter Digits: ");
    while(n1--)
    {
        scanf("%d",&val);
        appendToTail(&num1,val);
    }

    printf("Number 2 digits: ");
    scanf("%d",&n2);

    printf("Enter Digits: ");
    while(n2--)
    {
        scanf("%d",&val);
        appendToTail(&num2,val);
    }

    //addRev(num1,num2,&sum);
    addFor(num1,num2,&sum);

    printf("\nNumber 1: ");
    printList(num1);

    printf("\nNumber 2: ");
    printList(num2);

    printf("\nSum: ");
    printList(sum);

    return 0;
}
