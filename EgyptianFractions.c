#include <stdio.h>
void input(int a[],int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("enter the %d fraction",(i+1));
        scanf("%d",&a[i]);
        printf("1 / %d is the fraction\n",a[i]);
    }
    a[m]=1;
}
int product(int a[],int m)
{
    int i,result=1;
    for(i=0;i<m;i++)
    {
        result = (result * a[i]);
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


int findGCD(int a[], int m) 
{ 
    int result = a[0]; 
    int i;
    for (i = 1; i < m; i++) 
    {
        result = gcd(a[i] , result); 
    }
  
    return result; 
} 

void reduce(int *num,int *dem) 
{ 
    int common_factor = gcd(*num,*dem); 
    *dem = *dem/common_factor; 
    *num = *num/common_factor; 
} 



void addfraction(int a[],int m)
{
    int i,sum=0;
    int num[m],dem,n;
    int g = findGCD(a,m);
    printf("%d is gcd\n",g);
    int p = product(a,m);
    printf("%d is product\n",p);
    dem = p / g;
    printf("%d is denominator\n",dem);
    for(i=0;i<m;i++)
    {
        num[i]=0;
        num[i]  = 1*(dem/a[i]);
        printf("%d is the %d numerator\n",num[i],(i+1));
    }
    for(i=0;i<m;i++)
    {
        sum=sum + num[i];
    }
   n = sum;
   
     reduce(&n,&dem);
    printf("the sum is %d / %d\n",n,dem);
    
    
    
}
int main()
{
   int n,i;
  printf("enter the number of fraction for addtion\n");
  scanf("%d",&n);
   for(i=0;i<n;i++)
   {
       int m;
       printf("enter the number of fraction \n");
       scanf("%d",&m);
       int a[m];
       input(a,m);
       if(m>1)
       {
       addfraction(a,m);
       }
       else
       {
           printf("the addtion of fraction is 1/%d",a[0]);
       }
   }
    return 0;
}
