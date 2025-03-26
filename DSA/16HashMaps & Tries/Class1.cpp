#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

void countCharacter(unordered_map<char, int> &mp, string &str)
{
    for (auto ch : str)
    {
        mp[ch]++;
    }
}
int main()
{
    // map creation
    unordered_map<string, int> mapping;

    // pair creation
    pair<string, int> p = make_pair("Om", 20);
    pair<string, int> q("Nitin", 19);
    pair<string, int> r;
    r.first = "Raghav";
    r.second = 16;
    pair<string, int> s = {"Jatin", 21};

    // map insertion
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    mapping.insert(s);
    mapping["Babbar"] = 51;

    cout << "Size of map : " << mapping.size() << endl; // size
    cout << mapping.at("Nitin") << endl;                // at
    cout << mapping["Om"] << endl;                      // accessing the value using key

    cout << mapping.count("Love") << endl; // count
    cout << mapping.count("Babbar") << endl;

    if (mapping.find("Babbar") != mapping.end())
    {
        cout << "Found." << endl;
    }
    else
    {
        cout << "Not Found." << endl;
    }

    cout << "Size of map is : " << mapping.size() << endl;
    cout << mapping["Kumar"] << endl; // whenever we try to access a member using square brackets, if it is not present a new entry will be created in the map
    cout << "Size of map is : " << mapping.size() << endl;

    string str = "raghavaggarwal";
    unordered_map<char, int> mp;
    countCharacter(mp, str);

    for (auto i : mp)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    map<char, int> omp; // ordered map
    return 0;
}