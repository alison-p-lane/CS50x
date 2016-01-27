#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

//void b/c i'm not supposed to use command line args yet!
int main(void)
{
    //get user input of name(s)
    string name = GetString();

    //in case of null sentinel
    if (name != NULL)
    {

        //for first character (c = 0)
        printf("%c", toupper(name[0]));
    
        //for loop to go thru rest of input and check for first letters, then capitalize and print
        for (int i = 0, n = strlen(name); i < n; i++)//should i start i at one b/c of above?
        {
            if(name[i] == ' ' && name[i++] != '\0')
            {
                printf("%c", toupper(name[i++]));
            }
    }
    
    //newline at the end
    printf("\n");
    
    }
}

/*
pseudo:
printchar function
check if char is lowercase
    make uppercase
    print char
else print char

(void)printchar(string name/char c?) -- or name[c]? or just char c?
{
    if(int islower(int c) != 0)
    {
        int toupper(int c);
        printf("%c", c????);
    }
    else printf("%c", c);
    
}

^^didn't really end up needing that

*/





