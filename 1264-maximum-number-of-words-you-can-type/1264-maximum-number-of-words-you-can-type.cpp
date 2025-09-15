#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        // Step 1: mark broken letters in a lookup table
        bool broken[26] = {false}; // array of 26 flags for 'a'...'z'
        for (char c : brokenLetters) broken[c - 'a'] = true;     

        // Step 2: split text into words using stringstream
        std::stringstream ss(text);
        std::string word;
        int completeWordCount = 0;

        while (ss >> word) {
            bool brokenLetterExists = false;

            // Step 3: check each character in the word
            for (char c : word) {
                if (broken[c - 'a']) {
                    brokenLetterExists = true;
                    break;
                }
            }

            // Step 4: count only words without broken letters
            if (!brokenLetterExists) {
                completeWordCount++;
            }
        }

        return completeWordCount;
    }
};