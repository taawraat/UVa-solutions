#include <bits/stdc++.h>
#define ll long long
#define ushort unsigned short int
#define ui unsigned int
#define max 10000000
bool primes[max] = {};
using namespace std;

// Prime function sieve
void primeGen()
{
  primes[1] = 1;
  for(ll i = 2; i*i <= max; i++)
    if(!primes[i])
      for(ll j = i; i * j <= max; j++)
        primes[i*j] = 1;
}


// Driver function
int main()
{
    primeGen();

    ui num;
    while(cin >> num){
        ui reversed = 0, num2 = num;
        
        // reverse of num
        while(num2 > 0){
            int temp = num2 % 10;

            reversed *= 10;
            reversed += temp;

            num2 /= 10;
        }
        cout << num;
        if(!primes[num] && !primes[reversed] && num != reversed)
            cout << " is emirp.";
        else if(!primes[num])
            cout << " is prime.";
        else
            cout << " is not prime.";

        cout << endl;
    }
}
