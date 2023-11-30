#include <stdio.h>
#include <stdlib.h>


// print array
void printArray(int arr[], int n)
{
    printf("{");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("}\n");
}


/*
Bubble sort and apply adaptive
Interchange and bubble sort are the same
*/
void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
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
                swap(&arr[j], &arr[j+1]);
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
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
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

/*
Merge sort
*/
void merge(int arr[], int low, int middle, int high)
{
    int i, j, k;
    i = k = low;
    j = middle + 1;
    int temp[high + 1];

    while ( i <= middle && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }

    while (i <= middle)
    {
        temp[k++] = arr[i++];
    }

    while (j <= high)
    {
        temp[k++] = arr[j++];
    }

    for (int p = low; p <= high; p++)
    {
        arr[p] = temp[p];
    }

}

void iterativeMertgeSort(int arr[], int n)
{
    for (int curSize=1; curSize <= n - 1; curSize *= 2 )
    {
        for (int left = 0; left < n - 1; left += curSize * 2)
        {
            int right = left + 2 * curSize - 1;
            int mid = (left + right) / 2;

            merge(arr, left, mid, right);
        }
    }
}

void recursiveMergeSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;

        recursiveMergeSort(arr, l, mid);
        recursiveMergeSort(arr, mid+1, h);
        merge(arr, l, mid, h);
    }
}



int main()
{
    
    int arr[] = {3, 6, 8, 10, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);

    printf("Select a sorting algorithm: \n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Quick Sort\n");
    printf("4. Iteractive Merge Sort\n");
    printf("5. Recursive Merge Sort\n");
    printf("Enter your choice : ");
    int choice;
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        bubbleSort(arr, n);
        break;
    
    case 2:
        insertionSort(arr, n);
        break;

    case 3:
        quickSort(arr, 0, n - 1, n);
        break;

    case 4:
        iterativeMertgeSort(arr, n);
        break;

    case 5:
        recursiveMergeSort(arr, 0, n-1);
        break;


    default:
        printf("No valid choice");
        break;
    }

    printf("The sorted array: \n");
    printArray(arr, n);

    return 0;
}
