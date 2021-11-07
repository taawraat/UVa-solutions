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
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }

bool isEqual(double a, double b) { return abs(a-b) < EPS; }

bool isGreater(double a, double b) { return a >= b + EPS; }

bool isGreaterEqual(double a, double b) { return a > b - EPS; }

ll _size[5000];
ll par[5000];

void init(){
    for(ll i = 0; i <= 5000; i++){
        _size[i] = 0;
        par[i] = i;
    }
}

ll findP(ll node){
    if(par[node] == node)
        return node;
    
    return par[node] = findP(par[node]);
}

void Union(int u, int v){
    u = findP(u);
    v = findP(v);

    if(v == u) return;

    if(_size[u] > _size[v]){
        _size[u] += _size[v];
        par[v] = par[u];
    }
    else{
        _size[v] += _size[u];
        par[u] = par[v];
    }
}

ll Kruskal(vector<pair<ll, pair<ll, ll>>>& data){
    ll minCost = 0;
    ll u,v,cost;

    for(auto &it: data){
        cost = it.first;
        u = it.second.first;
        v = it.second.second;

        if(findP(u) != findP(v)){
            minCost += cost;
            Union(u,v);
        }
    }

    return minCost;
}

void solve(){
    init();
    int n, m; cin >> n >> m;

    map<string, int> mpp;
    set<string> s;
    vector<pair<ll, pair<ll, ll>>> data;

    ll id = 0, cost;
    string city1, city2;

    for(ll i = 0; i < m; i++){
        cin >> city1 >> city2 >> cost;

        if(!s.count(city1)){
            mpp[city1] = ++id;
            s.insert(city1);
        }
        if(!s.count(city2)){
            mpp[city2] = ++id;
            s.insert(city2);
        }

        data.pb({cost, {mpp[city1], mpp[city2]}});
    }

    sort(all(data));

    cout << Kruskal(data);
    nline;
}

void TC(){
    int Case = 0;
    int t = 1;
    cin >> t;
    
    while(t--){
        // cout << "CASE " << ++Case << ": ";
        solve();
        if(t)
        nline;
    }
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
