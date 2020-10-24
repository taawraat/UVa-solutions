#include <bits/stdc++.h>

using ull = unsigned long long;
using ll = long long;

#define sc scanf
#define inp(t) scanf("%d\n", &t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define pf printf
#define wh(n) while(n--)
ull factOf[21];
using namespace std;

// returns lcm of x,y
ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

// returns factorial of n
ull fact(int n){
  if(n==1 || n==0)
    return 1;
  return n*fact(n-1);
}

// Generates factiral of 1 to 20
void factGen(){
  for(int i = 0; i <= 20; i++)
    factOf[i] = fact(i);
}

int main(){
  factGen();

  int n; inp(n);
  string word;

  FOR(1,n+1){
    cin >> word;
    int freq[28] = {};

    // initial ans = factorial of total length
    unsigned long long ans = factOf[word.length()];

    // counting frequency of each character
    for(int i = 0; word[i] != '\0'; i++)
      freq[word[i]-64]++;

    // ans = fact of length/(fact of (frequency of all characters))
    for(int i = 1; i <= 26; i++)
      ans = ans/factOf[freq[i]];

    pf("Data set %d: %llu\n", i,ans);
  }
}
