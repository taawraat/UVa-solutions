#include <stdio.h>
int main() 
{
  int T,store,positions[100];
  scanf("%d",&T);
  while(T--){
    int highest=0,lowest=100;
    scanf("%d",&store);

    for(int i = 0; i < store; i++){
      scanf("%d",&positions[i]);
      if(positions[i]>highest)
        highest = positions[i];
      if(positions[i]<lowest)
        lowest = positions[i];
      }
      printf("%d\n",(highest-lowest)*2);
  }
}