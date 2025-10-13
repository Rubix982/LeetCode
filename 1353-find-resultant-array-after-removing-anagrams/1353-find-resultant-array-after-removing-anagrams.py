from collections import Counter

class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = []
        prev_counter = None

        for word in words:
            curr_counter = Counter(word)
            if curr_counter != prev_counter:
                res.append(word)
                prev_counter = curr_counter
        return res
        