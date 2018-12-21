#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> & vec)
{
    for (int & elem : vec)
        cout << elem;
    cout << '\n';
}

vector<int> big_multiply(vector<int> & a, vector<int> & b) // a > b
{
    vector<int> product(a.size()+b.size(), 0);
    int offset {0};
    int prod, ones, tens;
    for (int j=b.size()-1; j>=0; j--)
    {
        for (int i=a.size()-1; i>=0; i--)
        {
            prod = a[i] * b[j];
            int pos = i + b.size() - offset;
            product[pos] += prod;

            while (product[pos] > 9)
            {
               ones = product[pos]%10;
               tens = (product[pos]/10);

               product[pos] = ones;
               product[--pos] += tens;
            }
        }
        offset++;
    }
    return product;
}

int main()
{
    int m;
    cin >> m;
    vector<int> a (m);
    for (int & elem : a)
        cin >> elem;
    int n;
    cin >> n;
    vector<int> b (n);
    for (int & elem : b)
        cin >> elem;

    vector<int> result = big_multiply(a, b);
    printVec(result);
}