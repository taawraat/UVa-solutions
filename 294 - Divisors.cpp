#include <stdio.h>
#include <iostream>
typedef long long ll;
typedef unsigned int ui;
#define pf printf
#define sc scanf
// #define MAX 1000000000
using namespace std;

// divisors of num function O(sqrt(N))
int divisors(ll num)
{
    int count = 0;
    int result = 1;
    if(num == 1)
        return 1;
    else{
        while(!(num & 1)){
            count += 1;
            num /= 2;
        }
        result *= (count+1);
        for(ui i = 3; i*i <= num; i += 2){
            count = 0;
            while (!(num % i)){
                count += 1;
                num /= i;
            }
            result *= (count+1);
        }
        if(num > 2)
            result *= 2;
    }
    return result;
}

int main(){
    int T; sc("%d", &T);
    ll L,U;

    while(T--){
        int max = -1, N = -1;
        sc("%lld%lld", &L, &U);
        
        pf("Between %lld and %lld, ", L,U);
        for(ll i = L; i <= U; i++){
            int totalDivisors = divisors(i);

            if(totalDivisors > max){
                max = totalDivisors;
                N = i;
            }
        }
        pf("%d has a maximum of %d divisors.", N, max);
        pf("\n");
    }
}
