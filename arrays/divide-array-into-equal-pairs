class Solution {
    
public:
    bool divideArray(vector<int>& nums) {
        int num=nums.size()/2;
        map<int,int>mymap;
        for(int i=0;i<nums.size();i++)
        {
            mymap[nums[i]]++;
        }
        map<int,int>::iterator it;

        for(it=mymap.begin();it!=mymap.end();++it)
        {
            if(it->second%2)
                return false;
        }  
        return true;
    }
};
