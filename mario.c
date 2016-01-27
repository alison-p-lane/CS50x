#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int height, row, spaces, hash;
    
    do 
    {
        printf("Enter a positive integer less than 24: ");
        height = GetInt();
    }
    while (height < 0 || height >= 24); 
    
    
    for (row = 0; row < height; row++)
        {
        //print spaces
        for (spaces = 0; spaces <= height - (row + 2); spaces++)
            {
            printf(" ");
            }
        
        //print hashtags
        for (hash = 0; hash < row + 2; hash++)
            {
            printf("#");
            }
            
        //print newline
            printf("\n");
        }

}
