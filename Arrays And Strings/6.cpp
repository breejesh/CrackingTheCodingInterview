#include <iostream>
#include <conio.h>
#include <stdio.h>

#define MAX 100

using namespace std;

void rotate_90(int input[][MAX],int n)
{
    int levels=n/2,i=0,temp;
    while(i<levels)
    {
        for(int k=i+1;k<n-1-i;k++)
        {
            temp = input[i][k];
            input[i][k] = input[k][n-1-i];
            input[k][n-1-i] = temp;

            temp = input[n-1][k];
            input[n-1][k] = input[k][0];
            input[k][0] = temp;
        }
        for(int k=1+i;k<n-1-i;k++)
        {
            temp = input[i][n-k-1];
            input[i][n-k-1] = input[n-i-1-i][k];
            input[n-i-1][k] = temp;
        }

        //Swapping Each Extreme

        temp=input[i][i];
        input[i][i]=input[n-1-i][i];
        input[n-1-i][i]=input[n-1-i][n-1-i];
        input[n-1-i][n-1-i]=input[i][n-1-i];
        input[i][n-1-i]=temp;

        i++;
    }
}

int main()
{
    int input[MAX][MAX],n;
    cout<<"Enter N : ";
    cin>>n;
    cout<<"Enter the Matrix : "<<endl;

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>input[i][j];

    rotate_90(input,n);

    cout<<endl<<endl<<"Output"<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<input[i][j]<<" ";
        cout<<endl;
    }
}
