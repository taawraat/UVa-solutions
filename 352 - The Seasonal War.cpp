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

void OJ(){
    // file I/O
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

ll LCM(ll x, ll y){ return x * (y/__gcd(x,y)); }

// DFS solution
int n;
int parts[25][25];
bool visited[25][25];

// check 8 co-ordinates of a node
int fx[]= {-1, -1, 0, 1, 1, 1, 0, -1};
int fy[]= {0, 1, 1, 1, 0, -1, -1, -1};

void startVisiting(int i, int j){
    if(visited[i][j]) return;

    visited[i][j] = true;

    for(int d = 0; d < 8; ++d){
        
        // check the boundary
        if(fx[d]+i < n && fy[d]+j < n && fx[d]+i >= 0 && fy[d]+j >= 0){
            int tempI = i+fx[d];
            int tempJ = j+fy[d];

            if(!visited[tempI][tempJ] && parts[tempI][tempJ])
                // if a non visited node found then stop visiting previous and visit new one
                startVisiting(tempI, tempJ);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    string s;
    int Case = 0;
    while(inp(n)){
        int count = 0;
        FOR(0,n){
            inp(s);

            FOR2(0,n){
                parts[i][j] = s[j] - 48;
                visited[i][j] = false;
            }
        }

        FOR(0,n)
            FOR2(0,n){
                if(!visited[i][j] && parts[i][j]){
                    count++;

                    // start visiting if a node is found
                    startVisiting(i,j);
                }
            }
        
        out("Image number ") << ++Case << " contains " << count <<" war eagles.\n";
    }
    
}
