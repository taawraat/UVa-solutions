#include   <bits/stdc++.h>
#define    pf printf
#define    sc scanf
#define    nline cout << '\n'
#define    dbg(x) \
           cout << "debug " << #x << ": " << x << '\n';
#define    inp(t) cin >> (t)
#define    out(t) cout << (t)
#define    lastof(s) s.size()-1
#define    all(x) x.begin(),x.end()
#define    pb push_back
#define    FOR(n,x) for(int i = n; i < x; i++)
#define    FOR2(N,X) for(int j = N; j < X; j++)
#define    wh(n) while(n--)
#define    EPS 1e10

using      ull = unsigned long long;
using      ll = long long;
using      namespace std;

// global
set<char> s = {'I', 'E', 'H', 'O', 'V', 'A', '#'};
bool visited[10][10];
char cobbles[10][10];
int x,y;

// FILE INPUT OUTPUT
void OJ(){
    // file I/O
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

bool isSafe(char ch){
    if(s.count(ch) != 0) return true;
    else return false;
}

// solution using DFS
void startVisiting(int r, int c){
    visited[r][c] = true;

    if((r >= 0 && c >= 0) && (r < x && c < y)){
        
        if(c-1 >= 0 && isSafe(cobbles[r][c-1]) && !visited[r][c-1]){
            if(cobbles[r][c-1] == '#'){
                out("left");
                return;
            }
            out("left ");
            startVisiting(r, c-1);
        }

        else if(c+1 <= y && isSafe(cobbles[r][c+1]) && !visited[r][c+1]){
            if(cobbles[r][c+1] == '#'){
                out("right");
                return;
            }
            out("right ");
            startVisiting(r, c+1);
        }

        else if(r-1 >= 0 && isSafe(cobbles[r-1][c]) && !visited[r-1][c]){
            if(cobbles[r-1][c] == '#'){
                out("forth");
                return;
            }
            out("forth ");
            startVisiting(r-1, c);
        }
    }
}

void solve(){
    inp(x) >> y;

    FOR(0,x){
        FOR2(0,y){
            inp(cobbles[i][j]);
            visited[i][j] = false;
        }
    }

    FOR(0,x){
        FOR2(0,y){
            if(cobbles[i][j] == '@') startVisiting(i,j);
        }
    }

    nline;
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    int n; inp(n);

    wh(n){
        solve();
    }
}
