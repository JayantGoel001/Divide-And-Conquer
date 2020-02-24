#include<iostream>
using namespace std;
int maximum(int a,int b,int c)
{
    if(a>=b && a>=c)
    {
        return a;
    }
    else if(b>=a && b>=c)
    {
        return b;
    }
    else if(c>=a && c>=b)
    {
        return c;
    }
}
int MaxCrossing(int ar[],int l,int mid,int r)
{
    int sum=0;
    int right_sum=-999;
    int left_sum=-999;
    for(int i=mid;i>=l;i--)
    {
        sum+=ar[i];
        if(left_sum<sum)
        {
            left_sum=sum;
        }
    }
    sum=0;
    for(int i=mid+1;i<=r;i++)
    {
        sum+=ar[i];
        if(right_sum<sum)
        {
            right_sum=sum;
        }
    }
    return left_sum+right_sum;
}
int MaxSum(int ar[],int i,int j)
{
    if(i==j)
    {
        return ar[i];
    }
    else
    {
        int mid=(i+j)/2;
        return maximum(MaxSum(ar,i,mid),MaxSum(ar,mid+1,j),MaxCrossing(ar,i,mid,j));
    }
}
int main()
{
    int ar[]={-2,-5,6,-2,-3,1,5,-6};
    int n=8;
    int sum=0;
    cout<<MaxSum(ar,0,7);
}
