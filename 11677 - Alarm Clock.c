#include <stdio.h>

int main(void) 
{
  while(1)
  {
    int H1,M1,H2,M2;
    
    scanf("%d%d%d%d",&H1,&M1,&H2,&M2);
    
    if(H1==0 && M1==0 && H2==0 && M2==0) break;
    
    else if(H1<H2 || (H1==H2 && M2>=M1))
      printf("%d\n",((H2-H1)*60)+(M2-M1));
      
    else
      printf("%d\n",((24-(H1-H2))*60) + (M2-M1));
  }
}