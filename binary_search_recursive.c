#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5
int sorted_arr[SIZE] = {21,22,23,24,25};

bool binary_search (int start, int end, int val)
{
    if (start <= end)
    {
        int mid = (start+end)/2;

        if (val < sorted_arr[mid])
        {
            binary_search (start, mid-1, val);
        }
        else if (val > sorted_arr[mid])
        {
            binary_search (mid+1, end, val);
        }
        else 
        {
            printf ("Item found, pos : %d\n", mid);
            return true;
        }
    }
    else
    {
        printf ("Item not found\n");
        return false;
    }
}

void call_binary_search ()
{
    int tmp1 = 0;
    printf ("Enter value to search\n");
    scanf ("%d", &tmp1);
    binary_search(0, SIZE-1, tmp1);
}

int main()
{
    int tmp = 0;
    printf ("Binary search\n");
    //binary_search (sorted_arr, SIZE, 21);

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