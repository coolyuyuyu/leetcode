class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map <int, int> hash;
        for (int i = 0; i < numbers.size(); ++i) {
            unordered_map <int, int>::const_iterator iter = hash.find(target - numbers[i]);
            if (iter != hash.end()) {
                return {iter->second + 1, i + 1};
            }
            else {
                hash.emplace(numbers[i], i);
            }
        }
        return {};
    }
};