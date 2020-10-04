// UVa 444
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void swap_n_print(int);

int main(void) 
{
  char msg[1000];

  while(fgets(msg,1000,stdin) != NULL)
  {
    int pos = strlen(msg)-1;
    
    if(!(msg[0] >= '0' && msg[0] <= '9'))
    {
      while(pos--)
      {
        int ascii = msg[pos];
        
        swap_n_print(ascii);
      }
    }
    else
    {
      for(int i = pos-1; i >= 0; )
      {
        int ascii;
        if(msg[i] != '1')
        {
          ascii = (msg[i] - '0') * 10;
          i--;
          ascii += msg[i] - '0';
          i--;
        }
        else
        {
          ascii = (msg[i] - '0') * 100;
          i--;
          ascii += (msg[i] - '0') * 10;
          i--;
          ascii += (msg[i] - '0');
          i--;
        }
        printf("%c", ascii);
      }
    }
    printf("\n");
  }
}

void swap_n_print(int num)
{
  int swapped[5];
  if(num < 100)
  {
    swapped[0] = num % 10;
    num /= 10;
    swapped[1] = num % 10;
    printf("%d%d",swapped[0],swapped[1]);
  }
  else
  {
    swapped[0] = num % 10;
    num /= 10;
    swapped[1] = num % 10;
    num /= 10;
    swapped[2] = num % 10;
    printf("%d%d%d", swapped[0],swapped[1],swapped[2]); 
  }
}