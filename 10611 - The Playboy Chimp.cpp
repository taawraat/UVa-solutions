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
#define    FOR(n,x) for(ll i = n; i < x; i++)
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

pair<ll,ll> binarySearch(ll &query,vector<ll>& v){
    int start = 0;
    int end = v.size()-1;
    pair<ll,ll> p;

    if(query == v[0]){
        p.first = -1;
        p.second = start+1;
        return p;
    }
    if(query == v[end]){
        p.first = end-1;
        p.second = -1;
        return p;
    }

    while(start <= end){
        int mid = (start+end)/2;

        if(v[mid] == query){
            p.first = mid-1;
            p.second = mid+1;
            return p;
        }

        if(v[mid] < query) start = mid+1;
        else end = mid-1;
        
    }
    p.first = end;
    p.second = start;
    return p;
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    // TC();
    int n; inp(n);

    vector<ll> v;
    set<ll> s;
    ll h;
    FOR(0,n){
        inp(h);
        if(!s.count(h)){
            v.pb(h);
            s.insert(h);
        }
    }

    int q; inp(q);
    ll qry;
    pair<ll,ll> p;

    FOR(0,q){
        inp(qry);

        if(qry < v[0])
            out('X') << ' ' << v[0];
        else if(qry > v[lastof(v)])
            out(v[lastof(v)]) << ' ' << 'X';
        else{
            p = binarySearch(qry,v);
            p.first == -1 ? out('X') : out(v[p.first]);
            cout << ' ';
            p.second == -1 ? out('X') : out(v[p.second]);
        }
        nline;
    }
}
