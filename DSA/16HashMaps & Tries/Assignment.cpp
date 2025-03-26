#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// GFG (ARRAY SUBSET OF ANOTHER ARRAY)
string isSubset(int a1[], int a2[], int n, int m)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[a1[i]]++;
    }

    for (int j = 0; j < m; j++)
    {
        if (mp.find(a2[j]) == mp.end() || mp[a2[j]] == 0)
        {
            return "No";
        }
        else
        {
            mp[a2[j]]--;
        }
    }

    return "Yes";
}

// GFG (UNION OF TWO LINKED LIST)
struct Node *makeUnion(struct Node *head1, struct Node *head2)
{
    map<int, Node *> mp;
    Node *temp = head1;
    while (temp != NULL)
    {
        mp[temp->data] = temp;
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL)
    {
        mp[temp->data] = temp;
        temp = temp->next;
    }

    Node *head = NULL;
    temp = NULL;
    for (auto i : mp)
    {
        if (!head)
        {
            head = i.second;
            temp = i.second;
        }
        else
        {
            temp->next = i.second;
            temp = temp->next;
        }
    }
    temp->next = 0;

    return head;
}

// GFG (INTERSECTION OF TWO LINKED LIST)
Node *findIntersection(Node *head1, Node *head2)
{
    unordered_map<int, bool> mp;
    Node *temp = head2;
    while (temp != NULL)
    {
        mp[temp->data] = true;
        temp = temp->next;
    }

    Node *head = NULL;
    Node *it = NULL;
    temp = head1;

    while (temp != NULL)
    {
        if (mp.find(temp->data) != mp.end())
        {
            if (!head)
            {
                head = temp;
                it = head;
            }
            else
            {
                it->next = temp;
                it = it->next;
            }
        }
        temp = temp->next;
    }
    if (it)
        it->next = NULL;
    return head;
}

// GFG (SUM EQUALS TO SUM)
bool findPairs(vector<int> &arr)
{
    unordered_map<int, bool> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            int sum = arr[i] + arr[j];
            if (mp.find(sum) == mp.end())
            {
                mp[sum] = true;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}

// GFG (LARGEST SUBARRAY WITH 0 SUM)
int maxLen(vector<int> &arr, int n)
{
    int maxLength = 0;
    int sum = 0;
    unordered_map<int, int> mp; // {sum, index};
    mp.insert({0, -1});
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
        else
        {
            maxLength = max(maxLength, i - mp[sum]);
        }
    }
    return maxLength;
}

// GFG (LARGEST SUBARRAY OF 0 AND 1)
int maxLen(int arr[], int N)
{
    unordered_map<int, int> mp;
    int sum = 0;
    int maxLength = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == 0)
        {
            sum += 1;
        }
        else
        {
            sum -= 1;
        }
        if (sum == 0)
            maxLength = i + 1;
        if (mp.find(sum) == mp.end())
        {
            mp[sum] = i;
        }
        else
        {
            maxLength = max(maxLength, i - mp[sum]);
        }
    }
    return maxLength;
}

// LEETCODE 208 (IMPLEMENT TRIE - PREFIX TREE)
// class TrieNode
// {
// public:
//     char value;
//     unordered_map<char, TrieNode *> children;
//     bool isTerminal;

//     TrieNode(char data)
//     {
//         value = data;
//         isTerminal = false;
//     }
// };

// class Trie
// {
// public:
//     TrieNode *root;
//     void insertUtil(TrieNode *root, string &s, int index)
//     {
//         if (index >= s.length())
//         {
//             root->isTerminal = true;
//             return;
//         }
//         char ch = s[index++];
//         if (root->children.find(ch) == root->children.end())
//         {
//             root->children[ch] = new TrieNode(ch);
//         }
//         insertUtil(root->children[ch], s, index);
//     }

//     bool searchUtil(TrieNode *root, string &s, int index)
//     {
//         if (index >= s.length())
//         {
//             return root->isTerminal;
//         }
//         char ch = s[index++];

//         if (root->children.find(ch) == root->children.end())
//         {
//             return false;
//         }
//         else
//         {
//             return searchUtil(root->children[ch], s, index);
//         }
//     }

