#include <stdio.h>
#include <cs50.h>
#include <math.h>

/*Notes to self 1/14/16: it seems like I may have gone about this in the most complicated,
least concise way possible.  But I wanted to see what I could do on my own,
and what I could work through on my own, and I did. It was definitely satisfying to
work through and eliminate all the errors that came up during this process.  The only 
bug I can't seem to get rid of is the one Check50 finds -- that 4.2 outputs 22.  Why
is this??? No matter how many times I go through that bit of code, I can't seem to 
figure it out -- this is definitely one of those occasions when having another person,
with fresh eyes, would be very helpful. (OK, it continued to irk me, so I did some
googling and worked out the round function, so now it fully works!)

In the end, after having written this overcomplicated monster, seeing other people's
code was really interesting and helpful.  Obviously, though, in the future, it will
not be tenable to just stick to an overcomplicated attempt just for the sake of
seeing it through...which means I've got to get used to linear, computational logic --
because this is not ideal code.

Maybe try writing a more concise, whittled down version and re-submit in the future?*/

int main(void)
{
    
    float change;
    
    do
    {
        printf("How much change is owed? ");
        change = GetFloat();
    }
    while (change < 0);
    
    //only available coins are .25, .10, .05, .01...if, else if..?
    
    int chtotal = round(change * 100);
    int coins, quarters, dimes, nickels, pennies;
    
    //IF QUARTERS ARE POSSIBLE
    if (chtotal >= 25)
    {
        quarters = chtotal / 25;
            //then if dimes are possible
            if ((chtotal - quarters * 25) >= 10)
            {
                dimes = (chtotal - quarters * 25) / 10;
                    //then if nickels are possible
                    if ((chtotal - quarters * 25 - dimes * 10) >= 5)
                        {
                            nickels = (chtotal - quarters * 25 - dimes * 10) / 5;
                                //then if pennies are possible
                                if ((chtotal - quarters * 25 - dimes * 10 - nickels * 5) > 0)
                                {
                                    pennies = chtotal - quarters * 25 - dimes * 10 - nickels * 5;
                                }
                                //or if pennies aren't possible
                                else 
                                {
                                    pennies = 0;
                                }
                        }
                    //or if nickels aren't possible, but pennies are
                    else if ((chtotal - quarters * 25 - dimes * 10) >= 1)
                    {
                        pennies = chtotal - quarters * 25 - dimes * 10;
                        nickels = 0;
                    }
                    //or if neither nickels nor dimes are possible
                    else 
                    {
                        nickels = 0;
                        pennies = 0;
                    }
            }
            else if ((chtotal - quarters * 25) >= 5)
            {
                nickels = (chtotal - quarters *25) / 5;
                pennies = chtotal - quarters * 25 - nickels * 5;
                dimes = 0;
            }
            else if ((chtotal - quarters * 25) > 0)
            {
                pennies = chtotal - quarters * 25;
                dimes = 0;
                nickels = 0;
            }
            else 
            {
                dimes = 0;
                nickels = 0;
                pennies = 0;
            }
    }
    else if (chtotal >= 10)
    {
        dimes = chtotal / 10;
            if ((chtotal - dimes * 10) >= 5)
            {
                nickels = (chtotal - dimes * 10) / 5;
                if ((chtotal - dimes * 10 - nickels * 5) >= 1)
                {
                    pennies = chtotal - dimes * 10 - nickels * 5;
                    quarters = 0;
                }
                else
                {
                    pennies = 0;
                    quarters = 0;
                }
            }
            else if ((chtotal - dimes * 10) >= 1)
            {
                pennies = chtotal - dimes * 10;
                quarters = 0;
                nickels = 0;
            }
            else
            {
                quarters = 0;
                nickels = 0;
                pennies = 0;
            }
    }
    else if (chtotal >= 5)
    {
        nickels = chtotal / 5;
            if ((chtotal - nickels * 5) >= 1)
                {    
                    pennies = chtotal - nickels * 5;
                    quarters = 0;
                    dimes = 0;
                }
            else 
            {
                quarters = 0;
                dimes = 0;
                pennies = 0;
            }
    }
    else 
    {
        pennies = chtotal;
        quarters = 0;
        dimes = 0;
        nickels = 0;
    }    
        
    coins = quarters + dimes + nickels + pennies;

    
   printf("%i\n", coins);
    
}
