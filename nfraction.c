#include <stdio.h> 
struct fraction
{
    int dem,num;
};
void inputn(int *n)
{
    printf("enter the count of numbers");
    scanf("%d",n);
}
void input(struct fraction f[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
    printf("enter the numerator and denominator for %d number \n",(i+1));
    scanf(" %d %d",&f[i].num,&f[i].dem);
    
    }
    
    
}

int product(struct fraction f[],int n)
{
    int i,result=1;
    for(i=0;i<n;i++)
    {
        result = (result*(f[i].dem));
    }
    return result;
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
       g = a;
    }
    else
    {
        g = gcd(b,a%b);
    }
    return g;
}


int findGCD(struct fraction f[], int n) 
{ 
    int result = f[0].dem; 
    int i;
    for (i = 1; i < n; i++) 
    {
        result = gcd(f[i].dem , result); 
    }
  
    return result; 
} 

void reduce(struct fraction *f3) 
{ 
    int common_factor = gcd(f3->num,f3->dem); 
    f3->dem = f3->dem/common_factor; 
    f3->num = f3->num/common_factor; 
} 



struct fraction addfraction(struct fraction f[],int n)
{
    int i,sum=0;
    struct fraction f1;
    int g = findGCD(f,n);
    printf("%d is gcd\n",g);
    int p = product(f,n);
    printf("%d is product\n",p);
    f1.dem=p/g;
    for(i=0;i<n;i++)
    {
        f[i].num  = f[i].num*(f1.dem/f[i].dem);
    }
    for(i=0;i<n;i++)
    {
        sum=sum + f[i].num;
    }
    f1.num = sum;
     reduce(&f1);
     return f1;
}

int main() 
{ 
    int n; 
    inputn(&n);
    struct fraction f[n],f1;
    input(f,n);
    f1=addfraction(f,n);
     printf("the sum is %d / %d",f1.num,f1.dem);
    return 0; 
}
