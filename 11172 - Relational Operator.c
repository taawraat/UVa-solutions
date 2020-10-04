#include<stdio.h>
int main (){
  int T,N1,N2;
  scanf("%d",&T);
  while(T--)
  {
    scanf("%d %d", &N1, &N2);
    if(N1 > N2) 
      printf(">\n");
     else if(N1 < N2) 
       printf("<\n");
     else 
        printf("=\n");
  }
}