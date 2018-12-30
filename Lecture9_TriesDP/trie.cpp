#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Node
{
    char c;
    unordered_map<char, Node*> m;
    bool terminal;

    Node(char c): c{c}, terminal{false} {}
};

// Also called Prefix Tree
class Trie
{
    Node *root;
    int total_words;

public:
    Trie()
    {
        root = new Node('\0');
        total_words = 0;
    }
    void add_word(string word)
    {
        Node *temp = root;
        for (char & ch : word)
        {
            if (temp->m.find(ch)==temp->m.end())
            {
                Node *n = new Node (ch);
                temp->m[ch] = n;
                temp = n;
            }
            else
            {
                temp = temp->m[ch];
            }
        }
        temp->terminal = true;
    }
    bool lookup(string word)
    {
        Node *temp = root;
        for (char & ch : word)
        {
            if (temp->m.find(ch)==temp->m.end())
            {
                return false;
            }
            else
            {
                temp = temp->m[ch];
            }
        }
        return temp->terminal;
    }
};

int max_xor(vector<int> v)
{
    // For n=10^7 i.e. O(N)
    return 0;
}

int main()
{
    Trie dictionary;
    dictionary.add_word("apple");
    dictionary.add_word("mango");
    dictionary.add_word("guava");
    dictionary.add_word("banana");

    cout << dictionary.lookup("kiwi") << '\n';
    cout << dictionary.lookup("apple") << '\n';
    cout << dictionary.lookup("appl") << '\n';
}