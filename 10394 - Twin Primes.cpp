#include <stdio.h>
#define pf printf
#define MAX 20000001

int twinPrime[MAX];
char prime[MAX];

// check if n is prime
bool isPrime(int n){
  if(n == 2) return true;
  else if(!(n & 1)) return false;
  else if(!prime[n]) return true;
  else return false;
}


// prime function using sieve
void primeGen(){
  for(int i = 3; i*i <= MAX ; i += 2)
    if(isPrime(i))
      for(int j = i+i; j <= MAX; j += i)
        prime[j] = 1;
}

// mapping serial with value
void mkPair(){
  int serial = 1;
  for(int i = 3; i < MAX; i += 2){
    if(isPrime(i) && isPrime(i+2)){
      twinPrime[serial] = i;
      serial++;
    }
  }
}

int main(){
  primeGen();
  mkPair();
  int serial;

  while(scanf("%d", &serial) == 1)
    pf("(%d, %d)\n", twinPrime[serial], twinPrime[serial]+2);
}
