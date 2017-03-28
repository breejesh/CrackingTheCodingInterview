#include <iostream>
#include <conio.h>
#include <stdio.h>

#define MAX 100

using namespace std;

short checkUnique1(char input[],int n)
{
    int hashTable[300]={0},i;
    for(i=0;i<n;i++)
    {
        if(hashTable[input[i]]==0)
            hashTable[input[i]]++;
        else return 0;
    }


    return 1;


}
short checkUnique2(char input[],int n)
{
    char c;
    int i,j;
    for(i=0;i<n;i++)
    {
        c=input[i];
        for(j=i+1;j<n;j++)
        {
            if(c==input[j])
                return 0;
        }
    }
    return 1;
}

int main()
{
    char input[MAX];
    int n,i;
    cout<<"Enter a string: ";
    cin.getline(input,MAX);
    for(n=0;input[n]!=0;n++);
    n++;
    if(checkUnique1(input,n))
        cout<<"String contains unique characters!"<<endl;
    else cout<<"String does not contain unique characters!"<<endl;
}

