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

class myStack{
public:
    int size;
    int top = -1;

    myStack(int s){
        size = s;
    }

    bool isEmpty(){
        if(top == -1)
            return true;
        return false;
    }

    bool isFull(){
        if(top == size-1)
            return true;
        return false;
    }
    int isTop(){
        return top;
    }

    void push(vector<char> &v, char p){
        if(!isFull()){
            top++;
            v[top] = p;
        }
    }
    void pop(){
        top--;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    OJ();

    // Start
    char ch;
    int n; inp(n) >> ch;
    int opening[300], closing[300];
    
    opening['('] = 1;
    opening['{'] = 2;
    opening['['] = 3;
    closing[')'] = 1;
    closing['}'] = 2;
    closing[']'] = 3;

    wh(n){
        string s; getline(cin,s);
        bool flag = true;
        if(s.length() & 1)
            flag = false;
        
        else{
            myStack stack(s.length()/2);
            vector<char> v(s.length()/2);
            
            FOR(0, s.length()){
                if(s[i] == '[' || s[i] == '(' || s[i] == '{')
                    stack.push(v, s[i]);
                
                else if(stack.isEmpty() && closing[s[i]]){
                    flag = false;
                    break;
                }

                else if(opening[v[stack.isTop()]] != closing[s[i]]){
                    flag = false;
                    break;
                }
                else if(opening[v[stack.isTop()]] == closing[s[i]])
                    stack.pop();
            }
            if(!stack.isEmpty() && flag)
                flag = false;
        }

        flag ? out("Yes") : out("No");
        nline;
    }
}
