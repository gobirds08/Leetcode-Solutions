import heapq

class Solution(object):
    def reorganizeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        pq = []
        letter_freq = {}

        for letter in s:
            if letter in letter_freq:
                letter_freq[letter] += 1
            else:
                letter_freq[letter] = 1
        
        for key, value in letter_freq.items():
            heapq.heappush(pq, (-1 * value, key))

        new_s = ""
        prev = None
        while pq:
            temp = []
            while True:
                priority, letter = heapq.heappop(pq)
                if letter != prev:
                    new_s += letter
                    if priority + 1 != 0:
                        heapq.heappush(pq, (priority + 1, letter))
                    prev = letter
                    break

                temp.append((priority, letter))

                if not pq:
                    return ""

            while temp:
                heapq.heappush(pq, temp.pop())

        return new_s





        


if __name__ == '__main__':
    solution = Solution()
    solution.reorganizeString("aab")
