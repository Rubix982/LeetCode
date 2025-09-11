#include <iostream>

class Solution {
public:
    string sortVowels(string s) {
        char vowels[10] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        std::vector<char> vowelCharactersOnly;
        for (char strChar : s) {
            for (char vowel : vowels) {
                if (strChar != vowel) {
                    continue;
                }

                vowelCharactersOnly.push_back(strChar);
            }
        }

        std::sort(vowelCharactersOnly.begin(), vowelCharactersOnly.end());

        int vowelCharactersOnlyIdx = 0;
        for (int i = 0; i < s.length(); i++) {
            bool foundVowel = false;
            for (char vowel : vowels) {
                if (s[i] != vowel || foundVowel) {
                    continue;
                }

                s[i] = vowelCharactersOnly.at(vowelCharactersOnlyIdx++);
                foundVowel = true;
            }
        }

        return s;
    }
};