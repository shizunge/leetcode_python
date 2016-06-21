class Solution(object):
    def countNumbersWithUniqueDigits(self, n):
		"""
		:type n: int
		:rtype: int
		"""
		"""
		0: 1
		1: 10 = 9 + 1
		2: 91 = 9*(9) + 10
		3: 739 = 9*(9*8) + 91
		4: 5275 = 9*(9*8*7) + 739
		"""
		if (n>10):
			return 0
		if (n==0):
			return 1
		total = 1
		for i in range(n):
			subtotal = 1
			for j in range(9, 9-i, -1):
				subtotal = subtotal * j
			total = 9 * subtotal + total
		return total
