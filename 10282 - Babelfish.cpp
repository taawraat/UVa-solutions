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
    map<string,string> dict;
    string words,converted;
    
    // mapping word1 to word2
    while(getline(cin, words)){
        if(words == "") break;
        string word1 = "", word2 = "";
        stringstream ss(words);
        
        while(ss >> converted)
            if(word1 == "")
                word1 = converted;
            else
                word2 = converted;
        
        dict.insert({word2,word1});
    }
    string word;

    while(inp(word))
        if(dict.count(word) == 0)
            out("eh\n");
        else
            out(dict[word]) << '\n';
}
