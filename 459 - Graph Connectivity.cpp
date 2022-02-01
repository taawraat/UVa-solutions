#include   <bits/stdc++.h>

#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    rall(x)       x.rbegin(), x.rend()
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-5
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

const ll mod = 1000000000+7;
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

ll ZeroBased(ll& i){ return i-1; }

ll OneBased(ll& i){ return i+1; }

bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }

bool isEqual(double a, double b) { return abs(a-b) < EPS; }

bool isGreater(double a, double b) { return a >= b + EPS; }

bool isGreaterEqual(double a, double b) { return a > b - EPS; }

int par[300];
int _size[300];

void init(){
    for(ll i = 'A'; i <= 'Z'; i++){
        par[i] = i;
        _size[i] = 1;
    }
}


int findP(int node){
    if(par[node] == node) return node;

    return par[node] = findP(par[node]);
}

void Union(int x, int y){
    int u = findP(x);
    int v = findP(y);

    if(u == v) return;

    if(_size[u] > _size[v]){
        par[v] = u;
        _size[u] += _size[v];
    }
    else{
        par[u] = v;
        _size[v] += _size[u];
    }
}

void solve(){
    string chs;
    getline(cin, chs);

    char ch = chs[0];

    string s;

    init();

    int total = (ch - 'A') + 1;

    while(1){
        if(!getline(cin, s) || s.length() == 0) break;
        if(findP(s[0]) != findP(s[1])){
            total--;
            Union(s[0], s[1]);
        }
    }

    cout << total << '\n';
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    scanf("%d\n\n", &t);
    
    while(t--){
        // cout << "Case " << ++Case << ": ";
        solve();
        if(t)
            nline;
    }
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    TC();
}
