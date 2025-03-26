#include <iostream>
#include <cmath>
using namespace std;

void insertionSort(vector<int> &v)
{

    for (int i = 1; i < v.size(); i++)
    {
        int nums = v[i];
        int index = i;
        while (index > 0 && v[index - 1] > nums)
        {
            v[index] = v[index - 1];
            index--;
        }
        v[index] = nums;
    }
}
int main()
{
    vector<int> v{5, 4, 3, 2, 1};
    insertionSort(v);
    for (auto i : v)
    {
        cout << i << " " << endl;
    }
}
