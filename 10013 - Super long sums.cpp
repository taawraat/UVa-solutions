#include <bits/stdc++.h>
using ull = unsigned long long;
using ll = long long;
#define pf printf
#define sc scanf
#define nline cout << '\n';
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

// adding two large digit numbers
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
    reverse(ans.begin(), ans.end());
    return ans;
}


int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    // OJ();

    // Start
    int t; sc("%d\n\n", &t);
    string num1,num2;
    char n2;
    wh(t){
        int n, a, b;
        sc("%d", &n);

        // taking n digits of two numbers
        wh(n){
            // taking first and second digit
            sc("%d%d", &a,&b);

            // add the digit a in num1 string and digit b in num2 string
            num1.push_back(a+48);
            num2.push_back(b+48);
        }

        // n2 for taking an extra new line as input
        sc("%c", &n2);

        // ans = summaiton of num1 and num2
        out(sum(num1,num2));
        cout << '\n';

        // every output has an extra newline to print
        // last extra newline should not be printed
        if(t)
            cout << '\n';
        
        // clear after summation is done
        num1.clear();
        num2.clear();
    }
}
