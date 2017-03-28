#include <iostream>
#include <stdio.h>

using namespace std;

void reverseString(char *str)
{
    char temp;
    int length,i=0;
    for(length=0;*(str+length)!=0;length++);
    while(i<length/2)
    {
        temp = *(str+i);
        *(str+i) = *(str+length-1-i);
        *(str+length-1-i) = temp;
        i++;
    }
}

int main()
{

    char *str,input[100];
    str=input;
    cout<<"Enter a string: ";
    cin.getline(input,100);
    cout<<str<<endl;
    reverseString(str);
    cout<<str;
    return 0;
}
