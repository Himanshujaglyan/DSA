#include <iostream>
#include <list>
#include <vector>
#include <limits.h>
#include <unordered_map>
#include <stack>
using namespace std;

template <typename T>
class Graph
{
public:
    unordered_map<T, list<pair<T, int>>> adjList;

    void addEdge(T u, T v, int wt, bool direction)
    {
        if (direction)
        {
            adjList[u].push_back({v, wt});
        }
        else
        {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> { ";
            for (auto j : i.second)
            {
                cout << "{" << j.first << ", " << j.second << "}, ";
            }
            cout << "}";
            cout << endl;
        }
    }

    void bellmanford(int n, T src)
    {
        vector<int> distance(n, INT_MAX);
        distance[src - 'A'] = 0;

        // (N-1) times Relaxation
        for (int i = 0; i < n - 1; i++)
        {
            // Traverse on entire edgeList
            for (auto a : adjList)
            {
                for (auto b : a.second)
                {
                    T u = a.first;
                    T v = b.first;
                    int wt = b.second;
                    if (distance[u - 'A'] != INT_MAX && distance[u - 'A'] + wt < distance[v - 'A'])
                    {
                        distance[v - 'A'] = distance[u - 'A'] + wt;
                    }
                }
            }
        }
        // Check for negative cycle
        bool anyUpdate = false;
        for (auto a : adjList)
        {
            for (auto b : a.second)
            {
                char u = a.first;
                char v = b.first;
                int wt = b.second;
                if (distance[u - 'A'] != INT_MAX && distance[u - 'A'] + wt < distance[v - 'A'])
                {
                    anyUpdate = true;
                    break;
                }
            }
            if (anyUpdate)
                break;
        }

        if (anyUpdate)
        {
            cout << "Negative cycle Present" << endl;
        }
        else
        {
            cout << "No Negative cycle Present" << endl;
            cout << "Prinitng Distance Array :- ";
            for (auto i : distance)
            {
                cout << i << ", ";
            }
            cout << endl;
        }
    }

    void floydWarshall(int n)
    {
        vector<vector<int>> dist(n, vector<int>(n, 1e9));
        // distance on node to itself is zero
        for (int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }
        // set the distance present in adjList
        for (auto i : adjList)
        {
            for (auto j : i.second)
            {
                int u = i.first;
                int v = j.first;
                int wt = j.second;
                dist[u][v] = wt;
            }
        }
        // Find distance using helper node
        for (int helper = 0; helper < n; helper++)
        {
            for (int src = 0; src < n; src++)
            {
                for (int des = 0; des < n; des++)
                {
                    dist[src][des] = min(dist[src][des], dist[src][helper] + dist[helper][des]);
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

class Graph2
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        if (direction)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> { ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << "}";
            cout << endl;
        }
    }

    void dfs(int node, stack<int> &ordering, unordered_map<int, bool> &visited)
    {
        visited[node] = true;
        for (auto nbr : adjList[node])
        {
            if (!visited[nbr])
            {
                dfs(nbr, ordering, visited);
            }
        }
        ordering.push(node);
    }

    void dfs2(int node, unordered_map<int, bool> &visited2, unordered_map<int, list<int>> &reverseAdjList)
    {
        visited2[node] = true;
        cout << node << " ";
        for (auto nbr : reverseAdjList[node])
        {
            if (!visited2[nbr])
            {
                dfs2(nbr, visited2, reverseAdjList);
            }
        }
    }
    int getStronglyConnectedComponents(int n)
    {
        // Step1 :- Get the ordering
        stack<int> ordering;
        unordered_map<int, bool> visited;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, ordering, visited);
            }
        }
        // Step2 :- Reverse Edges
        unordered_map<int, list<int>> reversedAdjList;
        for (auto a : adjList)
        {
            for (auto b : a.second)
            {
                int u = a.first;
                int v = b;
                reversedAdjList[v].push_back(u);
            }
        }
        // Step3 :- Traverse using ordering and count components
        int count = 0;
        unordered_map<int, bool> visited2;
        while (!ordering.empty())
        {
            int top = ordering.top();
            ordering.pop();
            if (!visited2[top])
            {
                cout << "SCC " << count + 1 << " -> ";
                dfs2(top, visited2, reversedAdjList);
                count++;
                cout << endl;
            }
        }
        return count;
    }
};

// LEETCODE 1192 (CRITICAL CONNECTION IN A NETWORK)
void solve(int src, int parent, vector<int> &tin, vector<int> &low, int &timer, vector<vector<int>> &ans, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited)
{
    visited[src] = true;
    low[src] = timer;
    tin[src] = timer;
    timer++;

    for (auto nbr : adjList[src])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!visited[nbr])
        {
            solve(nbr, src, tin, low, timer, ans, adjList, visited);
            low[src] = min(low[src], low[nbr]);
            if (low[nbr] > tin[src])
            {
                ans.push_back({src, nbr});
            }
        }
        else
        {
            low[src] = min(low[src], low[nbr]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adjList;
    for (auto vec : connections)
    {
        int u = vec[0];
        int v = vec[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int timer = 1;
    vector<vector<int>> ans;
    vector<int> tin(n, 0);
    vector<int> low(n, 0);
    int src = 0;
    int parent = -1;
    unordered_map<int, bool> visited;
    solve(src, parent, tin, low, timer, ans, adjList, visited);
    return ans;
}
int main()
{
    // Graph<char> g;
    // g.addEdge('A', 'B', -1, 1);
    // g.addEdge('B', 'C', 2, 1);
    // g.addEdge('C', 'D', -3, 1);
    // g.addEdge('D', 'E', 5, 1);
    // g.addEdge('A', 'E', 4, 1);
    // g.addEdge('B', 'E', 3, 1);
    // g.addEdge('D', 'B', 1, 1);
    // g.addEdge('B', 'D', 2, 1);
    // g.printAdjList();
    // g.bellmanford(5, 'A');

    // Graph<int> g;
    // g.addEdge(0, 1, 3, 1);
    // g.addEdge(1, 0, 2, 1);
    // g.addEdge(0, 3, 5, 1);
    // g.addEdge(1, 3, 4, 1);
    // g.addEdge(3, 2, 2, 1);
    // g.addEdge(2, 1, 1, 1);
    // g.floydWarshall(4);

    Graph2 g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 0, 1);
    g.addEdge(2, 4, 1);
    g.addEdge(4, 5, 1);
    g.addEdge(5, 6, 1);
    g.addEdge(6, 4, 1);
    g.addEdge(6, 7, 1);

    cout << g.getStronglyConnectedComponents(8) << endl;
    return 0;
}