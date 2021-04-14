#include   <bits/stdc++.h>

#define    pf           printf
#define    sc           scanf
#define    nline        cout << '\n';
#define    dbg(x)       cout << "debug " << #x << ": " << x << '\n';
#define    inp(t)       cin >> (t)
#define    out(t)       cout << (t)
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    FOR(n, x)    for (ll i = n; i < x; i++)
#define    FOR2(N, X)   for (ll j = N; j < X; j++)
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-06

typedef    unsigned long long ull;
typedef    long long ll;
using      namespace std;

void OJ(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool descFun(ll i, ll j) { return (i > j); }

ll LCM(ll& x, ll& y) { return x * (y / __gcd(x, y)); }

ll sum(ll& n) { return (n * (n + 1)) / 2; }

ll logAB(ll& a, ll& b) { return log(a) / log(b); }

ll ceilAB(ll& a, ll& b) { return (a + b - 1) / b; }

ll chartoint(char& ch) { return ch - '0'; }

bool coPrime(ll& a, ll& b) { return __gcd(a,b) == 1; }

bool isEven(ll& n) { return (n&1) == 0; }

// returns how many numbers are divisible by Sn from 1 to range
ll divisibilityOfSet(ll range, ll set[], int elements){

    // subsets = (2^elements) - 1
    ll subSets = (1<<elements);
    ll ans = 0;

    // loop from 1 to subsets
    for(int i = 1; i < subSets; i++){
        ll devide = 1;
        ll bitSets = __builtin_popcount(i);

        // searching setbit positions
        for(int j = 0; j < elements; j++){
            if(i & (1<<j))
                devide = LCM(devide, set[j]);
        }

        // if number of elements is odd then add to ans
        if(bitSets & 1)
            ans = ans + (range/devide);

        // if number of elements is even then subtract from ans
        else
            ans = ans - (range/devide);
    }
    
    return ans;
}

void solve(){
    ll total, m;

    while(inp(total) >> m){
        ll set[m+1];

        FOR(0,m) inp(set[i]);

        out(total - divisibilityOfSet(total, set, m)) << '\n';
    }
}

void TC(){
    // int Case = 0;
    int t = 1;
    // inp(t);
    

    while (t--){
        // out("Case ") << ++Case << ": ";
        solve();
        // nline;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    

    // Start
    TC();
}
