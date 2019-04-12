#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10
int sorted_arr[SIZE] = {21,22,23,24,25,25,26,26,26,27};

bool binary_search (int *sorted_array, int size, int val)
{
    int start = 0;
    int end = SIZE - 1;
    int mid = 0;

    while (start <= end)
    {
        mid = (start + end)/2;

        if (val == sorted_array[mid])
        {
            printf ("item found, position : %d\n", mid);
            return true;
        }
        else if (val < sorted_array[mid])
        {
            end = mid - 1;
        }
        else if (val > sorted_array[mid])
        {
            start = mid + 1;
        }
    }
    printf ("Item not found\n");
    return false;
}

bool binary_search_leftmost (int *sorted_array, int size, int val)
{
    int start = 0;
    int end = SIZE - 1;
    int mid = 0;
    int result = -1;

    while (start <= end)
    {
        mid = (start + end)/2;

        if (val == sorted_array[mid])
        {
            end = mid -1 ;
            result = mid;
        }
        else if (val > sorted_array[mid])
        {
            start = mid + 1;
        }
        else if (val < sorted_array[mid])
        {
            end = mid - 1;
        }
    }

    if (result == -1)
    {
        printf ("item not found\n");
    }
    else
    {
        printf ("leftmost position is : %d\n", result);
    }
}

bool binary_search_rightmost (int *sorted_array, int size, int val)
{
    int start = 0;
    int end = SIZE - 1;
    int mid = 0;
    int result = -1;

    while (start <= end)
    {
        mid = (start + end)/2;

        if (val == sorted_array[mid])
        {
            start = mid + 1 ;
            result = mid;
        }
        else if (val > sorted_array[mid])
        {
            start = mid + 1;
        }
        else if (val < sorted_array[mid])
        {
            end = mid - 1;
        }
    }

    if (result == -1)
    {
        printf ("item not found\n");
    }
    else
    {
        printf ("rightmost position is : %d\n", result);
    }
    
}

void call_binary_search ()
{
    int tmp1 = 0;
    printf ("Enter value to search\n");
    scanf ("%d", &tmp1);
    binary_search_rightmost(sorted_arr, SIZE, tmp1);
}

int main()
{
    int tmp = 0;
    printf ("Binary search\n");
    binary_search (sorted_arr, SIZE, 21);

    while (1)
    {
        printf ("Enter 1 to search and 2 to exit\n");
        scanf ("%d", &tmp);

        switch (tmp)
        {
            case 1:
                call_binary_search ();
                break;
            case 2:
                return 0;
                break;
            default:
                printf ("invalid value\n");
                break;
        }
    }
    return 0;
}