//     bool searchPrefixUtil(TrieNode *root, string &s, int index)
//     {
//         if (index >= s.length())
//         {
//             return true;
//         }
//         char ch = s[index++];

//         if (root->children.find(ch) == root->children.end())
//         {
//             return false;
//         }
//         else
//         {
//             return searchPrefixUtil(root->children[ch], s, index);
//         }
//     }

//     Trie()
//     {
//         root = new TrieNode('-');
//     }

//     void insert(string word)
//     {
//         insertUtil(root, word, 0);
//     }

//     bool search(string word)
//     {
//         return searchUtil(root, word, 0);
//     }

//     bool startsWith(string prefix)
//     {
//         return searchPrefixUtil(root, prefix, 0);
//     }
// };

// LEETCODE 648 (REPLACE WORDS)
// class TrieNode
// {
// public:
//     char value;
//     unordered_map<char, TrieNode *> children;
//     bool isTerminal;

//     TrieNode(char data)
//     {
//         value = data;
//         isTerminal = false;
//     }
// };
// void insert(TrieNode *root, string s)
// {
//     if (s.length() == 0)
//     {
//         root->isTerminal = true;
//         return;
//     }

//     char ch = s[0];
//     TrieNode *child = NULL;

//     if (root->children.find(ch) == root->children.end())
//     {
//         child = new TrieNode(ch);
//         root->children[ch] = child;
//     }
//     else
//     {
//         child = root->children[ch];
//     }

//     insert(child, s.substr(1));
// }

// bool searchWord(TrieNode *root, string s, string &ans)
// {
//     if (root->isTerminal)
//     {
//         return true;
//     }
//     char ch = s[0];
//     TrieNode *child = NULL;
//     if (root->children.find(ch) == root->children.end())
//     {
//         return false;
//     }
//     else
//     {
//         child = root->children[ch];
//         ans += s[0];
//         return searchWord(child, s.substr(1), ans);
//     }
// }
// class Solution
// {
// public:
//     string replaceWords(vector<string> &dictionary, string sentence)
//     {
//         TrieNode *root = new TrieNode('-');

//         for (int i = 0; i < dictionary.size(); i++)
//         {
//             insert(root, dictionary[i]);
//         }

//         string ans = "";
//         string helper = "";

//         for (int i = 0; i < sentence.length(); i++)
//         {
//             if (sentence[i] == ' ')
//             {
//                 string ans2 = "";
//                 if (searchWord(root, helper, ans2))
//                 {
//                     ans += ans2;
//                 }
//                 else
//                 {
//                     ans += helper;
//                 }
//                 ans.push_back(' ');
//                 helper = "";
//             }
//             else
//             {
//                 helper += sentence[i];
//             }
//         }
//         string ans2 = "";
//         if (searchWord(root, helper, ans2))
//         {
//             ans += ans2;
//         }
//         else
//         {
//             ans += helper;
//         }
//         return ans;
//     }
// };

// LAKSHAY CODE
// class TrieNode
// {
// public:
//     char value;
//     unordered_map<char, TrieNode *> children;
//     bool isTerminal;

//     TrieNode(char data)
//     {
//         value = data;
//         isTerminal = false;
//     }
// };

// class Trie
// {
// public:
//     TrieNode *root;
//     void insertUtil(TrieNode *root, string &s, int index)
//     {
//         if (index >= s.length())
//         {
//             root->isTerminal = true;
//             return;
//         }
//         char ch = s[index++];
//         if (root->children.find(ch) == root->children.end())
//         {
//             root->children[ch] = new TrieNode(ch);
//         }
//         insertUtil(root->children[ch], s, index);
//     }

//     bool searchUtil(TrieNode *root, string &s, int &index)
//     {
//         if (root->isTerminal)
//             return true;
//         if (index >= s.length())
//         {
//             return root->isTerminal;
//         }
//         char ch = s[index++];

//         if (root->children.find(ch) == root->children.end())
//         {
//             return false;
//         }
//         else
//         {
//             return searchUtil(root->children[ch], s, index);
//         }
//     }

//     Trie()
//     {
//         root = new TrieNode('-');
//     }

//     void insert(string word)
//     {
//         insertUtil(root, word, 0);
//     }

