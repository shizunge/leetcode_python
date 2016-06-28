# Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
# 
# Note:
# 
#     Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
#     The solution set must not contain duplicate triplets.
# 
#     For example, given array S = {-1 0 1 2 -1 -4},
# 
#     A solution set is:
#     (-1, 0, 1)
#     (-1, -1, 2)
# 
class Solution:
	# @param {integer[]} nums
	# @return {integer[][]}
	def threeSum(self, nums):
		# small to large
		nums.sort()
		result = []
		for i in range(len(nums)-2):
			# pick up the first element
			if i == 0 or nums[i] > nums[i-1]:
				# search boundary
				left = i + 1
				right = len(nums) - 1
				while (left < right):
					if (nums[left] + nums[right] == -nums[i]):
						result.append([nums[i], nums[left], nums[right]])
						left += 1
						right -= 1
						while (left < right and nums[left] == nums[left-1]): 
							left +=1
						while (left < right and nums[right] == nums[right+1]): 
							right -= 1
					elif (nums[left] + nums[right] < -nums[i]):
						while left < right:
							left += 1
							if nums[left] > nums[left-1]: 
								break
					else:
						while left < right:
							right -= 1
							if nums[right] < nums[right+1]: 
								break
		return result

