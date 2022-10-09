class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> ans;

        string prev;
        for (const auto& word : words) {
            string tmp = word;
            std::sort(tmp.begin(), tmp.end());
            if (tmp != prev) {
               ans.push_back(word);
               prev = tmp;
           }
        }

        return ans;
    }
};
