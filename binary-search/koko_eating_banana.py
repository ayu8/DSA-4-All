"""
Ques Link: https://leetcode.com/problems/koko-eating-bananas/
"""
from math import ceil

class Solution:
    def minEatingSpeed(self, piles, H):
        l, r = 0, max(piles)
        while l + 1 < r:
            mid = (l + r) // 2
            if sum(ceil(i / mid) for i in piles) > H:
                l = mid
            else:
                r = mid
                
        return r
