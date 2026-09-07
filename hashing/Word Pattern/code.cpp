class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        int j = 0;

        for (int i = 0; i < pattern.size(); i++) {
            string word = "";

            while (j < s.size() && s[j] != ' ') {
                word += s[j];
                j++;
            }

            // word missing
            if (word == "")
                return false;

            if (mp.count(pattern[i])) {
                if (mp[pattern[i]] != word)
                    return false;
            }
            else if (rev.count(word)) {
                return false;
            }
            else {
                mp[pattern[i]] = word;
                rev[word] = pattern[i];
            }

            // space skip
            if (j < s.size())
                j++;
        }

        // extra words
        if (j < s.size())
            return false;

        return true;
    }
};