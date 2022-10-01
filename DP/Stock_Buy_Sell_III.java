class Solution {
    int helper(int[] prices, int i, int buy, Integer[][][] dp, int cap) {
        if(i == prices.length)
            return 0;
        if(cap == 0)
            return 0;
        if(dp[i][buy][cap] != null)
            return dp[i][buy][cap];
        int profit=0;
        if(buy==1) 
            profit=Math.max(-prices[i]+helper(prices, i+1, 0, dp, cap),
                           0+helper(prices, i+1, 1, dp, cap)); 
        else 
            profit=Math.max(prices[i]+helper(prices, i+1, 1, dp, cap-1),
                            0+helper(prices, i+1, 0, dp, cap)); 
        return dp[i][buy][cap]=profit;
    }
    public int maxProfit(int[] prices) {
        int n=prices.length;
        Integer[][][] dp=new Integer[n][2][3];
        return helper(prices, 0, 1, dp, 2);
    }
}



// question link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
