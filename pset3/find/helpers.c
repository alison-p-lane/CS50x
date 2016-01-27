/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include <math.h>


#include "helpers.h"




/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n < 0)
    {
        return false;
    }
    
    int h = round(n / 2);
    int m = log(n) / log(2);
    //i is number of divisions, in this case
    for(int i = 1; i <= m + 1; i++)
    {
        //if the midpoint is the value, congrats!
        if(value == values[h])
        {
            return true;
            //should i break here?
        }
        //if the value is less than the midpoint value
        else if(value < values[h])
        {
            //establish a new, lower midpoint that carries over for next iteration
            h = round(h - ((n / pow(2,i)) / 2));
        }
        //the value must be greater than the midpoint value
        else
        {
            //establish a new, higher midpoint that carries over for next iteration
            h = round(h + ((n / pow(2,i)) / 2));
        }
    }
    return false;
}




/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    // bubble sort algorithm
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n - 1; i++)
        {
            if(values[i] > values[i + 1])
            {
                int temp = values[i];
                int temp2 = values[i + 1];
                values[i + 1] = temp;
                values[i] = temp2;
            }
        }
        
    }
    return;

}


