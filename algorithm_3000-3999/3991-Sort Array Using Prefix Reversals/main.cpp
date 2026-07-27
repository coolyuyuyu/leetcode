class Solution {
public:
    int sortArray(vector<int>& nums, vector<int>& pre) {
        int n = nums.size();

        std::function<int(const vector<int>&)> computeId = [](const vector<int>& nums) {
            int ret = 0;
            for (int num : nums) {
                ret = ret * 10 + num + 1;
            }
            return ret;
        };
        unordered_set<int> visited;

        queue<vector<int>> q;
        visited.insert(computeId(nums));
        q.emplace(nums);
        for (int ret = 0; !q.empty(); ++ret) {
            for (int i = q.size(); 0 < i--;) {
                auto cur = q.front();
                q.pop();

                if (std::is_sorted(cur.begin(), cur.end())) {
                    return ret;
                }

                for (int len : pre) {
                    auto nxt = cur;
                    std::reverse(nxt.begin(), nxt.begin() + len);
                    if (visited.insert(computeId(nxt)).second) {
                        q.emplace(nxt);
                    }
                }
            }
        }

        return -1;
    }
};
