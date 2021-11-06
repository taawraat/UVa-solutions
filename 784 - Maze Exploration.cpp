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

bool printed;
char grid[50][100];
bool visited[50][100];
char wall;

void reset(){
    printed = false;
    for(ll i = 0; i < 50; i++){
        for(ll j = 0; j < 100; j++){
            grid[i][j] = '\n';
            visited[i][j] = false;
        }
    }
}

bool terminate(string s){
    if(!s.length())
        return false;
    for(auto &ch: s){
        if(ch != '_')
            return false;
    }

    return true;
}

int dx[] = {0, 0, 1,-1};
int dy[] = {1,-1, 0, 0};

bool isWall(char ch){
    return ch != ' ' && ch != '_' && ch != '*';
}

void dfs(int x, int y){
    visited[x][y] = true;
    grid[x][y] = '#';

    for(ll j = 0; j < 4; j++){
        if(!isWall(grid[dx[j]+x][dy[j]+y])){
            if(!visited[dx[j]+x][dy[j]+y])
                dfs(dx[j]+x, dy[j]+y);
        }
    }
}

void solve(){
    reset();

    int n;
    string s;
    
    vector<int> sz(50);
    int si, sj;

    for(ll i = 0; !terminate(s) ; i++){
        getline(cin, s);

        n = s.length();

        for(ll j = 0; j < n; j++){
            grid[i][j] = s[j];

            if(s[j] == '*'){
                si = i;
                sj = j;
            }
        }

        if(!n) i--;
        sz[i] = n;
    }

    dfs(si, sj);

    for(ll i = 0; i < 40; i++){
        for(ll j = 0; j < sz[i]; j++){
            cout << grid[i][j];
            printed = true;
        }
        if(sz[i])
            nline;
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    cin >> t;
    
    while(t){
        // cout << "CASE " << ++Case << ": ";
        solve();

        if(printed)
            t--;
        // nline;
    }
}
    
int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
