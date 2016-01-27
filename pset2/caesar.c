#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

//include funtion prototypes if they exist
//int GetPositiveInt(void); //<---This works -- didn't end up needing it, though

//main

int main(int argc, string argv[])
{

    if (argc == 2 && atoi(argv[1]) >= 0)
    {
        //get user's plaintext string
        //printf("Enter your text: ");
        string plntxt = GetString();
        //change string value to int k
        int k = atoi(argv[1]);
            //if k won't actually encrypt
            if(k == 26 || k == 0)
            {
                printf("%s\n", plntxt);
                return 0;
            }
            else    
            {    //use k to calculate key, between 1 and 25
                int key = k % 26;
                //move over approp number of characters
                for(int i = 0, j = strlen(plntxt); i < j; i++)
                {
                    //to change lowercase letters
                    if (islower(plntxt[i]) && isalpha(plntxt[i]))
                    {
                        plntxt[i] = (plntxt[i] - 'a' + key) % 26 + 97;
                    }
                    //to change uppercase letters
                    else if (isupper(plntxt[i]) && isalpha(plntxt[i]))
                    {
                        plntxt[i] = (plntxt[i] - 'A' + key) % 26 + 65;
                    }
                    //print encrypted string and newline
                    printf("%c", plntxt[i]);
                }
                    printf("\n");
                    return 0;
            }
    }
    else
    {
        
        printf("1\n");
        return 1;
    }
   
}


/*

THIS WORKS

int GetPositiveInt(void)
{
   int k;
   do
   {
       printf("Please enter a positive integer: ");
       k = GetInt();
   }
   while(k < 1);
   return k; 
}

*/
