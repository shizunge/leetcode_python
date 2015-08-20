class Solution:
	# @param {integer[]} nums
	# @param {integer} target
	# @return {integer[]}
	def twoSum(self, nums, target):
		dict = {}
		for i in xrange(len(nums)):
			x = nums[i]
			if target-x in dict:
				return (dict[target-x]+1, i+1)
			dict[x] = i
