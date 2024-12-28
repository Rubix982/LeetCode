class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        return self.simplerFindSubstring(s, words)
        result = []
        length = len(words[0])
        word_count = defaultdict(int)

        for word in words:
            word_count[word] += 1

        # Iterate for each offset (as many times as the length of each word)
        for offset in range(length):
            # Sliding window size
            size = 0
            # Sliding window memory (frequency map)
            seen = defaultdict(int)

            # Iterate over the string, with the step equals to length
            for i in range(offset, len(s) - length + 1, length):
                # This is the word we're going to check
                sub = s[i:i + length]

                # If the word is absent in the reference map, clear the sliding window and move on
                if sub not in word_count:
                    seen.clear()
                    size = 0
                    continue

                # Increase the number of occurrences of the word in seen map
                seen[sub] += 1
                size += 1

                # To make sure the sliding window is valid, check the recent occurrence against the reference
                while seen[sub] > word_count[sub]:
                    # If the occurrences amount exceeds the reference amount,
                    # shrink the window from the left until it becomes valid again

                    # A word at the beginning of the current sliding window
                    first = s[i - (size - 1) * length:i - (size - 1) * length + length]

                    # Remove the occurrence from the window, shrinking it from the left
                    seen[first] -= 1
                    size -= 1

                # If we used all words from the words array, we have found the correct spot
                # and we need to calculate the beginning index of the current sliding window
                if size == len(words):
                    result.append(i - (size - 1) * length)

        return result

    def simplerFindSubstring(self, s: str, words: List[str]) -> List[int]:
        result = []
        if not s or not words:
            return result
        
        word_len = len(words[0])
        word_count = Counter(words)
        total_len = len(words) * word_len
        s_len = len(s)
        
        # Iterate for each possible offset in the word length
        for offset in range(word_len):
            seen = Counter()
            start = offset
            for end in range(offset, s_len - word_len + 1, word_len):
                word = s[end:end + word_len]
                
                # If the word is valid, process it
                if word in word_count:
                    seen[word] += 1
                    
                    # Shrink the window if there are too many occurrences of the word
                    while seen[word] > word_count[word]:
                        seen[s[start:start + word_len]] -= 1
                        start += word_len
                    
                    # If we matched all words, add the starting index to result
                    if end - start + word_len == total_len:
                        result.append(start)
                else:
                    # Reset the window if the word is invalid
                    seen.clear()
                    start = end + word_len
        
        return result
