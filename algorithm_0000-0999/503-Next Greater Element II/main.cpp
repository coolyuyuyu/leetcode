class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nexts(nums.size(), -1);

        stack<size_t> indexes;
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!indexes.empty() && nums[indexes.top()] < nums[i]) {
               nexts[indexes.top()] = nums[i];
               indexes.pop();
            }
            indexes.push(i);
        }
        for (size_t i = 0; i < nums.size(); ++i) {
            while (!indexes.empty() && nums[indexes.top()] < nums[i]) {
               nexts[indexes.top()] = nums[i];
               indexes.pop();
            }
        }

        return nexts;
    }
};