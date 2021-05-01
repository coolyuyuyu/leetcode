class Solution {
public:
    int countElements(vector<int>& arr) {
        vector<bool> existences(1001, false);
        for (int num : arr) {
            existences[num] = true;
        }

        auto pred = [&existences](int num) {
            return existences[num + 1];
        };
        return count_if(arr.begin(), arr.end(), pred);
    }
};
