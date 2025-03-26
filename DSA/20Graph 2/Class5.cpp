#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

// LEETCODE 207 (COURSE SCHEDULE)
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, int> indegree;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[v].push_back(u);
        indegree[u]++;
    }
    vector<int> topoOrder;
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
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
        topoOrder.push_back(front);
        for (auto nbr : adjList[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
    return topoOrder.size() == numCourses;
}

// MY APPROACH
bool dfs(int srcNode, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsTrack, unordered_map<int, list<int>> &adjList)
{
    visited[srcNode] = true;
    dfsTrack[srcNode] = true;
    for (auto nbr : adjList[srcNode])
    {
        if (!visited[nbr])
        {
            bool ans = dfs(nbr, visited, dfsTrack, adjList);
            if (ans)
                return true;
        }
        else if (dfsTrack[nbr])
        {
            return true;
        }
    }
    dfsTrack[srcNode] = false;
    return false;
}

bool canFinish1(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[u].push_back(v);
    }
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsTrack;
    for (auto i : adjList)
    {
        if (!visited[i.first])
        {
            bool ans = dfs(i.first, visited, dfsTrack, adjList);
            if (ans)
                return false;
        }
    }
    return true;
}

// LEETCODE 210 (COURSE SCHEDULE II)
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adjList;
    unordered_map<int, int> indegree;
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adjList[v].push_back(u);
        indegree[u]++;
    }
    vector<int> topoOrder;
    queue<int> q;
    for (int i = 0; i < numCourses; i++)
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
        topoOrder.push_back(front);
        for (auto nbr : adjList[front])
        {
            indegree[nbr]--;
            if (indegree[nbr] == 0)
            {
                q.push(nbr);
            }
        }
    }
    if (topoOrder.size() == numCourses)
    {
        return topoOrder;
    }
    else
    {
        return {};
    }
}

// LEETCODE 1631 (PATH WITH MINIMUM EFFORT)
bool isSafe(int newX, int newY, int row, int col)
{
    return (newX < row && newY < col && newX >= 0 && newY >= 0);
}

int minimumEffortPath(vector<vector<int>> &heights)
{
    int row = heights.size();
    int col = heights[0].size();
    vector<vector<int>> effort(row, vector<int>(col, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> mini;

    // set initial state
    effort[0][0] = 0;
    mini.push({0, {0, 0}});

    while (!mini.empty())
    {
        pair<int, pair<int, int>> top = mini.top();
        mini.pop();
        int currDiff = top.first;
        int currX = top.second.first;
        int currY = top.second.second;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            if (isSafe(newX, newY, row, col))
            {
                int newDiff = max(currDiff, abs(heights[newX][newY] - heights[currX][currY]));
                if (newDiff < effort[newX][newY]) // CONDITION
                {
                    mini.push({newDiff, {newX, newY}});
                }
                effort[newX][newY] = min(effort[newX][newY], newDiff);
            }
        }
    }
    return effort[row - 1][col - 1];
}

// BABBAR CODE
class Solution
{
public:
    bool isSafe(int newX, int newY, int row, int col, vector<vector<int>> &diff, int currX, int currY)
    {
        if (newX >= 0 && newY >= 0 && newX < row && newY < col && diff[currX][currY] < diff[newX][newY]) // CONDITION SET HERE
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int minimumEffortPath(vector<vector<int>> &heights)
    {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> mini;
        int row = heights.size();
        int col = heights[0].size();
        vector<vector<int>> diff(row, vector<int>(col, INT_MAX));
        int destX = row - 1;
        int destY = col - 1;
        diff[0][0] = 0;
        mini.push({0, {0, 0}});
        while (!mini.empty())
        {
            auto topPair = mini.top();
            mini.pop();
            int currDiff = topPair.first;
            pair<int, int> currNodeIndexPair = topPair.second;
            int currX = currNodeIndexPair.first;
            int currY = currNodeIndexPair.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = currX + dx[i];
                int newY = currY + dy[i];
                if (isSafe(newX, newY, row, col, diff, currX, currY))
                {
                    int maxDiff = max(currDiff, abs(heights[currX][currY] - heights[newX][newY]));
                    diff[newX][newY] = min(diff[newX][newY], maxDiff);
                    mini.push({diff[newX][newY], {newX, newY}});
                }
            }
        }
        return diff[destX][destY];
    }
};
int main()
{
    return 0;
}