#include <iostream>
#include <stdio.h>
#include <string.h>
#include <bits/stdc++.h> 
using namespace std;
int checkVowel(char);

int main() 
{
  string inp;
  while(getline(cin,inp))
  {
    char word[1000], ch;
    int isVowel = 0, stored = 0, first = 1;

    for(int i = 0, j = 0; i <= inp.size(); i++)
    {
      if(inp[i] == ' ' && inp[i+1] != ' ')
      {
        if(isVowel)
          cout << "ay ";
        else
          cout << ch << "ay ";
        
        isVowel = 0;
        stored = 0;
        first = 1;
      }
      
      else if((inp[i] >= 'A' && inp[i] <= 'Z') || (inp[i] >= 'a' && inp[i] <= 'z'))
      {
        if(!isVowel && checkVowel(inp[i]) && first)
        {
          first = 0;
          isVowel = 1;
        }

        if(isVowel)  
          cout << inp[i];
        
        else
        {
          first = 0;
          if(!stored)
          {
            ch = inp[i];
            stored = 1;
          }
          if(inp[i+1] != ' ')
           cout << inp[i+1];
        }
      }

      else
      {
        if((inp[i-1] >= 'A' && inp[i-1] <= 'Z') || (inp[i-1] >= 'a' && inp[i-1] <= 'z'))
          cout << "ay" << inp[i];
        else
          cout << inp[i];
      }
    }
    cout << endl;
  }
}

int checkVowel(char ch)
{
  if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    return 1;

  else if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
    return 1;

  else
    return 0;  
}