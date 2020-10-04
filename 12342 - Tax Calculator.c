#include<stdio.h>
#include<math.h>
int main()
{
    int T;
    scanf("%d",&T);

    for(int i=1; i<=T; i++)
    {
        double total_tax = 0,temp = 0,income;
        scanf("%lf", &income);
        
        printf("Case %d: ", i);
        
        if(income <= 180000)
        {
            printf("0\n");
            continue;
        }
        if(income > 1180000)
        {
            temp = income - 1180000;
            total_tax += (temp * 25) / 100;
            income -= temp;
            temp = 0;
        }
        if(income <= 1180000 && income > 880000)
        {
            temp = income - 880000;
            total_tax += (temp * 20) / 100;
            income -= temp;
            temp = 0;
        }
        if(income <= 880000 && income > 480000)
        {
            temp = income - 480000;
            total_tax += (temp * 15) / 100;
            income -= temp;
            temp = 0;
        }
        if(income <= 480000 && income > 180000)
        {
            temp = income - 180000;
            total_tax += (temp * 10) / 100;
            income -= temp;
            temp = 0;
        }
        if(total_tax > 2000)
            printf("%.0lf\n", ceil(total_tax));
        else
            printf("2000\n");
    }
}