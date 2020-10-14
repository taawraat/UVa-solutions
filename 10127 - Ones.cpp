#include <bits/stdc++.h>
#define sc scanf
#define t1(t) scanf("%d", &t)
#define FOR(x) for(int i = 0; i < x; i++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
using namespace std;

int ones(int x){
  int count = 1;

  for(int i = 1; i % x ; i = ((i*10)+1) % x)
    count++;
  
  return count;
}

int main(){
    int t;

    while(t1(t) == 1)
      pf("%d\n", ones(t));
}
