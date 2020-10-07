// UVa 583
#include <bits/stdc++.h>
#define ll long long
#define ushort unsigned short int
#define ui unsigned int
using namespace std;

// factorization function O(sqrt(N))
void primeFactors(ll num)
{
    if(num == 1)
        printf("1");
    else{
        while(!(num & 1)){
            printf("2");
            num /= 2;
            if(num != 1)
                printf(" x ");
        }
        for(ui i = 3; i*i <= num; i += 2){
            while (!(num % i)){
                printf("%d", i);
                num /= i;
                if(num != 1)
                    printf(" x ");
            }
        }
        if(num > 2)
            cout << num;
    }
    cout << endl;
}

// Driver function
int main()
{
    ll num;

    while(cin >> num){
        if(!num) break;

        printf("%d = ", num);
        if(num < 0){
            printf("-1 x ");
            num = num * -1;
        }
        primeFactors(num);
    }
}
