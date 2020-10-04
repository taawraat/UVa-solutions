#include <stdio.h>
int main() 
{
  int S,created[12],required[12],Case=1;
  while(Case){
    scanf("%d",&S);
    if(S<0)
      break;
    for(int i = 0; i < 12; i++){
      scanf("%d",&created[i]);
    }
    for(int i = 0; i < 12; i++){
      scanf("%d",&required[i]);
    }
    printf("Case %d:\n",Case);
    for(int i = 0; i < 12; i++){
      if(S < required[i])
        printf("No problem. :(\n");
      else{
        printf("No problem! :D\n");
        S -= required[i];
      }
      S += created[i];
    }
    Case++;
  }
}