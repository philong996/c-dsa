#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

// print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


/*
Bubble sort and apply adaptive
Interchange and bubble sort are the same
*/
void swap(int& a, int& b)
{
    int temp = b;
    b = a;
    a = temp;
}

void bubbleSort(int arr[], int n)
{
    int flag;
    for (int i=0; i < n - 1 ; i++)
    {
        flag = 0;
        for (int j=0; j < n -1 - i; j ++ )
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

/*
Insertion sort
it is adaptive for sorted array. It is just scan 1 time.
*/
void insertionSort(int arr[], int n)
{
    for (int i=1; i < n; i++)
    {
        int j = i - 1;
        int current_value = arr[i];
        while ( j >= 0 && arr[j] > current_value)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = current_value;
    }
}

/*
Quick sort
*/
int quickSortPartitioning(int arr[], int low, int high, int n)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j)
    {
        while (i <= high & arr[i] <= pivot)
        {
            i++;
        }

        while (j > low & arr[j] >= pivot)
        {
            j--;
        }

        if (i < j)
            swap(arr[i], arr[j]);
        printArray(arr, n);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high, int n)
{
    if (low < high)
    {
        int middle = quickSortPartitioning(arr, low, high, n);
        quickSort(arr, low, middle - 1, n);
        quickSort(arr, middle + 1, high, n);
    }
}


int main()
{
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    // insertionSort(arr, n);
    // selectionSort(arr, n);
    // bubbleSort(arr, n);
    quickSort(arr, 0, n - 1, n);

    // int middle = quickSortPartitioning(arr, 0, n-1, n);
    
    
    cout << "The sorted array: ";
    printArray(arr, n);

    return 0;
}
