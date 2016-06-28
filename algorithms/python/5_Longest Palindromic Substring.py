# // Source : https://oj.leetcode.com/problems/longest-palindromic-substring/
# 
# /********************************************************************************** 
# * 
# * Given a string S, find the longest palindromic substring in S. 
# * You may assume that the maximum length of S is 1000, 
# * and there exists one unique longest palindromic substring.
# *               
# **********************************************************************************/
# runtime : 1232ms
class Solution(object):
	def longestPalindrome(self, s):
		"""
		:type s: str
		:rtype: str
		"""
		"""
		input : a
		output : a
		input : bb
		output : bb
		input : abb
		output : bb
		input : aaabaaaa
		output : aaabaaa
		"""
		length = len(s)
		if (length<=1):
			return s
		oddradian = 0
		oddmididx = 0
		evenradian = 0
		evenmididx = 0
		for i in range(length):
			maxoddradian = min(i-0, length-1-i)
			maxevenradian = min(i-0+1, length-1-i)
			for j in range(1, maxevenradian+1, 1):
				# check even length palindrome
				subleft = s[i+1-j]
				subright = s[i+j]
				if (subleft==subright):
					if (j>evenradian):
						evenradian = j
						evenmididx = i
				else:
					break
			for j in range(1, maxoddradian+1, 1):
				# check odd length palindrome
				# excluding single char (radian=0)
				subleft = s[i-j]
				subright = s[i+j]
				if (subleft==subright):
					if (j>oddradian):
						oddradian = j
						oddmididx = i
				else:
					break
		if ((2*evenradian)>(2*oddradian+1)):
			# even len > odd len
			return s[evenmididx-evenradian+1:evenmididx+evenradian+1]
		else:
			# even len < odd len
			return s[oddmididx-oddradian:oddmididx+oddradian+1]
