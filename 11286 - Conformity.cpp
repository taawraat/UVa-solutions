#include   <bits/stdc++.h>
    
#define    pf           printf
#define    sc           scanf
#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    FOR(n, x)    for (ll i = n; i < x; i++)
#define    FOR2(N, X)   for (ll j = N; j < X; j++)
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-6

typedef    unsigned long long ull;
typedef    long long ll;
using      namespace std;
    
void OJ(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

// auto debug(){ return cout << endl,0; }
// template<typename Arg,typename... Args>
// auto debug(Arg elem,Args... elems){
//     cout << "debugging: " << elem << ' ';
//     // cout << endl;
//     return debug(elems...);
// }

template<typename T>
void printVec(vector<T>& v){
    cout << "vect: [ ";
    for(auto &it: v) cout << it << ' ';
    cout << "]\n";
}
    
bool DescFun(ll i, ll j) { return (i > j); }
    
ll Lcm(ll x, ll y) { return x * (y / __gcd(x, y)); }
    
ll Sum(ll n) { return (n * (n + 1)) / 2; }
    
ll logAB(ll a, ll b) { return log(a) / log(b); }
    
ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
    
ll chartoint(char& ch) { return ch - '0'; }
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }
    
bool isEven(ll n) { return (n&1) == 0; }
    
const ll mod = 1000000000+7;
const ll maxN = 1000000;

void solve(){
    int n;

    while(cin >> n){
        if(!n) break;

        int num, mx = 1;
        vector<int> v;
        map<vector<int>, int> m;
        set<vector<int>> s;

        for(ll i = 0; i < n; i++){
            for(ll j = 0; j < 5; j++){
                cin >> num;
                v.pb(num);
            }
            
            sort(all(v));

            m[v]++;
            mx = max(mx, m[v]);
            s.insert(v);

            v.clear();
        }

        int cnt = 0;

        for(auto &it: s){
            if(m[it] == mx) cnt++;
        }

        cout << mx*cnt << '\n';
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "Case " << ++Case << ": ";
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
