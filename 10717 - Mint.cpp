#include   <bits/stdc++.h>

#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    rall(x)       x.rbegin(), x.rend()
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-12
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

const ll mod = 2000000011;
const ll maxN = 150000+10;

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
    
ll Lcm(ll x, ll y) { return x * y / __gcd(x, y); }
    
ll Sum(ll n) { return (n * (n + 1)) / 2; }
    
ll logAB(ll a, ll b) { return log(a) / log(b); }
    
ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
    
ll chartoint(char ch) { return ch - '0'; }
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }

bool isEqual(double a, double b) { return abs(a-b) < EPS; }

bool isGreater(double a, double b) { return a >= b + EPS; }

bool isGreaterEqual(double a, double b) { return a > b - EPS; }

void bruteforce(vector<ll>& v, vector<ll>& allLcm, int n){
    ll a,b,c,d;
    ll lcm;

    for(ll i = 0; i < n-3; i++){
        for(ll j = i+1; j < n-2; j++){
            for(ll k = j+1; k < n-1; k++){
                for(ll l = k+1; l < n; l++){
                    a = v[i];
                    b = v[j];
                    c = v[k];
                    d = v[l];

                    lcm = Lcm(a, Lcm(b, Lcm(c,d)));
                    allLcm.pb(lcm);
                }
            }
        }
    }
}

void solve(){
    int n,m;

    while(cin >> n >> m && !(!n && !m)){
        vector<ll> v(n), allLcm;

        for(auto &it: v){
            cin >> it;
        }

        ll mx = -1, mn = INT_MAX;
        
        bruteforce(v, allLcm, n);
        int sz = allLcm.size();

        ll table;

        for(ll i = 0; i < m; i++){
            cin >> table;

            mn = INT_MAX;
            mx = -1;
            
            for(ll j = 0; j < sz; j++){
                mx = max(mx, allLcm[j] * (table/allLcm[j]));
                mn = min(mn, allLcm[j] * ceilAB(table,allLcm[j]));
            }

            cout << mx << ' ' << mn;
            nline;
        }
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "Case #" << ++Case << ": ";
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
