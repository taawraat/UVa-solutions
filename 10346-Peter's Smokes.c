#include <stdio.h>
int main() 
{
  int n,k,total;
  while(scanf("%d%d",&n,&k) == 2){
    total = n;
    while(n/k != 0){
      total += n/k;
      n = (n/k) + (n%k);
    }
    printf("%d\n", total);
  }
}