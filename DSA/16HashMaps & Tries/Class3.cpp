#include <iostream>
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

TrieNode *findNode(TrieNode *root, string input)
{
    if (input.length() == 0)
    {
        return root;
    }

    char ch = input[0];
    int index = ch - 'a';

    if (root->children[index] != NULL)
    {
        return findNode(root->children[index], input.substr(1));
    }
    else
    {
        return NULL;
    }
}

void storeString(TrieNode *root, string input, vector<string> &ans)
{
    if (root->isTerminal)
    {
        ans.push_back(input);
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            string next = input + root->children[i]->value;
            storeString(root->children[i], next, ans);
        }
    }
}
void findPrefixString(TrieNode *root, string input, vector<string> &ans)
{
    TrieNode *node = findNode(root, input);
    if (node)
        storeString(node, input, ans);
}

void getSuggestion(TrieNode *root, string input, vector<vector<string>> &container)
{
    string s = "";
    TrieNode *prev = root;
    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];
        int index = ch - 'a';
        TrieNode *curr = prev->children[index];
        if (curr)
        {
            s += input[i];
            vector<string> ans;
            storeString(curr, s, ans);
            container.push_back(ans);
            prev = curr;
        }
        else
        {
            break;
        }
    }
}

// LEETCODE 1268 (SEARCH SUGGESTION SYSTEM)
// class TrieNode
// {
// public:
//     char value;
//     unordered_map<char, TrieNode *> children;
//     bool isTerminal;
//     TrieNode(char val)
//     {
//         this->value = val;
//         isTerminal = false;
//     }
// };

// void insert(TrieNode *root, string word)
// {
//     if (word.length() == 0)
//     {
//         root->isTerminal = true;
//         return;
//     }
//     TrieNode *child = NULL;
//     char ch = word[0];
//     if (root->children.find(ch) != root->children.end())
//     {
//         child = root->children[ch];
//     }
//     else
//     {
//         child = new TrieNode(ch);
//         root->children[ch] = child;
//     }
//     insert(child, word.substr(1));
// }

// class Solution
// {
// public:
//     void storeString(TrieNode *root, string input, vector<string> &ans)
//     {
//         if (ans.size() == 3)
//             return;
//         if (root->isTerminal)
//         {
//             ans.push_back(input);
//         }
//         for (char i = 'a'; i <= 'z'; i++)
//         {
//             if (root->children.find(i) != root->children.end())
//             {
//                 string next = input + root->children[i]->value;
//                 storeString(root->children[i], next, ans);
//             }
//         }
//     }

//     void getSuggestion(TrieNode *root, string input, vector<vector<string>> &container)
//     {
//         string s = "";
//         TrieNode *prev = root;
//         for (int i = 0; i < input.length(); i++)
//         {
//             char ch = input[i];
//             if (prev->children.find(ch) != prev->children.end())
//             {
//                 TrieNode *curr = prev->children[ch];
//                 s.push_back(ch);
//                 vector<string> ans;
//                 storeString(curr, s, ans);
//                 container.push_back(ans);
//                 prev = curr;
//             }
//             else
//             {
//                 break;
//             }
//         }

//         // If suggestions are incomplete, fill the rest with empty vectors
//         while (container.size() < input.length())
//         {
//             container.push_back({});
//         }
//     }

//     vector<vector<string>> suggestedProducts(vector<string> &products, string searchWord)
//     {
//         TrieNode *root = new TrieNode('-');
//         for (int i = 0; i < products.size(); i++)
//         {
//             insert(root, products[i]);
//         }

//         vector<vector<string>> ans;
//         getSuggestion(root, searchWord, ans);

//         return ans;
//     }
// };

// LEETCODE 14 (LONGEST COMMON PREFIX)
// class TrieNode
// {
// public:
//     char value;
//     TrieNode *children[26];
//     bool isTerminal;
//     int childCount;

//     TrieNode(char val)
//     {
//         this->value = val;
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//         isTerminal = false;
//         childCount = 0;
//     }
// };

// void insert(TrieNode *root, string word)
// {
//     if (word.length() == 0)
//     {
//         root->isTerminal = true;
//         return;
//     }

//     TrieNode *child;
//     char ch = word[0];
//     int index = ch - 'a';

//     if (root->children[index] != NULL)
//     {
//         child = root->children[index];
//     }
//     else
//     {
//         child = new TrieNode(ch);
//         root->children[index] = child;
//         root->childCount++;
//     }

//     insert(child, word.substr(1));
// }
// class Solution
// {
// public:
//     string longestCommonPrefix(vector<string> &strs)
//     {
//         TrieNode *root = new TrieNode('-');
//         for (int i = 0; i < strs.size(); i++)
//         {
//             insert(root, strs[i]);
//         }

//         string ans = "";
//         while (root->childCount == 1 && root->isTerminal != true)
//         {
//             for (int i = 0; i < 26; i++)
//             {
//                 if (root->children[i] != NULL)
//                 {
//                     ans += root->children[i]->value;
//                     root = root->children[i];
//                     break;
//                 }
//             }
//         }
//         return ans;
//     }
// };

int main()
{
    TrieNode *root = new TrieNode('-');
    insert(root, "code");
    insert(root, "court");
    insert(root, "car");
    insert(root, "card");
    insert(root, "codehelp");
    insert(root, "love");
    insert(root, "lovely");
    insert(root, "loved");
    insert(root, "lover");
    insert(root, "load");
    insert(root, "dove");
    insert(root, "dovey");
    insert(root, "babu");
    insert(root, "shona");
    insert(root, "cutie");
    insert(root, "dot");
    insert(root, "supra");
    insert(root, "supreme");

    string s = "loa";
    vector<string> ans;
    findPrefixString(root, s, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    vector<vector<string>> container;
    getSuggestion(root, s, container);
    for (auto i : container)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;

    // map<pair<int, int>, int> mpo;
    // unordered_map<pair<int, int>, int> mp1; // error
    // unordered_map<pair<int, int>, int> mp;  // error
}