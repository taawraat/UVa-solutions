#include <bits/stdc++.h>
#define sc scanf
#define t1(t) scanf("%d", &t)
#define FOR(x) for(int i = 0; i < x; i++)
#define pf printf
#define wh(n) while(n--)
#define ll long long
using namespace std;

int main()
{
    int t,x,y;;
    t1(t);
    wh(t){
      sc("%d%d", &x,&y);

      !(y%x) ? pf("%d %d", x,y) : pf("-1");
      pf("\n");
    }
}
