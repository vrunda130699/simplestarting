#include <stdio.h>
#include<math.h>
struct area
{
    float x1,x2,x3,y1,y2,y3;
};

void inputn(int *n)
{
    printf("enter the count of area to be calculated");
    scanf("%d",n);
}
void input(struct area a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the points for %d rectangle\n",(i+1));
        scanf(" %f %f %f %f %f %f",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2,&a[i].x3,&a[i].y3);
        printf("%f %f %f %f %f %f is vertices of %d",a[i].x1,a[i].y1,a[i].x2,a[i].y2,a[i].x3,a[i].y3,(i+1));
    }
}
void compute(struct area a[],int n,float c[])
{
    int i;
    float d,b,p;
    for(i=0;i<n;i++)
    {
       d = sqrt(pow(a[i].x2-a[i].x1,2) + pow(a[i].y2-a[i].y1,2)*1.0);
       b = sqrt(pow(a[i].x3-a[i].x2,2) + pow(a[i].y3-a[i].y2,2)*1.0);
       p = d*b;
       c[i]=p;
        printf("\n%f is area",c[i]);
    }
}

int main()
{
    int n,i;
    inputn(&n);
    struct area a[n];
    float c[n];
    input(a,n);
    compute(a,n,c);
   
    return 0;
}
