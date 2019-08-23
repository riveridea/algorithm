#
# @lc app=leetcode id=327 lang=python
#
# [327] Count of Range Sum
#
# https://leetcode.com/problems/count-of-range-sum/description/
#
# algorithms
# Hard (33.35%)
# Total Accepted:    33.9K
# Total Submissions: 101.6K
# Testcase Example:  '[-2,5,-1]\n-2\n2'
#
# Given an integer array nums, return the number of range sums that lie in
# [lower, upper] inclusive.
# Range sum S(i, j) is defined as the sum of the elements in nums between
# indices i and j (i ≤ j), inclusive.
# 
# Note:
# A naive algorithm of O(n2) is trivial. You MUST do better than that.
# 
# Example:
# 
# 
# Input: nums = [-2,5,-1], lower = -2, upper = 2,
# Output: 3 
# Explanation: The three ranges are : [0,0], [2,2], [0,2] and their respective
# sums are: -2, -1, 2.
# 
#
class Solution(object):
    def countRangeSum(self, nums, lower, upper):
        """
        :type nums: List[int]
        :type lower: int
        :type upper: int
        :rtype: int
        """
        sums = nums[:]
        for x in range(1, len(sums)):
            sums[x] += sums[x - 1]
        osums = sorted(set(sums))
        ft = FenwickTree(len(osums))
        ans = 0
        for sumi in sums:
            left = bisect.bisect_left(osums, sumi - upper)
	    print left
            right = bisect.bisect_right(osums, sumi - lower)
	    print right
            ans += ft.sum(right) - ft.sum(left) + (lower <= sumi <= upper)
	    print ans
            ft.add(bisect.bisect_right(osums, sumi), 1)
        return ans

class FenwickTree(object):
    def __init__(self, n):
        self.n = n
        self.sums = [0] * (n + 1)
    def add(self, x, val):
        while x <= self.n:
            self.sums[x] += val
            x += self.lowbit(x)
    def lowbit(self, x):
        return x & -x
    def sum(self, x):
        res = 0
        while x > 0:
            res += self.sums[x]
            x -= self.lowbit(x)
        return res
        
