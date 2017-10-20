/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"
bool search1 (int value, int values[], int a, int b);

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    return search1(value, values, 0, n-1);
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int temp[65537];
    
    for (int i = 0; i < 65537; i++)
    {
        temp[i] = 0;
    }
    
    for (int a = 0; a < n; a++)
    {
        temp[values[a]] += 1;
    }
    
    int k = 0;
    for (int i = 0; i < 65537; i++)
    {
        if (temp[i] != 0)
        {
            for (int j = 0; j < temp[i]; j++)
            {
                values[k] = i;
                k++;
            }
        }
    }
    
    return;
}

bool search1 (int value, int values[], int a, int b)
{
    int c = (a+b)/2;;
    
    if (a>b)
    {
        return false;
    }
    else if (values[c] == value)
    {
        return true;
    }
    else if (values[c] < value)
    {
        return search1(value, values, c+1, b);
    }
    else if (values[c] > value)
    {
        return search1(value, values, a, c-1);
    }
    else
    {
        return false;
    }
}