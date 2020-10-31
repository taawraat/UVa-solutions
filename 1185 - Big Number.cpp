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
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    // OJ();

    // Start
    int t; inp(t);
    wh(t){
        int num; inp(num);
        double ans = 0;
        FOR(2,num+1)
            ans += log10(i);
        
        pf("%.0lf\n", floor(ans)+1);
    }
}
