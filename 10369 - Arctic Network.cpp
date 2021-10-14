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
    
ll Lcm(ll x, ll y) { return x * (y / __gcd(x, y)); }
    
ll Sum(ll n) { return (n * (n + 1)) / 2; }
    
ll logAB(ll a, ll b) { return log(a) / log(b); }
    
ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
    
ll chartoint(char ch) { return ch - '0'; }
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }

bool isEqual(double a, double b) { return abs(a-b) < EPS; }

bool isGreater(double a, double b) { return a >= b + EPS; }

bool isGreaterEqual(double a, double b) { return a > b - EPS; }

int sat,m;
int par[1000];
int _size[1000];

void init(){
    for(ll i = 0; i < 1000; i++){
        par[i] = i;
        _size[i] = 1;
    }
}

int findP(int node){
    if(node == par[node])
        return node;
    
    return par[node] = findP(par[node]);
}

void Union(int u,int v){
    u = findP(u);
    v = findP(v);
 
    if(u == v) return;
 
    if(_size[u] < _size[v]){
        par[u] = v;
        _size[v] += _size[u];
    }
    else{
        par[v] = u;
        _size[u] += _size[v];
    }
}

double Kruskal(vector<pair<double, pair<int, int>>>& data){
    int u, v;
    int n = data.size();
    double ans = 0;

    for(ll i = 0; i < n && m != sat; i++){
        u = data[i].second.first;
        v = data[i].second.second;

        if(findP(u) != findP(v)){
            ans = data[i].first;
            Union(u,v);
            m--;
        }
    }

    return ans;
}

double cost(pair<int, int>& p1, pair<int, int>& p2){
    ll x = (p2.first - p1.first)*(p2.first - p1.first);
    ll y = (p2.second - p1.second)*(p2.second - p1.second);

    return sqrt(abs(x)+abs(y));
}

void solve(){
    init();
    vector<pair<double, pair<int, int>>> data;

    cin >> sat >> m;

    vector<pair<int, int>> v(m+5);

    for(ll i = 1; i <= m; i++){
        cin >> v[i].first >> v[i].second;
    }

    double dist;

    for(ll i = 1; i <= m; i++){
        for(ll j = i+1; j <= m; j++){
            dist = cost(v[i], v[j]);

            data.pb({dist, {i,j}});
        }
    }

    sort(all(data));

    cout << fixed << setprecision(2) << Kruskal(data);  
}

void TC(){
    int Case = 0;
    int t = 1;
    cin >> t;
    
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
