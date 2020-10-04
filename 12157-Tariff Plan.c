#include <stdio.h>
#include <math.h>
int main() 
{
  int T,N,duration,Mile[100],Juice[100];
  scanf("%d",&T);

  for(int i=1; i <= T; i++){
    Mile[i] = 0;
    Juice[i] = 0;
    scanf("%d",&N);
    while(N--){
      int juiceRate = 60,mileRate = 30;  

      scanf("%d",&duration);
      if(juiceRate % 60 == 0)
        juiceRate = (duration/60)+1;
      if(mileRate % 30 == 0)
        mileRate = (duration/30)+1;

      Mile[i] += mileRate * 10;
      Juice[i] += juiceRate * 15;
    }
  }
  for(int i=1; i <= T; i++){
    if(Mile[i] == Juice[i])
      printf("Case %d: Mile Juice %d\n",i,Mile[i]);
    else if(Mile[i] < Juice[i])
      printf("Case %d: Mile %d\n",i,Mile[i]);
    else
      printf("Case %d: Juice %d\n",i,Juice[i]);
  }

  return 0;
}