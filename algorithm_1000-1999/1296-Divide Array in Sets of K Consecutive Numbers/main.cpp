class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        multiset<int> ms;
        for (int num : nums) {
            ms.insert(num);
        }

        while (!ms.empty()) {
            int x = *ms.begin();
            for (int i = 0; i < k; ++i) {
                int num = x + i;
                auto itr = ms.find(num);
                if (itr == ms.end()) { return false ;}
                ms.erase(itr);
            }
        }

        return true;
    }
};