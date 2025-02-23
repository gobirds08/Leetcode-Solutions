class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        open_index = 1
        nums_size = len(nums)

        for i in range(1, nums_size):
            if nums[i] > nums[i - 1]:
                nums[open_index] = nums[i]
                open_index += 1
        
        return open_index
            
            

    

if __name__ == '__main__':
    solution = Solution()
    # print(solution.removeDuplicates([0,0,1,1,1,2,2,3,3,4]))
    # nums = [1,1,1,2,2]
    # print(solution.removeDuplicates(nums))
    # print(nums)
    # print(solution.removeDuplicates([1,2,3,3]))
    print(solution.removeDuplicates([1,2,3]))