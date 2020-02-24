#include<iostream>
using namespace std;
int main()
{
    int ar[]={1,2,3,4};
    int n=4;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int count1=0;
        int pivot=ar[i];
        for(int j=i-1;j>=0;j--)
        {
            if(ar[j]>pivot)
            {
                break;
            }
            count1++;
        }
        int count2=0;
        for(int j=i+1;j<n;j++)
        {
            if(ar[j]>=pivot)
            {
                break;
            }
            count2++;
        }
        sum+=((count1+1)*(count2+1))*pivot;
    }
    cout<<sum;
}
