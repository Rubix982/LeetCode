class Solution:
    def minWindow(self, s: str, t: str) -> str:
        # Fixed size array for ASCII characters
        required = [0] * 128  # Supports ASCII characters (0 to 127)
        
        # Populate frequency of characters in t
        for char in t:
            required[ord(char)] += 1

        start, end = 0, 0
        min_window_length = float('inf')
        min_window_start = 0
        number_of_chars_to_be_included = len(t)

        while end < len(s):
            char_end = s[end]
            # If character is in t, decrement its count in the bitmap
            if required[ord(char_end)] > 0:
                number_of_chars_to_be_included -= 1
            required[ord(char_end)] -= 1

            # Shrink the window when all characters are matched
            while number_of_chars_to_be_included == 0:
                # Update the minimum window
                if end - start + 1 < min_window_length:
                    min_window_length = end - start + 1
                    min_window_start = start

                # Remove the start character from the window
                char_start = s[start]
                required[ord(char_start)] += 1
                if required[ord(char_start)] > 0:
                    number_of_chars_to_be_included += 1

                start += 1

            end += 1

        # Return the smallest window
        return "" if min_window_length == float('inf') else s[min_window_start:min_window_start + min_window_length]
