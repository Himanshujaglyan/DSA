#include <iostream>
#include <list>
#include <unordered_map>
#include <stack>
#include <vector>
#include <set>
#include <limits.h>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<pair<int, int>>> adjList;

    void addEgde(int u, int v, int wt, bool direction)
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
        for (auto it : adjList)
        {
            cout << it.first << " -> { ";
            for (auto nbr : it.second)
            {
                cout << "{" << nbr.first << ", " << nbr.second << "}, ";
            }
            cout << "}" << endl;
        }
    }

    void topoOrderDfs(int src, unordered_map<int, bool> &visited, stack<int> &topoOrder)
    {
        visited[src] = true;
        for (auto nbr : adjList[src])
        {
            if (!visited[nbr.first])
                topoOrderDfs(nbr.first, visited, topoOrder);
        }
        topoOrder.push(src);
    }

    void shortestPathDfs(stack<int> &topoOrder)
    {
        vector<int> distance(topoOrder.size(), INT_MAX);
        int src = topoOrder.top();
        topoOrder.pop();
        distance[src] = 0;

        for (auto nbr : adjList[src])
        {
            if (distance[src] + nbr.second < distance[nbr.first])
            {
                distance[nbr.first] = distance[src] + nbr.second;
            }
        }

        while (!topoOrder.empty())
        {
            int src = topoOrder.top();
            topoOrder.pop();

            for (auto nbr : adjList[src])
            {
                if (distance[src] + nbr.second < distance[nbr.first])
                {
                    distance[nbr.first] = distance[src] + nbr.second;
                }
            }
        }

        for (int it : distance)
        {
            cout << it << " ";
        }
    }

    void dijkstra(int n, int src, int dest)
    {
        vector<int> distance(n + 1, INT_MAX);
        set<pair<int, int>> st;

        st.insert({0, src});
        distance[src] = 0;

        while (!st.empty())
        {
            auto topElement = st.begin();
            pair<int, int> topPair = *topElement;
            int topDist = topPair.first;
            int topNode = topPair.second;
            st.erase(st.begin());

            for (auto nbr : adjList[topNode])
            {
                if (topDist + nbr.second < distance[nbr.first])
                {
                    auto prev = st.find({distance[nbr.second], nbr.first});
                    if (prev != st.end())
                    {
                        st.erase(prev);
                    }
                    distance[nbr.first] = topDist + nbr.second;
                    st.insert({distance[nbr.first], nbr.first});
                }
            }
        }

        cout << "Shortest distance from " << src << " to " << dest << " :- " << distance[dest] << endl;
    }
};
int main()
{
    // Graph g;
    // g.addEgde(0, 1, 5, 1);
    // g.addEgde(0, 2, 3, 1);
    // g.addEgde(2, 1, 2, 1);
    // g.addEgde(1, 3, 3, 1);
    // g.addEgde(2, 3, 5, 1);
    // g.addEgde(2, 4, 6, 1);
    // g.addEgde(4, 3, 1, 1);
    // g.printAdjList();

    // stack<int> topoOrder;
    // unordered_map<int, bool> visited;
    // g.topoOrderDfs(0, visited, topoOrder);
    // g.shortestPathDfs(topoOrder);

    // // while (!topoOrder.empty())
    // // {
    // //     cout << topoOrder.top() << " ";
    // //     topoOrder.pop();
    // // }

    Graph g2;
    g2.addEgde(1, 2, 7, 0);
    g2.addEgde(1, 3, 9, 0);
    g2.addEgde(1, 6, 14, 0);
    g2.addEgde(2, 3, 10, 0);
    g2.addEgde(2, 4, 15, 0);
    g2.addEgde(3, 4, 11, 0);
    g2.addEgde(3, 6, 2, 0);
    g2.addEgde(4, 5, 6, 0);
    g2.addEgde(5, 6, 9, 0);

    g2.dijkstra(6, 6, 4);
    return 0;
}