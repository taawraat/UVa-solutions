#include <iostream>
#include <stdio.h>
using namespace std;
int main() 
{
  int T; cin >> T;

  for(int i = 1; i <= T; i++)
  {
    char ch1,ch2; cin >> ch1 >> ch2;
    
    int canSymmetric = 1;
    int N; cin >> N;

    long long int matrix[N*N];

    for(int i = 1; i <= N*N; i++)
    {
      cin >> matrix[i];
      
      if(canSymmetric && matrix[i] < 0)
        canSymmetric = 0;
    }
    
    printf("Test #%d: ", i);

    if(!canSymmetric)
      cout << "Non-symmetric.\n";
    
    else
    {
      for(int i = 1; i <= (N*N)/2; i++)
      {
        int opposite = (N*N) - (i - 1);
        
        if(matrix[i] == matrix[opposite])
          continue;
        
        else
        {
          canSymmetric = 0;
          break;
        }
      }
      
      canSymmetric ? printf("Symmetric.\n") : printf("Non-symmetric.\n");
    }
  }
}
