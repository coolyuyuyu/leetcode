class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int delta = 0; unordered_set<int> set2; {
            delta -= std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
            for (int num : bobSizes) {
                delta += num;
                set2.insert(num);
            }
            delta /= 2;
        }

        for (int x : aliceSizes) {
            int y = delta + x;
            if (set2.find(y) != set2.end()) {
                return {x, y};
            }
        }

        assert(false); // at least one valid answer
        return {-1, -1};
    }
};
