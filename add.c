#include <stdio.h>

void input(int *a,int *b)
{
    printf("enter two numbers");
    scanf("%d%d",a,b);
}
void sum(int a,int b,int *c)
{
    *c=a+b;
}
void output(int c)
{
    printf("the sum is %d",c);
}

int main()
{
    int a,b,c;
    input(&a,&b);
    sum(a,b,&c);
    output(c);
    return 0;
}
