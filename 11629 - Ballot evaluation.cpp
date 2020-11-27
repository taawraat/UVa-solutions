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
    // ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    map<string,double> m;
    int x,y; inp(x); inp(y);
    char ch;
    wh(x){
        string name;
        double value;
        inp(name); inp(value);
        // mapping name to value
        m.insert({name,value});
    }

    // for last '\n' character
    sc("%c\n", &ch);

    FOR(1,y+1){
        pf("Guess #%d ", i);
        bool comp = false;
        double total = 0;
        double value;
        string single,comparison;
        string guess; getline(cin,guess);
        stringstream ss(guess);
        
        while(ss >> single){
            if(single == "=" || single == ">" || single == "<" || single == ">=" || single == "<="){
                comp = true;
                comparison = single;
            }

            // check if last value
            else if(comp)
                value = stoi(single);
            else if(single != "+")
                total = total + m[single];
        }

        // check the guess
        if(comparison == ">" && total > (value+1e-2) \
        || comparison == "<" && (total+1e-2) < value \
        || comparison == "<=" && ((total+1e-2) < value || abs(total-value) < 1e-2) \
        || comparison == ">=" && (total > (value+1e-2) || abs(total-value) < 1e-2) \
        || comparison == "=" && abs(total-value) < 1e-2)
            pf("was correct.\n");
        else
            pf("was incorrect.\n");
    }
}
