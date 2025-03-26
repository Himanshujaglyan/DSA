#include <iostream>
#include <vector>
using namespace std;

// GFG(MINIMUM COST OF ROPES)
int minCost(vector<int> &arr)
{
    priority_queue<int, vector<int>, greater<int>> mini;
    for (auto el : arr)
    {
        mini.push(el);
    }
    int sum = 0;
    while (mini.size() != 1)
    {
        int top1 = mini.top();
        mini.pop();
        int top2 = mini.top();
        mini.pop();
        sum += top1 + top2;
        mini.push(top1 + top2);
    }
    return sum;
}

// GFG (FRACTIONAL KNAPSACK)
double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    priority_queue<pair<double, int>> maxi;
    for (int i = 0; i < val.size(); i++)
    {
        double ratio = val[i] / double(wt[i]);
        maxi.push({ratio, i});
    }
    double ans = 0;
    while (!maxi.empty() && capacity > 0)
    {
        auto top = maxi.top();
        maxi.pop();
        double ratio = top.first;
        int value = val[top.second];
        int weight = wt[top.second];

        if (weight <= capacity)
        {
            capacity -= weight;
            ans += value;
        }
        else
        {
            double temp = ratio * capacity;
            ans += temp;
            capacity = 0;
        }
    }
    return ans;
}

// GFG (N MEETINGS IN A ROOM)
int maxMeetings(vector<int> &start, vector<int> &end)
{
    vector<pair<int, int>> v;
    for (int i = 0; i < start.size(); i++)
    {
        v.push_back({end[i], start[i]});
    }
    sort(v.begin(), v.end());
    int count = 1;
    int endTime = v[0].first;
    int index = 1;
    while (index < v.size())
    {
        if (v[index].second > endTime)
        {
            endTime = v[index].first;
            count++;
        }
        index++;
    }
    return count;
}
int main()
{
    // GREEDY ALGO FOCUSES ON THE LOCAL OPTIMUM i.e MOST OPTIMUM SOLUTION AT THIS MOMENT
    // DATA STRUCTURE FOR GREEDY :- PRIORITY-QUEUE, SET, SORTING

    // SPOJ (DEFKIN :- DEFENSE OF A KINGDOM)
    int row = 8;
    int col = 15;
    int tower = 3;
    vector<pair<int, int>> loc(tower);
    loc[0] = {3, 8};
    loc[1] = {11, 2};
    loc[2] = {8, 6};

    vector<int> xDim;
    xDim.push_back(0);
    xDim.push_back(col + 1);
    for (int i = 0; i < 3; i++)
    {
        xDim.push_back(loc[i].first);
    }
    sort(xDim.begin(), xDim.end());

    vector<int> yDim;
    yDim.push_back(0);
    yDim.push_back(row + 1);
    for (int i = 0; i < 3; i++)
    {
        yDim.push_back(loc[i].second);
    }
    sort(yDim.begin(), yDim.end());

    int maxX = INT_MIN;
    for (int i = 1; i < xDim.size(); i++)
    {
        int diff = xDim[i] - xDim[i - 1] - 1;
        maxX = max(maxX, diff);
    }
    int maxY = INT_MIN;
    for (int i = 1; i < yDim.size(); i++)
    {
        int diff = yDim[i] - yDim[i - 1] - 1;
        maxY = max(maxY, diff);
    }

    cout << "Answer: " << maxX * maxY << endl;
    return 0;
}