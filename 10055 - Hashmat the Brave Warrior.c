#include <stdio.h>
#include<stdlib.h>

int main(void) {
  long long int x,y;
  while(scanf("%lld%lld", &x,&y) == 2)
  {
    printf("%lld\n",llabs(x-y));
  }
}