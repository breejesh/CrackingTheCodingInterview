#include <iostream>
#include <conio.h>
#include <stdio.h>

#define MAX 100

using namespace std;

int setFreq(char output[],int freq,int j)
{
    int digs=0,temp=freq;
    while(temp)
    {
        digs++;
        temp=temp/10;
    }
    temp = j + digs + 1;
    while(freq)
    {
        output[j+digs] = '0' + freq%10;
        freq = freq/10;
        digs--;
    }
    return temp;
}

short compress(char input[], char output[], int n)
{
    short compressedFlag=0,i=0,j=0,freq;
    while(i<n)
    {
        freq=1;
        while(input[i]==input[i+1])
        {
            i++;
            freq++;
        }
        if(compressedFlag==0 && freq>1)
            compressedFlag=1;

        output[j]=input[i];
        j=setFreq(output,freq,j);
        i++;
    }
    output[j]=0;
    return compressedFlag;
}

int main()
{
    char input[MAX],output[MAX];
    int n,i;
    cout<<"Enter a string: ";
    cin.getline(input,MAX);
    for(n=0;input[n]!=0;n++);
    if(compress(input,output,n))
        cout<<output;
    else cout<<input;
}
