class Solution(object):
	def findMedianSortedArrays(self, nums1, nums2):
		"""
		:type nums1: List[int]
		:type nums2: List[int]
		:rtype: float
		"""
		rt1=0
		rt2=0
		if (len(nums2)==0):
		    if (len(nums1)%2==1) :
		        rt1=nums1[len(nums1)/2]
		        rt2=rt1
		    else:
		        rt1=nums1[len(nums1)/2-1]
		        rt2=nums1[len(nums1)/2]
		elif (len(nums1)==0):
		    if (len(nums2)%2==1) :
		        rt1=nums2[len(nums2)/2]
		        rt2=rt1
		    else:
		        rt1=nums2[len(nums2)/2-1]
		        rt2=nums2[len(nums2)/2]
		else:
		    len1=len(nums1)
		    len2=len(nums2)
		    tlen=(len1+len2)
		    #target
		    if (tlen%2==1):
		        mid1=tlen/2
		        mid2=mid1
		    elif:
		        mid1=tlen/2-1
		        mid2=tlen/2
		    ridx1=len1/2
		    ridx2=len2/2
		    while (ridx1!=mid1 && ridx2!=mid2):

		return (rt1+rt2)/2
				
