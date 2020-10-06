#include <bits/stdc++.h>
#define ll long long
using namespace std;

// bigMod function
ll bigMod(ll a, ll b, ll m)
{
  ll ans = 1;
  a = a % m;
  
  while(b){
    // checking if bit is 1
    if(b & 1)
      ans = (ans * a) % m;
      
    a = (a*a) % m;
    b /= 2;
  }
  return ans;
}

int main() 
{
  ll a, b, m;
  while(cin >> a >> b >> m){
    cout << bigMod(a,b,m) << endl;
  }
}
