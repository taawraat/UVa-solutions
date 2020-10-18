#include <bits/stdc++.h>
#define sc scanf
#define inp(t) scanf("%d", &t)
#define FOR(x) for(int i = 0; i < x; i++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
#define MAX 60
ll fib[MAX] = {}; 
using namespace std;

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

// returns Xth fibonacci number
ll fibOf(int x){ return fib[x]; }

// fibonacci number generator
void fibGen(){
  fib[0] = 1;
  fib[1] = 2;

  FOR(MAX)
    fib[i+2] = fib[i] + fib[i+1];
}

int main(){
  fibGen();
  int n; inp(n);

  for(int i = 1; i <= n; i++){
    int x; inp(x);
    pf("Scenario #%d:\n", i);
    pf("%lld\n\n", fibOf(x));
  }
}
