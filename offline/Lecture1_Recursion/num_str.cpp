#include <iostream>

using namespace std;

char digits[][10] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine"
};

void print_spellings(int n)
{
    if (n == 0)
        return;

    int digit = n%10;
    print_spellings(n/10);
    cout << digits[digit] << ' ';
    return;
}

int main()
{
    int n;
    cin >> n;
    print_spellings(n);
}