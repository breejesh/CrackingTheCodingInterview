#include <iostream>
#include <conio.h>
#include <stdio.h>

#define MAX 100

using namespace std;

void insert_20(char input[])
{
    int length,i,j=0,k=0,spaces=0;

    for(length=0;input[length]!=0;length++)
        if(input[length]==' ')
            spaces++;

    length--;
    i = length + 2*spaces;
    input[i+1]=0;

    while(k<=length)
    {
        if(input[length-k]!=' ')
        {
            input[i-j]=input[length-k];
            j++;
        }
        else
        {
            input[i-j]='0';
            input[i-j-1]='2';
            input[i-j-2]='%';
            j+=3;
        }
        k++;
    }
}

int main()
{
    char input[MAX];
    cout<<"Enter a string: ";
    cin.getline(input,MAX);
    insert_20(input);
    cout<<input;
}
