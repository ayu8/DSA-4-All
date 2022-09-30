class Solution {
    public int maxEnvelopes(int[][] arr) {
    //sort the array on the basis of width
        Arrays.sort(arr, new java.util.Comparator<int[]>() {
    public int compare(int[] a, int[] b) {
        return Integer.compare(a[0], b[0]);
    }
}); 
        //find Longest increasing subsequence on the basis of height
    int dp[]=new int[arr.length];
     int omax=0;
       for(int i=0;i<arr.length;i++){
           int max=0;
          for(int j=0;j<i;j++){
              if(arr[j][1]<arr[i][1] && arr[j][0]<arr[i][0]){
                  if(dp[j]>max){
                      max=dp[j];
                  }
              }
          }
           dp[i]=max+1;
           if(dp[i]>omax){
               omax=dp[i];
           }
       } 
        return omax;
    }
}

// question link:
// https://leetcode.com/problems/russian-doll-envelopes/
