class Solution {
public:
    // Time: O(n^3), TLE
    vector<vector<int>> bruteforce(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (size_t i = 0; i < nums.size(); ++i) {
            if (0 < i && nums[i - 1] == nums[i]) {
                continue;
            }
            for (size_t j = i + 1; j < nums.size(); ++j) {
                if ((i + 1) < j && nums[j - 1] == nums[j]) {
                    continue;
                }
                for (size_t k = j + 1; k < nums.size(); ++k) {
                    if ((j + 1) < k && nums[k - 1] == nums[k]) {
                        continue;
                    }
                    if ((nums[i] + nums[j] + nums[k]) == 0) {
                        ans.push_back({nums[i], nums[j], nums[k]});
                    }
                }
            }
        }

        return ans;
    }

    // Time: O(n^2)
    vector<vector<int>> twopointer(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        for (size_t i = 0; (i + 2) < nums.size(); ++i) {
            if (0 < i && nums[i - 1] == nums[i]) {
                continue;
            }

            for (size_t j = i + 1, k = nums.size() - 1; j < k;) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    do {
                        ++j;
                    } while (j < k && nums[j - 1] == nums[j]);
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
                else if (sum < 0) {
                    do {
                        ++j;
                    } while (j < k && nums[j - 1] == nums[j]);
                } 
                else {
                    do {
                        --k;
                    } while (j < k && nums[k] == nums[k + 1]);
                }
            }
        }

        return ans;
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        //return bruteforce(nums);
        return twopointer(nums);
    }
};
