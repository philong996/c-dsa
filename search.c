#include <stdio.h>
#include <stdlib.h>

int linearSearch(int x, int arr[], int n)
{
    for (int i; i < n; i++)
    {
        if (arr[i] == x)
        {
            return 1;
        }
    }
    return 0;
}

int binarySearch(int x, int arr[], int n)
{
    int mid = n / 2;
    int left = 0;
    int right = n-1;

    while (left <= right)
    {
        mid = left + (right - left) / 2;
        if (arr[mid] == x)
        {
            return 1;
        }
        else if (arr[mid] > x)
        {
            right = mid -1;
        } else {
            left = mid + 1;
        }
    }

    return 0;
}


int main()
{
    int arr[] = {1, 2, 3, 4, 6, 7 ,9};
    int n = 3;

    printf("1 is in the list (linear search): %d \n", linearSearch(1, arr, n)) ;
    printf("5 is in the list (linear search): %d \n", linearSearch(100, arr, n));

    printf("1 is in the list (binary search): %d \n", binarySearch(1, arr, n));
    printf("5 is in the list (binary search): %d \n", binarySearch(100, arr, n));
    return 0;
}
