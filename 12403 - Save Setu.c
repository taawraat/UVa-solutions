#include<stdio.h>
#include<string.h>
int main()
{
    char input[10];
    int T;
    long long int donation,total_donation = 0;
    scanf("%d", &T);

    while(T--)
    {
        scanf("%s", input);
        if(strcmp("donate",input) == 0)
        {
            scanf("%lld", &donation);
            total_donation += donation;
        }
        else
            printf("%lld\n",total_donation);
    }
}