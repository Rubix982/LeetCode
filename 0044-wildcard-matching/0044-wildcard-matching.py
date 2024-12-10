class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        return self.isMatchDPApproach(s, p) and self.isMatchIdxPointer(s, p)

    def isMatchDPApproach(self, s: str, p: str) -> bool:
        s_len, p_len = len(s), len(p)
        
        # DP table where dp[i][j] means if s[:i] matches p[:j]
        dp = [[False] * (p_len + 1) for _ in range(s_len + 1)]
        dp[0][0] = True  # Empty string matches empty pattern
        
        # Handle patterns with leading '*' (they can match empty string)
        for j in range(1, p_len + 1):
            if p[j - 1] == '*':
                dp[0][j] = dp[0][j - 1]
        
        for i in range(1, s_len + 1):
            for j in range(1, p_len + 1):
                if p[j - 1] == s[i - 1] or p[j - 1] == '?':
                    dp[i][j] = dp[i - 1][j - 1]
                elif p[j - 1] == '*':
                    dp[i][j] = dp[i][j - 1] or dp[i - 1][j]
        
        return dp[s_len][p_len]

    def isMatchIdxPointer(self, s: str, p: str) -> bool:
        s_len, p_len = len(s), len(p)
        s_idx, p_idx = 0, 0
        star_idx, s_tmp_idx = -1, -1

        while s_idx < s_len:
            # If characters match or pattern has '?'
            if p_idx < p_len and (p[p_idx] == s[s_idx] or p[p_idx] == '?'):
                s_idx += 1
                p_idx += 1
            # If pattern has '*', record position and try matching zero characters
            elif p_idx < p_len and p[p_idx] == '*':
                star_idx = p_idx
                s_tmp_idx = s_idx
                p_idx += 1
            # If mismatch occurs and there was a '*', backtrack
            elif star_idx != -1:
                p_idx = star_idx + 1
                s_tmp_idx += 1
                s_idx = s_tmp_idx
            else:
                return False

        # Check for remaining '*' in the pattern
        while p_idx < p_len and p[p_idx] == '*':
            p_idx += 1

        return p_idx == p_len
