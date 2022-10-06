// LeetCode Problem Link: https://leetcode.com/problems/valid-anagram/


class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s==t){
            return true;
        }
        return false;
    }
};