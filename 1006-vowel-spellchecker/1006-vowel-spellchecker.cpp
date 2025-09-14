class Solution {
public:
    string devowel(string word) {
        for (char &c : word) {
            if (isVowel(c)) c = '*';
            else c = tolower(c);
        }
        return word;
    }

    bool isVowel(char c) {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> words(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;

        for (string word : wordlist) {
            string lower = word;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);

            if (!caseInsensitive.count(lower)) {
                caseInsensitive[lower] = word;
            }

            string dev = devowel(lower);
            if (!vowelInsensitive.count(dev)) {
                vowelInsensitive[dev] = word;
            }
        }

        vector<string> result;
        for (string query : queries) {
            if (words.count(query)) {
                result.push_back(query);
                continue;
            }

            string lower = query;
            transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
            if (caseInsensitive.count(lower)) {
                result.push_back(caseInsensitive[lower]);
                continue;
            }

            string dev = devowel(lower);
            if (vowelInsensitive.count(dev)) {
                result.push_back(vowelInsensitive[dev]);
                continue;
            }

            result.push_back("");
        }

        return result;
    }
};
