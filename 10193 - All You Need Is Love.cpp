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
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
}

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    OJ();

    // Start
    int Case = 0,t; inp(t);
    string bin1,bin2;
    ll num1 = 0,num2 = 0;
    
    wh(t){
      inp(bin1); inp(bin2);
      
      // converting 1st binary string to decimal
      int i = bin1.length()-1;
      for(int j = 0; i >= 0; i--,j++)
        num1 += (bin1[i]-48) * (pow(2,j));
      
      // converting 2nd binary string to decimal
      i = bin2.length()-1;
      for(int j = 0; i >= 0; i--,j++)
        num2 += (bin2[i]-48) * (pow(2,j));

      cout << "Pair #" << ++Case << ':';

      // if gcd of num1 and num2 is 1 that means we cannot form s1 and s2 with L
      // if gcd > 1 then we can have such L
      __gcd(num1,num2) == 1 ? out(" Love is not all you need!\n"): out(" All you need is love!\n");

      num1 = 0;
      num2 = 0;
    }
}
