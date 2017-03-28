#include <iostream>
#include <conio.h>
#include <stdio.h>

#define MAX 100

using namespace std;

int main()
{
    int input[MAX][MAX];
    int m,n;
    int rows[MAX];
    int columns[MAX];

    cout<<"Enter M,N: ";
    cin>>m>>n;

    for(int i=0;i<m;i++)
    {
        rows[i]=0;
    }

    for(int j=0;j<n;j++)
    {
        columns[j]=0;
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
            if(input[i][j]==0)
            {
                rows[i]=1;
                columns[j]=1;
            }
        }
    }

    cout<<endl<<endl<<"Output"<<endl;

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(rows[i]==1 || columns[j]==1)
                input[i][j]=0;
            cout<<input[i][j]<<" ";
        }
        cout<<endl;
    }

}
