#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adjList;

    void addEdge(int u, int v, bool direction)
    {
        if (!direction)
        {
            adjList[u].push_back(v);
        }
        else
        {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void shortestPath(int src, int des)
    {
        unordered_map<int, bool> visited;
        queue<int> q;
        unordered_map<int, int> parent;

        q.push(src);
        parent[src] = -1;
        visited[src] = true;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            for (auto nbr : adjList[front])
            {
                if (!visited[nbr])
                {
                    visited[nbr] = true;
                    parent[nbr] = front;
                    q.push(nbr);
                }
            }
        }

        vector<int> ans;
        while (des != -1)
        {
            ans.push_back(des);
            des = parent[des];
        }

        reverse(ans.begin(), ans.end());

        for (auto it : ans)
        {
            cout << it << " ";
        }
    }
};

// GFG (TOPOLOGICAL SORT) (USING DFS)
void dfsTraversal(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int src, vector<int> &v)
{
    visited[src] = true;
    for (auto nbr : adj[src])
    {
        if (!visited[nbr])
        {
            dfsTraversal(adj, visited, nbr, v);
        }
    }
    v.push_back(src);
}

vector<int> topologicalSort(vector<vector<int>> &adj)
{
    vector<int> v;
    unordered_map<int, bool> visited;
    for (int i = 0; i < adj.size(); i++)
    {
        if (!visited[i])
        {
            dfsTraversal(adj, visited, i, v);
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

// GFG (TOPOLOGICAL SORT) (USING BFS)
vector<int> topologicalSort1(vector<vector<int>> &adj)
{
    vector<int> ans;
    queue<int> q;
    unordered_map<int, int> indegree;

    for (int i = 0; i < adj.size(); i++)
    {
        for (auto nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    for (int i = 0; i < adj.size(); i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto nbr : adj[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
    return ans;
}

// GFG (CYCLE IN A DIRECTED GRAPH) (USING BFS)
// IN CASE OF CYCLIC GRAPH THE INDEGREE WILL NEVER BE ZERO, HENCE THOSE COMPONENTS WILL NOT BE INSERTED IN THE ANSWER VECTOR
bool isCyclic(int V, vector<vector<int>> adj)
{
    // code here
    vector<int> ans;
    queue<int> q;

    unordered_map<int, int> indegree;

    for (int i = 0; i < adj.size(); i++)
    {
        for (auto nbr : adj[i])
        {
            indegree[nbr]++;
        }
    }

    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int front = q.front();
        q.pop();
        ans.push_back(front);
        for (auto nbr : adj[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
    return ans.size() != V;
}
int main()
{
    Graph g;
    g.addEdge(0, 5, 0);
    g.addEdge(5, 4, 0);
    g.addEdge(4, 3, 0);
    g.addEdge(0, 6, 0);
    g.addEdge(6, 3, 0);
    g.addEdge(0, 1, 0);
    g.addEdge(1, 2, 0);
    g.addEdge(2, 3, 0);

    g.shortestPath(0, 3);
    return 0;
}