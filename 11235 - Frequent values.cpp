#include   <bits/stdc++.h>

#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    rall(x)       x.rbegin(), x.rend()
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-5
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

ll ZeroBased(ll& i){ return i-1; }

ll OneBased(ll& i){ return i+1; }

bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }

bool isEqual(double a, double b) { return abs(a-b) < EPS; }

bool isGreater(double a, double b) { return a >= b + EPS; }

bool isGreaterEqual(double a, double b) { return a > b - EPS; }

int n;
ll ans;
int BLOCK = 700; // ~sqrt(n)
vector<ll> arr;
vector<ll> freq;
vector<ll> elemFreq;

struct query{
    int L,R,id;
};

bool cmp(query x, query y) {
	if(x.L/BLOCK != y.L/BLOCK) {
		return x.L/BLOCK < y.L/BLOCK;
	}
	return x.R < y.R;
}

void add(int i){
    freq[elemFreq[arr[i]]]--;
    elemFreq[arr[i]]++;
    freq[elemFreq[arr[i]]]++;

    ans = max(ans, elemFreq[arr[i]]);
}

void remove(int i){
    freq[elemFreq[arr[i]]]--;

    if(freq[elemFreq[arr[i]]] == 0 && ans == elemFreq[arr[i]])
        ans--;
    
    elemFreq[arr[i]]--;
    freq[elemFreq[arr[i]]]++;
}

void MO(vector<query>& Query, vector<ll>& Ans){
    sort(Query.begin(), Query.end(), cmp);

    int L,R;
    int currentL = 0, currentR = 0;

    for(auto &it: Query){
        L = it.L;
        R = it.R;

        while(currentL < L) {
			remove(currentL);
			currentL++;
		}
		while(currentL > L) {
			add(currentL-1);
			currentL--;
		}
		while(currentR <= R) {
			add(currentR);
			currentR++;
		}
		while(currentR > R+1) {
			remove(currentR-1);
			currentR--;
		}
        
        Ans[it.id] = ans;
    }
}

void solve(){
    while(1){
        cin >> n;

        if(n == 0) break;

        int q; cin >> q;
        
        ans = 0;
        arr = vector<ll>(n+5);
        freq = vector<ll>(11111+5, 0);
        elemFreq = vector<ll>(333333+5, 0);

        for(ll i = 0; i < n; i++){
            cin >> arr[i];
            arr[i] += (200000);
        }

        vector<query> Qry(q);

        for(ll i = 0; i < q; i++){
            cin >> Qry[i].L >> Qry[i].R;

            Qry[i].L--;
            Qry[i].R--;
            Qry[i].id = i;
        }

        vector<ll> Ans(q);

        freq[0]++;
        MO(Qry, Ans);

        for(auto &it: Ans){
            cout << it << '\n';
        }
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "Case " << ++Case << ":\n";
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
