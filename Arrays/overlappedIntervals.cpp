/*
    Q: overlapping intervals

    link: https://practice.geeksforgeeks.org/problems/overlapping-intervals

*/

class Solution
{
public:
    // brute force (n^2)
    bool isOverlap(int minS, int maxE, vector<int> interval)
    {
        if (minS > interval[1] || maxE < interval[0])
        {
            return false;
        }

        return true;
    }

    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> res;

        vector<bool> vis(n, false);

        for (int i = 0; i < n; i++)
        {
            if (vis[i])
            {
                continue;
            }

            vis[i] = true;
            int minS = intervals[i][0];
            int maxE = intervals[i][1];

            while (true)
            {
                int cnt = 0;

                for (int j = 0; j < n; j++)
                {
                    if (!vis[j] && isOverlap(minS, maxE, intervals[j]))
                    {
                        vis[j] = true;
                        minS = min(minS, intervals[j][0]);
                        maxE = max(maxE, intervals[j][1]);
                        cnt++;
                    }
                }

                if (cnt == 0)
                {
                    break;
                }
            }

            vector<int> interval = {minS, maxE};
            res.push_back(interval);
        }

        sort(res.begin(), res.end());
        return res;
    }

    // optimised code
    vector<vector<int>> overlappedInterval(vector<vector<int>> &intervals)
    {

        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());

        int mn = intervals[0][0], mx = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++)
        {

            if (mx >= intervals[i][0])
            {
                mx = max(intervals[i][1], mx);
            }
            else
            {
                ans.push_back({mn, mx});
                mn = intervals[i][0];
                mx = intervals[i][1];
            }
        }

        ans.push_back({mn, mx});

        return ans;
    }
};