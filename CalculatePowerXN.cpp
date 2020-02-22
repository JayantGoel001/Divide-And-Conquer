#include<iostream>
using namespace std;
double Power(int x,int n)
{
    if(n==0)
    {
        return 1;
    }
    else if(n>0)
    {
        if(n%2==0)
        {
            return Power(x,n/2)*Power(x,n/2);
        }
        else
        {
            return x*Power(x,n/2)*Power(x,n/2);
        }
    }
    else
    {
        if(n%2==0)
        {
            return Power(x,n/2)*Power(x,n/2);
        }
        else
        {
            return (double)Power(x,n/2)*Power(x,n/2)/x;
        }

    }
}
int main()
{
    int x,n;
    cout<<"Enter the value of x:";
    cin>>x;
    cout<<"Enter the value of n:";
    cin>>n;
    cout<<Power(x,n);

}
