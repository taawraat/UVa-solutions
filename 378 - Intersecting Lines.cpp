#include   <bits/stdc++.h>

#define    nline        cout << '\n';
#define    lastof(s)    s.size() - 1
#define    all(x)       x.begin(), x.end()
#define    rall(x)       x.rbegin(), x.rend()
#define    pb           push_back
#define    mp           make_pair
#define    EPS          1e-9
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

const ll mod = 1073741824;
const ll maxN = 100000+10;

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

void lineLineIntersection(pdd A, pdd B, pdd C, pdd D){
	double a1 = B.second - A.second;
	double b1 = A.first - B.first;
	double c1 = a1*(A.first) + b1*(A.second);

	double a2 = D.second - C.second;
	double b2 = C.first - D.first;
	double c2 = a2*(C.first)+ b2*(C.second);

	double determinant = a1*b2 - a2*b1;

    int Dx = c1*b2 - c2*b1;
    int Dy = a1*c2 - a2*c1;

	if (determinant == 0){
		if(Dx || Dy)
            cout << "NONE";
        else
            cout << "LINE";
        return;
	}
	else{
		double x = (Dx)/determinant;
		double y = (Dy)/determinant;
		cout << "POINT " << fixed << setprecision(2) << x << ' ' << y;
	}
}

void solve(){
    int x1,y1, x2,y2;
    int x3,y3, x4,y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    pdd A = make_pair(x1, y1);
    pdd B = make_pair(x2, y2);
    pdd C = make_pair(x3, y3);
    pdd D = make_pair(x4, y4);

    lineLineIntersection(A,B,C,D);
}

void TC(){
    int Case = 0;
    int t = 1;
    cin >> t;
    
    cout << "INTERSECTING LINES OUTPUT\n";
    while(t--){
        // cout << "CASE " << ++Case << ": ";
        solve();
        nline;
    }
    cout << "END OF OUTPUT\n";
}
    
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();
    
    // Start
    TC();
}
