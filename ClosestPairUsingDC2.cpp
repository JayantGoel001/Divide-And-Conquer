//O(n*log(n)) implementation
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
class Point
{
public:
    int x,y;
};
int compareX(const void *a,const void *b)
{
    Point *a0=(Point*)a;
    Point *b0=(Point*)b;
    return a0->x-b0->x;
}
int compareY(const void *a,const void *b)
{
    Point *a0=(Point*)a;
    Point *b0=(Point*)b;
    return a0->y-b0->y;
}
float dist(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
float bruteForce(Point P[],int n)
{
    float mini=99999.99;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(dist(P[i],P[j])<mini)
            {
                mini=dist(P[i],P[j]);
            }
        }
    }
    return mini;
}
float minimum(float x,float y)
{
    return x>y?y:x;
}
float stripClosest(Point strip[],int siz,float d)
{
    float mini=d;
    for(int i=0;i<siz;i++)
    {
        for(int j=i+1;j<siz &&(strip[j].y-strip[i].y)<mini;j++)
        {
            if(dist(strip[i],strip[j])<mini)
            {
                mini=dist(strip[i],strip[j]);
            }
        }
    }
    return mini;
}
float closestUtil(Point Px[],Point Py[],int n)
{
    if(n<=3)
    {
        return bruteForce(Px,n);
    }
    int mid=n/2;
    Point midPoint=Px[mid];
    Point Pyl[mid+1];
    Point Pyr[n-mid+1];
    int li=0;
    int ri=0;
    for(int i=0;i<n;i++)
    {
        if(Py[i].x<=midPoint.x)
        {
            Pyl[li++]=Py[i];
        }
        else
        {
            Pyr[ri++]=Py[i];
        }
    }
    float dl=closestUtil(Px,Pyl,mid);
    float dr=closestUtil(Px+mid,Pyr,n-mid);
    float d=minimum(dl,dr);
    Point strip[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(abs(Py[i].x-midPoint.x)<d)
        {
            strip[j]=Py[i];
            j++;
        }
    }
    return minimum(d,stripClosest(strip,j,d));
}
float closest(Point P[],int n)
{
    Point *Px=new Point[n];
    Point *Py=new Point[n];
    for(int i=0;i<n;i++)
    {
        Px[i]=P[i];
        Py[i]=P[i];
    }
    qsort(Px,n,sizeof(Point),compareX);
    qsort(Py,n,sizeof(Point),compareY);
    return closestUtil(Px,Py,n);
}
int main()
{
    Point P[]={{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
    int n=sizeof(P)/sizeof(P[0]);
    cout<<"The smallest distance is : "<<closest(P,n);
}