//     int search(string word)
//     {
//         int i = 0;
//         bool gotIt = searchUtil(root, word, i);
//         return gotIt ? i : -1;
//     }
// };

// class Solution
// {
// public:
//     string replaceWords(vector<string> &dictionary, string sentence)
//     {
//         string ans;
//         Trie trie;
//         for (auto it : dictionary)
//         {
//             trie.insert(it);
//         }

//         int start = 0;
//         int end = 0;
//         while (end < sentence.length())
//         {
//             if (sentence[end] == ' ' || end == sentence.length() - 1)
//             {
//                 int len = end == sentence.length() - 1 ? sentence.size() : end - start;
//                 string word = sentence.substr(start, len);
//                 int trieMatchIndex = (trie.search(word));
//                 ans += trieMatchIndex == -1 ? word : word.substr(0, trieMatchIndex);
//                 if (sentence[end] == ' ')
//                 {
//                     ans += " ";
//                 }
//                 start = end + 1;
//             }

//             end++;
//         }

//         return ans;
//     }
// };

// LEETCODE 692 (TOP K FREQUENT WORDS)
class TrieNode
{
public:
    char value;
    TrieNode *children[26];
    int isTerminal;

    TrieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        isTerminal = 0;
    }
};

void insert(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        root->isTerminal++;
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

class comparator
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        return a.second == b.second ? a > b : a.second < b.second;
    }
};

void travel(TrieNode *root, priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> &pq, string temp)
{
    if (root->isTerminal)
    {
        pq.push({temp, root->isTerminal});
    }
    for (int i = 0; i < 26; i++)
    {
        if (root->children[i] != NULL)
        {
            string next = temp + root->children[i]->value;
            travel(root->children[i], pq, next);
        }
    }
}
class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        TrieNode *root = new TrieNode('-');
        for (auto it : words)
        {
            insert(root, it);
        }

        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;
        string temp = "";
        travel(root, pq, temp);

        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            auto &top = pq.top();
            ans.push_back(top.first);
            pq.pop();
        }

        return ans;
    }
};

// ANOTHER APPROCH (MAX HEAP)
class comparator
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        // Sort by integer in descending order
        if (a.second != b.second)
            return a.second < b.second;
        // If integers are equal, sort by string in ascending lexicographical order
        return a.first > b.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mp;
        for (auto it : words)
        {
            mp[it]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;
        for (auto it : mp)
        {
            if (pq.size() >= k)
            {
                if (pq.top().second < it.second)
                {
                    pq.pop();
                }
            }
            else
                pq.push(it);
        }
        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};

// ANOTHER APPROACH (MIN HEAP)
class comparator
{
public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
        // Sort by integer in descending order
        if (a.second != b.second)
            return a.second > b.second;
        // If integers are equal, sort by string in ascending lexicographical order
        return a.first < b.first;
    }
};

class Solution
{
public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        map<string, int> mp;
        for (auto it : words)
        {
            mp[it]++;
        }
        priority_queue<pair<string, int>, vector<pair<string, int>>, comparator> pq;

        for (auto it : mp)
        {
            if (pq.size() >= k)
            {
                if (pq.top().second < it.second)
                {
                    pq.pop();
                    pq.push(it);
                }
            }
            else
                pq.push(it);
        }

