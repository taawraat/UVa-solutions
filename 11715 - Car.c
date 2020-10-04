#include<stdio.h>
#include<math.h>
int main()
{
    double u,v,t,a,s;
    for(int i = 1; i; i++)
    {
        int Case;
        scanf("%d", &Case);
        if(Case == 0) break;

        printf("Case %d: ", i);
        
        if(Case == 1)
        {
            scanf("%lf%lf%lf", &u,&v,&t);
            a = (v-u)/t;
            printf("%.3lf %.3lf\n", t*(u + ((a*t)/2)), a);            
        }
        else if(Case == 2)
        {
            scanf("%lf%lf%lf", &u,&v,&a);
            t = (v-u)/a;
            printf("%.3lf %.3lf\n", t*(u + ((a*t)/2)),t);
        }
        else if(Case == 3)
        {
            scanf("%lf%lf%lf", &u,&a,&s);
            v = sqrt(u*u + (2*a*s));
            printf("%.3lf %.3lf\n", v, (v-u)/a);
        }
        else if(Case == 4)
        {
            scanf("%lf%lf%lf", &v,&a,&s);
            u = sqrt(v*v - (2*a*s));
            printf("%.3lf %.3lf\n", u, (v-u)/a);
        }
    }
}