from collections import Counter

class Solution:
    def removeAnagrams(self, words: List[str]) -> List[str]:
        res = []
        prev = None
        
        for word in words:
            # Canonical representation using sorted characters
            curr = ''.join(sorted(word))
            
            if curr != prev:
                res.append(word)
                prev = curr
        
        return res
            