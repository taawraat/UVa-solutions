#include <bits/stdc++.h>
#define sc scanf
#define inp(t) scanf("%d", &t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
using namespace std;

// returns lcm of x,y
ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

int main(){
  int n, nCr;
  
  while(inp(n) == 1){
    if(!n) break;

    // total combination is nC2
    nCr = (n * (n-1))/2;

    int num[n], Rprimes = 0;

    FOR(0,n)
        inp(num[i]);

    FOR(0,n-1)
        FOR2(i+1,n)
            if(__gcd(num[i], num[j]) == 1)
                Rprimes++;
    
    double ans = (nCr * 6) / (Rprimes * 1.0);

    !Rprimes ? pf("No estimate for this data set.\n") : pf("%lf\n", sqrt(ans));

  }
}
