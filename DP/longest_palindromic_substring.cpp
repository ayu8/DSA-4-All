//problem link: https://leetcode.com/problems/longest-palindromic-substring/description/

class Solution {
private:   
    bool Palindrome(int a, int b,string &s) {
        if (a >= b)
            return true;
        return (s[a] == s[b] && Palindrome(a + 1, b - 1,s));
    }
    
public:    
    string longestPalindrome(string s) {
        int size = s.size();
        for (int i = size; i >= 1; i--) { 
			for (int j = 0; j <= size - i; j++) {
                int d = j + i - 1;
				if (Palindrome(j, d,s)) {
					return s.substr(j, i);
                }
            }
        }
        return "";
    }
};

