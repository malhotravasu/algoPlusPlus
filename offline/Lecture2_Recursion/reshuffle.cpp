#include <bits/stdc++.h>

using namespace std;

// void randomShuffle(size_t i, size_t j, int * arr)
// {
//     int n = j-i+1;

//     if (n < 2)
//         return;

//     if (n == 2)
//     {
//         swap(arr[i], arr[j]);
//         return;
//     }

//     if (n == 3)
//     {
//         switch(rand()%2)
//         {
//             case 0: swap(arr[i], arr[i+2]);
//                     swap(arr[i], arr[i+1]);
//                     break;
//             case 1: swap(arr[i], arr[i+1]);
//                     swap(arr[i], arr[i+2]);
//                     break;
//         }
//         return;
//     }

//     int new_pos = (i+1) + (rand()%(j - i));
//     swap(arr[i], arr[new_pos]);
//     randomShuffle(i, new_pos-1, arr);
//     randomShuffle(new_pos+1, j, arr);
// }

int main()
{
    srand (time(NULL));
    int n;
    cin >> n;
    int * arr = new int[n] {};
    for (int i=0; i<n; i++)
        cin >> arr[i];

    int pos;
    for (int i=0; i<(n-1); i++)
    {
        pos = (i+1) + (rand()%(n-1-i));
        swap(arr[i], arr[pos]);
    }
    for (int i=0; i<n; i++)
        cout << arr[i] << ' ';
}