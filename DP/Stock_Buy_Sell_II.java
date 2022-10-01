// RECURSION
// class Solution {
//     int helper(int[] prices, int i, boolean buy) {
//         if(i == prices.length)
//             return 0;
//         int profit=0;
//         if(buy) //we are buying here
//             profit=Math.max(-prices[i]+helper(prices, i+1, false), // take case 
//                            0+helper(prices, i+1, true)); // not take case
//         else // we are selling here
//             profit=Math.max(prices[i]+helper(prices, i+1, true), // take case
//                            0+helper(prices, i+1, false)); // not take case
//         return profit;
//     }
//     public int maxProfit(int[] prices) {
//         return helper(prices, 0, true);
//     }
// }




// RECURSION+MEMOIZATION
// class Solution {
//     int helper(int[] prices, int i, int buy, Integer[][] dp) {
//         if(i == prices.length)
//             return 0;
//         if(dp[i][buy] != null)
//             return dp[i][buy];
//         int profit=0;
//         if(buy==1) 
//             profit=Math.max(-prices[i]+helper(prices, i+1, 0, dp),
//                            0+helper(prices, i+1, 1, dp)); 
//         else 
//             profit=Math.max(prices[i]+helper(prices, i+1, 1, dp),
//                             0+helper(prices, i+1, 0, dp)); 
//         return dp[i][buy]=profit;
//     }
//     public int maxProfit(int[] prices) {
//         int n=prices.length;
//         Integer[][] dp=new Integer[n][2];
//         return helper(prices, 0, 1, dp);
//     }
// }



// TABULATION
// class Solution {
//     public int maxProfit(int[] prices) {
//         int n=prices.length;
//         int[][] dp=new int[n+1][2];
        
//         dp[n][0]=0;
//         dp[n][1]=0;
//         for(int i=n-1; i>=0; i--) {
//             for(int buy=0; buy<2; buy++) {
//                 int profit=0;
//                 if(buy==1)
//                     profit=Math.max(-prices[i]+dp[i+1][0], 0+dp[i+1][1]);
//                 else
//                     profit=Math.max(prices[i]+dp[i+1][1], 0+dp[i+1][0]);
//                 dp[i][buy]=profit;
//             }
//         }
//         return dp[0][1];
//     }
// }



class Solution {
    public int maxProfit(int[] prices) {
        int n=prices.length;
        int aheadNotBuy=0, aheadBuy=0, currBuy=0, currNotBuy=0;
        for(int i=n-1; i>=0; i--) {
            currBuy=Math.max(-prices[i]+aheadNotBuy, 0+aheadBuy);
            currNotBuy=Math.max(prices[i]+aheadBuy, 0+aheadNotBuy);
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        return aheadBuy;
    }
}



// question link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
