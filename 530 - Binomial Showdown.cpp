#include <bits/stdc++.h>

using ull = unsigned long long;
using ll = long long;
#define pf printf
#define sc scanf
#define dbg(x,n) \
    pf("debug %s: %lld\n", x,n);
#define inp(t) scanf("%d", &t)
#define FOR(n,x) for(ll i = n; i < (ll)x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define wh(n) while(n--)
// #define OJ \
//     freopen("input.txt", "r", stdin); \
//     freopen("output.txt", "w", stdout);
using namespace std;

int main(){
    // OJ;

    // Start
    int n,r;
    while(inp(n)==1 && inp(r)==1){
        if(!n && !r) break;

        ll ans = 1;
        int low = n-r;
        if(low < r){
            low = r;
            r = n-r; 
        }
        int div = 1;
        FOR(low+1, n+1){
            if(div <= r)
                ans = (ans*i)/div++;
            else
                ans *= i;
        }
        pf("%lld\n", ans);
    }
}
