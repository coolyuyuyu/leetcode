class Solution {
public:
    // Time: O(NlogN)
    vector<int> sortAndSquare(vector<int>& nums) {
        auto comp = [](int lft, int rht) {
            return abs(lft) < abs(rht);
        };
        std::sort(nums.begin(), nums.end(), comp);

        for (int& num : nums) {
            num *= num;
        }

        return nums;
    }

    // Time: O(N)
    vector<int> linearConverge(vector<int>& nums) {
        vector<int> ans(nums.size());
        for (size_t lft = 0, rht = nums.size(), i = nums.size(); 0 < i--;) {
            if (abs(nums[lft]) < abs(nums[--rht])) {
                ans[i] = nums[rht] * nums[rht];
            }
            else {
                ans[i] = nums[lft] * nums[lft];
                ++lft;
                ++rht;
            }
        }

        return ans;
    }

    vector<int> sortedSquares(vector<int>& nums) {
        //return sortAndSquare(nums);
        return linearConverge(nums);
    }
};
