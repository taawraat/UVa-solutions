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
  ll n;
  while(sc("%lld",&n) == 1){
    ll ans = 1;
    pf("%5lld -> ", n);
    for(ll i = 1; i <= n; i++){
      ans = ans * i;
      while(1){
        if(ans % 10){
          ans = ans % 1000000;
          break;
        }
        else
          ans = ans / 10;
      }
    }
    
    cout << ans%10 << endl;
  }
}
