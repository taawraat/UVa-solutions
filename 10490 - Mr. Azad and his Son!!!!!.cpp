#include <stdio.h>
#define pf printf
#define sc scanf
#define MAX 2000
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

  int N;
  
  while(sc("%d", &N) == 1){
    if(!N) break;

    if(N == 2) pf("Perfect: 6!");
    else if(N == 3) pf("Perfect: 28!");
    else if(N == 5) pf("Perfect: 496!");
    else if(N == 7) pf("Perfect: 8128!");
    else if(N == 13) pf("Perfect: 33550336!");
    else if(N == 17) pf("Perfect: 8589869056!");
    else if(N == 19) pf("Perfect: 137438691328!");
    else if(N == 31) pf("Perfect: 2305843008139952128!");
    else if(isPrime(N))
      pf("Given number is prime. But, NO perfect number is available.");
    else
      pf("Given number is NOT prime! NO perfect number is available.");
    
    pf("\n");
  }
}
