/*
    Q:Chocolate Distribution Problem

   link : https://practice.geeksforgeeks.org/problems/chocolate-distribution-problem3825/1
*/

// optimsed code
long long findMinDiff(vector<long long> a, long long n, long long m)
{
    // code
    sort(a.begin(), a.end());
    long long min = LLONG_MAX;
    // 1 3 4 7 9 9 12 56       3
    for (long long i = 0; i <= a.size() - m; i++)
    {
        if (a[m + i - 1] - a[i] < min)
        {
            min = a[m + i - 1] - a[i];
        }
    }
    return min;
}
