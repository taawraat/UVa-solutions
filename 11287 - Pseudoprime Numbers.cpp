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

#ifndef ONLINE_JUDGE
    auto debug(){ return cout << endl,0; }
    template<typename Arg,typename... Args>
    auto debug(Arg elem,Args... elems){
        cout << "debugging: " << elem << ' ';
        // cout << endl;
        return debug(elems...);
    }
    
    template<typename T>
    void printVec(vector<T>& v){
        cout << "vect: [ ";
        for(auto &it: v) cout << it << ' ';
        cout << "]\n";
    }
#endif
    
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

ll bigMod(ll a, ll b, ll m)
{
  ll ans = 1;
  a = a % m;
  
  while(b){
    // checking if bit is 1
    if(b & 1)
      ans = (ans * a) % m;
      
    a = (a*a) % m;
    b /= 2;
  }
  return ans;
}

bool isPrime(ll n){
    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0) return false;
    }

    return true;
}

void solve(){
    ll p, a;

    while(cin >> p >> a){
        if(!p && !a) break;
        
        if(isPrime(p))
            cout << "no";
        else if(bigMod(a,p,p) == a)
            cout << "yes";
        else
            cout << "no";

        nline;
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
