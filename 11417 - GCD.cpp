#include <bits/stdc++.h>
using namespace std;

int GCD(int N){
  int G=0;
  for(int i=1;i<N;i++)
  for(int j=i+1;j<=N;j++){
    G+=__gcd(i,j);
  }
  return G;
}

int main() {
  int n;
  while(1){
    cin >> n;
    if(!n) break;
    cout << GCD(n) << endl;
  }
}
