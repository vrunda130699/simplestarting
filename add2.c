#include <stdio.h>
void inputn(int *n)
{
    printf("enter the count of numbers");
    scanf("%d",n);
}
void input(int a[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the number");
        scanf("%d",&a[i]);
    }
}
void compute(int a[],int *sum,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        *sum=*sum+a[i];
    }
}
void output(int sum)
{
    printf("the sum is %d",sum);
}
int main()
{
    int n,sum=0;
    inputn(&n);
    int a[n];
    input(a,n);
    compute(a,&sum,n);
    output(sum);

    return 0;
}
