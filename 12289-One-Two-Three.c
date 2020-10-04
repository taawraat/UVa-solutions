#include <stdio.h>
#include <string.h>
int main() 
{
  char num[10];
  int n,total=0;

  scanf("%d",&n);

  while(n--){
    scanf(" %[^\n]",num);

    if(strlen(num)==5)
      printf("3\n");
    else if((num[0] == 't' && num[1] == 'w') ||(num[0]=='t' && num[2]=='o') || (num[1] == 'w' && num[2] == 'o'))
      printf("2\n");
    else
       printf("1\n");
  }
}