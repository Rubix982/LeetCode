class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
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
