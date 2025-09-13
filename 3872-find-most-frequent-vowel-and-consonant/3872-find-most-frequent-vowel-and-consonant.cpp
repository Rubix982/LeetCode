class Solution {
public:
    int maxFreqSum(std::string s) {
        // Frequency array for all lowercase letters (assuming input is lowercase a-z)
        std::vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Track vowel max and consonant max
        int maxVowel = 0, maxCons = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == 0) continue;
            char c = 'a' + i;
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                maxVowel = std::max(maxVowel, freq[i]);
            else
                maxCons = std::max(maxCons, freq[i]);
        }

        return maxVowel + maxCons;
    }
};