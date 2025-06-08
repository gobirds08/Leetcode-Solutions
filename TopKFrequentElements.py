import heapq

class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        num_freq = {}
        for num in nums:
            if num in num_freq:
                num_freq[num] += 1
            else:
                num_freq[num] = 1
        
        pq = []
        
        for key, value in num_freq.items():
            heapq.heappush(pq, (-1 * value, key))
        
        i = 0
        output = []
        while i < k:
            output.append(heapq.heappop(pq)[1])
            i += 1
        
        return output
