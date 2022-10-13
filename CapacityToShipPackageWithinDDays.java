/*
    Question link:
    https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
*/
class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int sum = 0, max = 0;
        for(int wt : weights){
            sum += wt;
            max = Math.max(wt, max);
        }
        
        int left = max, right = sum;
        
        while(left < right){
            int mid = (left + right)/2;
            int need = 1, curr = 0;
            for(int wt : weights){
                if(curr + wt > mid){
                    need += 1;
                    curr = 0;
                }
                curr += wt;
            }
            if(need > days){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return right;
    }
}