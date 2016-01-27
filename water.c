#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //ask for user input
    printf("minutes: ");
    int min = GetInt();

    //calculations
    int bottles = min * 192 / 16;

    //print result
    printf("bottles: %i\n", bottles);
}
