class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        anagram_dict = {}

        for word in strs:
            key = ''.join(sorted(word))
            if key in anagram_dict:
                anagram_dict[key].append(word)
            else:
                anagram_dict[key] = [word]
        
        return list(anagram_dict.values())