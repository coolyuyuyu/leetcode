class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        auto comp = [](const vector<int>& b1, const vector<int>& b2) {
            if (b1[1] == b2[1]) {
                return b1[0] > b2[0];
            }
            else {
                return b1[1] > b2[1];
            }
        };
        std::sort(boxTypes.begin(), boxTypes.end(), comp);


        int totalUnit = 0;
        for (const auto& boxType : boxTypes) {
            int pickSize = std::min(truckSize, boxType[0]);
            truckSize -= pickSize;
            totalUnit += (pickSize * boxType[1]);
            if (truckSize == 0) {
                break;
            }
        }

        return totalUnit;
    }
};
