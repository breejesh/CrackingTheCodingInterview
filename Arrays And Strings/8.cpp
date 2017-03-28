#include <iostream>
#include <conio.h>
#include <stdio.h>

#define MAX 100

using namespace std;

short isSubstring(char s1[],char s2[],int len,int lim)
{
    short result=0;
    int i=0,j=0,match=0;
    while(i<len)
    {
        if(s1[i]==s2[j])
        {
            i++;
            j++;
            match++;
        }
        else
        {
            i-=match;
            j-=match;
            i++;
        }
        if(j==lim)
            return 1;
    }
    return 0;

}

int main()
{
    char s1[MAX],s2[MAX];
    int len1,len2,match=0,i=0,j=0;
    cout<<"Enter String 1: ";
    cin.getline(s1,MAX);
    cout<<"Enter String 2: ";
    cin.getline(s2,MAX);

    for(len1=0;s1[len1]!=0;len1++);
    for(len2=0;s2[len2]!=0;len2++);

    if(len1==len2)
    {
        while(j<len2)
        {
            if(s1[i]==s2[j])
            {
                match++;
                i++;
                j++;
            }
            else
            {
                i-=match;
                j-=match;
                j++;
            }
        }
        if(isSubstring(s1,s2,len1,j-match))
            cout<<"Rotations!"<<endl;
        else cout<<"Not Rotations!"<<endl;
    }
    else cout<<"Not Rotations!"<<endl;

}
