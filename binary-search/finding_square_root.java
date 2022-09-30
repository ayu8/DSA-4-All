//https://leetcode.com/problems/sqrtx/

class Solution {
    public int  mySqrt(int  x) {
	        if(x <= 1) return x;
        int start = 1, mid = 1, end = x/2;
        while(start<=end){
            mid = start + (end - start)/2;
            if(mid == x/mid) return mid;
            if(mid > x/mid) end = mid-1;
            else if(mid < x/mid) start = mid+1;
        }
        return end;
  
    }
}