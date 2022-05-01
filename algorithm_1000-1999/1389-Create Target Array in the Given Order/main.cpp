class Solution {
public:
    vector<int> bruteforce1(vector<int>& nums, vector<int>& index) {
        vector<int> ans;
        for (size_t i = 0; i < nums.size(); ++i) {
            ans.insert(ans.begin() + index[i], nums[i]);
        }
        return ans;
    }

    vector<int> bruteforce2(vector<int>& nums, vector<int>& index) {
        vector<int> ans(nums.size());
        for (size_t i = 0; i < nums.size(); ++i) {
            for (size_t j = i + 1; (index[i] + 1) < j--;) {
                ans[j] = ans[j - 1];
            }
            ans[index[i]] = nums[i];
        }
        return ans;
    }

    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        //return bruteforce1(nums, index);
        return bruteforce2(nums, index);
    }
};
