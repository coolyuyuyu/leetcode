class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        array<bitset<3>, 101> bstrs;
        for (int num : nums1) {
            bstrs[num][0] = true;
        }
        for (int num : nums2) {
            bstrs[num][1] = true;
        }
        for (int num : nums3) {
            bstrs[num][2] = true;
        }

        vector<int> ans;
        for (int i = 0; i < bstrs.size(); ++i) {
            if (2 <= bstrs[i].count()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
