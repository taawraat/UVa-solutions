#include <bits/stdc++.h>
#define sc scanf
#define inp(t) scanf("%d", &t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
#define MAX 60
ll fib[MAX] = {}; 
using namespace std;

// returns lcm of x,y
ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

int main(){
  int step,mod;
  
  while(sc("%d%d", &step,&mod) == 2){
    int spaces = 9, digits = 10;
    while(step >= digits){
      spaces--;
      digits *= 10;
    }
    while(spaces--) pf(" ");

    pf("%d", step);

    spaces = 9, digits = 10;
    while(mod >= digits){
      spaces--;
      digits *= 10;
    }
    while(spaces--) pf(" ");

    pf("%d    ",mod);
    __gcd(step,mod) == 1 ? pf("Good Choice\n") : pf("Bad Choice\n");

    pf("\n");
  }
}
