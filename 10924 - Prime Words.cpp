#include <bits/stdc++.h>
#define ll long long
#define ushort unsigned short int
#define ui unsigned int
#define max 100000
bool primes[max] = {};
using namespace std;

// Prime function sieve
void primeGen()
{
  primes[1] = 0;
  for(ll i = 2; i*i <= max; i++)
    if(!primes[i])
      for(ll j = i; i * j <= max; j++)
        primes[i*j] = 1;
}


// Driver function
int main()
{
    primeGen();

    string word;
    while(cin >> word){
        ushort sum = 0;
        for(ushort i = 0; word[i] != '\0'; i++){
            if(word[i] >= 'A' && word[i] <= 'Z')
                sum += (int)(word[i]) - 38;
            else
                sum += (int)(word[i]) - 96;
        }

        if(!primes[sum])
            cout << "It is a prime word.";
        else
            cout << "It is not a prime word.";
        cout << endl;
    }
}
