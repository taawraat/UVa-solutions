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

  while(inp(base) && inp(convert) && inp(num)){
    cout << num;
    string other;
    ll total = 0;
    bool illegal = false;
    reverse(num.begin(), num.end());
    
    // converting base to decimal
    for(int i = 0; num[i] != '\0'; i++){
      if(num[i] >= 'A'){
        if((num[i]-55) >= base){
          illegal = true;
          cout << " is an illegal base " << base << " number\n";
          break;
        }
        else
          total += (num[i]-55) * (pow(base,i));
      }
      else{
        if((num[i]-48) >= base){
          illegal = true;
          cout << " is an illegal base " << base << " number\n";
          break;
        }
        else
          total += (num[i]-48) * (pow(base,i));
      }
    }
    if(illegal) continue;
    bool flag = true;

    cout << " base " << base <<  " = ";
    
    // if required conversion is 10 then no need to do further action
    if(convert == 10 && total <= 9999999) out(total);

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

        // if(digits > 7){ flag = false; break; }
      }
      other[i] = '\0';

      // reverse and display
      reverse(other.begin(), other.end());
      out(other);
    }
    cout << " base " << convert << '\n'; 
  }
}
