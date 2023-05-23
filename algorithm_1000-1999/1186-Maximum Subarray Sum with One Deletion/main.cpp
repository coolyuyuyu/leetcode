class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int delN = arr[0];  // delN[i]: the maximum subarray (of arr[0:i]) sum ending at i without deletion
        int delY = 0;       // delY[i]: the maximum subarray (of arr[0:i]) sum ending at i with deletion
        int ret = arr[0];
        for (int i = 1; i < arr.size(); ++i) {
            int tmpN = delN, tmpY = delY;
            delN = std::max(tmpN + arr[i], arr[i]);
            delY = std::max(tmpY + arr[i], tmpN);
            ret = std::max({ret, delN, delY});
        }

        return ret;
    }
};
