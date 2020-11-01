#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
#define pf printf
#define sc scanf
#define dbg(x) \
    cout << "debug " << #x << ": " << x << endl;
#define inp(t) cin >> (t)
#define out(t) cout << (t)
#define FOR(n,x) for(int i = n; i < x; i++)
#define FOR2(N,X) for(int j = N; j < X; j++)
#define wh(n) while(n--)
using namespace std;

void OJ(){
    #ifndef ONLINE_JUDGE 
        freopen("input.txt", "r", stdin); 
        freopen("output.txt", "w", stdout);
    #endif
}

string sum(string num1,string num2){
    int len1 = num1.length();
    int len2 = num2.length();
    string ans;
    bool end1 = false, end2 = false;
    int i = 0, carry = 0;
    
    // will break if num1 and num2 ends
    for( ;!end1 || !end2; ){
        // iterating in reverse order
        if(len1) len1--;
        if(len2) len2--;

        // adding num1 and num2
        int temp = (num1[len1]-48) + (num2[len2] - 48);
        temp += carry;

        carry = temp / 10;
        ans.push_back((temp % 10)+48);
        i++;

        // initializing to 0 if num1 or num2 ends
        if(!len1){ end1 = true; num1[len1] = '0'; }
        if(!len2){ end2 = true; num2[len2] = '0'; }
    }

    if(carry) ans.push_back(carry+48);
    // reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    // OJ();

    // Start
    int t; sc("%d\n", &t);
    string num1,num2; 
    wh(t){
        cin >> num1 >> num2;

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        string ans = sum(num1,num2);
        bool leadingZero = true;
        
        for(int i = 0; ans[i] != '\0'; i++){
            // checking for leading zero
            if(ans[i] != '0' && leadingZero)
                leadingZero = false;
            if(!leadingZero)
                pf("%c", ans[i]);
        }
        out('\n');
    }
}
