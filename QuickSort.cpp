#include<iostream>
using namespace std;
int Partition(int *ar,int low,int high)
{
    int pivot=ar[high];
    int i=low;
    for(int j=low;j<high;j++)
    {
        if(pivot>ar[j])
        {
            int temp=ar[i];
            ar[i]=ar[j];
            ar[j]=temp;
            i++;
        }
    }
    int temp=ar[i];
    ar[i]=ar[high];
    ar[high]=temp;
    return i;
}
void QuickSort(int *ar,int low,int high)
{
    if(low<high)
    {
        int p=Partition(ar,low,high);
        QuickSort(ar,low,p-1);
        QuickSort(ar,p+1,high);
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
    QuickSort(ar,0,n-1);
    cout<<"\nSorted Array:\n";
    for(int i=0;i<n;i++)
    {
        cout<<ar[i]<<" ";
    }
}
