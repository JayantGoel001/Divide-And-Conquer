#include<iostream>
using namespace std;
int mergeArray(int *ar,int *temp,int left,int mid,int right)
{
    int i=left;
    int j=mid+1;
    int k=left;
    int inv_count=0;
    while((i<=mid)&&(j<=right))
    {
        if(ar[i]<ar[j])
        {
            temp[k++]=ar[i++];
        }
        else
        {
            temp[k++]=ar[j++];
            inv_count+=(mid-i+1);
        }
    }
    while(i<=mid)
    {
        temp[k++]=ar[i++];
    }
    while(j<=right)
    {
        temp[k++]=ar[j++];
    }
    for(i=left;i<=right;i++)
    {
        ar[i]=temp[i];
    }
    return inv_count;
}
int mergeSort(int *ar,int *temp,int left,int right)
{
    int inv_count=0;
    if(left<right)
    {
        int mid=(left+right)/2;
        inv_count+=mergeSort(ar,temp,left,mid);
        inv_count+=mergeSort(ar,temp,mid+1,right);
        inv_count+=mergeArray(ar,temp,left,mid,right);
    }
    return inv_count;
}
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
    cout<<"Inversion Are:"<<endl;
    //O(n^2) Method
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
            {
                cout<<ar[i]<<" "<<ar[j]<<endl;
            }
        }
    }
    //O(n*log(n))
    int temp[n];
    cout<<"\nTotal Number of Inversions Are:"<<mergeSort(ar,temp,0,n-1);

}
