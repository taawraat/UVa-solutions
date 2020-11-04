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
    string num;
  int base,convert;

  while(inp(num)){
    if(num[0] == '-') break;
    // check the base of the number 
    if(num[1] == 'x'){
      base = 16;
      convert = 10;
    }
    else{
      base = 10;
      convert = 16;
      out("0x");
    }
    string other;
    ll total = 0;
    if(base==16)
      reverse(num.begin()+2, num.end());
    else
      reverse(num.begin(), num.end());
    
    // converting base to decimal
    int i;
    base == 16 ? i = 2 : i = 0;
    for(int j = 0; num[i] != '\0'; i++,j++){
      if(num[i] >= 'A')
        total += (num[i]-55) * (pow(base,j));
      else
        total += (num[i]-48) * (pow(base,j));
    }
    bool flag = true;
    // if required conversion is 10 then no need to do further action
    if(convert == 10) out(total);

    // if 0 then output is 0
    else if(!total) out(0);


    else{
      int i = 0, temp;
      // converting deciaml to required base
      while(total){
        temp = (total % convert);
        if(temp > 9)
          temp += 55;
        else 
          temp += 48;
        other.push_back(temp);
        i++;
        total /= convert;
      }
      other[i] = '\0';

      // reverse and display
      reverse(other.begin(), other.end());
      out(other);
    }
    nline;
  }
}
