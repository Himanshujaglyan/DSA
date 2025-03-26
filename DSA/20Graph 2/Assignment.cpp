#include <iostream>
using namespace std;

// PRIM'S ALGORITHM
int getMinimumValueNode(vector<int> &key, vector<bool> &mst)
{
    int temp = INT_MAX;
    int index = -1;
    for (int i = 0; i < key.size(); i++)
    {
        if (mst[i] == false && key[i] < temp)
        {
            temp = key[i];
            index = i;
        }
    }
    return index;
}

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<int> key(V, INT_MAX);
    key[0] = 0;
    vector<bool> mst(V, false);
    vector<int> parent(V, -1);
    while (true)
    {
        int u = getMinimumValueNode(key, mst);
        if (u == -1)
            break;
        mst[u] = true;
        for (auto edge : adj[u])
        {
            int v = edge[0];
            int w = edge[1];
            if (mst[v] == false && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
    int sum = 0;
    for (int u = 0; u < V; u++)
    {
        if (parent[u] == -1)
            continue;
        for (auto edge : adj[u])
        {
            int v = edge[0];
            int w = edge[1];
            if (v == parent[u])
            {
                sum += w;
            }
        }
    }
    return sum;
}
int main()
{
    return 0;
}