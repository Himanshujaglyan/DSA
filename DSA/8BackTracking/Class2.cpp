#include <bits/stdc++.h>
using namespace std;

void printPermutations(string &str, int index)
{
    if (index >= str.length())
    {
        cout << str << " ";
        return;
    }
    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);
        printPermutations(str, index + 1);
        swap(str[index], str[j]); // backtracking
    }
}
bool isSafe(int maze[][4], int newx, int newy, int &row, int &col, vector<vector<bool>> &visited)
{
    if ((newx >= 0 && newx < row) &&
        (newy >= 0 && newy < col) &&
        maze[newx][newy] != 0 &&
        visited[newx][newy] != true)
    {
        return true;
    }
    return false;
}

void printAllPaths(int maze[][4], int &row, int &col, string &output, int x, int y, vector<vector<bool>> &visited)
{
    // base case
    if (x == row - 1 && y == col - 1)
    {
        cout << output << endl;
        return;
    }

    // UP
    int newx = x - 1;
    int newy = y;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('U');
        printAllPaths(maze, row, col, output, newx, newy, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // DOWN
    newx = x + 1;
    newy = y;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('D');
        printAllPaths(maze, row, col, output, newx, newy, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // RIGHT
    newx = x;
    newy = y + 1;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('R');
        printAllPaths(maze, row, col, output, newx, newy, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
    // LEFT
    newx = x;
    newy = y - 1;
    if (isSafe(maze, newx, newy, row, col, visited))
    {
        visited[newx][newy] = true;
        output.push_back('L');
        printAllPaths(maze, row, col, output, newx, newy, visited);
        output.pop_back();
        visited[newx][newy] = false;
    }
}
int main()
{

    // string str = "abc";
    // int index = 0;
    // printPermutations(str, index);

    int maze[4][4] = {{1, 0, 0, 0},
                      {1, 1, 0, 0},
                      {1, 1, 1, 0},
                      {1, 1, 1, 1}};
    int row = 4;
    int col = 4;
    int x = 0;
    int y = 0;
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    string output = "";
    if (maze[0][0] == 0)
    {
        cout << "No Path Exist" << endl;
    }
    else
    {
        visited[x][y] = true;
        printAllPaths(maze, row, col, output, x, y, visited);
    }

    return 0;
}