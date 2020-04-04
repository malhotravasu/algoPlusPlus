#include <iostream>
#include <algorithm>

using namespace std;

// void bubbleInsert(int* arr, size_t n)
// {
//     if (n == 1)
//         return;
//     if (arr[0] > arr[1])
//     {
//         swap(arr[0], arr[1]);
//     }
//     bubbleInsert(arr+1, n-1);
// }

// void bubbleSort(int* arr, size_t n)
// {
//     if (n == 1)
//         return;
//     bubbleInsert(arr, n);
//     bubbleSort(arr, n-1);
// }

void bubbleSort2(size_t i, int* arr, size_t n)
{
    if (n == 1)
        return;
    
    if (i == n-1)
    {
        bubbleSort2(0, arr, n-1);
        return;
    }

    if (arr[i] > arr[i+1])
    {
        swap(arr[i], arr[i+1]);
    }
    bubbleSort2(i+1, arr, n);
    return;
}

int main()
{
    int n;
    cin >> n;
    int * arr = new int[n] {};
    for (int i=0; i<n; i++)
        cin >> arr[i];
    bubbleSort2(0, arr, n);
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
}