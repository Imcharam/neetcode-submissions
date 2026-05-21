class Solution {
public:
    bool isAnagram(string s, string t) {
        // base case, if unequal
        if (s.size() != t.size()) {
            return false;
        }
        // hash map of letters
        unordered_map<char,int> sletters;
        unordered_map<char,int> tletters;
        // iterate over
        for (int i = 0; i < s.length(); i++) {
            sletters[s[i]]++;
            tletters[t[i]]++;
        }
        if (sletters == tletters) {
            return true;
        }
        return false;
    }
};
