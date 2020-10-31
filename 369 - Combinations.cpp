#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
#define pf printf
#define sc scanf
#define dbg(x,n) \
    cout << "debug " << x << ": " << n << endl;
#define inp(t) cin >> (t)
#define out(t) cout << (t)
#define FOR(n,x) for(ll i = n; i < (ll)x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define wh(n) while(n--)
using namespace std;

void OJ(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    // OJ();

    // Start
     int n,r;
    while(scanf(" %3d %3d",&n, &r) == 2){
        if(!n && !r) break;
        cout << n << " things taken " << r << " at a time is ";
        ll ans = 1;
        int low = n-r;

        // declaring lower value
        if(low < r){
            low = r;
            r = n-r; 
        }
        int div = 1;

        FOR(low+1, n+1){
            // dividing n! by r!
            if(div <= r)
                ans = (ans*i)/div++;
            else
                ans *= i;
        }
         
        cout << ans << " exactly.";
        out("\n");
    }
}
