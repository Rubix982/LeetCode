class Solution {
public:
    int maxFreqSum(string s) {
        std::unordered_map<char, int> vowelCount = {
            {'a', 0},
            {'e', 0},
            {'i', 0},
            {'o', 0},
            {'u', 0},
        };
        std::unordered_map<char, int> consonants;
        std::unordered_set<char> vowels { 'a', 'e', 'i', 'o', 'u' };

        for (char c : s) {
            if (vowels.count(c)) {
                vowelCount[c]++;
            } else {
                // Key does not exist yet
                if (consonants.find(c) == consonants.end()) {
                    consonants.insert({{c, 1}});
                } else {
                    consonants[c]++;
                }
            }
        }

        int maxVowelCount = 0;
        int maxConsonantCount = 0;

        for (auto &x: vowelCount) {
            if (x.second > maxVowelCount) {
                maxVowelCount = x.second;
            }
        }

        for (auto &x: consonants) {
            if (x.second > maxConsonantCount) {
                maxConsonantCount = x.second;
            }
        }

        return maxVowelCount + maxConsonantCount;
    }
};