        vector<string> ans;
        for (int i = 0; i < k; i++)
        {
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

// LEETCODE 1023 (CAMELCASE MATCHING)
class TrieNode
{
public:
    char value;
    unordered_map<char, TrieNode *> children;
    bool isTerminal;
    TrieNode(char val)
    {
        this->value = val;
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
    TrieNode *child = NULL;
    char ch = word[0];
    if (root->children.find(ch) != root->children.end())
    {
        child = root->children[ch];
    }
    else
    {
        child = new TrieNode(ch);
        root->children[ch] = child;
    }
    insert(child, word.substr(1));
}

bool checkPattern(TrieNode *root, string word)
{
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];
    if (root->children.find(ch) != root->children.end())
    {
        return checkPattern(root->children[ch], word.substr(1));
    }
    else if (islower(ch))
    {
        return checkPattern(root, word.substr(1));
    }
    else
    {
        return false;
    }
}
class Solution
{
public:
    vector<bool> camelMatch(vector<string> &queries, string pattern)
    {
        TrieNode *root = new TrieNode('-');
        insert(root, pattern);

        vector<bool> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            ans.push_back(checkPattern(root, queries[i]));
        }
        return ans;
    }
};

// ANOTHER APPROACH
vector<bool> camelMatch(vector<string> &queries, string pattern)
{
    vector<bool> ans;

    for (int i = 0; i < queries.size(); i++)
    {
        int p1 = 0;
        int p2 = 0;
        string &str = queries[i];
        bool flag = true;
        while (p1 < str.length() && p2 < pattern.length())
        {
            if (str[p1] == pattern[p2])
            {
                p1++;
                p2++;
            }
            else if (islower(str[p1]))
            {
                p1++;
            }
            else
            {
                flag = false;
                break;
            }
        }
        if (!flag)
        {
            ans.push_back(flag);
        }
        else
        {
            while (p1 < str.length() && islower(str[p1]))
            {
                p1++;
            }
            if (p1 == str.length() && p2 == pattern.length())
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
    }
    return ans;
}

// LEETCODE 336 (PALINDROME PAIRS)
// class TrieNode
// {
// public:
//     char value;
//     TrieNode *children[26];
//     int stringNumber;
//     TrieNode(char val)
//     {
//         this->value = val;
//         stringNumber = -1;
//         for (int i = 0; i < 26; i++)
//         {
//             children[i] = NULL;
//         }
//     }
// };

// void insert(TrieNode *root, string &word, int &num, int i)
// {
//     if (i >= word.length())
//     {
//         root->stringNumber = num;
//         return;
//     }
//     TrieNode *child = NULL;
//     char ch = word[i++];
//     int index = ch - 'a';
//     if (root->children[index] != NULL)
//     {
//         child = root->children[index];
//     }
//     else
//     {
//         child = new TrieNode(ch);
//         root->children[index] = child;
//     }
//     insert(child, word, num, i);
// }

// bool isPalindrome(string str, int low, int high)
// {
//     while (low < high)
//     {
//         if (str[low] != str[high])
//         {
//             return false;
//         }
//         low++;
//         high--;
//     }
//     return true;
// }

// void searchCase2(TrieNode *root, vector<int> &myPalindrome, string s)
// {
//     if (root->stringNumber != -1)
//     {
//         if (isPalindrome(s, 0, s.size() - 1))
//         {
//             myPalindrome.push_back(root->stringNumber);
//         }
//     }

//     for (int i = 0; i < 26; i++)
//     {
//         if (root->children[i])
//         {
//             s += root->children[i]->value;
//             searchCase2(root->children[i], myPalindrome, s);
//             s.pop_back();
//         }
//     }
// }
// void search(TrieNode *root, string str, vector<int> &myPalindrome)
// {
//     for (int i = 0; i < str.length(); i++)
//     {
//         char ch = str[i];
//         int index = ch - 'a';
//         if (root->stringNumber != -1)
//         {
//             if (isPalindrome(str, i, str.size() - 1))
//             {
//                 myPalindrome.push_back(root->stringNumber);
//             }
//         }
//         if (root->children[index])
//         {
//             root = root->children[index];
//         }
//         else
//         {
//             return;
//         }
//     }

//     searchCase2(root, myPalindrome, "");
// }
// class Solution
// {
// public:
//     vector<vector<int>> palindromePairs(vector<string> &words)
//     {
//         TrieNode *root = new TrieNode('-');
//         for (int i = 0; i < words.size(); i++)
//         {
//             string str = words[i];
//             reverse(str.begin(), str.end());
//             insert(root, str, i, 0);
//         }
//         vector<vector<int>> ans;
//         for (int i = 0; i < words.size(); i++)
//         {
//             string str = words[i];
//             vector<int> myPalindrome;
//             search(root, str, myPalindrome);
//             for (auto it : myPalindrome)
//             {
//                 if (it != i)
//                 {
//                     ans.push_back({i, it});
//                 }
//             }
//         }
//         return ans;
//     }
// };
int main()
{
    return 0;
}