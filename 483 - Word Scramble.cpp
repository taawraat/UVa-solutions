#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h> 
using namespace std;
int main() 
{
  string inp;
  while(getline(cin,inp))
  {
    char word[1000];
    for(int i = 0, j = 0; i <= inp.size(); i++)
    {
      if(inp[i] == ' ' || inp[i] == '\0')
      {
        word[j] = '\0';
        reverse(word, word+j);
        printf("%s", word);
        
        if(inp[i] != '\0')
          cout << " ";
    
        j = 0;
      }
      else
      {
        word[j] = inp[i];
        j++;
      }
    }
    cout << endl;
  }
}