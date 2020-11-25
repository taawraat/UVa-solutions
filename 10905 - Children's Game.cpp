#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
#define pf printf
#define sc scanf
#define nline cout << '\n'
#define dbg(x) \
    cout << "debug " << #x << ": " << x << '\n';
#define inp(t) cin >> (t)
#define out(t) cout << (t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define wh(n) while(n--)
using namespace std;

void OJ(){
    // file I/O
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

// compares ex: x = 10 and y = 1
// if x+y = 101 > y+x = 110
bool comp(string x, string y){
    if(x+y > y+x) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    int n;
    while(inp(n)){
        if(!n) break;
        string nums[n+1];
        FOR(0,n)
            inp(nums[i]);
        
        // sort function takes third argument is a function
        sort(nums,nums+n, comp);

        for(auto it: nums)
            out(it);
        nline;
    }
}
