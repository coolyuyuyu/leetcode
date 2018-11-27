class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        typedef pair<int, int> NumPair;
        auto comp = [](const NumPair& lft, const NumPair& rht) { return lft.first + lft.second < rht.first + rht.second; };
        priority_queue<NumPair, vector<NumPair>, decltype(comp)> pq(comp);
        for (size_t i = 0; i < nums1.size(); ++i) {
            for (size_t j = 0; j < nums2.size(); ++j) {
                if (pq.size() < k) {
                    pq.emplace(nums1[i], nums2[j]);
                }
                else {
                    const NumPair& numPair = pq.top();
                    if (comp(NumPair(nums1[i], nums2[j]), numPair)) {
                        pq.pop();
                        pq.emplace(nums1[i], nums2[j]);
                    }
                    else {
                        break;
                    }
                }
            }
        }

        vector<pair<int, int>> ans;
        while (!pq.empty()) {
            NumPair numPair = pq.top();
            pq.pop();

            ans.push_back(numPair);
        }
        return ans;
    }
};