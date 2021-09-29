#include   <bits/stdc++.h>

#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
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
const ll maxN = 100000+10;

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

// CP3 book chap: 3.5.2
// MAX 2D range sum

void solve(){
    int n; cin >> n;

    int grid[n+1][n+1];

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cin >> grid[i][j];

            if(i > 0) grid[i][j] += grid[i-1][j];
            if(j > 0) grid[i][j] += grid[i][j-1];
            if(i > 0 && j > 0) grid[i][j] -= grid[i-1][j-1]; // removing double count of diagonals
        }
    }

    ll maxSubRect = -10000000000;
    ll subRect;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            for(ll k = i; k < n; k++){
                for(ll l = j; l < n; l++){
                    subRect = grid[k][l];


                    if(i > 0) subRect -= grid[i-1][l];
                    if(j > 0) subRect -= grid[k][j-1];
                    if(i > 0 && j > 0) subRect += grid[i-1][j-1]; // adding removed diagonals
                        
                    maxSubRect = max(maxSubRect, subRect);
                }
            }
        }
    }

    cout << maxSubRect;
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "CASE " << ++Case << ": ";
        solve();
        nline;
    }
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
