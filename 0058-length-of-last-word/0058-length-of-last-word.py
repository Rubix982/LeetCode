class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        s = s.strip()
        s_splits = s.split(" ")
        return len(s_splits[-1].strip())
        