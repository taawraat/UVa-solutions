#include <bits/stdc++.h>
#define max 1000000
int primes[max] = {};
using namespace std;

// Prime function
void primeNum()
{
  primes[1] = 1;
  for(long long int i = 2; i <= sqrt(max); i++)
    if(!primes[i])
      for(long long int j = 2; i * j <= max; j++)
        primes[i*j] = 1;
}


// Driver function
int main() 
{
  primeNum();
  int n;

  while(cin >> n)
  {
    if(!n) break;

    int count = 0;
    for(int i = 2; i <= n/2; i++)
    {
      if(!primes[i] && !primes[n-i])
        count++;
    }
    
    cout << count << endl;
  }
}
