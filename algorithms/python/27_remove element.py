class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        if (len(nums)<=0):
            return 0
        if (len(nums)==1):
            if (nums[0]==val):
                return 0
            else:
                return 1
        idx1=0
        idx2=0
        while(idx2<len(nums)):
            while(idx1<len(nums) and nums[idx1]!=val):
                idx1+=1
            if(idx2<=idx1):
                idx2=idx1+1
            while(idx2<len(nums) and nums[idx2]==val):
                idx2+=1
            if(idx2>=len(nums)):
                break
            tmp=nums[idx1]
            nums[idx1]=nums[idx2]
            nums[idx2]=tmp
        #print(len(nums))
        #print(idx1)
        return idx1
