#include <iostream>

using namespace std;


/*
Interchange sort
*/
void interchangeSort(int arr[], int n)
{
    int i = 0;

    while ( i < n)
    {
        int j,i, temp;
        for (int j = i + 1; j < n; j++)
        {
            if ( arr[j] < arr[i] )
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        i++;
    }
}

/*
Bubble sort and apply adaptive
Interchange and bubble sort are the same
*/
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
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
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
    int arr[] = {8, 7, 5 , 4, 3, 2, 1};
    int n = 7;

    std::cout << "Original array: ";
    printArray(arr, n);
    bubbleSort(arr, n);

    std::cout << "The sorted array: ";
    printArray(arr, n);

    return 0;
}
