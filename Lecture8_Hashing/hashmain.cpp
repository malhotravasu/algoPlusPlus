#include <iostream>
#include <string>
#include "hashtable.h"
using namespace std;

int main()
{
    int n;
    cin >> n;

    Hashtable h;
    for (int i=1; i<=n; i++)
    {
        h.insert(to_string(i*i), i);
    }
    h.print();

    cout << '\n';
    if (h.search("36")!=nullptr)
        cout << "Found\n";
    else
        cout << "Not Found!\n";
    h["49"] = 8;
    cout << h["49"] << '\n';
    h["49"] -= 1;
    cout << h["49"] << '\n';
    cout << h["3"];
}