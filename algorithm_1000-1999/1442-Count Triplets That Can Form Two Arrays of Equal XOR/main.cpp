class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> presum2indexes;
        presum2indexes[0].push_back(-1);

        int ret = 0;
        for (int k = 0, sum = 0; k < arr.size(); ++k) {
            int num = arr[k];

            sum ^= num;
            for (int t : presum2indexes[sum]) {
                int i = t + 1;
                ret += k - i;
            }

            presum2indexes[sum].push_back(k);
        }

        return ret;
    }
};
