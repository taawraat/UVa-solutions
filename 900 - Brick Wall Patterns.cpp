#include <bits/stdc++.h>

using ull = unsigned long long;
using ll = long long;

#define sc scanf
#define inp(t) scanf("%d", &t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define pf printf
#define wh(n) while(n--)
ll fib[51] = {}; 
using namespace std;

// returns lcm of x,y
ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

// returns Xth fibonacci number
ll fibOf(int x){ return fib[x]; }

// fibonacci number generator
void fibGen(){
  fib[0] = 1;
  fib[1] = 1;

  FOR(0,51)
    fib[i+2] = fib[i] + fib[i+1];
}

int main(){
    fibGen();
    while(1){
        int n; inp(n);

        if(!n) break;

        cout << fibOf(n) << endl;
    }
}
