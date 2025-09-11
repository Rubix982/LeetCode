#include <vector>
#include <algorithm>
#include <unordered_set>

class Solution {
public:
    string sortVowels(string s) {
        bool isVowel[256] = {0};
        for (char c : "aeiouAEIOU") isVowel[(unsigned char)c] = true;

        std::vector<char> vowelChars;
        vowelChars.reserve(s.size());

        for (char c : s)
            if (isVowel[(unsigned char)c])
                vowelChars.push_back(c);

        std::sort(vowelChars.begin(), vowelChars.end());

        int idx = 0;
        for (char &c: s)
            if (isVowel[(unsigned char)c])
                c = vowelChars.at(idx++);

        return s;
    }
};