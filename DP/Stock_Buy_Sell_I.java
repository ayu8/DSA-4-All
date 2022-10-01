class Solution {
    public int maxProfit(int[] a) {
        int mini=a[0], profit=0;
        for(int i=1; i<a.length; i++) {
            int diff=a[i]-mini;
            profit=Math.max(profit, diff);
            mini=Math.min(mini, a[i]);
        }
        return profit;
    }
}



// question link:
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
