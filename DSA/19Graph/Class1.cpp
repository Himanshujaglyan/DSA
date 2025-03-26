#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction)
    {
        if (direction)
        {
            // directed u->v
            adjList[u].push_back(v);
        }
        else
        {
            // undirected u->v, v->u
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for (auto i : adjList)
        {
            cout << i.first << " -> { ";
            for (auto neighbour : i.second)
            {
                cout << neighbour << ", ";
            }
            cout << "}" << endl;
        }
    }
};

template <typename T>
class WeightedGraph
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
            for (auto neighbour : i.second)
            {
                cout << "{" << neighbour.first << ", " << neighbour.second << "}, ";
            }
            cout << "}" << endl;
        }
    }

    void bfsTraversal(T src, unordered_map<char, bool> &visited)
    {
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty())
        {
            T frontNode = q.front();
            cout << frontNode << " ";
            q.pop();
            for (auto neighbour : adjList[frontNode])
            {
                if (!visited[neighbour.first])
                {
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                }
            }
        }
    }

    void dfsTraversal(T src, unordered_map<char, bool> &visited)
    {
        visited[src] = true;
        cout << src << " ";
        for (auto neighbour : adjList[src])
        {
            if (!visited[neighbour.first])
            {
                dfsTraversal(neighbour.first, visited);
            }
        }
    }
};
int main()
{
    // Graph g;
    // g.addEdge(0, 1, 0);
    // g.addEdge(1, 2, 0);
    // g.addEdge(1, 3, 0);
    // g.addEdge(2, 3, 0);
    // g.printAdjList();
    // cout << endl;

    // WeightedGraph<char> wg;
    // wg.addEdge('a', 'b', 5, 0);
    // wg.addEdge('a', 'c', 10, 0);
    // wg.addEdge('b', 'c', 10, 0);
    // wg.addEdge('c', 'd', 50, 0);
    // wg.addEdge('c', 'e', 20, 0);
    // wg.addEdge('e', 'f', 20, 0);
    // // wg.printAdjList();
    // unordered_map<char, bool> visited;
    // wg.bfsTraversal('a', visited); // This will fail in case of disconnected graph so to avoid this make call for each node individually
    // cout << endl;

    // WeightedGraph<char> wg1;
    // wg1.addEdge('a', 'b', 5, 0);
    // wg1.addEdge('b', 'c', 5, 0);
    // wg1.addEdge('d', 'e', 5, 0);
    // wg1.addEdge('f', 'f', 5, 0);
    // unordered_map<char, bool> visited1;
    // for (char node = 'a'; node <= 'f'; node++)
    // {
    //     if (!visited1[node])
    //     {
    //         wg1.bfsTraversal(node, visited1);
    //     }
    // }

    WeightedGraph<char> wg2;
    wg2.addEdge('a', 'b', 5, 0);
    // wg2.addEdge('a', 'c', 5, 0);
    wg2.addEdge('c', 'd', 5, 0);
    wg2.addEdge('c', 'e', 5, 0);
    wg2.addEdge('d', 'e', 5, 0);
    wg2.addEdge('e', 'f', 5, 0);
    unordered_map<char, bool> visited2;
    // wg2.dfsTraversal('a', visited2);
    for (char node = 'a'; node <= 'f'; node++)
    {
        if (!visited2[node])
        {
            wg2.bfsTraversal(node, visited2);
        }
    }
    return 0;
}