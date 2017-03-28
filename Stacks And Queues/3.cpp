#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 5

using namespace std;

class SetOfStacks
{
    private:

        int arr[MAX][MAX];
        int top[MAX];
        int currentStack;

    public:

        SetOfStacks()
        {
            currentStack=0;
            for(int i=0;i<MAX;i++)
                top[i]=-1;
        }

        short isEmpty()
        {
            return currentStack==0 && top[0]==-1;
        }

        short isFull()
        {
                return currentStack==MAX-1 && top[MAX-1]==MAX-1;
        }

        void push(int ele)
        {
            if(top[currentStack]==MAX-1)
            {
                currentStack++;
            }
            top[currentStack]++;
            arr[currentStack][top[currentStack]]=ele;
        }

        int peek()
        {
            return arr[currentStack][top[currentStack]];
        }

        int pop()
        {
            int x = arr[currentStack][top[currentStack]];
            if(top[currentStack]==-1)
            {
                currentStack--;
            }
            top[currentStack]--;
            return x;
        }

        int popAt(int stackNo)
        {
            if(stackNo<=currentStack+1)
            {
                if(top[stackNo-1]!=-1)
                {
                    int x = arr[stackNo-1][top[stackNo-1]];
                    top[stackNo-1]--;
                    cout<<"Value: ";
                    return x;
                }
                else cout<<"Stack "<<stackNo<<" is empty!"<<endl<<"Error Code: ";
            }
            else cout<<"Invalid Stack Number!"<<endl<<"Error Code: ";
        }

        void display()
        {
            for(int i=MAX-1;i>=0;i--)
            {
                for(int j=0;j<=currentStack;j++)
                {
                    if(top[j]<i)
                        cout<<"   ";
                    else cout<<arr[j][i]<<"  ";
                }
                cout<<endl;
            }
            cout<<"S1 S2 S3 S4 S5 S6 S7 S8 S9 S10"<<endl;
        }
};

int main()
{
    int choice,val;
    SetOfStacks s;

    do
    {
        system("cls");
        cout<<"1. Push"<<endl;
        cout<<"2. Pop"<<endl;
        cout<<"3. Pop At"<<endl;
        cout<<"4. Peek"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Enter a number: ";
                cin>>val;
                if(!s.isFull())
                    s.push(val);
                else cout<<"Stack OverFlow"<<endl;
                break;

            case 2:
                if(!s.isEmpty())
                    cout<<"Value: "<<s.pop()<<endl;
                else cout<<"Stack Underflow"<<endl;
                break;

            case 3:
                cout<<"Enter Stack Number: ";
                cin>>val;
                cout<<s.popAt(val);
                break;

            case 4:
                if(!s.isEmpty())
                    cout<<"Value: "<<s.peek()<<endl;
                else cout<<"Stack Empty"<<endl;
                break;

            case 5:
                s.display();
                break;

            case 6:
                cout<<"See You Again!"<<endl;
                break;

            default:
                cout<<"Invalid Choice. Try Again."<<endl;
        }

    getch();
    }while(choice!=6);

    return 0;
}
