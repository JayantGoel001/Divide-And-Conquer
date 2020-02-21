#include<iostream>
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
    int mid;
    while(start<=last)
    {
        mid=(start+last)/2;
        if(ar[mid]==x)
        {
            cout<<"Element Found at index: "<<mid;
            break;
        }
        else if(ar[mid]>x)
        {
            last=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }

}
