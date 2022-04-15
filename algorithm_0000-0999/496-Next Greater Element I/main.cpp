class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> greaters; {
            stack<int> stk;
            for (int num : nums2) {
                while (!stk.empty() && stk.top() < num) {
                    greaters[stk.top()] = num;
                    stk.pop();
                }
                stk.push(num);
            }
        }

        vector<int> ans;
        for (int num : nums1) {
            auto itr = greaters.find(num);
            if (itr != greaters.end()) {
                ans.push_back(itr->second);
            }
            else {
                ans.push_back(-1);
            }
        }

        return ans;
    }
};
