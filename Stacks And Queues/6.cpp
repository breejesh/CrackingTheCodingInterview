#include "Header/Stack.cpp"
#include <stdlib.h>

void sortStack(Stack *s1)
{
    Stack s2;
    int temp;
    while(!s1->isEmpty())
    {
        temp=s1->pop();
        while(temp>s2.peek() && !s2.isEmpty())
        {
            s1->push(s2.pop());
        }
        s2.push(temp);
        while(s2.peek()>s1->peek() && !s1->isEmpty())
        {
            s2.push(s1->pop());
        }
    }
    while(!s2.isEmpty())
    {
        s1->push(s2.pop());
    }
}
int main()
{
    int n,val;
    Stack s;

    cout<<"How many inputs? ";
    cin>>n;
    cout<<"Enter Values: ";
    while(n--)
    {
        cin>>val;
        s.push(val);
    }
    cout<<endl<<"Unsorted ";
    s.display();
    sortStack(&s);
    cout<<endl<<"Sorted ";
    s.display();
}
