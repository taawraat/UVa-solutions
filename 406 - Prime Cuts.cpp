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
#define    mp make_pair
#define    FOR(n,x) for(ll i = n; i < x; i++)
#define    FOR2(N,X) for(int j = N; j < X; j++)
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

ll sum(ll n){ return (n*(n+1))/2; }

ll logAB(ll a, ll b){ return log(a) / log(b); }

ll ceilAB(ll a, ll b){ return (a+b-1)/b; }

void solve(){

}

void TC(){
    int x; inp(x);

    while(x--){
        solve();
        nline;
    }
}

vector<ll> primes;
ll cnt[10000];

bool isPrime(ll &n){
    if(n%2 == 0 && n != 2)
        return false;

    for(ll i = 2; i*i <= n; i++){
        if(n%i == 0)
            return false;
    }
    return true;
}

void generate(){
    cnt[1] = 1;
    ll count = 1;
    primes.pb(1);

    for(ll i = 2; i <= 1000+100; i++){
        if(isPrime(i)){
            count++;
            primes.pb(i);
            cnt[i] = count;
        }
        else
            cnt[i] = count;
    }
}


int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    // TC();
    generate();

    ll n,c;

    while(inp(n) >> c){
        out(n) << ' ' << c << ": ";

        ll numOfPrimes,start;

        if(cnt[n] & 1)
            numOfPrimes = 2*c - 1;
        else
            numOfPrimes = 2*c;
        
        start = (cnt[n]/2) - (numOfPrimes/2);

        if(start < 0) start = 0;
        ll count = 0;

        while(1){
            out(primes[start++]);
            count++;
            if(primes[start] > n || count == numOfPrimes)
                break;
            else
                out(' ');
        }

        out("\n\n");
    } 
}
