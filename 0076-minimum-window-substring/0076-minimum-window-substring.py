class Solution:
    def minWindow(self, s: str, t: str) -> str:
        len_t = len(t)
        len_s = len(s)
        if len_s < len_t:
            return ""

        # Fixed size array for ASCII characters
        required = [0] * 128  # Supports ASCII characters (0 to 127)
        
        # Populate frequency of characters in t
        for char in t:
            required[ord(char)] += 1

        start, end = 0, 0
        min_window_length = len_s + 1
        min_window_start = 0
        number_of_chars_to_be_included = len_t

        while end < len_s:
            # If character is in t, decrement its count in the bitmap
            ord_char_end = ord(s[end])
            if required[ord_char_end] > 0:
                number_of_chars_to_be_included -= 1
            required[ord_char_end] -= 1

            # Shrink the window when all characters are matched
            while number_of_chars_to_be_included == 0:
                # Update the minimum window
                length_calc = end - start + 1
                if length_calc < min_window_length:
                    min_window_length = length_calc
                    min_window_start = start

                # Remove the start character from the window
                ord_char_start = ord(s[start])
                required[ord_char_start] += 1
                if required[ord_char_start] > 0:
                    number_of_chars_to_be_included += 1

                start += 1

            end += 1

        # Return the smallest window
        return "" if min_window_length == len_s + 1 else s[min_window_start:min_window_start + min_window_length]
