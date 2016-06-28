# Given an array of integers, find two numbers such that they add up to a specific target number.
# 
# The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
# 
# You may assume that each input would have exactly one solution.
# 
# Input: numbers={2, 7, 11, 15}, target=9
# Output: index1=0, index2=1
# 
class Solution:
	# @param {integer[]} nums
	# @param {integer} target
	# @return {integer[]}
	def twoSum(self, nums, target):
		dict = {}
		for i in xrange(len(nums)):
			x = nums[i]
			if target-x in dict:
				return (dict[target-x], i)
			dict[x] = i
