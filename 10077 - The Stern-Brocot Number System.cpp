#include   <bits/stdc++.h>

#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    rall(x)       x.rbegin(), x.rend()
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-9
#define    pdd          pair<double,double>

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

void solve(){
    ll n,m;
    
    ll LU , LD , RU, RD;
    ll curr_u, curr_d;

    while(cin >> n >> m && !(n == 1 && m == 1)){
        LU = 0, LD = 1, RU = 1, RD = 0;     // LU = Left up, LD = Left down
                                            // RU = Right up, RD = Right down
        curr_u = curr_d = 1;                // curr_u = current up, curr_d = current down

        while(1){
            if(curr_u == n && curr_d == m) break;
            if(curr_d * n < curr_u * m){
                cout << 'L';
                RU = curr_u;
                RD = curr_d;
            } else{
                cout << 'R';
                LU = curr_u;
                LD = curr_d;
            }

            curr_u = LU + RU;
            curr_d = LD + RD;
        }

        cout << '\n';
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "CASE " << ++Case << ": ";
        solve();
        // nline;
    }
}
    
int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
