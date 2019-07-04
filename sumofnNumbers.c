#include <stdio.h>
void input(int *n)
{
    printf("enter the count of numbers");
    scanf("%d",n);
}
void compute(int n,int *sum)
{
    int i,num;
    for(i=1;i<=n;i++)
    {
        printf("enter the number");
        scanf("%d",&num);
        *sum=*sum+num;
    }
}
void output(int sum)
{
    printf("the sum is %d",sum);
}
int main()
{
    int n,sum;
    input(&n);
    compute(n,&sum);
    output(sum);

    return 0;
}
