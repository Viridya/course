#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float answer = get_float("Change owed? ");
    int amount = round(answer * 100);

    while (amount < 0) 
    {
        answer = get_float("Change owed? ");
        amount = round(answer * 100);
    }

    for (int coin = 0; amount > 0; coin++) 
    {
        if (amount >= 25) 
        {
            amount = amount - 25;
        }
        else if (amount >= 10 && amount < 25) 
        {
            amount = amount - 10;
        }
        else if (amount >= 5 && amount < 10) 
        {
            amount = amount - 5;
        }
        else if (amount >= 1 && amount < 5) 
        {
            amount = amount - 1;
        }
        if (amount == 0)
        {
            printf("%i\n", coin + 1);
        }
    }
}

