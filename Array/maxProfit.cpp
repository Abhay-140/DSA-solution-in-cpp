/*
    Q; Best time to buy and sell stock

    link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

// brute force
int maxProfit(vector<int> &prices)
{

    int max = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            if (prices[j] - prices[i] > max)
                max = prices[j] - prices[i];
        }
    }
    return max;
}

// optimized approach

int maxProfit(vector<int> &prices)
{

    int max = 0, l = 0;

    for (int i = 1; i < prices.size(); i++)
    {
        if (prices[l] < prices[i] && max < prices[i] - prices[l])
        {
            max = prices[i] - prices[l];
        }
        else if (prices[l] > prices[i])
        {
            l = i;
        }
    }
    return max;
}
