class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        
        vector<int>freq(26,0);
        for(int i=0;i<n;i++)  freq[s[i]-'a']++;
        
        // stack for robot to hold the t string as in first operation of problem
        stack<char>st;
        // store the pattern written by robot
        string ans="";
        
        for(int i=0;i<n;i++){
            // give char to array
            st.push(s[i]);
            // reduce curr char frequency
            freq[s[i]-'a']--;
            // get the min freq element in vector
            char _min=getMin(freq);
            // write all elements which are lexicographically smaller than _min
            while(!st.empty()&&st.top()<=_min){
                ans+=st.top();
                st.pop();
            }
        }
         // while(!st.empty()){
         //        ans+=st.top();
         //        st.pop();
         //    }
        
        return ans;
    }
    char getMin(vector<int>&freq){
        for(int i=0;i<26;i++){
            if(freq[i]){
                return (i+'a');
            }
        } 
        return 'z';
    }
};
// Question Link:
// https://leetcode.com/problems/using-a-robot-to-print-the-lexicographically-smallest-string/
