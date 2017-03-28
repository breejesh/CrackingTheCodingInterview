#include <iostream>
#include <conio.h>

#define MAX 100
#define INFINITY 99999

using namespace std;

class Stack
{
    private:

        int top;
        int mini;
        int arr[MAX];

    public:

        Stack()
        {
            top=-1;
            mini=MAX-1;
            arr[mini]=INFINITY;
        }

        short isEmpty()
        {
            return top==-1;
        }

        short isFull()
        {
            return top==mini;
        }

        int peek()
        {
            return arr[top];
        }

        int pop()
        {
            int x=arr[top];
            top--;
            if(x==arr[mini])
                mini++;
            return x;
        }

        void push(int ele)
        {
            top++;
            arr[top]=ele;
            if(ele<=arr[mini])
            {
                mini--;
                arr[mini]=ele;
            }
        }

        int minimum()
        {
            return arr[mini];
        }

        void display()
        {
            cout<<endl<<"Stack"<<endl;
            for(int i=top;i>=0;i--)
            {
                cout<<arr[i]<<endl;
            }
            cout<<endl<<"Min: "<<arr[mini]<<endl;
        }
};

int main()
{
    Stack s;
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    s.push(1);
    s.push(0);
    s.push(-3);
    s.push(-4);
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    s.pop();
    s.display();
    return 0;
}
