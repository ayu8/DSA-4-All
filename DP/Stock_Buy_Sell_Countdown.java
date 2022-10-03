class Solution {
    int helper(int[] prices, int i, int buy, Integer[][] dp) {
        if(i >= prices.length)
            return 0;
        if(dp[i][buy] != null)
            return dp[i][buy];
        int profit=0;
        if(buy==1) 
            profit=Math.max(-prices[i]+helper(prices, i+1, 0, dp),
                           0+helper(prices, i+1, 1, dp)); 
        else 
            profit=Math.max(prices[i]+helper(prices, i+2, 1, dp),
                            0+helper(prices, i+1, 0, dp)); 
        return dp[i][buy]=profit;
    }
    public int maxProfit(int[] prices) {
        int n=prices.length;
        Integer[][] dp=new Integer[n][2];
        return helper(prices, 0, 1, dp);
    }
}



// question link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/
