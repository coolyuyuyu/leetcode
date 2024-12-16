class Solution {
public:
    int countPairs(vector<int>& nums) {
        int len = std::to_string(*std::max_element(nums.begin(), nums.end())).size();

        int ret = 0;
        unordered_map<int, int> cnts;
        for (int num : nums) {
            ret += cnts[num];

            string str = std::to_string(num);
            str = string(len - str.size(), '0') + str;

            unordered_set<int> uniques;
            uniques.insert(std::stoi(str));
            for (int i = 0; i < len; ++i) {
                for (int j = i + 1; j < len; ++j) {
                    std::swap(str[i], str[j]);
                    uniques.insert(std::stoi(str));
                    std::swap(str[i], str[j]);
                }
            }

            for (int unique : uniques) {
                ++cnts[unique];
            }
        }

        return ret;
    }
};
