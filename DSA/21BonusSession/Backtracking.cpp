#include <iostream>
#include <unordered_set>
using namespace std;

// LEETCODE 1079 (LETTER TILE POSSIBILITIES)
int solve(vector<int> &freq)
{
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i])
        {
            freq[i]--;
            ans += 1 + solve(freq);
            freq[i]++;
        }
    }
    return ans;
}

int numTilePossibilities(string tiles)
{
    vector<int> freq(26, 0);
    for (char &ch : tiles)
    {
        freq[ch - 'A']++;
    }
    return solve(freq);
}

// LEETCODE 17 (LETTER COMBINATIONS OF A PHONE NUMBER)
void solve(string &digits, int &index, string &output, string mapping[], vector<string> &ans)
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    int digit = digits[index++] - '0';
    string temp = mapping[digit];
    for (char &ch : temp)
    {
        output.push_back(ch);
        solve(digits, index, output, mapping, ans);
        output.pop_back();
    }
    index--;
}

vector<string> letterCombinations(string digits)
{
    if (digits == "")
        return {};
    string mapping[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    vector<string> ans;
    int index = 0;
    solve(digits, index, output, mapping, ans);
    return ans;
}

// LEETCODE 301 (REMOVE INVALID PARENTHESIS)
void solve(string &s, int index, int open, int close, int balance, string &output, unordered_set<string> &ans)
{
    if (index >= s.length())
    {
        if (open == 0 && close == 0 && balance == 0)
        {
            ans.insert(output);
        }
        return;
    }
    char ch = s[index];
    if (ch != '(' && ch != ')')
    {
        output.push_back(ch);
        solve(s, index + 1, open, close, balance, output, ans);
        output.pop_back();
    }
    else if (ch == '(')
    {
        // include
        output.push_back(ch);
        solve(s, index + 1, open, close, balance + 1, output, ans);
        output.pop_back();
        // exclude
        if (open > 0)
        {
            solve(s, index + 1, open - 1, close, balance, output, ans);
        }
    }
    else if (ch == ')')
    {
        // include
        if (balance > 0)
        {
            output.push_back(ch);
            solve(s, index + 1, open, close, balance - 1, output, ans);
            output.pop_back();
        }
        // exclude
        if (close > 0)
        {
            solve(s, index + 1, open, close - 1, balance, output, ans);
        }
    }
}

vector<string> removeInvalidParentheses(string s)
{
    int invalidOpen = 0;
    int invalidClose = 0;
    for (char &ch : s)
    {
        if (ch == '(')
        {
            invalidOpen++;
        }
        else if (ch == ')')
        {
            if (invalidOpen > 0)
            {
                invalidOpen--;
            }
            else
            {
                invalidClose++;
            }
        }
    }
    unordered_set<string> ans;
    int index = 0;
    string output = "";
    int balance = 0;
    solve(s, index, invalidOpen, invalidClose, balance, output, ans);
    return vector<string>(ans.begin(), ans.end());
}

// LEETCODE 51 (N-QUEENS)
class Solution
{
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> topDiagonal;
    unordered_map<int, bool> bottomDiagonal;
    bool isSafe(int &row, int &col)
    {
        if (rowCheck[row] || topDiagonal[col - row] || bottomDiagonal[row + col])
            return false;
        return true;
    }

    void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans)
    {
        vector<string> tempAns;
        for (auto &vec : board)
        {
            string temp = "";
            for (auto &ch : vec)
            {
                temp.push_back(ch);
            }
            tempAns.push_back(temp);
        }
        ans.push_back(tempAns);
    }
    void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int &n, int col)
    {
        if (col >= n)
        {
            storeSolution(board, ans);
        }
        for (int row = 0; row < n; row++)
        {
            if (isSafe(row, col))
            {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                topDiagonal[col - row] = true;
                bottomDiagonal[row + col] = true;

                solve(board, ans, n, col + 1);

                board[row][col] = '.';
                rowCheck[row] = false;
                topDiagonal[col - row] = false;
                bottomDiagonal[row + col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<char>> board(n, vector<char>(n, '.'));
        vector<vector<string>> ans;
        solve(board, ans, n, 0);
        return ans;
    }
};

// LEETCODE 37 (SUDOKU SOLVER)
bool isSafe(int &row, int &col, char &ch, vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        if (board[i][col] == ch)
        {
            return false;
        }
        if (board[row][i] == ch)
        {
            return false;
        }
        // if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch)
        //     return false;
    }

    int startRow = (row / 3) * 3;
    int startCol = (col / 3) * 3;

    for (int i = startRow; i < startRow + 3; i++)
    {
        for (int j = startCol; j < startCol + 3; j++)
        {
            if (board[i][j] == ch)
            {
                return false;
            }
        }
    }

    return true;
}

bool solve(vector<vector<char>> &board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (board[i][j] == '.')
            {
                for (char ch = '1'; ch <= '9'; ch++)
                {
                    if (isSafe(i, j, ch, board))
                    {
                        board[i][j] = ch;
                        bool recAns = solve(board);
                        if (recAns)
                            return true;
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}
int main()
{
    return 0;
}