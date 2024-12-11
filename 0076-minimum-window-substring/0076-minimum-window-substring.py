class Solution:
    def minWindow(self, s: str, t: str) -> str:
        from collections import Counter
        
        # Count the characters in t
        required = Counter(t)
        window = Counter()
        
        # Number of unique characters in t that need to match in the window
        required_chars = len(required)
        formed_chars = 0

        start, end = 0, 0
        min_window_length = float('inf')
        min_window_start = 0

        while end < len(s):
            char = s[end]
            window[char] += 1
            
            # If the current character matches the count in `required`, it's fully formed
            if char in required and window[char] == required[char]:
                formed_chars += 1

            # Try shrinking the window if all required characters are formed
            while formed_chars == required_chars:
                if end - start + 1 < min_window_length:
                    min_window_length = end - start + 1
                    min_window_start = start

                # Remove the leftmost character
                left_char = s[start]
                window[left_char] -= 1
                if left_char in required and window[left_char] < required[left_char]:
                    formed_chars -= 1
                
                start += 1

            end += 1

        # Return the smallest window
        return "" if min_window_length == float('inf') else s[min_window_start:min_window_start + min_window_length]