// problem link:- 
// https://leetcode.com/problems/string-to-integer-atoi/
class Solution {
public:
    int myAtoi(string s) {
        if(s.length()==0) return 0;
        int i=0;
        while(i<s.length() && s[i]==' ') i++;
        s=s.substr(i);//it will go till i to i.size()
        int sign=+1;
        long ans=0;
        if(s[0]=='-') sign = -1;
        int maxi=INT_MAX, mini=INT_MIN;
        i = (s[0] == '+' || s[0] == '-') ? 1 : 0;
        //traversing through the remaining string
        while(i < s.length()){
            //if a space or a non digit character is encountered then break
            if(s[0] == ' ' || !isdigit(s[i])) break;
            //including the valid string chars in the ans
            ans = ans*10+s[i] - '0';
            
            if(sign == -1 && -1*ans < mini) return mini;
            if(sign == +1 && ans > maxi) return maxi;
            
            i++;
        }
        return (int)(sign*ans);
    }
};