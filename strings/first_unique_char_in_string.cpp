// https://leetcode.com/problems/first-unique-character-in-a-string/
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<math.h>
using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector <int> v(26,0);
        int n = s.length();
        for (int i=0; i<n; i++) {
            v[s[i]-97]++;
        }

        for (int i=0; i<n; i++) {
            if (v[s[i]-97] == 1) {
                return i;
            }
        }
        return -1;
    }
};