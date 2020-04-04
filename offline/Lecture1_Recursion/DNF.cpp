#include <iostream>
#include <algorithm>

using namespace std;

void DNF(int *  arr, size_t n)
{
    size_t start = 0,
           mid = 0,
           end = n-1;
    
    while (mid <= end)
    {
        if (arr[mid] == 0)
        {
            swap(arr[start], arr[mid]);
            start++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[end]);
            end--;
        }
    }
}

int power(int a, int n)
{
    if (n == 1)
        return a;

    if (n%2 == 0)
    {
        int result = power(a, n/2);
        return result * result;
    }

    else
    {
        return a * power(a, n-1);
    }
}

void print_recursive(int n)
{
    if (n < 1)
        return;
    cout << n << ' ';
    print_recursive(n-1);
    cout << n << ' ';
}

void print_recursive_reverse(int n)
{
    if (n < 1)
        return;

    cout << n << ' ';
    print_recursive_reverse(n-1);
}

bool check_sorted(int * arr, size_t n)
{
    if (n == 1)
        return true;
    else if (arr[0] > arr[1])
        return false;
    else
        return check_sorted(arr+1, n-1);
}

int main()
{
    // int a, n;
    // cin >> a >> n;
    // cout << power(a, n);

    // int n;
    // cin >> n;
    // print_recursive(n);

    // int arr[5] {3, 5, 16, 13, 15};
    // cout << check_sorted(arr, 5);

    // int n;
    // cin >> n;
    // int * arr = new int[n] {};
    // for (int i=0; i<n; i++)
    //     cin >> arr[i];
    // DNF(arr, n);
    // for (int i=0; i<n; i++)
    //     cout << arr[i] << ' ';
}