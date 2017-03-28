#include <iostream>
#include <conio.h>

#define MAX 50

using namespace std;

class Stack
{
    private:

        int top;
        int arr[MAX];

    public:

        Stack()
        {
            top=-1;
        }

        short isEmpty()
        {
            return top==-1;
        }

        short isFull()
        {
            return top==MAX-1;
        }

        int peek()
        {
            return arr[top];
        }

        int pop()
        {
            int x=arr[top];
            top--;
            return x;
        }

        void push(int ele)
        {
            top++;
            arr[top]=ele;
        }

        void display()
        {
            cout<<endl<<"Stack"<<endl;
            for(int i=top;i>=0;i--)
            {
                cout<<arr[i]<<endl;
            }
        }
};
