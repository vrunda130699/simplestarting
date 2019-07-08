#include<stdio.h> 
struct Fraction
{
    int num,dem;
};

void input(struct Fraction *f1,struct Fraction *f2)
{
    printf("enter the numerator and denominator for 1st fraction");
    scanf("%d %d",(&f1->num),(&f1->dem));
    printf("enter the num and deno for 2nd fraction");
    scanf("%d %d",(&f2->num),(&f2->dem));
}
int gcd(int a, int b) 
{ 
    int i,gcd=0;
     for(i=1; i <= a && i <= b; ++i)
    {
        if(a%i==0 && b%i==0)
            gcd = i;
    }
    return gcd;

} 
  
struct Fraction * reduce(struct Fraction *f3) 
{ 
    int common_factor = gcd(f3->num,f3->dem); 
    f3->dem = f3->dem/common_factor; 
    f3->num = f3->num/common_factor; 
    return f3;
} 
  
void addFraction(struct Fraction f1,struct Fraction f2,struct Fraction *f3) 
{ 
    f3->dem = gcd(f1.dem,f2.dem); 
    f3->dem = (f1.dem*f2.dem) / f3->dem; 
    f3->num = (f1.num)*(f3->dem/f1.dem) + (f2.num)*(f3->dem/f2.dem); 
    f3=reduce(f3); 
} 
int main() 
{ 
    struct Fraction f1,f2,f3;
    input(&f1,&f2);
    addFraction(f1,f2,&f3); 
    printf("%d %d",f3.num,f3.dem);
    return 0; 
} 
