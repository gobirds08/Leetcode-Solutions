class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        current_substring = ''
        length = 0

        for letter in s:
            index_substring = current_substring.find(letter)
            length = max(length, len(current_substring))
            if index_substring != -1:
                current_substring = current_substring[index_substring + 1:]
            current_substring += letter
        length = max(length, len(current_substring))
        return length
