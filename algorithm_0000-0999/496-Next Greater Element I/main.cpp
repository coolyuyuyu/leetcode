class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> greaters;
        stack<int> stk;
        for (int num : nums2) {
            while (!stk.empty() && stk.top() <num) {
                greaters[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }

        vector<int> ret(nums1.size());
        for (size_t i = 0; i < nums1.size(); ++i){
            auto itr = greaters.find(nums1[i]);
            ret[i] = (itr == greaters.end() ? -1 : itr->second);
        }

        return ret;
    }
};
