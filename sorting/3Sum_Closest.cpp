int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        
        sort(nums.begin(),nums.end());
        int ans=INT_MAX;
        int res=-1;
        
        for(int i=0;i<n-1;i++){
            int low=i+1,high=n-1;
            
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(abs(target-sum)<ans){
                    res=sum;
                    ans=abs(target-sum);
                }
                
                if(sum<target)
                    low++;
                else if(sum>target)
                    high--;
                else
                    return target;
            }
            while(i<n-1 && nums[i]==nums[i+1]) i++;
        }
        
        return res;
  }
