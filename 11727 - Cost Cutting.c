#include<stdio.h>
int main()
{
  int T;
  scanf("%d",&T);
  for(int i=1; i<=T; i++)
  {
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    printf("Case %d: ", i);
    
    if((a>b && a<c) || (a<b && a>c))
    	printf("%d\n",a);
    else if((b>c && b<a) || (b>a && b<c))
    	printf("%d\n",b);
    else
    	printf("%d\n",c);
  }
}