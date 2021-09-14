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

pair<int, int> convertCoordinate(string s){
    int x = s[0] - ('a' - 1);
    int y = s[1] - 48;

    return {x,y};
}

bool upLeft(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(y+2 > 8 || x-1 < 1)
        return false;
    
    return true;
}

bool upRight(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(y+2 > 8 || x+1 > 8)
        return false;
    
    return true;
}

bool downLeft(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(y-2 < 1 || x-1 < 1)
        return false;
    
    return true;
}

bool downRight(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(y-2 < 1 || x+1 > 8)
        return false;
    
    return true;
}

bool leftUp(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(x-2 < 1 || y+1 > 8)
        return false;
    
    return true;
}

bool leftDown(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(x-2 < 1 || y-1 < 1)
        return false;
    
    return true;
}

bool rightUp(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(x+2 > 8 || y+1 > 8)
        return false;
    
    return true;
}

bool rightDown(pair<int, int> p){
    int x = p.first;
    int y = p.second;

    if(x+2 > 8 || y-1 < 1)
        return false;
    
    return true;
}


void solve(){
    string s1, s2;

    pair<int,int> start, dest, curr;

    map<pair<int, int>, bool> visited;

    ll ans, cost;
    int x,y;

    while(cin >> s1 >> s2){
        visited.clear();
        ans = 1000000000000;
        start = convertCoordinate(s1);
        dest = convertCoordinate(s2);

        queue<pair<pair<int,int>, int>> q;
        q.push({start, 0});

        visited[start] = true;
        
        // BFS traversal
        while(!q.empty()){
            curr = q.front().first;
            cost = q.front().second;
            x = curr.first;
            y = curr.second;

            q.pop();

            if(curr == dest)
                ans = min(cost, ans);
            else{
                if(upLeft(curr) && !visited[{x-1, y+2}]){
                    q.push({{x-1, y+2}, cost+1});
                    visited[{x-1, y+2}] = true;
                }
                if(upRight(curr) && !visited[{x+1, y+2}]){
                    q.push({{x+1, y+2}, cost+1});
                    visited[{x+1, y+2}] = true;
                }
                if(downLeft(curr) && !visited[{x-1, y-2}]){
                    q.push({{x-1, y-2}, cost+1});
                    visited[{x-1, y-2}] = true;
                }
                if(downRight(curr) && !visited[{x+1, y-2}]){
                    q.push({{x+1, y-2}, cost+1});
                    visited[{x+1, y-2}] = true;
                }
                
                if(leftUp(curr) && !visited[{x-2, y+1}]){
                    q.push({{x-2, y+1}, cost+1});
                    visited[{x-2, y+1}] = true;
                }
                if(leftDown(curr) && !visited[{x-2, y-1}]){
                    q.push({{x-2, y-1}, cost+1});
                    visited[{x-2, y-1}] = true;
                }
                if(rightUp(curr) && !visited[{x+2, y+1}]){
                    q.push({{x+2, y+1}, cost+1});
                    visited[{x+2, y+1}] = true;
                }
                if(rightDown(curr) && !visited[{x+2, y-1}]){
                    q.push({{x+2, y-1}, cost+1});
                    visited[{x+2, y-1}] = true;
                }
            }
        }

        cout << "To get from " << s1 << " to " << s2 << " takes " << ans << " knight moves.\n";
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
