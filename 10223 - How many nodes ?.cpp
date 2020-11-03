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
std::map<ll,int> m;
ll c[1000000];
using namespace std;

void OJ(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
}

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

// Generate catalan number in range 4294967298
void cat(){
    c[0] = 1;
    c[1] = 1;
    m.insert(make_pair(0,1));
    m.insert(make_pair(1,1));
    ll MAX = 4294967298;
    for(int i = 2; c[i-1]<MAX; i++)
    {
        for(int j = 0; j<i; j++)
            c[i] += c[j] * c[i-j-1];
        
        // maping value with the key
        m.insert(make_pair(c[i], i));
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    OJ();

    // Start
    cat();
    int n;
    while(inp(n))
        // printing index of catalan number n
        out(m[n]) << ('\n');
}
