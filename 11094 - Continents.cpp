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

int n, m;
int kn,km;
bool visited[30][30];
char grid[30][30];
char land;
int region;

void reset(){
    for(ll i = 0; i < 25; i++){
        for(ll j = 0; j < 25; j++){
            visited[i][j] = false;
        }
    }
}

void dfs(int i,int j){

    visited[i][j] = true;
    
    // for up
    if(i > 0 && grid[i-1][j] == land && !visited[i-1][j]){
        region++;
        dfs(i-1, j);
    }

    // for down
    if(i < n && grid[i+1][j] == land && !visited[i+1][j]){
        region++;
        dfs(i+1, j);
    }

    // for left right 
    if(j == m-1){
        if(grid[i][0] == land && !visited[i][0]){
            region++;
            dfs(i,0);
        }
    }

    if(j == 0){
        if(grid[i][m-1] == land && !visited[i][m-1]){
            region++;
            dfs(i,m-1);
        }
    }
    
    if(j > 0 && grid[i][j-1] == land && !visited[i][j-1]){
        region++;
        dfs(i,j-1);
    }
    
    if(j < m-1 && grid[i][j+1] == land && !visited[i][j+1]){
        region++;
        dfs(i,j+1);
    }
}

void solve(){

    while(cin >> n >> m){
        reset();
        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }

        cin >> kn >> km;
        land = grid[kn][km];

        dfs(kn, km);   // visit kings continent
        
        int maxContinent = 0;

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < m; j++){
                region = 1;
                if(!visited[i][j] && grid[i][j] == land){   // find maxContinet
                    dfs(i,j);
                    maxContinent = max(maxContinent, region);
                }
            }
        }

        
        cout << maxContinent << '\n';
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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
