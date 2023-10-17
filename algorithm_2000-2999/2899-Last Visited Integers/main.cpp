class Solution {
public:
    vector<int> lastVisitedIntegers(vector<string>& words) {
        vector<int> ret;

        vector<int> nums;
        int k = 0;
        for (const string& word : words) {
            if (word == "prev") {
                ++k;
                if (k > nums.size()) {
                    ret.push_back(-1);
                }
                else {
                    ret.push_back(nums[nums.size() - k]);
                }
            }
            else {
                k = 0;
                nums.push_back(std::stoi(word));
            }
        }
        return ret;
    }
};
