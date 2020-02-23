#include<iostream>
#include<math.h>
#include<algorithm>
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
    return (a0->x)-(b0->x);
}
int compareY(const void *a,const void *b)
{
    Point *a0=(Point*)a;
    Point *b0=(Point*)b;
    return (a0->y)-(b0->y);
}
float dist(Point p1,Point p2)
{
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
float minimum(float x,float y)
{
    return (x>y)?y:x;
}
float bruteForce(Point P[],int n)
{
    float mini=99999999.999;
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
float stripClosest(Point strip[],int siz,float d)
{
    float mini=d;
    qsort(strip,siz,sizeof(Point),compareY);
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
float closestUtil(Point P[],int n)
{
    if(n<=3)
    {
        return bruteForce(P,n);
    }
    int mid=n/2;
    Point midPoint=P[mid];
    float dl=closestUtil(P,mid);
    float dr=closestUtil(P+mid,n-mid);
    float d=minimum(dl,dr);
    Point strip[n];
    int j=0;
    for(int i=0;i<n;i++)
    {
        if(abs(P[i].x-midPoint.x)<d)
        {
            strip[j]=P[i];
            j++;
        }
    }
    return minimum(d,stripClosest(strip,j,d));
}
float closest(Point P[],int n)
{
    qsort(P,n,sizeof(Point),compareX);
    return closestUtil(P,n);
}
int main()
{
    Point P[]={{2,3},{12,30},{40,50},{5,1},{12,10},{3,4}};
    int n=sizeof(P)/sizeof(P[0]);
    cout<<"The smallest distance is "<<closest(P,n);
}
