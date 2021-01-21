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

void OJ(){
    // file I/O
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

bool descFun (ll i,ll j) { return (i>j); }

ll LCM(ll x, ll y) { return x * (y/__gcd(x,y)); }

void solve(){
        
}

void TC(){
    int x; inp(x);

    wh(x){
        solve();
        nline;
    }
}

// global variables
vector<vector<ll>> graph;
vector<bool> visited;
vector<ll> ans;

// topological sort
void topSort(int node){
    if(visited[node]) return;

    visited[node] = true;
    for(auto child: graph[node]){
        if(!visited[child])
            topSort(child);
    }
    ans.pb(node);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    // TC();

    int n,m;

    while(inp(n) && inp(m)){
        if(!n && !m) break;

        graph.resize(n+1);
        visited.resize(n+1, false);

        wh(m){
            int a,b; inp(a) >> b;
            graph[a].pb(b);
        }

        FOR(1,n+1)
            if(!visited[i])
                topSort(i);
        
        for(int i = n-1; i >= 1; i--)
            cout << ans[i] << ' ';
        out(ans[0]);
        
        ans.clear();
        graph.clear();
        visited.clear();
        nline;
    }
}
