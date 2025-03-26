#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

// GFG (UNDIRECTED GRAPH CYCLE) (USING BFS)
bool isCycle(vector<vector<int>> &adj)
{
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            int src = adj[i][j];
            if (!visited[src])
            {
                q.push(src);
                visited[src] = true;
                parent[src] = -1;
                while (!q.empty())
                {
                    int front = q.front();
                    q.pop();
                    for (auto nbr : adj[front])
                    {
                        if (!visited[nbr])
                        {
                            q.push(nbr);
                            visited[nbr] = true;
                            parent[nbr] = front;
                        }
                        else if (visited[nbr] && nbr != parent[front])
                        {
                            // cycle present
                            return true;
                        }
                    }
                }
            }
        }
    }
    // cycle not present
    return false;
}

// GFG (UNDIRECTED GRAPH CYCLE) (USING DFS)
bool isCycleUsingDFS(vector<vector<int>> &adj, unordered_map<int, bool> &visited, int src, int parent)
{
    visited[src] = true;
    for (int i = 0; i < adj[src].size(); i++)
    {
        if (!visited[adj[src][i]])
        {
            bool check = isCycleUsingDFS(adj, visited, adj[src][i], src);
            if (check)
                return true;
        }
        else if (visited[adj[src][i]] && adj[src][i] != parent)
        {
            return true;
        }
    }
    return false;
}

bool isCycle(vector<vector<int>> &adj)
{
    unordered_map<int, bool> visited;
    for (int i = 0; i < adj.size(); i++)
    {
        for (int j = 0; j < adj[i].size(); j++)
        {
            if (!visited[adj[i][j]])
            {
                bool check = isCycleUsingDFS(adj, visited, adj[i][j], -1);
                if (check)
                    return true;
            }
        }
    }
    return false;
}

// GFG (CYCLE IN A DIRECTED GRAPH) (USING DFS)
bool cycleCheck(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &dfsTrack)
{
    visited[node] = true;
    dfsTrack[node] = true;

    for (auto it : adj[node])
    {
        if (!visited[it])
        {
            if (cycleCheck(it, adj, visited, dfsTrack))
                return true;
        }
        else if (visited[it] && dfsTrack[it])
        {
            return true;
        }
    }

    dfsTrack[node] = false;
    return false;
}

bool isCyclic(int V, vector<vector<int>> adj)
{
    vector<bool> visited(V, false);
    vector<bool> dfsTrack(V, false);
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
        {
            if (cycleCheck(i, adj, visited, dfsTrack))
                return true;
        }
    }

    return false;
}
int main()
{
    return 0;
}