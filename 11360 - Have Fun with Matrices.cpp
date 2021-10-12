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
    
ll chartoint(char ch) { return ch - '0'; }
    
bool coPrime(ll a, ll b) { return __gcd(a,b) == 1; }
    
bool isEven(ll n) { return (n&1) == 0; }
    
const ll mod = 1000000000+7;
const ll maxN = 1000000;

int n;
char grid[20][20];

void printGrid(){
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cout << grid[i][j];
        }
        cout << '\n';
    }
}

void rowChange(int a, int b){
    for(ll i = 0; i < n; i++){
        swap(grid[a][i], grid[b][i]);
    }
}

void colChange(int a, int b){
    for(ll i = 0; i < n; i++){
        swap(grid[i][a], grid[i][b]);
    }
}

void increment(){
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            int val = (chartoint(grid[i][j])+1) % 10;
            grid[i][j] = val+48;
        }
    }
}

void decrement(){
    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            int val = chartoint(grid[i][j])-1;
            val = (val < 0 ? 9 : val%10);
            grid[i][j] = val+48;
        }
    }
}

void transpose(){
    char tmp[20][20];

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            tmp[j][i] = grid[i][j];
        }
    }

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            grid[i][j] = tmp[i][j];
        }
    }
}

void solve(){
    cin >> n;

    for(ll i = 0; i < n; i++){
        for(ll j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    int q; cin >> q;

    int a,b;
    string operation;

    while(q--){
        cin >> operation;

        if(operation == "transpose")
            transpose();
        else if(operation == "inc")
            increment();
        else if(operation == "dec")
            decrement();
        else if(operation == "row"){
            cin >> a >> b;
            rowChange(a-1,b-1);
        }
        else{
            cin >> a >> b;
            colChange(a-1,b-1);
        }
    }

    printGrid();
}

void TC(){
    int Case = 0;
    int t = 1;
    cin >> t;
    
    while(t--){
        cout << "Case #" << ++Case << "\n";
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
