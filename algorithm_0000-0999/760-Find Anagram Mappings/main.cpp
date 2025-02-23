class Solution {
public:
    vector<int> byArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        vector<int> m(100001);
        for (int i = 0; i < n; ++i) {
            m[nums2[i]] = i;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = m[nums1[i]];
        }

        return ret;
    }

    vector<int> byMap(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[nums2[i]] = i;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = m[nums1[i]];
        }

        return ret;
    }

    vector<int> byHash(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i) {
            m[nums2[i]] = i;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = m[nums1[i]];
        }

        return ret;
    }

    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        //return byArray(nums1, nums2);
        //return byMap(nums1, nums2);
        return byHash(nums1, nums2);
    }
};
