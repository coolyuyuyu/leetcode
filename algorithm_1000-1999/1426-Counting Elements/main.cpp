class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int elem : arr) {
            ++freq[elem];
        }

        int ret = 0;
        for (int elem : arr) {
            ret += (freq[elem + 1] > 0 ? 1 : 0);
        }

        return ret;
    }
};
