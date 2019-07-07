#include<stdio.h> 
struct addFraction
{
    int num,dem;
};

void input(struct addFraction f[])
{
    int i;
    for(i=0;i<2;i++)
    {
        printf("enter the numerator and denominator for %d",(i+1));
        scanf("%d%d",&f[i].num,&f[i].dem);
        printf("%d  %d\n",f[i].num,f[i].dem);
        
    }
}
int gcd(int a, int b) 
{ 
    if (a == 0) 
        return b; 
    return gcd(b%a, a); 
} 
  
struct addFraction lowest(struct addFraction f3) 
{ 
    int common_factor = gcd(f3.num,f3.dem); 
    f3.dem = f3.dem/common_factor; 
    f3.num = f3.num/common_factor; 
    return f3;
} 
  
void addFraction(struct addFraction f[]) 
{ 
    f[2].dem = gcd(f[0].dem,f[1].dem); 
    f[2].dem = (f[0].dem*f[1].dem) / f[2].dem; 
    f[2].num = (f[0].num)*(f[2].dem/f[0].dem) + (f[1].num)*(f[2].dem/f[1].dem); 
    f[2]=lowest(f[2]); 
} 
int main() 
{ 
    struct addFraction f[3];
    input(f);
    addFraction(f); 
    printf("%d %d",f[2].num,f[2].dem);
    
    return 0; 
} 
