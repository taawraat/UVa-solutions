#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
#define pf printf
#define sc scanf
#define nline cout << '\n'
#define dbg(x) \
    cout << "debug " << #x << ": " << x << '\n';
#define inp(t) cin >> (t)
#define out(t) cout << (t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define wh(n) while(n--)
using namespace std;

void OJ(){
    // file I/O
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    ll Case = 0, t; inp(t);
    wh(t){
        out("Case ") << '#' << ++Case << ":";
        set<ll> s;
        ll c,r; inp(c); inp(r);

        if(c == r){
            out(" 0\n");
            continue;
        }
        // ans = all the number 'x' such x | (c-r) where c >= x > r
        ll num = c-r;

        for(ll i = 1; i*i <= num; ++i){
            // searching for all such 'x'
            if(num%i == 0){
                if(i > r && i <= c)
                    s.insert(i);
                if(num/i > r && num/i <= c)
                    s.insert(num/i);
            }
        }
        // set is already sorted
        for(auto &it: s)
            out(' ') << it;
        nline;
    }
}
