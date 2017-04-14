class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        if (k > 0) {
            unordered_set<int> s;
            for (auto num: nums) {
                s.emplace(num);
            }

            for (auto num: s) {
                if (s.find(num + k) != s.end()) {
                    ++result;
                }
            }
        
        }
        else if (k == 0) {
            unordered_map<int, int> m;
            for (auto num: nums) {
                pair<unordered_map<int, int>::iterator, bool> p = m.emplace(num, 1);
                if (!p.second) {
                    ++p.first->second;
                }
            }

            for (auto kv: m) {
                if (1 < kv.second) {
                    ++result;
                }
            }
        }

        return result;
    }
};