#include <iostream>
#include <conio.h>
#include <stdio.h>

#define MAX 100

using namespace std;

short checkPerm1(char input1[],char input2[],int n)
{
    int hashTable[300]={0},i;
    for(i=0;i<n;i++)
    {
        hashTable[input1[i]]++;
    }
    for(i=0;i<n;i++)
    {
        if(hashTable[input2[i]]!=0)
            hashTable[input2[i]]--;
        else return 0;
    }
    return 1;
}

short checkPerm2(char input1[],char input2[],int n)
{
    char c;
    int i,j;
    short perm=0;
    for(i=0;i<n;i++)
    {
        c=input1[i];
        for(j=0;j<n;j++)
        {
            if(input2[j]==c)
            {
                input2[j]=0;
                perm = 1;
                break;
            }
        }
        if(perm==0)
            return 0;
        perm=0;
    }
    return 1;
}

int main()
{
    char input1[MAX],input2[MAX];
    int n1,n2,i;

    cout<<"Enter 1st string: ";
    cin.getline(input1,MAX);

    cout<<"Enter 2nd string: ";
    cin.getline(input2,MAX);

    for(n1=0;input1[n1]!=0;n1++);
    for(n2=0;input2[n2]!=0;n2++);

    if(n1==n2 && checkPerm1(input1,input2,n1))
        cout<<"Strings are Perms!"<<endl;
    else cout<<"String are not Perms!"<<endl;
}

