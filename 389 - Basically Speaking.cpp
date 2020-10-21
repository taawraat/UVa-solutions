#include <bits/stdc++.h>
#include <string.h>
#include <stdio.h>
#include <cmath>
#define sc scanf
#define inp(t) scanf("%d", &t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
using namespace std;

int main(){
  string num;
  int base,convert;

  while(cin >> num >> base >> convert){
    char other[20];
    int total = 0, digits = 0;
    reverse(num.begin(), num.end());
    
    // converting base to decimal
    for(int i = 0; num[i] != '\0'; i++){
      if(num[i] >= 'A')
        total += (num[i]-55) * (pow(base,i));
      else  
        total += (num[i]-48) * (pow(base,i));
    }
    bool flag = true;

    // if required conversion is 10 then no need to do further action
    if(convert == 10 && total <= 9999999) pf("%7d\n", total);

    // if 0 then output is 0
    else if(!total) pf("%7d\n", 0);


    else{
      int i = 0, temp;

      // converting deciaml to required base
      while(total){
        digits++;
        temp = (total % convert);
        if(temp > 9)
          temp += 55;
        else 
          temp += 48;
        other[i] = (char)temp;
        i++;
        total /= convert;

        if(digits > 7){ flag = false; break; }
      }
      other[i] = '\0';

      // reverse and display
      reverse(other, other+i);
      if(!flag) cout << "  ERROR";
      else
        pf("%7s", other);
      cout << endl;
    }
  }
}
