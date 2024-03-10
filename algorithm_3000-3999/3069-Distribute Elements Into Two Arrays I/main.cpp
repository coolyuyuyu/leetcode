class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1 = {nums[0]};
        vector<int> arr2 = {nums[1]};
        for (int i = 2; i < nums.size(); ++i) {
            if (arr1.back() > arr2.back()) {
                arr1.push_back(nums[i]);
            }
            else {
                arr2.push_back(nums[i]);
            }
        }

        vector<int> ret;
        ret.insert(ret.end(), arr1.begin(), arr1.end());
        ret.insert(ret.end(), arr2.begin(), arr2.end());

        return ret;
    }
};
