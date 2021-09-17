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

const ll mod = 998244353;
const ll maxN = 1000000;

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

bool isLeapYear(int year){
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0)
                return true;
            else
                return false;
        }
        else
            return true;
    }
    return false;
}

bool has31Days(int month){
    bool check[] = {0, 1, 0 , 1, 0, 1, 0, 1, 1, 0, 1, 0, 1};

    return check[month];
}

struct info{
    int day;
    int month;
    int year;

    ll amount;
};

bool isConsecutive(struct info &curr, struct info &prev){
    if(curr.year == prev.year){
        if(curr.month == prev.month){
            if(curr.day - prev.day == 1)
                return true;
            else
                return false;
        }
        else{
            if(curr.day != 1)
                return false;
            else if(curr.month - prev.month != 1)
                return false;
            else{
                if(prev.month == 2){
                    if(isLeapYear(prev.year)){
                        if(prev.day != 29)
                            return false;
                        else
                            return true;
                    }
                    else{
                        if(prev.day != 28)
                            return false;
                        else
                            return true;
                    }
                }
                if(has31Days(prev.month)){
                    if(prev.day != 31)
                        return false;
                    return true;
                }
                else{
                    if(prev.day != 30)
                        return false;
                    return true;
                }

            }
        }
    }
    else{
        if(curr.year - prev.year != 1 || curr.day != 1)
            return false;
        else{
            if(prev.month != 12 || prev.day != 31)
                return false;
            return true;
        }
    }

    return false;
}

void solve(){
    int n;

    struct info prev, curr;

    ll ans, cnt;

    while(cin >> n && n){
        cin >> prev.day >> prev.month >> prev.year >> prev.amount;
        
        ans = cnt = 0;

        for(ll i = 1; i < n; i++){
            cin >> curr.day >> curr.month >> curr.year >> curr.amount;

            if(isConsecutive(curr,prev)){
                ans += (curr.amount - prev.amount);
                cnt++;
            }

            prev = curr;
        }


        cout << cnt << ' ' << ans << '\n';
    }
}

void TC(){
    int Case = 0;
    int t = 1;
    // cin >> t;
    
    while(t--){
        // cout << "Case " << ++Case << ": ";
        solve();
        if(t) nline;
    }
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
