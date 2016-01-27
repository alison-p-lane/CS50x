#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //if there aren't two args, exit
    if(argc != 2) 
    {
      printf("1\n");
      return 1;  
    }
    //declare variables
    char *k = argv[1];
    int j = strlen(k);
    //and if argv[1] has nonalpha chars, exit
    for (int i = 0; i < j; i++)
    {
        //loop thru string to check
        if(isalpha(argv[1][i]) == 0)
        {
            //abort program if any nonalpha chars
            printf("1\n");
            return 1;
        }
    }

    //request plaintext string
    string p = GetString();
    int pL = strlen(p);

    //figure out how to repeat string for alpha chars
    //concatenate strings so that this will work...
    //new string?
    string kk = strcat(k,k);
    string kk2 = strcat(kk, kk);

    int ki = 0;
    
    for(int i = 0; i < pL; i++)
    {    
        if(isalpha(p[i]))
        {
            //case issues? this is for lowercase
            if(islower(p[i]))
            {
                if(islower(kk2[ki]))
                {
                    int key = kk2[ki] - 'a'; //key needs to repeat
                    p[i] = ((p[i] + key - 97) % 26) + 97;
                    printf("%c", p[i]);
                    ki = ki + 1;
                }
                else
                {
                    int key = tolower(kk2[ki]) - 'a'; //key needs to repeat
                    p[i] = ((p[i] + key - 97) % 26) + 97;
                    printf("%c", p[i]);
                    ki = ki + 1;
                }
            }
            //this is for uppercase
            else
            {
                if(islower(kk2[ki]))
                {    
                    int key = toupper(kk2[ki]) - 'A';
                    p[i] = ((p[i] + key - 65) % 26) + 65;
                    printf("%c", p[i]);
                    ki = ki + 1;
                }
                else
                {
                    int key = (kk2[ki]) - 'A';
                    p[i] = ((p[i] + key - 65) % 26) + 65;
                    printf("%c", p[i]);
                    ki = ki + 1;
                }
                
            }
        }
            //all other chars just print as is
        else
        {
            printf("%c", p[i]);
        }
       

    }
    //print newline and exit
    printf("\n");
    return 0;
    
}
