#include<iostream>
using namespace std;
void mergeArr(int* arr,int l,int mid,int r)
{
    int *a=new int[mid-l+1];
    int *b=new int[r-mid];
    for(int i1=0;i1<mid-l+1;i1++)
    {
        a[i1]=arr[i1+l];
    }
    for(int j1=0;j1<r-mid;j1++)
    {
        b[j1]=arr[j1+mid+1];
    }
    int i,j,k;
    i=0;
    j=0;
    k=l;
    while(i<mid-l+1 && j<r-mid)
    {
        if(a[i]<=b[j])
        {
            arr[k]=a[i];
            i++;
        }
        else
        {
            arr[k]=b[j];
            j++;
        }
        k++;
    }
    while(i<mid-l+1)
    {
        arr[k++]=a[i++];
    }
    while(j<r-mid)
    {
        arr[k++]=b[j++];
    }
}
void mergeSort(int *ar,int i,int j)
{
    if(i<j)
    {
        int mid=(i+j)/2;
        mergeSort(ar,i,mid);
        mergeSort(ar,mid+1,j);
        mergeArr(ar,i,mid,j);
    }
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
    mergeSort(ar,0,n-1);
    cout<<"\nSorted Array:\n";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
}
