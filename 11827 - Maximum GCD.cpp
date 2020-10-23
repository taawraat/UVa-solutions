#include <bits/stdc++.h>
#define sc scanf
#define inp(t) scanf("%d\n", &t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
using namespace std;

int main(){
  int n; inp(n);
  wh(n){
    string nums;
    int max = -1, num1 = 0, num2 = 0,i;
    getline(cin, nums);

    // iterate from 0 to N-1
    for(int i = 0;nums[i+1] != '\0'; i++)
    {
      // check if next character is a number
      if(nums[i]== ' ' && nums[i+1] != ' ')
      {

        for(int j=i+1; ; j++)
        {
          // check if next character a number or null
          if((nums[j] == ' ' && nums[j+1] != ' ') || nums[j] == '\0')
          {
            // check if gcd of num1 and num2 is greater than max
            if(num1 && num2 && __gcd(num1,num2) > max)
              max = __gcd(num1,num2);

            num2 = 0;
            if(nums[j] == '\0'){ num1 = 0; break; }
          }

          // converting charater to integer
          else if(nums[j] != ' ')
            num2 = (num2 * 10) + (nums[j] - 48);
        }
      }

      // converting character to integer
      else if(nums[i] != ' ')
        num1 = (num1 * 10) + (nums[i] - 48);
    }
    cout << max << endl;
  }
}
