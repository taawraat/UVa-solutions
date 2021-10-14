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
    
ll Lcm(ll x, ll y) { return x * (y / __gcd(x, y)); }
    
ll Sum(ll n) { return (n * (n + 1)) / 2; }
    
ll logAB(ll a, ll b) { return log(a) / log(b); }
    
ll ceilAB(ll a, ll b) { return (a + b - 1) / b; }
    
ll chartoint(char ch) { return ch - '0'; }
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }

bool isEqual(double a, double b) { return abs(a-b) < EPS; }

bool isGreater(double a, double b) { return a >= b + EPS; }

bool isGreaterEqual(double a, double b) { return a > b - EPS; }

vector<set<pair<string, string>>> ans(300);

void init(){
    for(ll i = 0; i < 300; i++){
        ans[i].clear();
    }
}

pair<string, string> parseData(string& cmd){
    int n = cmd.length();

    string num, str = "";

    for(ll i = 0; i < n; i++){
        if(!(cmd[i] == '(' || cmd[i] == ')' || cmd[i] == ',')){
            if(cmd[i] >= '0' && cmd[i] <= '9')
                num.pb(cmd[i]);
            else
                str.pb(cmd[i]);
        }
    }

    return {str, num};
}

void printData(int n){
    vector<string> v;

    for(ll i = 0; i <= n; i++){
        if(!ans[i].size()){
            cout << "not complete\n";
            return;
        }
        for(auto &it: ans[i]){
            v.pb(it.second);
            v.pb(" ");
        }
    }

    v.pop_back();

    for(auto &it: v){
        cout << it;
    }

    cout << '\n';
}

void solve(){
    string cmd;
    pair<string, string> p;
    bool complete = true;
    ll lvl = -1;
    set<string> allCmd;

    while(cin >> cmd){
        if(cmd == "()"){
            if(!complete)
                cout << "not complete\n";
            else
                printData(lvl);
            complete = true;
            init();
            allCmd.clear();
            lvl = -1;
        }
        else{
            p = parseData(cmd);
            if(allCmd.count(p.first))
                complete = false;
            else{
                allCmd.insert(p.first);
                ans[p.first.size()].insert(p);
                lvl = max(lvl, (long long)p.first.size());
            }
        }
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
