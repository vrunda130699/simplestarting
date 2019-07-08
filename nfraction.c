#include<stdio.h> 
struct addFraction
{
    int num,dem;
};

void inputn(int *n)
{
    printf("enter the count of numbers");
    scanf("%d",n);
}

void input(struct addFraction f[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("enter the numerator and denominator for %d",(i+1));
        scanf("%d%d",&f[i].num,&f[i].dem);
        printf("%d  %d",f[i].num,f[i].dem);
        
    }
}
int gcd(int a, int b) 
{ 
    int g;
    if(b>a)
    {
    g=gcd(b,a);
    }
    else if (b == 0)
    {
      g=a ;
    }
    else
    {
        g=gcd(b,a%b);
    }
    return g; 
} 
  
struct addFraction lowest(struct addFraction f3) 
{ 
    int common_factor = gcd(f3.num,f3.dem); 
    f3.dem = f3.dem/common_factor; 
    f3.num = f3.num/common_factor; 
    return f3;
} 
  
void addFraction(struct addFraction f[],int n) 
{ 
    int i;
    struct addFraction f1;
    for(i=0;i<=(n/2);i++)
    {
    f1.dem = gcd(f[0].dem,f[(i+1)].dem); 
    printf("%d",f1.dem);
    f1.dem = (f[0].dem*f[i+1].dem) / f1.dem; 
    f1.num = (f[0].num)*(f[2].dem/f[0].dem) + (f[1].num)*(f[2].dem/f[1].dem); 
    f[0]=lowest(f1); 
} 
int main() 
{ 
    int n;
    inputn(&n);
    struct addFraction f[n];
    input(f,n);
    addFraction(f); 
    printf("%d %d",f[2].num,f[2].dem);
    
    return 0; 
} 
