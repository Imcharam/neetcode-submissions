class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> groups;
        unordered_map<string,int> index_group;
        int index = 0;
        for (int i = 0; i < strs.size(); i++) {
            vector<int> char_length(26,0);
            for (int j = 0; j < strs[i].size(); j++) {
                char_length[strs[i][j] - 'a']++;
            }
            string chars;
            for (auto i : char_length) {
                char c = i + '0';
                chars += c;
            }
            if (index_group.contains(chars)) {
                groups[index_group[chars]].push_back(strs[i]);
            } else {
                index_group[chars] = index;
                groups.push_back({strs[i]});
                index++;
            }
        }
        return groups;
    }
};
