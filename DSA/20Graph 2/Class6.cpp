#include <iostream>
using namespace std;

// LEETCODE 547 (NUMBER OF PROVINCES)
void dfs(int src, vector<vector<int>> &isConnected, vector<bool> &visited)
{
    visited[src] = true;
    for (int i = 0; i < isConnected[0].size(); i++)
    {
        if (isConnected[src][i] == 1 && !visited[i])
        {
            dfs(i, isConnected, visited);
        }
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    vector<bool> visited(isConnected.size(), false);
    int provinces = 0;
    for (int i = 0; i < isConnected.size(); i++)
    {
        if (!visited[i])
        {
            provinces++;
            dfs(i, isConnected, visited);
        }
    }
    return provinces;
}

// LEETCODE 200 (NUMBER OF ISLANDS)
void solve(vector<vector<char>> &grid, vector<vector<bool>> &visited, int row, int col)
{
    if (row >= grid.size() || col >= grid[0].size() || grid[row][col] == '0' || visited[row][col] || row < 0 || col < 0)
    {
        return;
    }
    visited[row][col] = true;
    solve(grid, visited, row + 1, col);
    solve(grid, visited, row - 1, col);
    solve(grid, visited, row, col + 1);
    solve(grid, visited, row, col - 1);
}

int numIslands(vector<vector<char>> &grid)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    int islands = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '1' && !visited[i][j])
            {
                islands++;
                solve(grid, visited, i, j);
            }
        }
    }
    return islands;
}

// BABBAR CODE
bool isSafe(int x, int y, vector<vector<char>> &grid)
{
    return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size());
}

void bfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    while (!q.empty())
    {
        auto front = q.front();
        q.pop();
        int currX = front.first;
        int currY = front.second;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = currX + dx[i];
            int newY = currY + dy[i];
            if (isSafe(newX, newY, grid) && !visited[newX][newY] && grid[newX][newY] == '1')
            {
                q.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
    }
}

int numIslands(vector<vector<char>> &grid)
{
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    int count = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (!visited[i][j] && grid[i][j] == '1')
            {
                count++;
                bfs(i, j, grid, visited);
            }
        }
    }
    return count;
}

// LEETCODE 733 (FLOOD FILL)
bool isSafe(int x, int y, vector<vector<int>> &ans)
{
    return (x >= 0 && y >= 0 && x < ans.size() && y < ans[0].size());
}

void dfs(int x, int y, vector<vector<int>> &ans, int &oldColor, int &newColor)
{
    ans[x][y] = newColor;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (isSafe(newX, newY, ans) && ans[newX][newY] == oldColor)
        {
            dfs(newX, newY, ans, oldColor, newColor);
        }
    }
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    int oldColor = image[sr][sc];
    int newColor = color;
    if (oldColor == newColor)
        return image;
    vector<vector<int>> ans(image);
    dfs(sr, sc, ans, oldColor, newColor);
    return ans;
}

// LEETCODE 994 (ROTTING ORANGES)
bool isSafe(int x, int y, vector<vector<int>> &grid)
{
    return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size());
}

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    int freshOrange = 0;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 1)
            {
                freshOrange++;
            }
            else if (grid[i][j] == 2)
            {
                q.push({i, j});
            }
        }
    }
    if (freshOrange == 0)
        return 0;
    int minutes = 0;
    q.push({-1, -1});
    while (!q.empty())
    {
        pair<int, int> top = q.front();
        q.pop();
        if (top.first == -1 && top.second == -1)
        {
            minutes++;
            if (!q.empty())
            {
                q.push({-1, -1});
            }
        }
        else
        {
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = top.first + dx[i];
                int newY = top.second + dy[i];
                if (isSafe(newX, newY, grid) && grid[newX][newY] == 1)
                {
                    freshOrange--;
                    grid[newX][newY] = 2;
                    q.push({newX, newY});
                    if (freshOrange == 0)
                    {
                        return minutes + 1;
                    }
                }
            }
        }
    }
    return freshOrange == 0 ? minutes : -1;
}

// BABBAR CODE
bool isSafe(int x, int y, vector<vector<int>> &grid)
{
    return (x >= 0 && y >= 0 && x < grid.size() && y < grid[0].size());
}

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<pair<int, int>, int>> q; // coordinate, time
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
            }
        }
    }
    vector<vector<int>> &temp = grid;
    int minTime = 0;
    while (!q.empty())
    {
        auto top = q.front();
        q.pop();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = top.first.first + dx[i];
            int newY = top.first.second + dy[i];
            if (isSafe(newX, newY, temp) && temp[newX][newY] == 1)
            {
                temp[newX][newY] = 2;
                q.push({{newX, newY}, top.second + 1});
                minTime = top.second + 1;
            }
        }
    }
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (temp[i][j] == 1)
            {
                return -1;
            }
        }
    }
    return minTime;
}

// LAKSHAY CODE
void dfs(vector<vector<int>> &grid, int i, int j, int min)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || (grid[i][j] < min && grid[i][j] > 1))
    {
        return;
    }
    grid[i][j] = min;
    dfs(grid, i + 1, j, min + 1);
    dfs(grid, i - 1, j, min + 1);
    dfs(grid, i, j + 1, min + 1);
    dfs(grid, i, j - 1, min + 1);
}

int orangesRotting(vector<vector<int>> &grid)
{
    int min = 2;
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == 2)
            {
                dfs(grid, i, j, min);
            }
        }
    }
    for (auto v : grid)
    {
        for (auto it : v)
        {
            if (it == 1)
                return -1;
            min = max(min, it);
        }
    }
    return min - 2;
}
int main()
{
    return 0;
}