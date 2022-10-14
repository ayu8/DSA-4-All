/*
    Question link:
    https://www.interviewbit.com/problems/allocate-books/
*/
public class Solution {
    public int books(int[] A, int B) {
        
        int res = -1;
        int n = A.length;
        
        if(B > n)
            return -1;
            
        int low = A[0], high = 0;
        for(int x : A){
            low = Math.min(low, x);
            high += x;
        }
        
        while(low <= high){
            int mid = low + ((high - low) >> 1);
            
            if(isPossible(A, mid, B)){
                res = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return res;
    }
    boolean isPossible(int[] A, int pages, int stduents){
        int count = 0;
        int sumAllocated = 0;
        
        for(int x : A){
            if(sumAllocated + x > pages){
                count++;
                sumAllocated = x;
                if(sumAllocated > pages) return false;
            }else{
                sumAllocated += x;
            }
        }
        if(count < stduents) return true;
        else return false;
    }
}
