#include <iostream>
#include <vector>
using namespace std;

class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    bool isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = false;
    }
};

void insert(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    TrieNode *child;
    char ch = word[0];
    int index = ch - 'a';

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[index] = child;
    }

    insert(child, word.substr(1));
}

bool searchWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index] != NULL)
    {
        child = root->children[index];
    }
    else
    {
        return false;
    }

    return searchWord(child, word.substr(1));
}

void deleteWord(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal = 0;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    TrieNode *child;

    if (root->children[index])
    {
        child = root->children[index];
    }
    else
    {
        return;
    }

    deleteWord(child, word.substr(1));
}

int main()
{
    TrieNode *root = new TrieNode('-');
    insert(root, "cater");
    insert(root, "care");
    insert(root, "com");
    insert(root, "lover");
    insert(root, "loved");
    insert(root, "load");
    insert(root, "lov");
    insert(root, "bat");
    insert(root, "cat");
    insert(root, "car");

    if (searchWord(root, "care"))
    {
        cout << "Found." << endl;
    }
    else
    {
        cout << "Not Found." << endl;
    }

    deleteWord(root, "care");

    if (searchWord(root, "care"))
    {
        cout << "Found." << endl;
    }
    else
    {
        cout << "Not Found." << endl;
    }

    return 0;
}