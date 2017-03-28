#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 50

using namespace std;

class CatDogQ
{
    private:
        int cat[MAX];
        int dog[MAX];
        int cFirst;
        int cLast;
        int dFirst;
        int dLast;
        int time;

    public:
        CatDogQ()
        {
            time=0;
            cFirst=0;
            cLast=0;
            dFirst=0;
            dLast=0;
        }

        void enQue(char type)
        {
            if(type=='c')
            {
                time++;
                cat[cLast]=time;
                cLast++;
                cLast=cLast%MAX;
            }
            else if(type=='d')
            {
                time++;
                dog[dLast]=time;
                dLast++;
                dLast=dLast%MAX;
            }
            else cout<<"Invalid Animal!"<<endl;
        }

        int deQueAny()
        {
         int x;
         if(cat[cFirst]<dog[dFirst] && !isCatEmpty())
         {
            x=cat[cFirst];
            cFirst++;
            cFirst=cFirst%MAX;
            cout<<"You Got Cat Number: ";
         }
         else if(!isDogEmpty())
         {
            x=dog[dFirst];
            dFirst++;
            dFirst=dFirst%MAX;
            cout<<"You Got Dog Number: ";
         }
         return x;
        }

        int deQueCat()
        {
         int x = cat[cFirst];
         cFirst++;
         cFirst %= MAX;
        }

        int deQueDog()
        {
         int x = dog[dFirst];
         dFirst++;
         dFirst %= MAX;
        }

        short isCatEmpty()
        {
            return cFirst==cLast;
        }

        short isDogEmpty()
        {
            return dFirst==dLast;
        }

        short isCatFull()
        {
            return (cLast+1)%MAX==cFirst%MAX;
        }

        short isDogFull()
        {
            return (dLast+1)%MAX==dFirst%MAX;
        }

        void displayQ()
        {
            int i=cFirst,j=dFirst;
            short catFlag=1,dogFlag=1;
            while( catFlag || dogFlag )
            {
                if(cat[i]<dog[j] && catFlag)
                 {
                    if(i%MAX==cLast%MAX)
                    {
                        catFlag=0;
                    }
                    else
                    {
                        cout<<"Cat"<<cat[i]<<" ";
                        i++;
                        i=i%MAX;
                    }
                }
                 else if(dogFlag)
                 {
                    if(j%MAX==dLast%MAX)
                    {
                        dogFlag=0;
                    }
                    else
                    {
                        cout<<"Dog"<<dog[j]<<" ";
                        j++;
                        j=j%MAX;
                    }
                 }
            }
            cout<<endl;
        }

};

int main()
{
    int choice;
    char val;
    CatDogQ q;
    do
    {
        system("cls");
        cout<<"1. Insert"<<endl;
        cout<<"2. Retrieve Any"<<endl;
        cout<<"3. Retrieve Cat"<<endl;
        cout<<"4. Retrieve Dog"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                cout<<"Cat 'c' Or Dog 'd' ?: ";
                cin>>val;
                if(val=='c' && q.isCatFull() || val=='d' && q.isDogFull())
                    cout<<"Q is Full!"<<endl;
                else q.enQue(val);
                break;

            case 2:
                if(!q.isDogEmpty() || !q.isCatEmpty())
                    cout<<q.deQueAny()<<endl;
                else cout<<"Not Cat/Dog Available!"<<endl;
                break;

            case 3:
                if(!q.isCatEmpty())
                    cout<<"You Got Cat Number: "<<q.deQueCat()<<endl;
                else cout<<"Sorry! No Cats Available!"<<endl;
                break;

            case 4:
                if(!q.isDogEmpty())
                    cout<<"You Got Dog Number: "<<q.deQueDog()<<endl;
                else cout<<"Sorry! No Dogs Available!"<<endl;
                break;

            case 5:
                q.displayQ();
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
