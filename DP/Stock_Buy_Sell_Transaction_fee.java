class Solution {
    int helper(int[] prices, int i, int buy, Integer[][] dp, int fee) {
        if(i == prices.length)
            return 0;
        if(dp[i][buy] != null)
            return dp[i][buy];
        int profit=0;
        if(buy==1) 
            profit=Math.max(-prices[i]+helper(prices, i+1, 0, dp, fee),
                           0+helper(prices, i+1, 1, dp, fee)); 
        else 
            profit=Math.max(prices[i]-fee+helper(prices, i+1, 1, dp, fee),
                            0+helper(prices, i+1, 0, dp, fee)); 
        return dp[i][buy]=profit;
    }
    public int maxProfit(int[] prices, int fee) {
        int n=prices.length;
        Integer[][] dp=new Integer[n][2];
        return helper(prices, 0, 1, dp, fee);
    }
}



// question link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
