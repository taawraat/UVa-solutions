#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
  string sentence;
  while(getline(cin, sentence))
  {
    int count = 0;
    for(int i = 0; sentence[i] != '\0'; i++)
    {
      if(((sentence[i] >= 'A' && sentence[i] <= 'Z') || (sentence[i] >= 'a' && sentence[i] <= 'z')) && !((sentence[i+1] >= 'A' && sentence[i+1] <= 'Z') || (sentence[i+1] >= 'a' && sentence[i+1] <= 'z')))
        count++;
    }
    cout << count << endl;
  }
}