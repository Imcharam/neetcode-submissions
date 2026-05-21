class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;

        // Hashmap of charcount -> list of strings
        unordered_map<string, vector<string>> store;

        for (string str : strs) {
            vector<int> count(26,0);
            for (char c : str) {
                count[c - 'a']++;
            }
            
            string key = to_string(count[0]);
            for (int i = 1; i < count.size(); i++) {
                key += ',' + to_string(count[i]);
            }

            if (store.contains(key)) {
                store[key].push_back(str);
            } else {
                store[key] = {str};
            }
        }
        for (auto pair : store) {
            result.push_back(pair.second);
        }
        
        return result;
    }
};
