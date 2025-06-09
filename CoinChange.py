class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        num_coins = [0 for _ in range(amount + 1)]
        
        for i in range(1, amount + 1):
            for coin in coins:
                if i - coin >= 0:
                    num_coins[i] = min(num_coins[i], num_coins[i - coin] + 1)
        
        return num_coins[amount]