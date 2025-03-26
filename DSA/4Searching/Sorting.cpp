#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void bubbleSort(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}
void bubbleSort2(vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        for (int j = 0; j < v.size() - i - 1; j++)
        {
            if (v[j] < v[j + 1])
            {
                swap(v[j], v[j + 1]);
            }
        }
    }
}
void selectionSort(vector<int> &v)
{

    for (int i = 0; i < v.size() - 1; i++)
    {
        int minimum = i;
        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[minimum])
            {
                minimum = j;
            }
        }
        swap(v[i], v[minimum]);
    }
}
void insertionSort(vector<int> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}
bool comparator(int &a, int &b)
{
    return a > b; // descending order
    // return a < b; // ascending order
}
void print(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        vector<int> &temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout << a << " " << b << endl;
    }
}
bool customcomparator(vector<int> &a, vector<int> &b)
{
    // return a[0] < b[0];
    return a[1] < b[1];
}
int main()
{
    // vector<int> v{5, 0, -1, 23, 4, 56, -5};
    // bubbleSort(v);
    // print(v);
    // bubbleSort2(v);
    // print(v);

    // vector<int> v{5, 0, -1, 23, 4, 56, -5};
    // selectionSort(v);
    // print(v);

    // vector<int> v{5, 0, -1, 23, 4, 56, -5};
    // insertionSort(v);
    // print(v);
    
    // vector<int> v{5, 0, -1, 23, 4, 56, -5};
    // sort(v.begin(), v.end());
    // print(v);
    // sort(v.begin(), v.end(), comparator);
    // print(v);

    vector<vector<int>> v;
    vector<int> v1{1, 44};
    vector<int> v2{0, 55};
    vector<int> v3{0, 22};
    vector<int> v4{0, 11};
    vector<int> v5{2, 33};
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);
    v.push_back(v4);
    v.push_back(v5);

    sort(v.begin(), v.end());
    print(v);
    sort(v.begin(), v.end(), customcomparator);
    print(v);
    return 0;
}