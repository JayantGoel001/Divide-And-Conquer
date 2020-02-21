#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter n:\n";
    cin>>n;
    int *ar=new int[n];
    cout<<"Enter the elements:\n";
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    int x;
    cout<<"Enter the element to be searched:\n";
    cin>>x;
    int start=0;
    int last=n-1;
    int t=rand()%last+start;
    while(start<=last)
    {
        t=t%(last-start+1)+start;
        if(ar[t]==x)
        {
            cout<<"Element Found at index: "<<t;
            break;
        }
        else if(ar[t]>x)
        {
            last=t-1;
        }
        else
        {
            start=t+1;
        }
    }

}
