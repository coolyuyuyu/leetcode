class Solution {
public:
    vector<int> anagramMappings_ArrayLookup(vector<int>& nums1, vector<int>& nums2) {
        vector<int> indexes(100001);
        for (int i = 0; i < nums2.size(); ++i) {
            indexes[nums2[i]] = i;
        }

        vector<int> ans(nums1.size());
        for (size_t i = 0; i < nums1.size(); ++i) {
            ans[i] = indexes[nums1[i]];
        }

        return ans;
    }

    vector<int> anagramMappings_MapLookup(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> indexes;
        for (int i = 0; i < nums2.size(); ++i) {
            indexes[nums2[i]] = i;
        }

        vector<int> ans(nums1.size());
        for (size_t i = 0; i < nums1.size(); ++i) {
            ans[i] = indexes[nums1[i]];
        }

        return ans;
    }

    vector<int> anagramMappings_HashLookup(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> indexes;
        for (int i = 0; i < nums2.size(); ++i) {
            indexes[nums2[i]] = i;
        }

        vector<int> ans(nums1.size());
        for (size_t i = 0; i < nums1.size(); ++i) {
            ans[i] = indexes[nums1[i]];
        }

        return ans;
    }

    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        //return anagramMappings_ArrayLookup(nums1, nums2);
        //return anagramMappings_MapLookup(nums1, nums2);
        return anagramMappings_HashLookup(nums1, nums2);
    }
};
