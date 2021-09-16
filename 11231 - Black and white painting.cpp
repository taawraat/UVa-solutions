#include   <bits/stdc++.h>
    
#define    pf           printf
#define    sc           scanf
#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    FOR(n, x)    for (ll i = n; i < x; i++)
#define    FOR2(N, X)   for (ll j = N; j < X; j++)
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-9

typedef    unsigned long long ull;
typedef    long long ll;
using      namespace std;

void OJ(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

#ifndef ONLINE_JUDGE

auto debug(){ return cout << endl,0; }
template<typename Arg,typename... Args>
auto debug(Arg elem,Args... elems){
    cout << "debugging: " << elem << ' ';
    // cout << endl;
    return debug(elems...);
}

template<typename T>
void printVec(T& v){
    cout << "container : [ ";
    for(auto &it: v) cout << it << ' ';
    cout << "]\n";
}

#endif

const ll mod = 998244353;
const ll maxN = 1000000;

ll bigMod(ll a, ll b, ll m){
  ll ans = 1;
  a = a % m;
  
  while(b){
    if(b & 1)
      ans = (ans * a) % m;
      
    a = (a*a) % m;
    b /= 2;
  }
  return ans;
}

ll MOD(ll num){ return ((num%mod + mod)%mod); }

ll modAdd(ll a, ll b){ return MOD(MOD(a) + MOD(b)); }

ll modSub(ll a, ll b){ return MOD(MOD(a) - MOD(b)); }

ll modMul(ll a, ll b){ return MOD(MOD(a) * MOD(b)); }

ll modDiv(ll a, ll b){ return modMul(a, bigMod(b,mod-2, mod)); }
    
ll Lcm(ll x, ll y) { return x * (y / __gcd(x, y)); }
    
ll Sum(ll n) { return (n * (n + 1)) / 2; }
    
ll logAB(ll a, ll b) { return log(a) / log(b); }
    
ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
    
ll chartoint(char ch) { return ch - '0'; }
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }

bool isEqual(double a, double b) { return abs(a-b) < EPS; }

bool isGreater(double a, double b) { return a >= b + EPS; }

bool isGreaterEqual(double a, double b) { return a > b - EPS; }

void solve(){
    ll r,c;
    bool lastWhite;
    ll totalRow, totalCol;

    while(cin >> r >> c >> lastWhite){
        if(!r && !c) break;

        totalRow = (r-7);
        totalCol = (c-7);

        cout << ((totalRow*totalCol)+lastWhite)/2 << '\n';
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "Case " << ++Case << ": ";
        solve();
        if(t) nline;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
