class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nexts; // val -> next greater val
        stack<int> stk;
        for (int i = 0; i < nums2.size(); ++i) {
            while (!stk.empty() && stk.top() < nums2[i]) {
                nexts[stk.top()] = nums2[i];
                stk.pop();
            }

            stk.push(nums2[i]);
        }
        while (!stk.empty()) {
            nexts[stk.top()] = -1;
            stk.pop();
        }

        for (int& num : nums1) {
            num = nexts[num];
        }
        return nums1;
    }
};