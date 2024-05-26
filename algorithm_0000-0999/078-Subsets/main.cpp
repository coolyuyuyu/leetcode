class Solution {
public:
    vector<vector<int>> recursive(vector<int>& nums) {
        vector<int> comb;
        vector<vector<int>> combs;
        std::function<void(int)> f = [&](int i) {
            if (i >= nums.size()) {
                combs.push_back(comb);
                return;
            }

            f(i + 1);

            comb.push_back(nums[i]);
            f(i + 1);
            comb.pop_back();
        };
        f(0);

        return combs;
    }

    vector<vector<int>> iterative(vector<int>& nums) {
        vector<vector<int>> combs = {{}};
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = 0, n = combs.size(); j < n; ++j) {
                combs.push_back(combs[j]);
                combs[j].push_back(nums[i]);
            }
        }

        return combs;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        //return recursive(nums);
        return iterative(nums);
    }
};
