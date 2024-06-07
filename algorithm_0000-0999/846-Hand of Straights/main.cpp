class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        multiset<int> ms;
        for (int num : hand) {
            ms.insert(num);
        }

        while (!ms.empty()) {
            int x = *ms.begin();
            for (int i = 0; i < groupSize; ++i) {
                int num = x + i;
                auto itr = ms.find(num);
                if (itr == ms.end()) { return false ;}
                ms.erase(itr);
            }
        }

        return true;
    }
};
