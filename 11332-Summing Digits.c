#include <stdio.h>
int main() 
{
  long long int digit;
  while(1)
  {
    long long int digitSum = 0;
    scanf("%lld",&digit);
    if(digit == 0) break;

    while(digit != 0)
    {
      digitSum += digit % 10;
      digit = digit/10;
      
      if(digit == 0 && (digitSum >= 10)){
        digit = digitSum;
        digitSum = 0;
      }
    }
    printf("%lld\n",digitSum);
  }
}