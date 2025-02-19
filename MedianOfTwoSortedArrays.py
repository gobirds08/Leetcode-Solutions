class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        even = False
        total_length = len(nums1) + len(nums2)
        middle_index = int((total_length - 1)/ 2)
        if total_length % 2 == 0:
            even = True
            middle_index += 1
        
        i = 0
        prev = 0
        current = 0
        while i <= middle_index:
            prev = current
            if(len(nums1) != 0 and len(nums2) != 0):
                if nums1[0] <= nums2[0]:
                    current = nums1.pop(0)
                else:
                    current = nums2.pop(0)
            elif(len(nums1) == 0):
                current = nums2.pop(0)
            else:
                current = nums1.pop(0)
            i += 1

        result = 0.0
        if even:
            result = (float(prev) + float(current)) / 2
        else:
            result = current
        return result
            
        