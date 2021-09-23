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
const ll maxN = 10000000;

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

int ans[1000];
vector<ll> adj1[1000], adj2[1000];
vector<ll> cost(800);
int n, total, e;

void reset(){
    for(ll i = 0; i < 700; i++){
        adj1[i].clear();
        adj2[i].clear();
        cost[i] = 0;
        ans[i] = 0;
    }
    total = 0;
}

int minCost(int parent){
    int visited[700] = {};
    int curr, count = -cost[parent];

    queue<ll> q;

    q.push(parent);
    visited[parent] = true;

    // BFS traversal
    while(!q.empty()){
        curr = q.front();
        q.pop();

        count += cost[curr];
        for(auto &child: adj2[curr]){
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
            }
        }
    }

    return count;
}

int maxCost(int parent){
    int visited[700] = {};
    int curr, count = total;

    queue<ll> q;

    q.push(parent);
    visited[parent] = true;

    // BFS traversal
    while(!q.empty()){
        curr = q.front();
        q.pop();

        count -= cost[curr];
        for(auto &child: adj1[curr]){
            if(!visited[child]){
                visited[child] = true;
                q.push(child);
            }
        }
    }

    return count;
}

void BFS(){
    int mncost;

    for(ll i = 1; i <= n; i++){
        ans[i] = maxCost(i) - minCost(i);
    }
}

void solve(){
    int x,y, Case = 0;

    while(cin >> n >> e){
        if(!n && !e) break;
        reset();
        cout << "Case #" << ++Case << ":\n";
        
        for(ll i = 1; i <= n; i++){
            cin >> cost[i];
            total += cost[i];
        }

        while(e--){
            cin >> x >> y;
            adj1[y].pb(x);
            adj2[x].pb(y);
        }

        BFS();

        int num, q; cin >> q;

        while(q--){
            cin >> num;

            cout << ans[num] << '\n';
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
        if(t) nline;
    }
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
