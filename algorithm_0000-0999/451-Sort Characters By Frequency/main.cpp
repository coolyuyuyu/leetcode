class Solution {
public:
    string frequencySort(string s) {
        int counts[128] = {0};
        for (char c : s) {
            ++counts[c];
        }

        vector<string> buckets(s.size() + 1);
        for (size_t i = 0; i < 128; ++i) {
            buckets[counts[i]].append(counts[i], (char)i);
        }

        ostringstream oss;
        for (auto itr = buckets.rbegin(); itr != buckets.rend(); ++itr) {
            oss << *itr;
        }
        return oss.str();
    }
};