#include <stdio.h>
int main() 
{
  int T,N,creatureSpeed;
  
  scanf("%d",&T);
  
  for(int i = 1; i<=T; i++)
  {
    int requiredSpeed = 0;
    scanf("%d",&N);
    while(N--)
    {
      scanf("%d",&creatureSpeed);
      if(creatureSpeed>requiredSpeed)
        requiredSpeed = creatureSpeed;
    }
    printf("Case %d: %d\n",i,requiredSpeed);
  }
}