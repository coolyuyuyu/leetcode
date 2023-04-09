class Solution {
public:
    vector<int> anagramMappings_ArrayLookup(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        array<int, 100001> indexes;
        for (int i = 0; i < n; ++i) {
            indexes[nums2[i]] = i;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = indexes[nums1[i]];
        }

        return ret;
    }

    vector<int> anagramMappings_MapLookup(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        map<int, int> indexes;
        for (int i = 0; i < n; ++i) {
            indexes[nums2[i]] = i;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = indexes[nums1[i]];
        }

        return ret;
    }

    vector<int> anagramMappings_HashLookup(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<int, int> indexes;
        for (int i = 0; i < n; ++i) {
            indexes[nums2[i]] = i;
        }

        vector<int> ret(n);
        for (int i = 0; i < n; ++i) {
            ret[i] = indexes[nums1[i]];
        }

        return ret;
    }

    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        return anagramMappings_ArrayLookup(nums1, nums2);
        //return anagramMappings_MapLookup(nums1, nums2);
        //return anagramMappings_HashLookup(nums1, nums2);
    }
};
