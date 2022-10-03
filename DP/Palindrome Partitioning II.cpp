class Solution {
public:
     int dp[2005][2005];
    int dp1[2005][2005];
   
	bool isPalindrome(string& s, int i, int j) {
		if (i >= j)
            return true;
		if (dp1[i][j] != -1) 
            return dp1[i][j];
		if (s[i] == s[j]) 
            return dp1[i][j] = isPalindrome(s, i + 1, j - 1);
		return dp1[i][j] = false;
	}

	int solve(string s, int i, int j){
		if(i>=j) 
          return 0;
		if(dp[i][j]!=-1)
            return dp[i][j];
		if(isPalindrome(s,i,j)) 
            return 0;
		int mn = INT_MAX;
		for(int k=i;k<=j-1;k++){
			if(isPalindrome(s,i,k)) 
                mn = min(mn, 1+solve(s,k+1,j));
            dp[i][j] = mn;
		}
        
		return dp[i][j];
	}

    int minCut(string s) {
        int l=s.length();
        memset(dp,-1,sizeof(dp));
        memset(dp1,-1,sizeof(dp1));
       int ans=solve(s,0,l-1);
        return ans;
        
    }
};
