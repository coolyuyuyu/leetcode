class Solution {
public:
    // Time: O((M + N)logN), Space: N
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, size_t> m;
        for (size_t i = 0; i < list2.size(); ++i) {
            m[list2[i]] = i;
        }

        size_t minSum = std::numeric_limits<size_t>::max();
        std::vector<string> ans;
        for (size_t i = 0; i < list1.size(); ++i) {
            auto itr = m.find(list1[i]);
            if (itr != m.end()) {
                size_t sum = i + itr->second;
                if (sum == minSum) {
                    ans.push_back(list1[i]);
                }
                else if (sum < minSum) {
                    minSum = sum;
                    ans.clear();
                    ans.push_back(list1[i]);
                }
            }
        }

        return ans;
    }
};
