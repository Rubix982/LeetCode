class Solution:
    def ladderLength(self, beginWord: str, endWord: str, wordList: List[str]) -> int:
        if endWord not in wordList:
            return 0

        word_len = len(beginWord)
        word_dict = defaultdict(list)
        for word in wordList:
            for i in range(word_len):
                generic_word = f"{word[:i]}*{word[i+1:]}"
                word_dict[generic_word].append(word)

        # BFS initialization
        queue = deque([(beginWord, 1)])  # (current_word, current_depth)
        visited = set([beginWord])  # Track visited words

        while queue:
            current_word, level = queue.popleft()

            for i in range(word_len):
                generic_word = f"{current_word[:i]}*{current_word[i+1:]}"

                for neighbor in word_dict[generic_word]:
                    if neighbor == endWord:
                        return level + 1

                    if neighbor not in visited:
                        visited.add(neighbor)
                        queue.append((neighbor, level + 1))

                # Clear the processed generic_word to save memory
                word_dict[generic_word] = []

        return 0
