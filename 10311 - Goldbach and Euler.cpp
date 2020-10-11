#include <stdio.h>
#define pf printf
#define sc scanf
#define MAX 100000000
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
  prime[1] = 1;
  for(int i = 3; i*i <= MAX ; i += 2)
    if(isPrime(i))
      for(int j = i+i; j <= MAX; j += i)
        prime[j] = 1;
}

int main(){
  primeGen();

  long long int N;
  
  while(sc("%lld", &N) == 1){
    bool flag = false;
    pf("%lld is ", N);

    if(N & 1){
      if(isPrime(N-2) && N != 1)
        pf("the sum of 2 and %lld.", N-2);
      else
        pf("not the sum of two primes!");
    }
    else{
      long long X = (N/2) -1;

      for(int i = X; i >= 3; i--){
        if(isPrime(i) && isPrime(N - i)){
          pf("the sum of %d and %lld.", i, N-i);
          flag = true;
          break;
        }
      }
      if(!flag) pf("not the sum of two primes!");
    }
    pf("\n");
  }
}
