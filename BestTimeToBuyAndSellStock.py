class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        profit = 0
        if not prices or len(prices) == 1:
            return profit
        
        left = 0
        right = 1

        while right != len(prices):
            if prices[left] < prices[right]:
                profit = max(profit, prices[right] - prices[left])
                right += 1
            else:
                left += 1
                if left == right:
                    right += 1

        return profit
    
    # [7,1,5,3,6,4]