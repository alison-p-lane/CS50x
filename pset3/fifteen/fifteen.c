/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    //leave one and two in order for odd number board size
    if(d % 2 != 0)
    {
        int r = 0;
        int col = 0;
        //iterate thru array, assigning numbers in order
        for(int i = 1, t = d * d; i < t; i++)
        {
            board[r][col] =  t - i;
            col = col + 1;
            //when you reach end of column, move to next row, column 0
            if(col == d)
            {
                col = 0;
                r = r + 1;
            }
        }
        //last int in array is 0
        board[d - 1][d - 1] = 0;
    }
    
    //swap one and two for even number board sizes
    else
    {
        int r = 0;
        int col = 0;
        //iterate thru array, assigning numbers in order
        for(int i = 1, t = d * d; i < t; i++)
        {
            board[r][col] =  t - i;
            col = col + 1;
            //when you reach the end of the col, move to next row, col 0
            if(col == d)
            {
                col = 0;
                r = r + 1;
            }
        }
        //assign last three ints -- 1, 2, 0 -- order changes on even board sizes
        board[d - 1][d - 3] = 1;
        board[d - 1][d - 2] = 2;
        board[d - 1][d - 1] = 0;
    }
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{
        //initialize rows and columns to 0 for [0][0] start point
        int r = 0;
        int c = 0;
        //iterate thru entire array
        for(int i = 0, t = d * d; i < t; i++)
        {
            //if 0, print blank space
            if(board[r][c] == 0)
            {
                printf(" _  ");
                //with extra padding space
                //move to next column
                c = c + 1;
            }
            
            //if !=0, print number
            else if(board[r][c] != 0)
            {
                printf(" %i ", board[r][c]);
                //extra padding space, when appropriate
                if(board[r][c] < 10)
                {
                    printf(" ");
                }
                //move to next column
                c = c + 1;
            }
            
            //if, after that, you've reached the end of the columns
            //print two new lines and start next row
            if(c == d)
            {
                printf("\n\n");
                r = r + 1;
                c = 0;
            }
        }
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
 
//int tile is the input number
bool move(int tile)
{
    //iterate thru rows
    for(int i = 0; i < d; i++)
    {
        //iterate thru columns
        for(int j = 0; j < d; j++)
        {
            //if program finds the tile number on the board
            if(board[i][j] == tile)
            {
                //and if there's an adjacent zero on the board
                //swap the tiles and return true
                if((i + 1) < d && board[i + 1][j] == 0)
                {   
                    board[i + 1][j] = tile;
                    board[i][j] = 0;

                    return true;
                }
                else if((i - 1) >= 0 && board[i - 1][j] == 0)
                {
                    board[i - 1][j] = tile;
                    board[i][j] = 0;

                    return true; 
                }
                else if((j + 1) < d && board[i][j + 1] == 0)
                {
                    board[i][j + 1] = tile;
                    board[i][j] = 0;

                    return true;   
                }
                else if((j - 1) >= 0 && board[i][j - 1] == 0)
                {
                    board[i][j - 1] = tile;
                    board[i][j] = 0;

                    return true;
                }
                //else there's no adjacent zero
                else
                {
                    return false;
                }
            } 
           
        }
        
    }
    //else that tile doesn't exist on the board
    return false;
}

/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    //initialize a counter and do some math
    int counter = 1;
    int dsq = d * d;
    //int highest = dsq - 1;

    //iterate thru rows
    for(int i = 0; i < d; i++)
    {
        //iterate thru columns
        for(int j = 0; j < d; j++)
        {
            //if each tile is equal to the number it's supposed to be equal to, in order...
            if(board[i][j] == counter)
            {
                //add to the counter
                counter = counter + 1;
                //if all on board are correct, counter == dsq and last square == 0 and you won!
                if(counter == dsq && board[d - 1][d - 1] == 0)
                {
                    return true;
                }
            }
            //if something is out of order, you do not win...yet!
            else
            {
                return false;
            }
        }
    }
    return false;
}




