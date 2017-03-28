#include "Header/Stack.cpp"
#include <stdlib.h>

class MyQueue
{
    private:

        Stack s1,s2;

    public:

        MyQueue()
        {

        }

        void enQue(int ele);
        int deQue();
        short fullQ();
        short emptyQ();
        void displayQ();
};

void MyQueue::enQue (int ele)
{
    while(!s1.isEmpty())
    {
        s2.push(s1.pop());
    }
    s1.push(ele);
    while(!s2.isEmpty())
    {
        s1.push(s2.pop());
    }
}

int MyQueue::deQue ()
{
        return s1.pop();
}

short MyQueue::emptyQ()
{
    return s1.isEmpty();
}

short MyQueue::fullQ()
{
    return s1.isFull();
}

void MyQueue::displayQ()
{
    while(!s1.isEmpty())
    {
        cout<<s1.peek()<<" ";
        s2.push(s1.pop());
    }
    while(!s2.isEmpty())
    {
        s1.push(s2.pop());
    }
}

int main()
{
    int choice,val;
    MyQueue q;

    do
    {
        system("cls");
        cout<<"1. Insert"<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter a number: ";
                cin>>val;
                if(!q.fullQ())
                    q.enQue(val);
                else cout<<"Q is Full!"<<endl;
                break;

            case 2:
                if(!q.emptyQ())
                    cout<<"Value: "<<q.deQue()<<endl;
                else cout<<"Q is Empty!"<<endl;
                break;

            case 3:
                q.displayQ();
                break;

            case 4:
                cout<<"See You Again!"<<endl;
                break;

            default:
                cout<<"Invalid Choice. Try Again."<<endl;
        }

    getch();
    }while(choice!=4);

    return 0;
}
