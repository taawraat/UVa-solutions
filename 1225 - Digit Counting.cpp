#include <bits/stdc++.h>
#define sc scanf
#define inp(t) scanf("%d", &t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
using namespace std;

// returns lcm of x,y
ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

int main(){
  int n;
  inp(n);

  wh(n){
    int digits[11] = {};
    int range; inp(range);


    FOR(1,range+1){
      int num = i;

      // counting frequency of digits
      while(num){
        int temp = num % 10;
        digits[temp]++;
        num = num / 10;
      }
    }

    // printing frequency of 1 - 8
    FOR(0,9)
      pf("%d ", digits[i]);
    
    // printing frequency of 9
    cout << digits[9] << endl;
  }
}
