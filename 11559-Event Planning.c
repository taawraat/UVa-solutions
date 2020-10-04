#include <stdio.h>

int main() 
{
  long long int participants,budget,hotel,weekends;
  while(scanf("%lld%lld%lld%lld",&participants,&budget,&hotel,&weekends) == 4){
    
    long long int hotelPrice, rooms, inBudget = 0, minimumCost = budget + 1;
    
    while(hotel--){
      scanf("%lld",&hotelPrice);
      
      for(int i = 0; i < weekends; i++){
        scanf("%lld",&rooms);
        
        if(rooms>=participants)
        {
          if(participants*hotelPrice < minimumCost)
          {
            minimumCost = participants * hotelPrice;
            inBudget = 1;
          }
        }
      }
    }
    if(inBudget) 
        printf("%lld\n",minimumCost);
      else
        printf("stay home\n");
  }
}