#include <iostream>
using namespace std;

int main()
{
    // string str = "abc"; // using binary representation of number
    // int size = str.length();
    // int num = pow(2, size);
    // vector<string> v;
    // for (int i = 0; i < num; i++)
    // {
    //     string out = "";
    //     int n = i;
    //     int j = 0;
    //     while (n)
    //     {
    //         if (n & 1)
    //         {
    //             out += str[j];
    //         }
    //         j++;
    //         n >>= 1;
    //     }
    //     v.push_back(out);
    // }
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }

    // string s = "abc";
    // while (next_permutation(s.begin(), s.end()))
    // {
    //     cout << s << endl;
    // }

    // // Single Unit Allocation
    // int *intPtr = new int(5); // integer dynamic allocation// Here new keyword return the address where the value is stored in the memory (int*)
    // // But malloc utna hee bevkoof hei jitna new keyword intelligent hei
    // // malloc says that tum mujhe kitne bytes of memory chahiye vo btado or kyuki usko pata nahi hotta kee konsa data type hei toh vo (void*) return krta hei
    // void *ptr = malloc(4);
    // int *ptr2 = (int *)ptr;
    // *ptr2 = 5;
    // cout << *intPtr << " " << *ptr2 << endl;
    // delete intPtr;
    // free(ptr);

    // // 1-D Allocation
    // int *arrnew = new int[5];
    // int *arrmalloc = (int *)malloc(5 * sizeof(int));
    // for (int i = 0; i < 5; i++)
    // {
    //     int d;
    //     cin >> d;
    //     arrnew[i] = arrmalloc[i] = d;
    // }
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << arrnew[i] << " " << arrmalloc[i] << endl;
    // }

    // delete[] arrnew;
    // free(arrmalloc);

    // 2-D Allocation
    int **ptr2d = new int *[5];
    for (int i = 0; i < 5; i++)
    {
        ptr2d[i] = new int[5];
    }

    int **ptr2dmalloc = (int **)malloc(sizeof(int *) * 5);
    for (int i = 0; i < 5; i++)
    {
        ptr2dmalloc[i] = (int *)malloc(sizeof(int) * 5);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            ptr2d[i][j] = 7;
            ptr2dmalloc[i][j] = 8;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << ptr2d[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << ptr2dmalloc[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < 5; i++)
    {
        delete[] ptr2d[i];
        free(ptr2dmalloc[i]);
    }
    delete[] ptr2d;
    free(ptr2dmalloc);
    return 0;
}