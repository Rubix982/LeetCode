class Solution {
public:
    int maxFreqSum(std::string s) {
        std::array<int, 256> freq{};
        int maxVowel = 0, maxCons = 0;

        for (unsigned char c : s) {  // note unsigned to avoid negatives
            int count = ++freq[c];

            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                maxVowel = std::max(maxVowel, count);
            else
                maxCons = std::max(maxCons, count);
        }

        return maxVowel + maxCons;
    }
};