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
    
    bubbleSort(arr, n);
    
    cout << "The sorted array: ";
    printArray(arr, n);

    return 0;
}
