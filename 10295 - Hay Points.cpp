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

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    map<string,int> m;
    string word;
    int x,y; inp(x); inp(y);

    wh(x){
        inp(word);
        int value; inp(value);
        m.insert({word,value});
    }
    wh(y){
        ll total = 0;        
        while(inp(word)){
            if(word == ".") break;
            total += m[word];
        }
        out(total);
        nline;
    }
}
