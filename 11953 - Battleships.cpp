#include   <bits/stdc++.h>
#define    pf printf
#define    sc scanf
#define    nline cout << '\n'
#define    dbg(x) \
           cout << "debug " << #x << ": " << x << '\n';
#define    inp(t) cin >> (t)
#define    out(t) cout << (t)
#define    lastof(s) s.size()-1
#define    all(x) x.begin(),x.end()
#define    pb push_back
#define    FOR(n,x) for(int i = n; i < x; i++)
#define    FOR2(N,X) for(int j = N; j < X; j++)
#define    wh(n) while(n--)
#define    EPS 1e10

typedef    unsigned long long ull;
typedef    long long ll;
using      namespace std;

// global
int n;
char grid[1000][1000];
bool visited[1000][1000];

void OJ(){
    // file I/O
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool descFun (ll i,ll j) { return (i>j); }

ll LCM(ll x, ll y) { return x * (y/__gcd(x,y)); }

void dfs(int i, int j){
    if(i < 0 || j < 0 || i >= n || j >= n || visited[i][j]) return;

    if(grid[i][j] == '.') return;
    visited[i][j] = 1;

    dfs(i-1,j);
    dfs(i+1,j);
    dfs(i,j+1);
    dfs(i,j-1);
}

void solve(){
    inp(n);
    int ans = 0;

    FOR(0,n)
        FOR2(0,n){
            inp(grid[i][j]);

            visited[i][j] = 0;
        }
    
    FOR(0,n)
        FOR2(0,n){
            if(!visited[i][j] && grid[i][j] == 'x'){
                ans++;
                dfs(i,j);
            }
        }

    out(ans);
}

void TC(){
    int x; inp(x);
    int Case = 0;

    wh(x){
        out("Case ") << ++Case << ": ";
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
