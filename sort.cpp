#include <iostream>
#include <bits/stdc++.h> 

using namespace std;


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


// print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int arr[] = {95, 45, 48, 98, 1, 485, 65, 478, 1, 2325};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);
    
    cout << "The sorted array: ";
    printArray(arr, n);

    return 0;
}
