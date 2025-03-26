#include <iostream>
#include <vector>
#include <set>

using namespace std;
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void getdata(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element at index " << i << " : ";
        int data;
        cin >> data;
        arr[i] = data;
    }
    cout << endl;
}
void printVector(vector<int> v)
{
    cout << "Printing Vector : ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
void printVector2(vector<int> v)
{
    cout << "Printing Vector using method 2 : " << endl;
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    // int arr[5] = {1, 2, 3, 4, 5}; // STATIC MEMORY ALLOCATION
    // int n;
    // cout << "Enter the value of n : ";
    // cin >> n;
    // int *brr = new int[n]; // DYNAMIC MEMORY ALLOCATION
    // getdata(brr, n);
    // print(arr, 5);
    // print(brr, n);

    // // LET'S TRY TO INSERT MORE ELEMENTS // IT IS NOT VALID FOR EVERY COMPILER // SOMETIME IT WILL GET CORRUPTED
    // for (int i = 0; i < 10; i++)
    // {
    //     brr[n + i] = 80;
    // }
    // print(brr, n + 10);

    // vector<int> v;
    // v.push_back(1);                  //v.push_back()
    // v.push_back(11);
    // v.push_back(111);
    // printVector(v);
    // v.pop_back();                    //v.pop_back()
    // printVector(v);
    // v.pop_back();
    // printVector(v);
    // v.pop_back();
    // printVector(v);
    // v.pop_back(); // ERROR
    // printVector(v);

    // vector<int> v;
    // while (true)
    // {
    //     int d;
    //     cout << "Enter an element : ";
    //     cin >> d;
    //     v.push_back(d);
    //     cout << "Capacity : " << v.capacity() << endl    // v.capacity()
    //          << "Size : " << v.size() << endl;           //v.size()
    // }

    // vector<int> v;
    // int n;
    // cin >> n;
    // for(int i = 0; i < n; i++){
    //     int data;
    //     cin >> data;
    //     v.push_back(data);
    // }
    // printVector(v);
    // for(int i = 0; i < 10; i++){
    //     v.push_back(9);
    // }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v.at(i) << " ";                  // v.at(i)
    // }
    // cout << endl;
    // v.clear();                                   // v.clear()
    // printVector(v);
    // v.push_back(5);
    // printVector(v);

    // vector<int> arr(5, 9);
    // printVector(arr);
    // vector<int> arr2 = {1, 2, 3, 4, 5, 6};
    // printVector(arr2);
    // vector<int> arr3{1, 2, 3, 4, 5, 6, 7, 8};
    // printVector(arr3);
    // vector<int> arr4(arr3);
    // printVector(arr4);

    // vector<char> v;
    // v.push_back('a');
    // v.push_back('b');
    // v.push_back('c');
    // v.push_back('d');
    // cout << "Front element : " << v[0] << endl;
    // cout << "End element : " << v[v.size() - 1] << endl;
    // cout << "Front element : " << v.front() << endl;        //v.front()
    // cout << "End element : " << v.back() << endl;           //v.back()

    // vector<int> arr = {1, 2, 3, 4, 5, 6};
    // vector<int> copy = {11, 12, 13};
    // printVector(arr);
    // // printVector2(arr);
    // arr.erase(arr.begin() + 1);                          // arr.erase()
    // printVector(arr);
    // arr.erase(arr.begin(), arr.begin() + 2);             // arr.erase()
    // printVector(arr);
    // arr.insert(arr.begin(), 1);                          // arr.insert()
    // arr.insert(arr.begin() + 1, 2, 3);
    // printVector(arr);
    // arr.insert(arr.begin(), copy.begin(), copy.end());   // arr.insert()
    // printVector(arr);
    // arr.swap(copy);                                      // arr.swap()
    // printVector(arr);
    // printVector(copy);

    //  FOR VECTOR SINGLY LINKED LIST IS MAINTAINED
    //  FOR LIST DOUBLY LINKED LIST IS MAINTAINED

    // list<int> ls;
    // ls.push_back(5);
    // ls.emplace_back(15);

    // ls.push_front(4);// IT TAKES LESS TIME THAN THAT OF VECTOR
    // ls.emplace_front(87);

    // for (auto i : ls)
    // {
    //     cout << i << endl;
    // }

    // // SET (no repetition of element and in a sorted pattern)// A TREE IS MAINTAINED
    set<int> st;
    st.insert(4);
    st.emplace(2);
    st.insert(2);
    st.insert(3);
    st.insert(1);
    st.insert(1);

    for (auto i : st)
    {
        cout << i << endl;
    }

    // auto ite = st.find(3);  // IT WILL RETURN THE ADDRESS OF THAT ELEMENT
    // auto ite1 = st.find(6); // IT WILL RETURN st.end() ALWAYS WHENEVER IT DOES NOT FIND AN ELEMENT
    // st.erase(3);

    int a[] = {1, 2, 3, 4, 4, 7, 8, 9, 9, 10};
    int n = 8;
    int it1 = upper_bound(a, a + n, 4) - a - 1;
    int it2 = upper_bound(a, a + n, 5) - a - 1;
    int it3 = upper_bound(a, a + n, 15) - a - 1;

    cout << it1 << " " << it2 << " " << it3 << endl;

    // MULTISET (STORES ALL THE OCCURENCES IN SORTED MANNER)
    // multiset<int> ms;
    // ms.insert(1);
    // ms.insert(1);
    // ms.insert(1);

    // ms.erase(1);// all the occurences are erased

    // int ms_count = ms.count(1);
    return 0;
}