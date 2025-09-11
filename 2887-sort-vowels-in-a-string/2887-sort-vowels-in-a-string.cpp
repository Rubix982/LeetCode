#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    string sortVowels(string s) {
        std::unordered_set<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        std::vector<char> vowelChars;

        for (char c : s) {
            if (vowels.count(c)) {
                vowelChars.push_back(c);
            }
        }

        std::sort(vowelChars.begin(), vowelChars.end());

        int idx = 0;
        for (char &c: s) {
            if (vowels.count(c)) {
                c = vowelChars.at(idx++);
            }
        }

        return s;
    }
};