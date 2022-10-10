class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char,int> m;
        for(auto it : p)
        {
            m[it]++;
        }
        int k=p.size();
        int cnt=m.size();
        int i=0;
        int j=0;
        while(j<s.size())
        {    
            if(m.count(s[j]))
            {
              m[s[j]]--;
                if(m[s[j]]==0)
                    cnt--;
            }
            if((j-i+1)<k)
                j++;
            else if((j-i+1)==k)
            {
                if(cnt==0)
                    res.push_back(i);
                if(m.count(s[i]))
                {
                    m[s[i]]++;
                    if(m[s[i]]==1)
                     cnt++;
                }
                i++;
                j++;
            }
        }
        return res;
    }
};
// question link :- https://leetcode.com/problems/find-all-anagrams-in-a-string/
